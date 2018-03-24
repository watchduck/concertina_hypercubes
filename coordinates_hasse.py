from classes import Formula
from classes.functions_involving_formula_class import old_to_new_points_and_formulas
from utils.functions import create_hasse_matrix

from os import system


system('mkdir -p computed_results/coordinates computed_results/hasse')

# coordinates, vertical (quantifiers), horizontal (positions)
old_vertices = [
    ((0,), (False,), (0,)),
    ((2,), (True,), (0,)),
]

for n in range(2, 7):

    vertices = old_to_new_points_and_formulas(n, old_vertices)
    length = len(vertices)

    points_by_rank = {}
    indices_by_rank = {}
    number_of_ranks = int(1 + (n * (n + 1)) / 2)
    for i in range(number_of_ranks):
        points_by_rank[i] = []
        indices_by_rank[i] = []

    octal_strings = []
    abbr_strings = []
    longest_abbr = 0
    for i in range(length):
        point, vert, horz = vertices[i]
        rank = sum(point)/2
        formula = Formula(vert, horz)

        abbr = formula.abbr()
        abbr_strings.append(abbr)
        octal_strings.append(formula.octal())

        if len(abbr) > longest_abbr:
            longest_abbr = len(abbr)

        points_by_rank[rank].append(point)
        indices_by_rank[rank].append(i)

    # vertices

    f = open('./computed_results/coordinates/{n}.txt'.format(n=n), 'a')
    f.write('# These are the {l} vertices of a concertina {n}-cube represented as\n'
            '# abbreviations of the formulas, pseudo-octal strings and coordinates.\n'
            '# They are ordered by rank, and within that by coordinates.\n\n\n'.format(l=length, n=n))
    for rank in range(number_of_ranks):
        points = points_by_rank[rank]
        indices = indices_by_rank[rank]
        points, indices = zip(*sorted(zip(points, indices)))
        for point, i in zip(points, indices):
            abbr = abbr_strings[i]
            fill = (longest_abbr - len(abbr)) * ' '
            octal = octal_strings[i]
            f.write("{{ 'abbr'='{a}',{f} 'octal'='{o}', 'point'={p}, 'rank'={r} }},\n".format(
                a=abbr, f=fill, o=octal, p=point, r=rank
            ))
        f.write('\n')
    f.close()

    # edges
    
    hasse = create_hasse_matrix(octal_strings)
    number_of_edges = hasse.sum()

    f = open('./computed_results/hasse/{n}.txt'.format(n=n), 'a')
    f.write('# These are the {e} edges of a concertina {n}-cube.\n\n\n'.format(
        e=number_of_edges, n=n
    ))
    for i in range(length):
        for j in range(length):
            if hasse[i, j]:
                f.write(abbr_strings[i] + ' --> ' + abbr_strings[j] + '\n')
    f.close()

    # Points become the basis of the calculation of new points in the next dimension.
    old_vertices = vertices
