from functions import pairs_to_sequences
from variables import vertices

import numpy as np


polytope = LatticePolytope(vertices)

edge_pairs = []
edge_lengths = []
edge_objects = polytope.faces()[2]
for edge_object in edge_objects:
    point_objects = edge_object.points()
    point1 = tuple(point_objects[0])
    point2 = tuple(point_objects[1])
    index1 = vertices.index(point1)
    index2 = vertices.index(point2)
    edge_pairs.append(sorted([index1, index2]))

    length = np.linalg.norm(np.array(point1)-np.array(point2))
    if length == np.sqrt(2):
        edge_lengths.append(0)
    elif length == 2:
        edge_lengths.append(1)

print(edge_pairs)
print(edge_lengths)
