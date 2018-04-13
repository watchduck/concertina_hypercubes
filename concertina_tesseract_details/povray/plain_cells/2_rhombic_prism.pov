#include "cell.inc"


#declare Factor = 1;
#declare Abs = array[4]{ (0)*Factor, (sqrt(2)/2)*Factor, (1)*Factor, (1.22474487139159)*Factor, }
#declare P = array[8]{ <-Abs[1],-Abs[2],Abs[0]>, <-Abs[1],Abs[2],Abs[0]>, <Abs[0],-Abs[2],-Abs[3]>, <Abs[0],-Abs[2],Abs[3]>, <Abs[0],Abs[2],-Abs[3]>, <Abs[0],Abs[2],Abs[3]>, <Abs[1],-Abs[2],Abs[0]>, <Abs[1],Abs[2],Abs[0]>, }


#declare DarkVertices = array[4]{0, 4, 5, 6};

#declare LightVertices = array[4]{1, 2, 3, 7};


#declare Edges = array[12]{array[2]{0, 3}, array[2]{5, 7}, array[2]{3, 6}, array[2]{2, 4}, array[2]{2, 6}, array[2]{0, 2}, array[2]{3, 5}, array[2]{1, 5}, array[2]{1, 4}, array[2]{4, 7}, array[2]{6, 7}, array[2]{0, 1}};


#declare BlueFaces = array[4]{ array[5]{0, 1, 4, 2, 0}, array[5]{3, 0, 1, 5, 3}, array[5]{2, 4, 7, 6, 2}, array[5]{3, 6, 7, 5, 3} };

#declare YellowFaces = array[2]{ array[5]{5, 1, 4, 7, 5}, array[5]{6, 3, 0, 2, 6} };


#declare Transform = transform{
    rotate -50.77*x
    rotate -45*y
}


Drawing(Transform)
