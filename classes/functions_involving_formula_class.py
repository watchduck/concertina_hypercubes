from .formula import Formula


def old_to_new_formulas(n, old_formulas):

    new_lower_formulas = set()
    for old_vert, old_horz in old_formulas:
        for i in range(n):
            old_formula = Formula(old_vert, old_horz)
            new_formula = old_formula.insert(i)
            new_vert = new_formula.vert
            new_horz = new_formula.horz
            new_lower_formulas.add((
                tuple(new_vert), tuple(new_horz)
            ))
    new_lower_formulas = list(new_lower_formulas)

    new_upper_formulas = []
    for lower_vert, lower_horz in new_lower_formulas:
        lower_formula = Formula(lower_vert, lower_horz)
        upper_formula = lower_formula.complement()
        upper_vert = upper_formula.vert
        upper_horz = upper_formula.horz

        new_upper_formulas.append((
            tuple(upper_vert), tuple(upper_horz)
        ))

    return new_lower_formulas + new_upper_formulas


def old_to_new_points_and_formulas(n, old_vertices):

    top_point_coordinates = n * [(n+1)]  # e.g. [4, 4, 4] for dimension 3

    new_lower_vertices = set()
    for old_point, old_vert, old_horz in old_vertices:
        for i in range(n):

            new_point = list(old_point)
            new_point.insert(i, 0)

            old_formula = Formula(old_vert, old_horz)
            new_formula = old_formula.insert(i)
            new_vert = new_formula.vert
            new_horz = new_formula.horz

            new_lower_vertices.add((
                tuple(new_point), tuple(new_vert), tuple(new_horz)
            ))
    new_lower_vertices = list(new_lower_vertices)

    new_upper_vertices = []
    for lower_point, lower_vert, lower_horz in new_lower_vertices:
        upper_point = [t - p for t, p in zip(top_point_coordinates, lower_point)]

        lower_formula = Formula(lower_vert, lower_horz)
        upper_formula = lower_formula.complement()
        upper_vert = upper_formula.vert
        upper_horz = upper_formula.horz

        new_upper_vertices.append((
            tuple(upper_point), tuple(upper_vert), tuple(upper_horz)
        ))

    return new_lower_vertices + new_upper_vertices