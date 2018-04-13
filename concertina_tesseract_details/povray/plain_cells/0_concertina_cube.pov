#include "cell.inc"


#declare Factor = 1;
#declare Abs = array[3]{ (0)*Factor, (1)*Factor, (2)*Factor, }
#declare P = array[26]{ <-Abs[2],-Abs[2],-Abs[2]>, <-Abs[2],-Abs[2],Abs[0]>, <-Abs[2],-Abs[1],Abs[1]>, <-Abs[2],Abs[0],-Abs[2]>, <-Abs[2],Abs[1],-Abs[1]>, <-Abs[2],Abs[1],Abs[1]>, <-Abs[1],-Abs[2],Abs[1]>, <-Abs[1],-Abs[1],Abs[2]>, <-Abs[1],Abs[1],-Abs[2]>, <-Abs[1],Abs[1],Abs[2]>, <-Abs[1],Abs[2],-Abs[1]>, <-Abs[1],Abs[2],Abs[1]>, <Abs[0],-Abs[2],-Abs[2]>, <Abs[0],Abs[2],Abs[2]>, <Abs[1],-Abs[2],-Abs[1]>, <Abs[1],-Abs[2],Abs[1]>, <Abs[1],-Abs[1],-Abs[2]>, <Abs[1],-Abs[1],Abs[2]>, <Abs[1],Abs[1],-Abs[2]>, <Abs[1],Abs[2],-Abs[1]>, <Abs[2],-Abs[1],-Abs[1]>, <Abs[2],-Abs[1],Abs[1]>, <Abs[2],Abs[0],Abs[2]>, <Abs[2],Abs[1],-Abs[1]>, <Abs[2],Abs[2],Abs[0]>, <Abs[2],Abs[2],Abs[2]>, }


#declare LightVertices = array[14]{0, 2, 4, 6, 8, 9, 11, 14, 16, 17, 19, 21, 23, 25};

#declare DarkVertices = array[12]{1, 3, 5, 7, 10, 12, 13, 15, 18, 20, 22, 24};


#declare Edges = array[42]{array[2]{13, 25}, array[2]{22, 25}, array[2]{0, 1}, array[2]{24, 25}, array[2]{0, 3}, array[2]{0, 12}, array[2]{19, 24}, array[2]{3, 8}, array[2]{20, 23}, array[2]{6, 15}, array[2]{15, 21}, array[2]{4, 10}, array[2]{10, 11}, array[2]{14, 20}, array[2]{16, 18}, array[2]{14, 15}, array[2]{16, 20}, array[2]{1, 2}, array[2]{15, 17}, array[2]{4, 5}, array[2]{12, 16}, array[2]{21, 22}, array[2]{9, 13}, array[2]{1, 6}, array[2]{2, 7}, array[2]{8, 10}, array[2]{5, 9}, array[2]{12, 14}, array[2]{18, 19}, array[2]{3, 4}, array[2]{23, 24}, array[2]{10, 19}, array[2]{7, 9}, array[2]{7, 17}, array[2]{6, 7}, array[2]{2, 5}, array[2]{8, 18}, array[2]{11, 13}, array[2]{18, 23}, array[2]{5, 11}, array[2]{20, 21}, array[2]{17, 22}};


#declare RedFaces = array[6]{array[7]{11, 10, 19, 24, 25, 13, 11}, array[7]{18, 8, 3, 0, 12, 16, 18}, array[7]{15, 6, 1, 0, 12, 14, 15}, array[7]{0, 3, 4, 5, 2, 1, 0}, array[7]{22, 25, 24, 23, 20, 21, 22}, array[7]{7, 17, 22, 25, 13, 9, 7}};

#declare BlueFaces = array[6]{array[5]{5, 9, 7, 2, 5}, array[5]{19, 10, 8, 18, 19}, array[5]{5, 4, 10, 11, 5}, array[5]{20, 16, 18, 23, 20}, array[5]{6, 7, 17, 15, 6}, array[5]{20, 14, 15, 21, 20}};

#declare YellowFaces = array[6]{array[5]{12, 16, 20, 14, 12}, array[5]{6, 1, 2, 7, 6}, array[5]{3, 4, 10, 8, 3}, array[5]{15, 17, 22, 21, 15}, array[5]{19, 24, 23, 18, 19}, array[5]{13, 9, 5, 11, 13}};


#declare Transform = transform{
    rotate 45*z
    rotate -35*x
    rotate 120*y
}


Drawing(Transform)

