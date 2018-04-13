import numpy as np


def pairs_to_sequences(pairs_arg):
    """
    This function takes pairs of objects that are neighbours,
    and returns a list of lists of objects that form a chain of neighbours.

    pairs_to_sequences([(1, 2), (2, 3), (3, 4), (4, 5), (5, 6)])   gives   [[1, 2, 3, 4, 5, 6]]
    pairs_to_sequences([(1, 2), (2, 3), (4, 5), (5, 6)])           gives   [[4, 5, 6], [1, 2, 3]]

    Whether or not the sequence described by the pairs forms a circle is not visible in the result:
    pairs_to_sequences([(1, 2), (2, 3)])           gives   [[1, 2, 3]]
    pairs_to_sequences([(1, 2), (2, 3), (1, 3)])   gives   [[2, 1, 3]]
    """

    pairs = []
    for pair in pairs_arg:
        pairs.append(list(pair))

    sequences = []

    while pairs:

        if not sequences:

            random_pair = pairs.pop()
            sequences.append(random_pair)

        else:

            used_pair = None
            for sequence in sequences:
                first = sequence[0]
                last = sequence[-1]
                for [i, j] in pairs:
                    if first in [i, j] or last in [i, j]:
                        used_pair = [i, j]
                        if i == last:
                            sequence.append(j)
                            break
                        elif j == last:
                            sequence.append(i)
                            break
                        elif i == first:
                            sequence.insert(0, j)  # prepend
                            break
                        elif j == first:
                            sequence.insert(0, i)  # prepend
                            break

            if used_pair:
                pairs.remove(used_pair)
            else:
                random_pair = pairs.pop()
                sequences.append(random_pair)

    for s in sequences:
        if s[-1] == s[0]:
            s.pop()

    return sequences


# POLYGON ANGLES
# https://stackoverflow.com/questions/2827393/angles-between-two-n-dimensional-vectors-in-python/13849249#13849249

def unit_vector(vector):
    """ Returns the unit vector of the vector.  """
    return vector / np.linalg.norm(vector)


def angle_between(v1, v2):
    """ Returns the angle in radians between vectors 'v1' and 'v2'"""
    v1_u = unit_vector(v1)
    v2_u = unit_vector(v2)
    return np.arccos(np.clip(np.dot(v1_u, v2_u), -1.0, 1.0))


def representative_circular_list(a):
    length = len(a)
    aa = a[:] + a[:]
    versions = []
    for i in range(length):
        version = aa[i:i+length]
        versions.append(version)
    return sorted(versions)[0]


angles_rad_to_deg = {
    0.7853981633974484: 45,
    1.0471975511965979: 60,
    1.5707963267948966: 90,
    2.0943951023931953: 120
}
lengths_val_to_key = {
    1.4142135623730951: 0,
    2.0: 1
}

def polygon_shape(points_input):
    n = len(points_input)
    points = points_input[:] + points_input[0:2]
    angles = []
    lengths = []
    for i in range(n):
        a, b, c = [np.array(points[j]) for j in range(i, i+3)]
        v = a - b
        w = b - c
        angle = angle_between(v, w)
        angle = angles_rad_to_deg[angle]
        angles.append(angle)
        length = np.linalg.norm(v)
        length = lengths_val_to_key[length]
        lengths.append(length)

    angles = tuple(representative_circular_list(angles))
    lengths = tuple(sorted(lengths))
    return angles, lengths


# PROJECTION FROM 4D TO 3D
# inspired by http://blog.hypercubed.com/wp-content/misc/hypercube.pov

def norm(v):
    u = []
    vnorm = np.linalg.norm(v)
    for e in v:
        u.append(e/vnorm)
    return u


def cross(u, v, w):
    # calculate intermediate values
    a = (v[0] * w[1]) - (v[1] * w[0])
    b = (v[0] * w[2]) - (v[2] * w[0])
    c = (v[0] * w[3]) - (v[3] * w[0])
    d = (v[1] * w[2]) - (v[2] * w[1])
    e = (v[1] * w[3]) - (v[3] * w[1])
    f = (v[2] * w[3]) - (v[3] * w[2])
    # calculate the result-vector components
    x = ((u[1] * f) - (u[2] * e) + (u[3] * d))
    y = ((u[0] * f) + (u[2] * c) - (u[3] * b))
    z = ((u[0] * e) - (u[1] * c) + (u[3] * a))
    t = (-(u[0] * d) + (u[1] * b) - (u[2] * a))
    return x, y, z, t


tp = 2

point_to = np.array([0, 0, 0, 0])  # to
point_up = np.array([0, -1, 0, 0])  # up
point_ov = np.array([0, 0, -1, 0])  # over


def project_from_4d_to_3d(point_preimage, point_fr):
    d = norm(point_to - point_fr)
    a = norm(cross(point_up, point_ov, d))
    b = norm(cross(point_ov, d, a))
    c = cross(d, a, b)
    tm = np.vstack([a, b, c, d])

    v = np.dot(tm, point_preimage - point_fr)
    r = v[3] * tp
    return np.array([v[0]/r, v[1]/r, v[2]/r])
