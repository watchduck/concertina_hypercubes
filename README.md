# Concertina Hypercubes

The graph of a concertina <i>n</i>-cube is the [Hasse diagram](https://en.wikipedia.org/wiki/Hasse_diagram)
of implications between <i>n</i>-place [formulas in predicate logic](https://en.wikiversity.org/wiki/Formulas_in_predicate_logic).

The concertina <i>n</i>-cube is the geometric interpretation of this graph as a truncation of the [<i>n</i>-cube](https://en.wikipedia.org/wiki/Hypercube).<br>
Each of its pairs of opposite vertices corresponds to a hyperface of the [permutohedron](https://en.wikipedia.org/wiki/Permutohedron) of order <i>n</i>.

## Geometry

<table>
  <tr>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_cube_graph.svg">
        <img width="300" src="https://upload.wikimedia.org/wikipedia/commons/8/8c/Concertina_cube_graph.svg"/>
      </a>
    </td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_cube_Hasse_diagram.png">
        <img width="300" src="https://upload.wikimedia.org/wikipedia/commons/4/41/Concertina_cube_Hasse_diagram.png"/>
      </a>
    </td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_cube_with_direction_colors;_ortho_rhomb.png">
        <img width="300" src="https://upload.wikimedia.org/wikipedia/commons/d/d6/Concertina_cube_with_direction_colors%3B_ortho_rhomb.png"/>
      </a>
    </td>
  </tr>
  <tr>
    <td>Hasse diagram of 3-place formulas...</td>
    <td>interpreted as a convex polyhedron</td>
    <td>... called concertina cube</td>
  </tr>
</table>

The red hexagons in the concertina 3-cube are concertina 2-cubes. The blue edges are concertina 1-cubes.

The image gives an idea how the coordinates of a concertina <i>n</i>-cube are constructed from the next smaller one:<br>
The (<i>n</i>−1)-place coordinate tuples of the concertina (<i>n</i>−1)-cube are used to create the lower half of
the <i>n</i>-place tuples of the concertina <i>n</i>-cube by inserting 0s in all <i>n</i> possible places of every tuple.

For <i>n</i>=3 this means that from the 6 points of the concertina square 13 points are created,
which belong to 3 concertina squares between the 3 pairs of axes.

The upper half of the points is created by [point reflections](https://en.wikipedia.org/wiki/Point_reflection)
through the center.<br>
All coordinates of the top vertex are <i>n</i>+1, so all coordinates of the center are (<i>n</i>+1)/2.

### Cocoon concertina hypercube

When variables are allowed to coincide (like in <i>∃x L(x, x)</i> for "Someone loves himself.")
the resulting Hasse diagram becomes rather messy. There seems to be no reasonable interpretation as
a polytope — let alone a convex one. For <i>n</i>>2 the vertices have no ranks. It seems to be possible to
force the inner vertices on the rank levels of the convex polytope
(see ranks [1 / 5](https://commons.wikimedia.org/wiki/File:Cocoon_concertina_cube;_ranks_1_and_5.png),
[2 / 4](https://commons.wikimedia.org/wiki/File:Cocoon_concertina_cube;_ranks_2_and_4.png) and
[3](https://commons.wikimedia.org/wiki/File:Cocoon_concertina_cube;_rank_3.png) for <i>n</i>=3), but this
is a complicated process. There is also no obvious way to find coordinates for these vertices.

<table>
  <tr>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Cocoon_concertina_square_graph;_matrix_sketches.svg">
        <img width="250" src="https://upload.wikimedia.org/wikipedia/commons/4/40/Cocoon_concertina_square_graph%3B_matrix_sketches.svg"/>
      </a>
    </td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Cocoon_concertina_square_graph.svg">
        <img width="250" src="https://upload.wikimedia.org/wikipedia/commons/b/bb/Cocoon_concertina_square_graph.svg"/>
      </a>
    </td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Cocoon_concertina_cube.png">
        <img width="300" src="https://upload.wikimedia.org/wikipedia/commons/1/10/Cocoon_concertina_cube.png"/>
      </a>
    </td>
  <tr>
  <tr>
    <td colspan="2">Cocoon concertina square with 8 vertices and 13 edges</td>
    <td>Cocoon concertina cube<br>with 46 vertices and 139 edges</td>
  </tr>
</table>

## Logic

Note that the abbreviation counts from 1 while the code representation counts from 0.<br>
The formula and its abbreviation read the visualisation vertically.

<table>
  <tr>
    <th>formula</th>
    <th>abbreviation</th>
    <th>visualized</th>
    <th>code representation</th>
  </tr>
  <tr>
    <td>∀y ∃x ∀z P(x, y, z)</td>
    <td>a2 e1 a3</td>
    <td style="text-align: center;">
      <a href="https://commons.wikimedia.org/wiki/File:Predicate_logic;_3_variables;_ordered_partition_a2e1a3.svg">
        <img width="50" src="https://upload.wikimedia.org/wikipedia/commons/3/33/Predicate_logic%3B_3_variables%3B_ordered_partition_a2e1a3.svg"/>
      </a>
    </td>
    <td>
      <code>vert = [False, True, False]</code><br>
      <code>horz = [1, 0, 2]</code>
    </td>
  </tr>
  <tr>
    <td>∀y ∀z ∃x P(x, y, z)</td>
    <td>a23 e1</td>
    <td style="text-align: center;">
      <a href="https://commons.wikimedia.org/wiki/File:Predicate_logic;_3_variables;_ordered_partition_a23e1.svg">
        <img width="50" src="https://upload.wikimedia.org/wikipedia/commons/b/ba/Predicate_logic%3B_3_variables%3B_ordered_partition_a23e1.svg"/>
      </a>
    </td>
    <td>
      <code>vert = [False, True]</code><br>
      <code>horz = [1, 0, 0]</code>
    </td>
  </tr>
  <tr>
    <td>∃x ∃z ∀y P(x, y, z)</td>
    <td>e13 a2</td>
    <td style="text-align: center;">
      <a href="https://commons.wikimedia.org/wiki/File:Predicate_logic;_3_variables;_ordered_partition_e13a2.svg">
        <img width="50" src="https://upload.wikimedia.org/wikipedia/commons/6/67/Predicate_logic%3B_3_variables%3B_ordered_partition_e13a2.svg"/>
      </a>
    </td>
    <td>
      <code>vert = [True, False]</code><br>
      <code>horz = [0, 1, 0]</code>
    </td>
  </tr>
  <tr>
    <td>∃x ∀y P(x, y, x)</td>
    <td>e(13) a2</td>
    <td style="text-align: center;">
      <a href="https://commons.wikimedia.org/wiki/File:Predicate_logic;_3_variables;_ordered_partition_e(13)a2.svg">
        <img width="50" src="https://upload.wikimedia.org/wikipedia/commons/3/3e/Predicate_logic%3B_3_variables%3B_ordered_partition_e%2813%29a2.svg"/>
      </a>
    </td>
    <td>
      <code>vert = [True, False]</code><br>
      <code>horz = [0, 1, 0]</code><br>
      <code>partitions_dict = {0: [[0, 2]]}</code>
    </td>
  </tr>
</table>

The formula in the first row implies that in the second row.<br>
No other formula is between them, so this implication corresponds to an edge in the Hasse diagram.

The formula in the last row has coinciding variables: The first and the last variable in the predicate are the same.<br>
So this vertex is not found in the convex but only in the cocoon concertina cube.

## Integer sequences

This project was created to calculate some integer sequences describing concertina hypercubes.<br>
They are found in the [OEIS](https://en.wikipedia.org/wiki/On-Line_Encyclopedia_of_Integer_Sequences).
Currently there are no formulas, and the calculations take too long for <i>n</i>>6.

### Convex

ID | description | <i>n</i> = 3
--- | --- | ---
[A300700](https://oeis.org/A300700) | triangle of k-faces |26, 42, 18, 1
[A300701](https://oeis.org/A300701) | all hyperfaces <small>(row sums of A300700)</small> | 87
[A000629](https://oeis.org/A000629)<br><small>= 2 * [A000670](https://oeis.org/A000670) for <i>n</i>>0</small> | all vertices <small>(column 0 of A300700, row sums of A300699)</small><br><small>2 * [ordered Bell number](https://en.wikipedia.org/wiki/Ordered_Bell_number)</small> | 26
[A300693](https://oeis.org/A300693) | all edges <small>(column 1 of A300700)</small> | 42
[A300699](https://oeis.org/A300699) | triangle of numbers of vertices by rank | 1, 3, 6, 6, 6, 3, 1
[A300697](https://oeis.org/A300697)<br><small>[A300698](https://oeis.org/A300698)</small> | volumes<br><small>half volumes</small> | 52<br><small>26</small>

### Cocoon

ID | description | <i>n</i> = 3
--- | --- | ---
[A300695](https://oeis.org/A300695) | triangle of numbers of vertices by rank | 1, 6, 13, 6, 13, 6, 1
[A300696](https://oeis.org/A300696)<br><small>= 2 * [A083355](https://oeis.org/A083355) for <i>n</i>>0</small> | all vertices<br><small>2 * number of preferential arrangements</small> | 46
[A300694](https://oeis.org/A300694) | all edges | 139

## Names

These structures seem to be unnamed, so I name the solid for its similarity to a
[concertina](https://en.wikipedia.org/wiki/Concertina), and the variant with substructures for its
similarity to a [cocoon](https://en.wikipedia.org/wiki/Pupa#Cocoon).