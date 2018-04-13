#include "concertina_tesseract.inc"


union{

    // VERTICES
    union{
        #for( i, 1, dimension_size(VertexPoints, 1)-1 )
            #local Rank = VertexRanks[i];
            #local Rad = RankToVertexRad(Rank);
            sphere{ VertexPoints[i]*Factor, Rad 
                #if(VertexRankParities[i])
                    pigment{color rgb DarkVertexColor}
                #else
                    pigment{color LightVertexColor}
                #end
            }
        #end
    }

    // EDGES
    union{
        #for( i, 0, dimension_size(EdgesWithoutOrigin, 1)-1 )
            #local EdgeIndex = EdgesWithoutOrigin[i];
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
        #for( i, 0, dimension_size(FacesWithoutOrigin, 1)-1 )
            #local FaceIndex = FacesWithoutOrigin[i];
            #local FaceArray = FaceArrays[FaceIndex];
            #local LenOfFaceArray = dimension_size(FaceArray, 1);
            polygon{ LenOfFaceArray,
                #for(VertexIndexInFace, 0, LenOfFaceArray-1)
                    #local VertexIndexInPolytope = FaceArray[VertexIndexInFace];
                    VertexPoints[VertexIndexInPolytope]*Factor
                #end
            }
        #end
        pigment{color rgbt BlueFaceColor}
    }
    
    rotate -90*x
    rotate 4*y
    rotate 4*z
}

