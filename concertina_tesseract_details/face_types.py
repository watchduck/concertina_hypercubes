from variables import vertices, faces
from functions import polygon_shape

known_shapes = [
    ((45, 45, 90, 45, 45, 90), (0, 0, 1, 1, 1, 1)),  # concertina square (red)
    ((60, 120, 60, 120), (0, 0, 0, 0)),  # rhomb (yellow)
    ((90, 90, 90, 90), (0, 0, 1, 1)),  # rectangle (blue)
    ((90, 90, 90, 90), (0, 0, 0, 0)),  # square (green)
]

shape_keys = []

for face in faces:
    points = [vertices[pointindex] for pointindex in face]
    shape = polygon_shape(points)
    shape_key = known_shapes.index(shape)
    shape_keys.append(shape_key)

print(shape_keys)