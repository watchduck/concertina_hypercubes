# Concertina Hypercubes

The graph of a concertina <i>n</i>-cube is the [Hasse diagram](https://en.wikipedia.org/wiki/Hasse_diagram)
of implications between <i>n</i>-place [formulas in predicate logic](https://en.wikiversity.org/wiki/Formulas_in_predicate_logic).

The concertina <i>n</i>-cube is the geometric interpretation of this graph as a truncation of the [<i>n</i>-cube](https://en.wikipedia.org/wiki/Hypercube).<br>
Each of its pairs of opposite vertices corresponds to a hyperface of the [permutohedron](https://en.wikipedia.org/wiki/Permutohedron) of order <i>n</i>.

The cocoon concertina hypercube is a version with additional internal vertices and edges.

## Names

These structures seemed to be unnamed, so I named the solid for its similarity to a
[concertina](https://en.wikipedia.org/wiki/Concertina), and the variant with substructures for its
similarity to a [cocoon](https://en.wikipedia.org/wiki/Pupa#Cocoon). For the sake of brevity
the convex concertina <i>n</i>-cube is also called <b><i>n</i>-concertina</b>
and the cocoon concertina <i>n</i>-cube is called <b><i>n</i>-cocoon</b>.

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

The red hexagons in the 3-concertina are 2-concertinas. The blue edges are 1-concertinas.

The image gives an idea how the coordinates of an <i>n</i>-concertina are constructed from the next smaller one:<br>
The (<i>n</i>−1)-place coordinate tuples of the (<i>n</i>−1)-concertina are used to create the lower half of
the <i>n</i>-place tuples of the <i>n</i>-concertina by inserting 0s in all <i>n</i> possible places of every tuple.

For <i>n</i>&nbsp;=&nbsp;3 this means that from the 6 points of the concertina square 13 points are created,<br>
which belong to 3 concertina squares between the 3 pairs of axes.

The upper half of the points is created by [point reflection](https://en.wikipedia.org/wiki/Point_reflection)
through the center.<br>
(All coordinates of the top vertex are <i>n</i>+1, so all coordinates of the center are (<i>n</i>+1)/2.)

This inductive calculation of the coordinates is realized in [`old_to_new_points`](https://github.com/watchduck/concertina_hypercubes/blob/master/utils/functions.py).<br>
A similar calculation of the formulas is realized in [`old_to_new_formulas`](https://github.com/watchduck/concertina_hypercubes/blob/master/classes/functions_involving_formula_class.py).

The coordinates, abbreviated formulas and pseudo-octal strings for <i>n</i>&nbsp;=&nbsp;2..6 can be found here:
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/coordinates/2.txt">2</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/coordinates/3.txt">3</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/coordinates/4.txt">4</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/coordinates/5.txt">5</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/coordinates/6.txt">6</a><br>
The edges of <i>n</i>-concertinas for <i>n</i>&nbsp;=&nbsp;2..5 can be found here:
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/hasse/2.txt">2</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/hasse/3.txt">3</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/hasse/4.txt">4</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/hasse/5.txt">5</a>

### Cocoon concertina hypercube

When variables are allowed to coincide (like in <i>∃x L(x, x)</i> for "Someone loves himself.")
the resulting Hasse diagram becomes rather messy. There seems to be no reasonable interpretation as
a polytope — let alone a convex one.

For <i>n</i>&nbsp;&ge;&nbsp;3 this poset is not [graded](https://en.wikipedia.org/wiki/Graded_poset).
But it seems to be possible to force each inner vertex on a rank level of the convex polytope
(see ranks [1&nbsp;/&nbsp;5](https://commons.wikimedia.org/wiki/File:Cocoon_concertina_cube;_ranks_1_and_5.png),
[2&nbsp;/&nbsp;4](https://commons.wikimedia.org/wiki/File:Cocoon_concertina_cube;_ranks_2_and_4.png) and
[3](https://commons.wikimedia.org/wiki/File:Cocoon_concertina_cube;_rank_3.png) for <i>n</i>&nbsp;=&nbsp;3).
The reason is that there are many substructures with (real or assigned) ranks.
Among them are smaller cocoons
(like [this 2- in a 3-cocoon](https://commons.wikimedia.org/wiki/File:Cocoon_concertina_cube;_diag_yz.png))
and Hasse diagrams of set partitions
(like [this one for a 4-set](https://commons.wikimedia.org/wiki/File:Set_partitions_4;_Hasse;_circles.svg)).
One for a 3-set with [Bell](https://en.wikipedia.org/wiki/Bell_number)(3)&nbsp;=&nbsp;5 vertices can be seen
in the 3-cocoon between the origin and the lower orange vertex.

There is no obvious way to find coordinates for the inner vertices.

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

The similarity of the 2-cocoon with the cube (just one edge more) is rather misleading.<br>
But labeling its vertices from 0 to 7
[like those of a cube](https://commons.wikimedia.org/wiki/File:Cube_diagram;_octal_numbers.svg)
is handy in the pseudo-octal representation of longer formulas.

The edges of <i>n</i>-cocoons for <i>n</i>&nbsp;=&nbsp;2..5 can be found here:
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/cocoon/hasse/2.txt">2</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/cocoon/hasse/3.txt">3</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/cocoon/hasse/4.txt">4</a>,
<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/cocoon/hasse/5.txt">5</a>

## Logic

Note that the abbreviation counts from 1 while the code representation counts from 0.<br>
The formula and its abbreviation read the visualisation vertically.

<table>
  <tr>
    <th>formula</th>
    <th>abbr.</th>
    <th>oct.</th>
    <th>vis.</th>
    <th>code representation</th>
  </tr>
  <tr>
    <td>∀y ∃x<br>P(x, y)</td>
    <td>a2 e1</td>
    <td>3</td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Predicate_logic;_2_variables;_ordered_partition_a2e1.svg">
        <img width="37" src="https://upload.wikimedia.org/wikipedia/commons/1/18/Predicate_logic%3B_2_variables%3B_ordered_partition_a2e1.svg"/>
      </a>
    </td>
    <td>
      <code>vert = [False, True]</code><br>
      <code>horz = [1, 0]</code>
    </td>
  </tr>
  <tr>
    <td>∃x<br>P(x, x)</td>
    <td>e(12)</td>
    <td>5</td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Predicate_logic;_2_variables;_ordered_partition_e(12).svg">
        <img width="37" src="https://upload.wikimedia.org/wikipedia/commons/e/e9/Predicate_logic%3B_2_variables%3B_ordered_partition_e%2812%29.svg"/>
      </a>
    </td>
    <td>
      <code>vert = [True]</code><br>
      <code>horz = [0, 0]</code><br>
      <code>partitions_dict = {0: [[0, 1]]}</code>
    </td>
  </tr>
  <tr>
    <td>∀y ∃x ∀z<br>P(x, y, z)</td>
    <td>a2 e1 a3</td>
    <td>31-0</td>
    <td>
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
    <td>∀y ∀z ∃x<br>P(x, y, z)</td>
    <td>a23 e1</td>
    <td>33-0</td>
    <td>
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
    <td>∃x ∃z ∀y<br>P(x, y, z)</td>
    <td>e13 a2</td>
    <td>17-4</td>
    <td>
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
    <td>∃x ∀y<br>P(x, y, x)</td>
    <td>e(13) a2</td>
    <td>15-4</td>
    <td>
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

  <tr>
    <td>∀y ∃x ∀z ∃w<br>P(w, x, y, z)</td>
    <td>a3 e2 a4 e1</td>
    <td>733-31-0</td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Predicate_logic;_4_variables;_ordered_partition_a3e2a4e1.svg">
        <img width="62" src="https://upload.wikimedia.org/wikipedia/commons/6/62/Predicate_logic%3B_4_variables%3B_ordered_partition_a3e2a4e1.svg"/>
      </a>
    </td>
    <td>
      <code>vert = [False, True, False, True]</code><br>
      <code>horz = [3, 1, 0, 2]</code><br>
    </td>
  </tr>

  <tr>
    <td>∃z ∀x ∀y<br>P(x, y, z, x)</td>
    <td>e3 a(14)2</td>
    <td>042-40-1</td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Predicate_logic;_4_variables;_ordered_partition_e3a(14)2.svg">
        <img width="62" src="https://upload.wikimedia.org/wikipedia/commons/5/54/Predicate_logic%3B_4_variables%3B_ordered_partition_e3a%2814%292.svg"/>
      </a>
    </td>
    <td>
      <code>vert = [True, False]</code><br>
      <code>horz = [1, 1, 0, 1]</code><br>
      <code>partitions_dict = {1: [[0, 3], [1]]}</code>
    </td>
  </tr>

</table>

Formulas with parentheses in the abbreviations (and white dots in the visualisations) have coinciding variables,<br>
so they are not found in the convex but only in the cocoon concertina hypercubes.

The formula <i>a2 e1 a3</i> implies <i>a23 e1</i>. The octal strings make this easy to see: <i>31-0</i> is bitwise&nbsp;&le; <i>33-0</i>.<br>
As there are no formulas between them
[`a2 e1 a3 --> a23 e1`](https://github.com/watchduck/concertina_hypercubes/blob/master/computed_results/hasse/3.txt)
is an edge of the concertina cube.

The implication is realized in
[`octal_implies`](https://github.com/watchduck/concertina_hypercubes/blob/master/utils/functions.py).
It checks if corresponding digits of two pseudo-octal strings are bitwise&nbsp;&le; or if they are 2&nbsp;and&nbsp;5 (the one edge of the 2-cocoon that is not in the cube).

## Integer sequences

This project was created to calculate some integer sequences describing concertina hypercubes.<br>
They are found in the [OEIS](https://en.wikipedia.org/wiki/On-Line_Encyclopedia_of_Integer_Sequences).
Currently there are no formulas, and the calculations take too long for <i>n</i>&nbsp;>&nbsp;6.

### Convex

ID | description | <i>n</i> = 3 | calculation
--- | --- | --- | ---
[A300700](https://oeis.org/A300700) | k-faces | 26, 42, 18, 1 | <a href="https://github.com/watchduck/concertina_hypercubes/blob/master/faces.sage">faces.sage</a>
[A300701](https://oeis.org/A300701) | sum of k-faces<br>(row sums of A300700) | 87 | faces.sage
[A000629](https://oeis.org/A000629) | vertices<br>(column 0 of A300700,<br>row sums of A300699) | 26 |
[A300693](https://oeis.org/A300693) | edges<br>(column 1 of A300700) | 42 | <a href="https://github.com/watchduck/concertina_hypercubes/blob/master/coordinates_hasse.py">coordinates_hasse.py</a>
[A300699](https://oeis.org/A300699) | vertices by rank | 1, 3, 6, 6, 6, 3, 1 | <a href="https://github.com/watchduck/concertina_hypercubes/blob/master/ranks_convex.py">ranks_convex.py</a>
[A300697](https://oeis.org/A300697)<br>[A300698](https://oeis.org/A300698) | volumes<br>half volumes | 52<br>26 | <a href="https://github.com/watchduck/concertina_hypercubes/blob/master/volume.py">volume.py</a>

For <i>n</i>&nbsp;&ge;&nbsp;1 the number of vertices is twice an
[ordered Bell number](https://en.wikipedia.org/wiki/Ordered_Bell_number) ([A000670](https://oeis.org/A000670))
in the <i>n</i>-concertina,<br>
and twice the number of preferential arrangements ([A083355](https://oeis.org/A083355))
in the <i>n</i>-cocoon.

### Cocoon

ID | description | <i>n</i> = 3 | calculation
--- | --- | --- | ---
[A300695](https://oeis.org/A300695) | vertices by rank | 1, 6, 13, 6, 13, 6, 1 | <a href="https://github.com/watchduck/concertina_hypercubes/blob/master/cocoon.py">cocoon.py</a>
[A300696](https://oeis.org/A300696) | vertices<br>(row sums of A300695) | 46 | <a href=""></a>
[A300694](https://oeis.org/A300694) | edges | 139 | cocoon.py

