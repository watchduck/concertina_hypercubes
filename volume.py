from utils.functions import old_to_new_points
from scipy.spatial import ConvexHull
from os import system

system('mkdir computed_results')

old_points = [(0,), (2,)]

for dimension in range(2, 7):

    new_points = old_to_new_points(dimension, old_points)

    hull = ConvexHull(new_points)
    volume = hull.volume

    # The computed results differ very slightly from integers (e.g. 52.00000000000001).
    # That is why the round function was added.
    f = open('./computed_results/volume.txt', 'a')
    f.write(str(round(volume)) + '\n')
    f.close()

    # Points become the basis of the calculation of new points in the next dimension.
    old_points = new_points
