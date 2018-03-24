from utils.functions import create_hasse_matrix


"""
This script checks if the geometric object created with `old_to_new_points` and `LatticePolytope`
and the Hasse diagram created with `old_to_new_formulas` and `octal_implies` are really equivalent.

`vertex_dicts` is copied from `computed_results/coordinates/5.txt`.
"""


vertex_dicts = [

    { 'abbr': 'a12345',         'octal': '0000-000-00-0', 'point': (0, 0, 0, 0, 0), 'rank': 0 },

    { 'abbr': 'e5 a1234',       'octal': '0004-004-04-4', 'point': (0, 0, 0, 0, 2), 'rank': 1 },
    { 'abbr': 'e4 a1235',       'octal': '0040-040-40-1', 'point': (0, 0, 0, 2, 0), 'rank': 1 },
    { 'abbr': 'e3 a1245',       'octal': '0400-400-11-0', 'point': (0, 0, 2, 0, 0), 'rank': 1 },
    { 'abbr': 'e2 a1345',       'octal': '4000-111-00-0', 'point': (0, 2, 0, 0, 0), 'rank': 1 },
    { 'abbr': 'e1 a2345',       'octal': '1111-000-00-0', 'point': (2, 0, 0, 0, 0), 'rank': 1 },

    # ...

    { 'abbr': 'a1 e2345',       'octal': '6666-777-77-7', 'point': (4, 6, 6, 6, 6), 'rank': 14 },
    { 'abbr': 'a2 e1345',       'octal': '3777-666-77-7', 'point': (6, 4, 6, 6, 6), 'rank': 14 },
    { 'abbr': 'a3 e1245',       'octal': '7377-377-66-7', 'point': (6, 6, 4, 6, 6), 'rank': 14 },
    { 'abbr': 'a4 e1235',       'octal': '7737-737-37-6', 'point': (6, 6, 6, 4, 6), 'rank': 14 },
    { 'abbr': 'a5 e1234',       'octal': '7773-773-73-3', 'point': (6, 6, 6, 6, 4), 'rank': 14 },

    { 'abbr': 'e12345',         'octal': '7777-777-77-7', 'point': (6, 6, 6, 6, 6), 'rank': 15 },

]

# geometry
points = []
for vertex_dict in vertex_dicts:
    points.append(vertex_dict['point'])
polytope = LatticePolytope(points)
edge_objects = polytope.faces()[2]
edge_pairs_from_polytope = []
for edge_object in edge_objects:
    edge_list = []
    for vertex_object in edge_object.faces()[1]:
        point = tuple(vertex_object.points()[0])
        edge_list.append(point)
    edge_pair = tuple(sorted(edge_list))
    edge_pairs_from_polytope.append(edge_pair)
edge_pairs_from_polytope = sorted(edge_pairs_from_polytope)

#logic
octal_strings = []
for vertex_dict in vertex_dicts:
    octal_strings.append(vertex_dict['octal'])
hasse = create_hasse_matrix(octal_strings)
edge_pairs_from_hasse = []
for i in range(len(hasse)):
    point1 = vertex_dicts[i]['point']
    for j in range(len(hasse)):
        if hasse[i, j]:
            point2 = vertex_dicts[j]['point']
            edge_pair = tuple(sorted([point1, point2]))
            edge_pairs_from_hasse.append(edge_pair)
edge_pairs_from_hasse = sorted(edge_pairs_from_hasse)

#compare
if edge_pairs_from_polytope == edge_pairs_from_hasse:
    print('Geometry and logic give the same edges.')



