#include "cell.inc"


#declare Factor = 1;
#declare Abs = array[3]{ (0)*Factor, (1)*Factor, (2)*Factor, }
#declare P = array[8]{ <Abs[0],Abs[0],Abs[0]>, <Abs[0],Abs[1],Abs[1]>, <Abs[1],Abs[0],Abs[1]>, <Abs[1],Abs[1],Abs[0]>, <Abs[1],Abs[1],Abs[2]>, <Abs[1],Abs[2],Abs[1]>, <Abs[2],Abs[1],Abs[1]>, <Abs[2],Abs[2],Abs[2]>, }


#declare DarkVertices = array[4]{0, 4, 5, 6};

#declare LightVertices = array[4]{1, 2, 3, 7};


#declare Edges = array[12]{array[2]{5, 7}, array[2]{0, 2}, array[2]{1, 4}, array[2]{3, 6}, array[2]{2, 6}, array[2]{6, 7}, array[2]{4, 7}, array[2]{3, 5}, array[2]{2, 4}, array[2]{0, 3}, array[2]{1, 5}, array[2]{0, 1}};

#declare YellowFaces = array[6]{array[5]{2, 6, 7, 4, 2}, array[5]{5, 3, 6, 7, 5}, array[5]{3, 6, 2, 0, 3}, array[5]{1, 4, 7, 5, 1}, array[5]{4, 2, 0, 1, 4}, array[5]{0, 1, 5, 3, 0}};


#declare Transform = transform{
    translate <-1, -1, -1>
    rotate 45*y
    rotate 54.73*z  // arctan(sqrt(2))
    rotate 30*y
}


Drawing(Transform)

