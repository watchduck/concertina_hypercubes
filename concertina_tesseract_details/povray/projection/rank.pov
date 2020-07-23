#include "projection.inc"


#local HighlightRank = 5;

#local LightRed = <1, 0, 0, 0>;
#local DarkRed = <.6, 0, 0, 0>;

#local VertexColors = array[2]{
    array[2]{ LightVertexColor, LightRed },
    array[2]{ DarkVertexColor, DarkRed }
}


#local Faces = array[120]{

1, 3, 10, 18, 20, 22, 23, 24, 25, 29, 30, 31, 32, 46, 48, 58, 59, 60, 123, 131, 133, 180, 181, 182,

5, 12, 14, 26, 34, 36, 37, 41, 45, 49, 54, 61, 64, 67, 68, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 86, 87, 88, 89, 90, 91, 95, 96, 97, 98, 109, 111, 119, 125, 127, 134, 139, 143, 144, 145, 146, 152, 159, 166, 170, 184, 186, 189, 190, 194, 195, 196, 197, 198, 199, 203, 204, 205, 206, 211, 216, 220, 230, 231, 232, 233,

85, 92, 101, 120, 121, 122, 147, 172, 178, 200, 208, 213, 214, 215, 221, 228, 236, 237, 238, 239, 240, 243, 244, 245

}


union{

    // VERTICES
    union{
        #for( i, FirstVertex, dimension_size(VertexPoints, 1)-1 )
            #local Rank = VertexRanks[i];
            #local Rad = RankToVertexRad(Rank);
            #if(Rank=HighlightRank)
                #local Highlight = 1;
            #else
                #local Highlight = 0;
            #end
            #local VertexColor = VertexColors[VertexRankParities[i]][Highlight];
            sphere{ VertexPoints[i]*Factor, Rad   pigment{color rgbt VertexColor}   }
        #end
    }

    // EDGES
    union{
        #for( i, 0, dimension_size(EdgeIndices, 1)-1 )
            #local EdgeIndex = EdgeIndices[i];
            #local Edge = EdgeArrays[EdgeIndex];
            #local VertexIndex1 = Edge[0];
            #local VertexIndex2 = Edge[1];
            #local Point1 = VertexPoints[VertexIndex1]*Factor;
            #local Point2 = VertexPoints[VertexIndex2]*Factor;
            #local Rank1 = VertexRanks[VertexIndex1];
            #local Rank2 = VertexRanks[VertexIndex2];
            #local Rad1 = RankToEdgeRad(Rank1);
            #local Rad2 = RankToEdgeRad(Rank2);
            cone{ Point1, Rad1, Point2, Rad2 }
        #end
        pigment{color rgb .5}
    }

    // FACES
    union{
        #for( i, 0, dimension_size(Faces, 1)-1 )
            #local FaceIndex = Faces[i];
            #local FaceArray = FaceArrays[FaceIndex];
            #local LenOfFaceArray = dimension_size(FaceArray, 1);
            polygon{ LenOfFaceArray,
                #for(VertexIndexInFace, 0, LenOfFaceArray-1)
                    #local VertexIndexInPolytope = FaceArray[VertexIndexInFace];
                    VertexPoints[VertexIndexInPolytope]*Factor
                #end
            }
        #end
        pigment{color rgbt <.7, .7, .7, .5>}
    }
    
    Rotate()
}

