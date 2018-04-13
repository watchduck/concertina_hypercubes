# Details of the 4-concertina

In this section the individual [faces](https://en.wikipedia.org/wiki/Face_(geometry)#k-face) of the 4-concertina are listed with their properties and used in 3D projections.

They were calculated in
[`edges.sage`](https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/edges.sage),
[`faces.sage`](https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/faces.sage) and
[`cells.sage`](https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/cells.sage), and are now all in
[`variables.py`](https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/variables.py).<br>
Their POV-Ray counterparts are in
[`concertina_tesseract.inc`](https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/povray/concertina_tesseract.inc),
included by the `.pov` files.

## Tetrahedral shadow

The 3D coordinates were calculated in
[`projection_from_vertex.py`](https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/projection_from_vertex.py)
using
[`project_from_4d_to_3d`](https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/functions.py).<br>
(This Python code was inspired by [this](http://blog.hypercubed.com/wp-content/misc/hypercube.pov)
POV-Ray code by [J. Harshbarger](https://github.com/Hypercubed)).

<table>
  <tr>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_tesseract_with_blue_faces.png">
        <img width="300" src="https://upload.wikimedia.org/wikipedia/commons/3/34/Concertina_tesseract_with_blue_faces.png"/>
      </a>
    </td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_tesseract;_rank_03.png">
        <img width="300" src="https://upload.wikimedia.org/wikipedia/commons/a/ae/Concertina_tesseract%3B_rank_03.png"/>
      </a>
    </td>
    <td>
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_tesseract;_concertina_cubes,_upper.png">
        <img width="300" src="https://upload.wikimedia.org/wikipedia/commons/9/9a/Concertina_tesseract%3B_concertina_cubes%2C_upper.png"/>
      </a>
    </td>
  </tr>
  <tr>
    <td>Projection to 3D</td>
    <td>Vertices with rank 3 highlighted</td>
    <td>4 cells highlighted</td>
  </tr>
  <tr>
    <td>
      <a href="https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/povray/blue.pov">
        <code>blue.pov</code>
      </a>
    </td>
    <td>
      <a href="https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/povray/rank.pov">
        <code>rank.pov</code>
      </a>
    </td>
    <td>
      <a href="https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/povray/tetrahedral_shadow/6_upper_concertina_cube.pov">
        <code>6_upper_concertina_cube.pov</code>
      </a>
    </td>
  </tr>
</table>


<a href="https://commons.wikimedia.org/wiki/File:Tesseract_tetrahedron_shadow_with_alternating_vertex_colors.png">
  <img align="left" width="300" src="https://upload.wikimedia.org/wikipedia/commons/2/24/Tesseract_tetrahedron_shadow_with_alternating_vertex_colors.png"/>
</a>
On the left is a tesseract projected in the same way. The 15 vertices in this projection are in the same positions as some of the vertices
in the projection of the concertina. It should be noted that the original 4D points projected to the same 3D point are different
(except for the top vertex projected to the center).
Tesseract and concertina have only two opposite points in common.
The other 14 points of the tesseract correspond not to vertices, but to cells of the concertina ―
namely those highlighted in gray in the rank picture above.



`[1/5, -1, -1, -1]` is a vertex with rank 1 in the concertina<br>
`[1, -1, -1, -1]` is a vertex with rank 1 in the tesseract.<br>
For both points `project_from_4d_to_3d` returns `[0.70710678 -0.40824829 -0.28867513]`,
a vertex of the tetrahedron.

<br clear=all>
## Plain cells

The four different cell types apart from the concertina cube:

<table>
  <tr>
    <td style="text-align: center;">
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_tesseract_cell;_trigonal_trapezohedron,_lower.png">
        <img width="108" src="https://upload.wikimedia.org/wikipedia/commons/2/24/Concertina_tesseract_cell%3B_trigonal_trapezohedron%2C_lower.png"/>
      </a>
    </td>
    <td style="text-align: center;">
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_tesseract_cell;_rhombic_prism,_lower.png">
        <img width="153" src="https://upload.wikimedia.org/wikipedia/commons/4/48/Concertina_tesseract_cell%3B_rhombic_prism%2C_lower.png"/>
      </a>
    </td>
    <td style="text-align: center;">
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_tesseract_cell;_rhombic_dodecahedron.png">
        <img width="171" src="https://upload.wikimedia.org/wikipedia/commons/c/c1/Concertina_tesseract_cell%3B_rhombic_dodecahedron.png"/>
      </a>
    </td>
    <td style="text-align: center;">
      <a href="https://commons.wikimedia.org/wiki/File:Concertina_tesseract_cell;_concertina_square_prism.png">
        <img width="213" src="https://upload.wikimedia.org/wikipedia/commons/7/73/Concertina_tesseract_cell%3B_concertina_square_prism.png"/>
      </a>
    </td>
  </tr>
  <tr>
    <td>Trigonal trapezohedron</td>
    <td>Right rhombic prism</td>
    <td>Squared rhombic dodecahedron</td>
    <td>Concertina cube prism</td>
  </tr>
</table>

The POV-Ray sources are
<code>plain_cells/<a href="https://github.com/watchduck/concertina_hypercubes/blob/master/concertina_tesseract_details/povray/plain_cells/3a_rhombic_dodecahedron.pov">3a_rhombic_dodecahedron.pov</a></code>,
etc.
