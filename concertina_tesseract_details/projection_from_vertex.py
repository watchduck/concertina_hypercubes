from functions import project_from_4d_to_3d

import numpy as np


point_fr = np.array([-1, -1, -1, -1])  # from

vertices = [[-1, -1, -1, -1/5], [-1, -1, -3/5, 1/5], [-1, -1, -1/5, -1], [-1, -1, 1/5, -3/5], [-1, -1, 1/5, 1/5], [-1, -3/5, -1, 1/5], [-1, -3/5, -3/5, 3/5], [-1, -3/5, 1/5, -1], [-1, -3/5, 1/5, 3/5], [-1, -3/5, 3/5, -3/5], [-1, -3/5, 3/5, 1/5], [-1, -1/5, -1, -1], [-1, -1/5, 3/5, 3/5], [-1, 1/5, -1, -3/5], [-1, 1/5, -1, 1/5], [-1, 1/5, -3/5, -1], [-1, 1/5, -3/5, 3/5], [-1, 1/5, 1/5, -1], [-1, 1/5, 3/5, -3/5], [-1, 3/5, -3/5, -3/5], [-1, 3/5, -3/5, 1/5], [-1, 3/5, -1/5, 3/5], [-1, 3/5, 1/5, -3/5], [-1, 3/5, 3/5, -1/5], [-1, 3/5, 3/5, 3/5], [-3/5, -1, -1, 1/5], [-3/5, -1, -3/5, 3/5], [-3/5, -1, 1/5, -1], [-3/5, -1, 1/5, 3/5], [-3/5, -1, 3/5, -3/5], [-3/5, -1, 3/5, 1/5], [-3/5, -3/5, -1, 3/5], [-3/5, -3/5, -3/5, 1], [-3/5, -3/5, 1/5, 1], [-3/5, -3/5, 3/5, -1], [-3/5, -3/5, 1, -3/5], [-3/5, -3/5, 1, 1/5], [-3/5, -1/5, 3/5, 1], [-3/5, -1/5, 1, 3/5], [-3/5, 1/5, -1, -1], [-3/5, 1/5, -1, 3/5], [-3/5, 1/5, -3/5, 1], [-3/5, 1/5, 3/5, -1], [-3/5, 1/5, 1, -3/5], [-3/5, 3/5, -1, -3/5], [-3/5, 3/5, -1, 1/5], [-3/5, 3/5, -3/5, -1], [-3/5, 3/5, -1/5, 1], [-3/5, 3/5, 1/5, -1], [-3/5, 3/5, 3/5, 1], [-3/5, 3/5, 1, -1/5], [-3/5, 3/5, 1, 3/5], [-3/5, 1, -3/5, -3/5], [-3/5, 1, -3/5, 1/5], [-3/5, 1, -1/5, 3/5], [-3/5, 1, 1/5, -3/5], [-3/5, 1, 3/5, -1/5], [-3/5, 1, 3/5, 3/5], [-1/5, -1, -1, -1], [-1/5, -1, 3/5, 3/5], [-1/5, -3/5, 3/5, 1], [-1/5, -3/5, 1, 3/5], [-1/5, -1/5, 1, 1], [-1/5, 3/5, -1, 3/5], [-1/5, 3/5, -3/5, 1], [-1/5, 3/5, 3/5, -1], [-1/5, 3/5, 1, -3/5], [-1/5, 3/5, 1, 1], [-1/5, 1, -3/5, 3/5], [-1/5, 1, -1/5, 1], [-1/5, 1, 3/5, -3/5], [-1/5, 1, 3/5, 1], [-1/5, 1, 1, -1/5], [-1/5, 1, 1, 3/5], [1/5, -1, -1, -3/5], [1/5, -1, -1, 1/5], [1/5, -1, -3/5, -1], [1/5, -1, -3/5, 3/5], [1/5, -1, 1/5, -1], [1/5, -1, 3/5, -3/5], [1/5, -3/5, -1, -1], [1/5, -3/5, -1, 3/5], [1/5, -3/5, -3/5, 1], [1/5, -3/5, 3/5, -1], [1/5, -3/5, 1, -3/5], [1/5, 1/5, -1, -1], [1/5, 3/5, -1, -3/5], [1/5, 3/5, -3/5, -1], [1/5, 1, -3/5, -3/5], [1/5, 1, 1, 1], [3/5, -1, -3/5, -3/5], [3/5, -1, -3/5, 1/5], [3/5, -1, -1/5, 3/5], [3/5, -1, 1/5, -3/5], [3/5, -1, 3/5, -1/5], [3/5, -1, 3/5, 3/5], [3/5, -3/5, -1, -3/5], [3/5, -3/5, -1, 1/5], [3/5, -3/5, -3/5, -1], [3/5, -3/5, -1/5, 1], [3/5, -3/5, 1/5, -1], [3/5, -3/5, 3/5, 1], [3/5, -3/5, 1, -1/5], [3/5, -3/5, 1, 3/5], [3/5, -1/5, -1, 3/5], [3/5, -1/5, -3/5, 1], [3/5, -1/5, 3/5, -1], [3/5, -1/5, 1, -3/5], [3/5, -1/5, 1, 1], [3/5, 1/5, -1, -3/5], [3/5, 1/5, -3/5, -1], [3/5, 3/5, -1, -1/5], [3/5, 3/5, -1, 3/5], [3/5, 3/5, -3/5, 1], [3/5, 3/5, -1/5, -1], [3/5, 3/5, 3/5, -1], [3/5, 3/5, 1, -3/5], [3/5, 1, -3/5, -1/5], [3/5, 1, -3/5, 3/5], [3/5, 1, -1/5, -3/5], [3/5, 1, -1/5, 1], [3/5, 1, 3/5, -3/5], [3/5, 1, 1, -1/5], [1, -3/5, -3/5, -3/5], [1, -3/5, -3/5, 1/5], [1, -3/5, -1/5, 3/5], [1, -3/5, 1/5, -3/5], [1, -3/5, 3/5, -1/5], [1, -3/5, 3/5, 3/5], [1, -1/5, -3/5, 3/5], [1, -1/5, -1/5, 1], [1, -1/5, 3/5, -3/5], [1, -1/5, 3/5, 1], [1, -1/5, 1, -1/5], [1, -1/5, 1, 3/5], [1, 1/5, -3/5, -3/5], [1, 1/5, 1, 1], [1, 3/5, -3/5, -1/5], [1, 3/5, -3/5, 3/5], [1, 3/5, -1/5, -3/5], [1, 3/5, -1/5, 1], [1, 3/5, 3/5, -3/5], [1, 3/5, 1, -1/5], [1, 1, -1/5, -1/5], [1, 1, -1/5, 3/5], [1, 1, 1/5, 1], [1, 1, 3/5, -1/5], [1, 1, 1, 1/5], [1, 1, 1, 1]]
projected_vertices = []
vertex_distances = []
for vertex in vertices:
    projected_vertices.append(
        project_from_4d_to_3d(vertex, point_fr)
    )
    vertex_distances.append(
        np.linalg.norm(vertex - point_fr)
    )

povray_vertex_strings = ''
for vertex in projected_vertices:
    povray_point = ''
    for c in vertex:
        povray_point += str(c) + ', '
    povray_point = povray_point[:-2]
    povray_vertex_strings += '<{p}>, '.format(p=povray_point)

print(povray_vertex_strings)