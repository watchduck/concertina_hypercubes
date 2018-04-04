from functions import pairs_to_sequences
from variables import *


polytope = LatticePolytope(vertices)


# CREATE `cell_dicts` WITH VERTICES, EDGES AND FACES

cell_dicts = []
cell_objects = polytope.faces()[4]
for cell_object in cell_objects:

    vertex_objects = cell_object.faces()[1]
    vertex_indices = []
    for vertex_object in vertex_objects:
        vertex = tuple(vertex_object.points()[0])
        vertex_indices.append(vertices.index(vertex))

    edge_objects = cell_object.faces()[2]
    edge_pairs = []  # sorted pairs of vertex indices
    for edge_object in edge_objects:
        edge_pair = []
        point_objects = edge_object.faces()[1]
        for point_object in point_objects:
            point = tuple(point_object.points()[0])
            point_index = vertices.index(point)
            edge_pair.append(point_index)
        edge_pairs.append(sorted(edge_pair))
    edge_indices = []
    for edge_pair in edge_pairs:
        edge_indices.append(edges.index(edge_pair))

    face_objects = cell_object.faces()[3]
    face_lists = []  # sorted lists of vertex indices
    for face_object in face_objects:
        face_list = []
        point_objects = face_object.faces()[1]
        for point_object in point_objects:
            point = tuple(point_object.points()[0])
            point_index = vertices.index(point)
            face_list.append(point_index)
        face_lists.append(sorted(face_list))
    face_indices = []
    for face_list in face_lists:
        for i, face in enumerate(faces):
            if face_list == sorted(face):
                face_indices.append(i)

    cell_dicts.append({
        'vertices': vertex_indices,
        'edges': edge_indices,
        'faces': face_indices
    })


# RECOGNIZE TYPE OF EACH CELL AND ADD IT TO `cell_dicts`

rank_tuples_to_names = {
    (0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 6): 'lower concertina cube',
    (4, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 10): 'upper concertina cube',

    (1, 2, 2, 2, 3, 3, 3, 4): 'lower trigonal trapezohedron',
    (6, 7, 7, 7, 8, 8, 8, 9): 'upper trigonal trapezohedron',

    (2, 3, 3, 3, 4, 4, 4, 5): 'lower rhombic prism',
    (5, 6, 6, 6, 7, 7, 7, 8): 'upper rhombic prism',

    (3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7): 'rhombic dodecahedron',
    (3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7): 'concertina square prism'
}

for cell_dict in cell_dicts:
    rank_list = []
    vertices = cell_dict['vertices']
    for vertex in vertices:
        rank_list.append(vertex_ranks[vertex])
    rank_tuple = tuple(sorted(rank_list))
    name = rank_tuples_to_names[rank_tuple]
    cell_dict['type'] = name


# FIND CELLS OF SAME TYPE IN `cell_dicts`,
# find elements that belong and those that don't belong to them
# and print them as separate Povray arrays

for type in rank_tuples_to_names.values():
    print('################################## ' + type)

    # FACES
    face_indices = set()
    for cell_dict in cell_dicts:
        if cell_dict['type'] == type:
            new_face_indices = cell_dict['faces']
            for new_face_index in new_face_indices:
                if new_face_index not in faces_containing_origin:
                    face_indices.add(new_face_index)
    povray = 'array[{l}]{{'.format(l=len(face_indices))
    for face_index in sorted(face_indices):
        povray += str(face_index) + ', '
    povray = povray[:-2] + '}'
    print('###### faces')
    print(povray)

    # EDGES
    edge_indices = []
    for cell_dict in cell_dicts:
        if cell_dict['type'] == type:
            new_edge_indices = cell_dict['edges']
            for new_edge_index in new_edge_indices:
                if new_edge_index not in edges_containing_origin:
                    edge_indices.append(new_edge_index)

    unique_edge_indices = list(set(edge_indices))
    edge_indices_by_count = {1: [], 2: [], 3: []}
    for edge_index in unique_edge_indices:
        count = edge_indices.count(edge_index)
        edge_indices_by_count[count].append(edge_index)

    # absent edges
    edge_indices_by_count[0] = list(
        set(range(344)).difference(set(edges_containing_origin)).difference(set(edge_indices))
    )

    for count in range(4):
        length = len(edge_indices_by_count[count])
        print('###### edges ' + str(count))
        if length > 0:
            povray = 'array[{l}]{{'.format(l=length)
            for edge_index in sorted(edge_indices_by_count[count]):
                povray += str(edge_index) + ', '
            povray = povray[:-2] + '},'
            print(povray)


    # VERTICES
    vertex_indices = set()
    for cell_dict in cell_dicts:
        if cell_dict['type'] == type:
            vertex_indices = vertex_indices.union(set(cell_dict['vertices']))
    vertex_indices = vertex_indices.difference({0})
    vertex_indices_by_count = {
        0: list(set(range(1, 150)).difference(vertex_indices)),
        1: list(vertex_indices)
    }
    for count in range(2):
        length = len(vertex_indices_by_count[count])
        print('###### vertices ' + str(count))
        povray = 'array[{l}]{{'.format(l=length)
        for vertex_index in sorted(vertex_indices_by_count[count]):
            povray += str(vertex_index) + ', '
        povray = povray[:-2] + '},'
        print(povray)
