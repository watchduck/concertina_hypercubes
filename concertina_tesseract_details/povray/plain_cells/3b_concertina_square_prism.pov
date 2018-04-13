#include "cell.inc"


#declare Factor = 1;
#declare Abs = array[3]{ (0.5)*Factor, (sqrt(2)/2)*Factor, (1.5)*Factor, }
#declare P = array[12]{ <-Abs[2],-Abs[2],-Abs[1]>, <-Abs[2],-Abs[2],Abs[1]>, <-Abs[2],Abs[0],-Abs[1]>, <-Abs[2],Abs[0],Abs[1]>, <-Abs[0],Abs[2],-Abs[1]>, <-Abs[0],Abs[2],Abs[1]>, <Abs[0],-Abs[2],-Abs[1]>, <Abs[0],-Abs[2],Abs[1]>, <Abs[2],-Abs[0],-Abs[1]>, <Abs[2],-Abs[0],Abs[1]>, <Abs[2],Abs[2],-Abs[1]>, <Abs[2],Abs[2],Abs[1]>, }


#declare DarkVertices = array[6]{0, 4, 8, 3, 7, 11};

#declare LightVertices = array[6]{2, 6, 10, 1, 5, 9};


#declare Edges = array[18]{ array[2]{2, 3}, array[2]{3, 5}, array[2]{6, 8}, array[2]{10, 11}, array[2]{0, 1}, array[2]{4, 5}, array[2]{6, 7}, array[2]{8, 9}, array[2]{5, 11}, array[2]{1, 3}, array[2]{0, 6}, array[2]{2, 4}, array[2]{9, 11}, array[2]{1, 7}, array[2]{0, 2}, array[2]{7, 9}, array[2]{4, 10}, array[2]{8, 10} };


#declare BlueFaces = array[4]{ array[5]{8, 10, 11, 9, 8}, array[5]{0, 2, 3, 1, 0}, array[5]{6, 0, 1, 7, 6}, array[5]{5, 11, 10, 4, 5} };

#declare GreenFaces = array[2]{ array[5]{3, 2, 4, 5, 3}, array[5]{7, 6, 8, 9, 7} };

#declare RedFaces = array[2]{ array[7]{4, 2, 0, 6, 8, 10, 4}, array[7]{7, 1, 3, 5, 11, 9, 7} };


#declare Transform = transform{
    rotate 45*z
    rotate -18.43*x
    rotate 45*y
}


Drawing(Transform)
