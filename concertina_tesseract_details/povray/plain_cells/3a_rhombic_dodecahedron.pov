#include "cell.inc"


#declare Factor = 1;
#declare Abs = array[3]{ (0)*Factor, (1)*Factor, (2)*Factor, }
#declare P = array[14]{ <-Abs[1],-Abs[1],Abs[0]>, <-Abs[1],Abs[0],-Abs[1]>, <-Abs[1],Abs[0],Abs[1]>, <-Abs[1],Abs[1],Abs[0]>, <Abs[0],-Abs[2],Abs[0]>, <Abs[0],-Abs[1],-Abs[1]>, <Abs[0],-Abs[1],Abs[1]>, <Abs[0],Abs[1],-Abs[1]>, <Abs[0],Abs[1],Abs[1]>, <Abs[0],Abs[2],Abs[0]>, <Abs[1],-Abs[1],Abs[0]>, <Abs[1],Abs[0],-Abs[1]>, <Abs[1],Abs[0],Abs[1]>, <Abs[1],Abs[1],Abs[0]>, }


#declare DarkVertices = array[6]{1, 2, 4, 9, 11, 12};

#declare LightVertices = array[8]{0, 3, 5, 6, 7, 8, 10, 13};


#declare Edges = array[24]{array[2]{4, 5}, array[2]{3, 9}, array[2]{4, 10}, array[2]{1, 3}, array[2]{4, 6}, array[2]{9, 13}, array[2]{0, 2}, array[2]{12, 13}, array[2]{8, 9}, array[2]{0, 1}, array[2]{2, 6}, array[2]{8, 12}, array[2]{10, 11}, array[2]{2, 8}, array[2]{7, 11}, array[2]{11, 13}, array[2]{2, 3}, array[2]{6, 12}, array[2]{10, 12}, array[2]{7, 9}, array[2]{5, 11}, array[2]{1, 5}, array[2]{0, 4}, array[2]{1, 7}};


#declare YellowFaces = array[8]{ array[5]{1, 0, 4, 5, 1}, array[5]{7, 11, 13, 9, 7}, array[5]{9, 7, 1, 3, 9}, array[5]{8, 9, 13, 12, 8}, array[5]{2, 8, 9, 3, 2}, array[5]{4, 6, 2, 0, 4}, array[5]{10, 11, 5, 4, 10}, array[5]{10, 12, 6, 4, 10} };

#declare GreenFaces = array[4]{ array[5]{2, 0, 1, 3, 2}, array[5]{1, 7, 11, 5, 1}, array[5]{13, 12, 10, 11, 13}, array[5]{6, 2, 8, 12, 6} };


#declare Transform = transform{
    rotate 20*y
}


Drawing(Transform)
