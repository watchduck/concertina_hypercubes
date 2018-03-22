from utils.functions import create_set_partitions, covered_vectors, create_hasse_matrix, \
    no_coinciding_variables
from classes.functions_involving_formula_class import old_to_new_points_and_formulas
from classes import Formula

from os import system

"""
This script generates cocoon concertina n-cubes.
It is currently used to find the number of edges and to print the whole Hasse diagram.

It contains the first steps to calculate the ranks in that structure, which is complicated.
It does not really have ranks, because some of the internal edges cross more than one rank layer.
But the vertices on the convex hull have ranks. Given that edges can only be between vertices
on different rank layers (i.e. they can not be horizontal), the possible rank layers for each
internal vertex can be narrowed down, until lower and upper bound are equal.
Currently this works only up to n=3. These are the first rows of the triangle:

    k   0    1    2    3    4    5    6
  n
  0     1
  1     1    1
  2     1    3    3    1
  3     1    6   13    6   13    6    1 
  
The next step would be to make use of substructures in the shape of cocoon concertina m-cubes 
with m < n. Their convex hulls are formed by formulas that have the same partitions in common.
"""


system('mkdir -p computed_results/cocoon/ranks computed_results/cocoon/hasse')

# coordinates, vertical (quantifiers), horizontal (positions)
old_points_and_formulas = [
    ((0,), (False,), (0,)),
    ((2,), (True,), (0,)),
]

for n in range(2, 7):
    print('##################################', n)

    highest_rank = int(1 + (n * (n + 1)) / 2) - 1
    middle_rank = int(highest_rank / 2)

    # FIND ALL FORMULAS, CREATE PSEUDO-OCTAL STRINGS, FIND RANKS OF THOSE WITHOUT COINC. VARIABLES

    octal_strings = []
    abbr_strings = []
    ranks = []

    # formulas without coinciding variables, i.e. vertices of the convex concertina n-cube
    points_and_formulas = old_to_new_points_and_formulas(n, old_points_and_formulas)

    for point, vert, horz in points_and_formulas:

        rows_requiring_partitions = []
        partitions_of_sets = []
        numbers_of_partitions_of_sets = []
        for i in range(len(vert)):
            # The set in question contains the positions of entries in this row.
            positions = [j for j, horzval in enumerate(horz) if horzval == i]
            if len(positions) > 1:
                rows_requiring_partitions.append(i)
                partitions_of_set = create_set_partitions(positions)
                partitions_of_sets.append(partitions_of_set)
                numbers_of_partitions_of_sets.append(len(partitions_of_set))

        # vectors in which each element is the index number of one partition of the set for that row
        combinations_of_partitions_of_sets = covered_vectors(numbers_of_partitions_of_sets)

        # These combinations describe every formula with these `horz` and `vert` values
        # that has any coinciding variables.
        for combination_of_partitions_of_sets in combinations_of_partitions_of_sets:
            partitions_dict = {}
            for i, partition_index in enumerate(combination_of_partitions_of_sets):
                row_index = rows_requiring_partitions[i]
                row_partition = partitions_of_sets[i][partition_index]
                partitions_dict[row_index] = row_partition
            formula = Formula(vert, horz, partitions_dict)
            octal_strings.append(formula.octal())
            abbr_strings.append(formula.abbr())

            if no_coinciding_variables(partitions_dict):
                ranks.append(int(sum(point) / 2))
            else:
                ranks.append(None)

    length = len(octal_strings)

    # CREATE HASSE DIAGRAM MATRIX

    hasse = create_hasse_matrix(octal_strings)
    number_of_edges = hasse.sum()

    f = open('./computed_results/cocoon/hasse/{n}.txt'.format(n=n), 'a')
    f.write('# These are the {e} edges of a cocoon concertina {n}-cube.\n\n\n'.format(
        e=number_of_edges, n=n
    ))
    for i in range(length):
        for j in range(length):
            if hasse[i, j]:
                f.write(abbr_strings[i] + ' --> ' + abbr_strings[j] + '\n')
    f.close()


    ############### START of unfinished rank calculation

    minranks = ranks.copy()
    maxranks = ranks.copy()

    last_ranks = ranks.copy()
    last_minranks = minranks.copy()
    last_maxranks = maxranks.copy()
    while True:

        # find lower bounds
        for row, minrank in enumerate(minranks):
            if minrank is not None:
                for col, val in enumerate(hasse[row, :]):
                    if val:
                        if minranks[col] is None or minranks[col] < minrank + 1:
                            minranks[col] = minrank + 1

        # find upper bounds
        for col, maxrank in enumerate(maxranks):
            if maxrank is not None:
                for row, val in enumerate(hasse[:, col]):
                    if val:
                        if maxranks[row] is None or maxranks[row] > maxrank - 1:
                            maxranks[row] = maxrank - 1

        # check where lower equals upper bound
        for i in range(length):
            if minranks[i] is not None:
                if minranks[i] == maxranks[i]:
                    ranks[i] = minranks[i]

        # check for cases where the middle rank can be excluded
        # because it would lead to horizontal edges
        pairs_to_be_changed = []
        for i in range(length):
            for j in range(length):
                if hasse[i, j]:
                    if maxranks[i] == minranks[j] == middle_rank:
                        pairs_to_be_changed.append((i, j))
        for i, j in pairs_to_be_changed:
            maxranks[i] = middle_rank - 1
            minranks[j] = middle_rank + 1

        # finished?
        if ranks == last_ranks and minranks == last_minranks and maxranks == last_maxranks:
            break
        last_ranks = ranks.copy()
        last_minranks = minranks.copy()
        last_maxranks = maxranks.copy()

    f = open('./computed_results/cocoon/ranks/{n}.txt'.format(n=n), 'a')
    for i in range(length):
        f.write(abbr_strings[i] + ' --- ' + str(minranks[i]) + ' ' + str(maxranks[i]) + ' --- ' + str(ranks[i]) + '\n')
    f.close()

    ############### END of unfinished rank calculation


    # Formulas become the basis of the calculation of new formulas in the next iteration.
    old_points_and_formulas = points_and_formulas
