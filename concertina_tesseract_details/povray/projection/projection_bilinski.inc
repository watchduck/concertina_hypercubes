#declare Camera_Position = 28 * vnormalize(<13.2, 3, -45>);

// +ua +fn +H3000 +W1680
camera{
    location Camera_Position
    right    x*image_width/image_height
    angle    9.5
    look_at <0, .022, 0>
}


#declare VertexPoints = array[150]{<-1.618033988749895, -4.23606797749979, -2.618033988749895>, <-2.4180339887498947, -2.9416407864998737, -2.618033988749895>, <-2.818033988749895, -1.894427190999916, -1.9708203932499369>, <-1.618033988749895, -3.43606797749979, -1.323606797749979>, <-2.018033988749895, -2.388854381999832, -0.676393202250021>, <-2.818033988749895, -1.094427190999916, -0.676393202250021>, <-2.1708203932499366, -2.294427190999916, -2.218033988749895>, <-2.570820393249937, -1.2472135954999581, -1.570820393249937>, <-0.9708203932499369, -3.0360679774997896, -0.27639320225002095>, <-2.570820393249937, -0.4472135954999581, -0.27639320225002095>, <-1.3708203932499368, -1.9888543819998317, 0.3708203932499369>, <-2.1708203932499366, -0.6944271909999158, 0.3708203932499369>, <-0.323606797749979, -4.23606797749979, -1.8180339887498949>, <-1.923606797749979, -0.04721359549995796, 0.7708203932499369>, <-0.076393202250021, -3.5888543819998318, -1.418033988749895>, <-0.8763932022500209, -2.294427190999916, -1.418033988749895>, <0.323606797749979, -3.83606797749979, -0.7708203932499369>, <-1.2763932022500208, -1.2472135954999581, -0.7708203932499369>, <0.323606797749979, -3.0360679774997896, 0.523606797749979>, <-0.076393202250021, -1.9888543819998317, 1.1708203932499368>, <0.5708203932499369, -3.188854381999832, -0.3708203932499369>, <-0.2291796067500631, -1.894427190999916, -0.3708203932499369>, <-0.6291796067500631, -0.847213595499958, 0.27639320225002095>, <0.5708203932499369, -2.388854381999832, 0.923606797749979>, <0.1708203932499368, -1.3416407864998738, 1.570820393249937>, <-0.6291796067500631, -0.04721359549995796, 1.570820393249937>, <-2.4180339887498947, -1.6472135954999578, -2.618033988749895>, <-2.818033988749895, -0.6000000000000001, -1.9708203932499369>, <-1.218033988749895, -2.388854381999832, -0.676393202250021>, <-2.818033988749895, 0.19999999999999996, -0.676393202250021>, <-1.618033988749895, -1.3416407864998736, -0.029179606750063147>, <-2.4180339887498947, -0.04721359549995785, -0.029179606750063147>, <-2.170820393249937, -1.0, -2.218033988749895>, <-2.570820393249937, 0.04721359549995796, -1.570820393249937>, <-2.570820393249937, 0.847213595499958, -0.27639320225002095>, <-0.5708203932499368, -1.9888543819998317, 0.3708203932499369>, <-0.9708203932499369, -0.9416407864998737, 1.0180339887498948>, <-1.7708203932499367, 0.35278640450004217, 1.0180339887498948>, <-1.923606797749979, 1.2472135954999581, 0.7708203932499369>, <-1.523606797749979, 1.0, 1.418033988749895>, <0.723606797749979, -3.5888543819998318, -1.418033988749895>, <-0.8763932022500209, -1.0, -1.418033988749895>, <-1.2763932022500208, 0.04721359549995796, -0.7708203932499369>, <0.723606797749979, -1.9888543819998317, 1.1708203932499368>, <0.323606797749979, -0.9416407864998737, 1.8180339887498949>, <0.970820393249937, -2.9416407864998737, -1.0180339887498948>, <0.17082039324993692, -1.6472135954999578, -1.0180339887498948>, <1.3708203932499368, -3.188854381999832, -0.3708203932499369>, <-0.6291796067500631, 0.4472135954999581, 0.27639320225002095>, <1.3708203932499368, -2.388854381999832, 0.923606797749979>, <-0.6291796067500631, 1.2472135954999581, 1.570820393249937>, <0.5708203932499368, -0.2944271909999159, 2.218033988749895>, <-0.2291796067500631, 1.0, 2.218033988749895>, <1.618033988749895, -2.541640786499874, 0.029179606750063147>, <0.818033988749895, -1.247213595499958, 0.029179606750063147>, <0.41803398874989484, -0.19999999999999996, 0.676393202250021>, <1.618033988749895, -1.7416407864998737, 1.323606797749979>, <1.218033988749895, -0.6944271909999159, 1.9708203932499369>, <0.41803398874989484, 0.6, 1.9708203932499369>, <-0.8180339887498949, -2.9416407864998737, -2.618033988749895>, <-2.418033988749895, 1.2472135954999577, -0.029179606750063147>, <-2.170820393249937, 1.8944271909999157, 0.3708203932499369>, <-1.770820393249937, 1.6472135954999578, 1.0180339887498948>, <-1.523606797749979, 2.294427190999916, 1.418033988749895>, <0.17082039324993686, -0.35278640450004217, -1.0180339887498948>, <-0.22917960675006316, 0.6944271909999159, -0.3708203932499369>, <1.770820393249937, -1.341640786499874, 1.570820393249937>, <1.370820393249937, -0.2944271909999159, 2.218033988749895>, <-0.22917960675006316, 2.294427190999916, 2.218033988749895>, <0.8180339887498949, 0.04721359549995785, 0.029179606750063147>, <0.4180339887498949, 1.094427190999916, 0.676393202250021>, <2.018033988749895, -0.6944271909999159, 1.9708203932499369>, <0.4180339887498949, 1.8944271909999157, 1.9708203932499369>, <1.618033988749895, 0.35278640450004195, 2.618033988749895>, <0.8180339887498949, 1.6472135954999578, 2.618033988749895>, <-0.8180339887498949, -1.6472135954999578, -2.618033988749895>, <-1.618033988749895, -0.35278640450004195, -2.618033988749895>, <-0.4180339887498949, -1.8944271909999157, -1.9708203932499369>, <-2.018033988749895, 0.6944271909999159, -1.9708203932499369>, <-0.4180339887498949, -1.094427190999916, -0.676393202250021>, <-0.8180339887498949, -0.04721359549995785, -0.029179606750063147>, <0.22917960675006316, -2.294427190999916, -2.218033988749895>, <-1.370820393249937, 0.2944271909999159, -2.218033988749895>, <-1.770820393249937, 1.341640786499874, -1.570820393249937>, <0.22917960675006316, -0.6944271909999159, 0.3708203932499369>, <-0.17082039324993686, 0.35278640450004217, 1.0180339887498948>, <1.523606797749979, -2.294427190999916, -1.418033988749895>, <1.770820393249937, -1.6472135954999578, -1.0180339887498948>, <2.170820393249937, -1.8944271909999157, -0.3708203932499369>, <2.418033988749895, -1.2472135954999577, 0.029179606750063147>, <0.8180339887498949, 2.9416407864998737, 2.618033988749895>, <-0.41803398874989484, -0.6, -1.9708203932499369>, <-1.218033988749895, 0.6944271909999159, -1.9708203932499369>, <-1.618033988749895, 1.7416407864998737, -1.323606797749979>, <-0.41803398874989484, 0.19999999999999996, -0.676393202250021>, <-0.818033988749895, 1.247213595499958, -0.029179606750063147>, <-1.618033988749895, 2.541640786499874, -0.029179606750063147>, <0.2291796067500631, -1.0, -2.218033988749895>, <-0.5708203932499368, 0.2944271909999159, -2.218033988749895>, <0.6291796067500631, -1.2472135954999581, -1.570820393249937>, <-1.3708203932499368, 2.388854381999832, -0.923606797749979>, <0.6291796067500631, -0.4472135954999581, -0.27639320225002095>, <-1.3708203932499368, 3.188854381999832, 0.3708203932499369>, <-0.17082039324993692, 1.6472135954999578, 1.0180339887498948>, <-0.970820393249937, 2.9416407864998737, 1.0180339887498948>, <-0.323606797749979, 0.9416407864998737, -1.8180339887498949>, <-0.723606797749979, 1.9888543819998317, -1.1708203932499368>, <1.2763932022500208, -0.04721359549995796, 0.7708203932499369>, <0.8763932022500209, 1.0, 1.418033988749895>, <-0.723606797749979, 3.5888543819998318, 1.418033988749895>, <1.523606797749979, -1.0, -1.418033988749895>, <1.923606797749979, -1.2472135954999581, -0.7708203932499369>, <1.7708203932499367, -0.35278640450004217, -1.0180339887498948>, <0.9708203932499369, 0.9416407864998737, -1.0180339887498948>, <0.5708203932499368, 1.9888543819998317, -0.3708203932499369>, <2.570820393249937, -0.847213595499958, 0.27639320225002095>, <2.570820393249937, -0.04721359549995796, 1.570820393249937>, <2.170820393249937, 1.0, 2.218033988749895>, <2.4180339887498947, 0.04721359549995785, 0.029179606750063147>, <1.618033988749895, 1.3416407864998736, 0.029179606750063147>, <2.818033988749895, -0.19999999999999996, 0.676393202250021>, <1.218033988749895, 2.388854381999832, 0.676393202250021>, <2.818033988749895, 0.6000000000000001, 1.9708203932499369>, <2.4180339887498947, 1.6472135954999578, 2.618033988749895>, <0.6291796067500631, 0.04721359549995796, -1.570820393249937>, <-0.1708203932499368, 1.3416407864998738, -1.570820393249937>, <-0.5708203932499369, 2.388854381999832, -0.923606797749979>, <0.6291796067500631, 0.847213595499958, -0.27639320225002095>, <0.2291796067500631, 1.894427190999916, 0.3708203932499369>, <-0.5708203932499369, 3.188854381999832, 0.3708203932499369>, <0.076393202250021, 1.9888543819998317, -1.1708203932499368>, <-0.323606797749979, 3.0360679774997896, -0.523606797749979>, <1.2763932022500208, 1.2472135954999581, 0.7708203932499369>, <-0.323606797749979, 3.83606797749979, 0.7708203932499369>, <0.8763932022500209, 2.294427190999916, 1.418033988749895>, <0.076393202250021, 3.5888543819998318, 1.418033988749895>, <1.923606797749979, 0.04721359549995796, -0.7708203932499369>, <0.323606797749979, 4.23606797749979, 1.8180339887498949>, <2.1708203932499366, 0.6944271909999158, -0.3708203932499369>, <1.3708203932499368, 1.9888543819998317, -0.3708203932499369>, <2.570820393249937, 0.4472135954999581, 0.27639320225002095>, <0.9708203932499369, 3.0360679774997896, 0.27639320225002095>, <2.570820393249937, 1.2472135954999581, 1.570820393249937>, <2.1708203932499366, 2.294427190999916, 2.218033988749895>, <2.818033988749895, 1.094427190999916, 0.676393202250021>, <2.018033988749895, 2.388854381999832, 0.676393202250021>, <1.618033988749895, 3.43606797749979, 1.323606797749979>, <2.818033988749895, 1.894427190999916, 1.9708203932499369>, <2.4180339887498947, 2.9416407864998737, 2.618033988749895>, <1.618033988749895, 4.23606797749979, 2.618033988749895>}
#declare FirstVertex = 0;

// all edge and face indices
#declare EdgeIndices = array[344]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343}
#declare FaceIndices = array[252]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251}


#macro RankToVertexRad(Rank)
    .4
#end

#macro RankToEdgeRad(Rank)
    .12
#end


#macro Rotate()
	rotate -32 * x
	rotate 18 * z
	rotate 32 * y
	scale .11
#end