def old_to_new_points(n, old_points):

    top_vertex = n * [(n+1)]  # e.g. [4, 4, 4] for dimension 3

    new_lower_points = set()
    for old in old_points:
        for i in range(n):
            new = list(old)
            new.insert(i, 0)
            new_lower_points.add(tuple(new))
    new_lower_points = list(new_lower_points)

    new_upper_points = []
    for lower in new_lower_points:
        new_upper_points.append(
            tuple([t - p for (t, p) in zip(top_vertex, lower)])
        )

    return new_lower_points + new_upper_points


old_points = [(0,), (2,)]

for n in range(2, 7):

    new_points = old_to_new_points(n, old_points)

    # A lattice polytope is a polytope whose vertices all have integer coordinates.
    polytope = LatticePolytope(new_points)

    numbers_of_faces = []  # n-faces with n from 0 to `dimension`
    for i in range(1, n + 2):
        numbers_of_faces.append(len(
            polytope.faces()[i]
        ))

    f = open('./computed_results/nfaces.txt', 'a')
    f.write(str(numbers_of_faces) + '\n')
    f.close()

    # Points become the basis of the calculation of new points in the next dimension.
    old_points = new_points