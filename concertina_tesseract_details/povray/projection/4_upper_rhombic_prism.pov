#include "projection.inc"


#local Faces = array[72]{51, 53, 55, 57, 69, 71, 76, 77, 83, 84, 85, 87, 89, 92, 93, 94, 95, 97, 99, 100, 101, 136, 138, 140, 142, 147, 148, 149, 156, 157, 163, 164, 167, 168, 171, 172, 173, 174, 175, 177, 178, 179, 191, 193, 195, 198, 200, 201, 202, 204, 205, 207, 208, 209, 217, 219, 221, 222, 223, 224, 226, 227, 228, 229, 230, 232, 234, 235, 236, 240, 241, 242}


#local EdgesByCount = array[3]{

array[208]{1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 69, 70, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 90, 91, 92, 97, 101, 102, 103, 104, 105, 106, 107, 109, 110, 111, 113, 118, 119, 120, 123, 128, 129, 130, 132, 133, 135, 139, 146, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 203, 204, 205, 206, 207, 208, 210, 211, 212, 216, 221, 222, 223, 225, 226, 228, 232, 233, 234, 235, 236, 237, 244, 245, 253, 258, 268, 269, 270, 271, 272, 273, 275, 276, 277, 278, 279, 285, 290, 302, 303, 304, 305, 306, 307, 308, 313, 331, 332, 333, 337, 338, 339, 340, 341, 342, 343},

array[120]{39, 40, 41, 68, 71, 89, 94, 95, 96, 98, 100, 108, 112, 114, 116, 121, 122, 124, 125, 126, 127, 131, 134, 136, 137, 138, 140, 141, 142, 143, 144, 145, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 200, 201, 202, 209, 213, 215, 217, 219, 220, 224, 227, 229, 230, 231, 238, 239, 240, 241, 243, 246, 247, 248, 250, 251, 252, 254, 256, 257, 259, 260, 261, 263, 264, 265, 266, 267, 274, 280, 282, 283, 284, 286, 287, 288, 289, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 309, 311, 312, 314, 315, 316, 317, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 334, 335, 336},

array[12]{93, 99, 115, 214, 218, 242, 249, 255, 262, 281, 310, 318}

}


#local VerticesByCount = array[2]{

array[79]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 23, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 40, 41, 42, 43, 44, 45, 46, 47, 49, 53, 54, 56, 59, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 94, 97, 98, 99, 101, 110, 111, 124, 125, 127, 136, 137, 146, 148, 149},

array[70]{13, 22, 24, 25, 38, 39, 48, 50, 51, 52, 55, 57, 58, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 93, 95, 96, 100, 102, 103, 104, 105, 106, 107, 108, 109, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 126, 128, 129, 130, 131, 132, 133, 134, 135, 138, 139, 140, 141, 142, 143, 144, 145, 147}

}


SelectionOfCellsUnion(Faces, EdgesByCount, VerticesByCount)
