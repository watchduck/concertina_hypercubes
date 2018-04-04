from functions import pairs_to_sequences
from variables import vertices


polytope = LatticePolytope(vertices)

edge_pairs = []
edge_objects = polytope.faces()[2]
for edge_object in edge_objects:
    point_objects = edge_object.points()
    index1 = vertices.index(tuple(point_objects[0]))
    index2 = vertices.index(tuple(point_objects[1]))
    edge_pairs.append(sorted([index1, index2]))

print(edge_pairs)
