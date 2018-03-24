from utils.functions import old_to_new_points


old_points = [(0,), (2,)]

for n in range(2, 7):

    points = old_to_new_points(n, old_points)

    # A lattice polytope is a polytope whose vertices all have integer coordinates.
    polytope = LatticePolytope(points)

    numbers_of_faces = []  # n-faces with n from 0 to `dimension`
    for i in range(1, n + 2):
        numbers_of_faces.append(len(
            polytope.faces()[i]
        ))

    f = open('./computed_results/faces.txt', 'a')
    f.write(str(numbers_of_faces) + '\n')
    f.close()

    # Points become the basis of the calculation of new points in the next dimension.
    old_points = points