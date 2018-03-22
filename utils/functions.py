from itertools import product
import numpy as np


# compare `old_to_new_formulas` and `old_to_new_points_and_formulas`
# in `classes/functions_involving_formula_class.py`
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


# https://stackoverflow.com/questions/19368375/set-partitions-in-python
def create_set_partitions(collection):

    def create_all_set_partitions(collection):
        if len(collection) == 1:
            yield [ collection ]
            return

        first = collection[0]
        for smaller in create_all_set_partitions(collection[1:]):
            # insert `first` in each of the subpartition's subsets
            for n, subset in enumerate(smaller):
                yield smaller[:n] + [[ first ] + subset]  + smaller[n+1:]
            # put `first` in its own subset
            yield [ [ first ] ] + smaller

    all_set_partitions = [sorted(p) for p in create_all_set_partitions(collection)]

    return all_set_partitions


def covered_vectors(vector):
    """Takes a vector of positive integers.
    Returns all vectors of non-negative integers that are element-wise smaller."""
    range_vector = []
    for i in range(len(vector)):
        range_vector.append(range(vector[i]))
    return [v for v in product(*range_vector)]


def octal_implies(v1, v2):
    """`v1` and `v2` are pseudo-octal strings."""
    def digit_implies(d1, d2):
        if d1 == d2 == '-':  # just the prettifier
            return True
        d1 = int(d1)
        d2 = int(d2)
        if (d1 & d2 == d1) or (d1 == 2 and d2 == 5):  # bitwise smaller or central arrow
            return True
        else:
            return False

    result = True
    for i in range(len(v1)):
        if not digit_implies(v1[i], v2[i]):
            result = False

    return result


def create_hasse_matrix(list_of_nodes):
    # uses `octal_implies()`

    n = len(list_of_nodes)
    old = np.zeros([n, n], dtype=bool)
    for i, a in enumerate(list_of_nodes):
        for j, b in enumerate(list_of_nodes):
            if octal_implies(a, b):
                old[i, j] = True

    for i in range(n):
        old[i, i] = False

    new = old.copy()
    last_sum = sum(sum(new))
    while True:
        for i in range(n):
            for j in range(n):
                # An arrow (i, j) is redundant if there are shorter arrows (i, k) and (k, j).
                # Check for shorter arrows in `old`, remove redundant longer arrows in `new`.
                if new[i, j]:
                    for k in range(n):
                        if old[i, k] and old[k, j]:
                            new[i, j] = False
        current_sum = sum(sum(new))
        if current_sum == last_sum:
            break
        last_sum = current_sum

    return new


def pair_in_partitions_dict(pair, partitions_dict):
    pairset = set(pair)
    for partition in partitions_dict.values():
        for block in partition:
            blockset = set(block)
            if pairset.issubset(blockset):
                return True
    return False


def no_coinciding_variables(partitions_dict):
    if len(partitions_dict) == 0:
        return True
    for partition in partitions_dict.values():
        for block in partition:
            if len(block) > 1:
                return False
    return True


####################################

def project_4d(point, dist):
    (x, y, z, w) = point
    denom = w * (dist - 1)
    a = x * dist * w / denom
    b = y * dist * w / denom
    c = z * dist * w / denom
    return(a, b, c)


def binary_vector_to_str(l):
    # gives '01' for inputs [False, True], [0, 1], (False, True) and (0, 1)
    return ''.join([str(int(bool(e))) for e in l])  # the ``bool()`` is for sympy.logic.boolalg.BooleanFalse and ...True


def reverse_binary_vector_to_number(l):
    binstr = binary_vector_to_str(l)[::-1]
    return int(binstr, 2)


def number_to_reverse_binary_string(n, length):
    return "{0:b}".format(n).zfill(length)[::-1]


def binary_str_to_list(s):
    # gives [False, True] for input '01'
    return [bool(int(d)) for d in s]


def number_to_reverse_binary_list(n, length):
    return binary_str_to_list(number_to_reverse_binary_string(n, length))


def hypercube_edges(dimension):
    edges = []
    for edge_direction in range(dimension):
        for edge_position in range(2**(dimension-1)):
            edge_position_binary = number_to_reverse_binary_list(edge_position, dimension-1)
            first_half = edge_position_binary[:edge_direction]
            second_half = edge_position_binary[edge_direction:]
            bottom_vertex = reverse_binary_vector_to_number( first_half + [0] + second_half )
            top_vertex = reverse_binary_vector_to_number( first_half + [1] + second_half )
            edges.append([bottom_vertex, top_vertex])
    return edges


tesseract_vertices = [(-1, -1, -1, -1), (-1, -1, -1, 1), (-1, -1, 1, -1), (-1, -1, 1, 1), (-1, 1, -1, -1), (-1, 1, -1, 1), (-1, 1, 1, -1), (-1, 1, 1, 1), (1, -1, -1, -1), (1, -1, -1, 1), (1, -1, 1, -1), (1, -1, 1, 1), (1, 1, -1, -1), (1, 1, -1, 1), (1, 1, 1, -1), (1, 1, 1, 1)]
tesseract_edges = [[0, 1], [2, 3], [4, 5], [6, 7], [8, 9], [10, 11], [12, 13], [14, 15], [0, 2], [1, 3], [4, 6], [5, 7], [8, 10], [9, 11], [12, 14], [13, 15], [0, 4], [1, 5], [2, 6], [3, 7], [8, 12], [9, 13], [10, 14], [11, 15], [0, 8], [1, 9], [2, 10], [3, 11], [4, 12], [5, 13], [6, 14], [7, 15]]
