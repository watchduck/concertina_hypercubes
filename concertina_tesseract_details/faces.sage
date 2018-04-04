from functions import pairs_to_sequences
from variables import vertices


polytope = LatticePolytope(vertices)

sequences_of_vertex_indices = []

face_objects = polytope.faces()[3]
for face_object in face_objects:
    edge_objects = face_object.faces()[2]
    edge_pairs = []
    for edge_object in edge_objects:
        points = edge_object.faces()[1]
        edge_pair = (
            tuple(points[0].points()[0]),
            tuple(points[1].points()[0])
        )
        edge_pairs.append(edge_pair)
    sequence_of_vertices = pairs_to_sequences(edge_pairs)[0]
    sequence_of_vertex_indices = []
    for vertex in sequence_of_vertices:
        vertex_index = vertices.index(vertex)
        sequence_of_vertex_indices.append(vertex_index)
    sequences_of_vertex_indices.append(sequence_of_vertex_indices)
print(sequences_of_vertex_indices)

povray = ''
for sequence in sequences_of_vertex_indices:
    string = "array[{n}]{{".format(n=len(sequence))
    for el in sequence:
        string += str(el) + ', '
    string = string[:-2] + '}, '
    povray += string
# print(povray)

