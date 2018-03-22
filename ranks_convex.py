from os import system

from utils.functions import old_to_new_points


system('mkdir computed_results')

bfile_counter = 3

old_points = [(0,), (2,)]

for dimension in range(2, 7):

    new_points = old_to_new_points(dimension, old_points)

    number_of_ranks = int(1 + (dimension * (dimension + 1)) / 2)
    numbers_of_points_by_rank = number_of_ranks * [0]
    for point in new_points:
        rank_of_this_point = int(sum(point) / 2)
        numbers_of_points_by_rank[rank_of_this_point] += 1

    central_index = int(number_of_ranks / 2)

    f = open('./computed_results/ranks_convex.txt', 'a')
    f.write(str(numbers_of_points_by_rank) + '\n')
    f.close()

    f = open('./computed_results/ranks_convex_central.txt', 'a')
    f.write(str(numbers_of_points_by_rank[central_index]) + '\n')
    f.close()

    for value in numbers_of_points_by_rank:
        f = open('./computed_results/ranks_convex_bfile.txt', 'a')
        f.write(str(bfile_counter) + ' ' + str(value) + '\n')
        f.close()
        bfile_counter += 1

    f = open('./computed_results/ranks_convex_bfile.txt', 'a')
    f.write('\n')
    f.close()

    # Points become the basis of the calculation of new points in the next dimension.
    old_points = new_points
