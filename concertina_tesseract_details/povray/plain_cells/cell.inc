#version 3.6;
global_settings { assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 conserve_energy}}

#include "colors.inc"

///////////////////////////// camera and light

#declare Camera_Position = <0, -1 ,-13>;
camera{
	angle 32
    location Camera_Position
    look_at  <0, -0.1, 0>
    up    <0, 1, 0>
    right   <1, 0, 0>
}

light_source{ <-400, 500, -300> color White*0.9 shadowless}
light_source{ <400, 200, 100> color White*0.4 shadowless}
light_source{ Camera_Position  color rgb<0.9,0.9,1>*0.2 shadowless}
sky_sphere{ pigment{ White } }


/////////////////////////////////////////////////////////////////////////////////////////////////


#declare EdgeColor = <.5, .5, .5, 0>;

#declare LightVertexColor = <1, .8, .65> * .5;
#declare DarkVertexColor  = <1, .8, .65> * .2;

#declare FaceRed =  <1, .03, .03, .18>;
#declare FaceBlue =  <.05, .05, 1, .18>;
#declare FaceYellow =  <1, .65, 0, .18>;
#declare FaceGreen =  <0, .7, 0, .18>;

#declare RadVert = .1;
#declare RadEdge = RadVert / 3.5;


/////////////////////////////////////////////////////////////////////////////////////////////////


#macro Drawing(Transform)

    union{

        // VERTICES

        union{
            #for( Index, 0, dimension_size(LightVertices, 1) - 1 )
                sphere{ P[LightVertices[Index]], RadVert }
            #end
            pigment{color rgb LightVertexColor}
        }

        union{
            #for( Index, 0, dimension_size(DarkVertices, 1) - 1 )
                sphere{ P[DarkVertices[Index]], RadVert }
            #end
            pigment{color rgb DarkVertexColor}
        }


        // EDGES

        union{
            #for( Index, 0, dimension_size(Edges, 1) - 1 )
                #local EdgeArray = Edges[Index];
                cylinder{ P[EdgeArray[0]], P[EdgeArray[1]], RadEdge }
            #end
            pigment{color Gray}
        }
        
        
        // FACES
        
        #ifdef(RedFaces)
            union{
                #for( Index, 0, dimension_size(RedFaces, 1) - 1 )
                    #local FaceArray = RedFaces[Index];
                    #local LenOfFaceArray = dimension_size(FaceArray, 1);
                    polygon{ LenOfFaceArray,
                        #for(VertexIndexInFace, 0, LenOfFaceArray-1)
                            P[FaceArray[VertexIndexInFace]]
                        #end
                    }
                #end
                pigment{color rgbt FaceRed}
            }
        #end

        #ifdef(YellowFaces)
            union{
                #for( Index, 0, dimension_size(YellowFaces, 1) - 1 )
                    #local FaceArray = YellowFaces[Index];
                    #local LenOfFaceArray = dimension_size(FaceArray, 1);
                    polygon{ LenOfFaceArray,
                        #for(VertexIndexInFace, 0, LenOfFaceArray-1)
                            P[FaceArray[VertexIndexInFace]]
                        #end
                    }
                #end
                pigment{color rgbt FaceYellow}
            }
        #end

        #ifdef(BlueFaces)
            union{
                #for( Index, 0, dimension_size(BlueFaces, 1) - 1 )
                    #local FaceArray = BlueFaces[Index];
                    #local LenOfFaceArray = dimension_size(FaceArray, 1);
                    polygon{ LenOfFaceArray,
                        #for(VertexIndexInFace, 0, LenOfFaceArray-1)
                            P[FaceArray[VertexIndexInFace]]
                        #end
                    }
                #end
                pigment{color rgbt FaceBlue}
            }
        #end

        #ifdef(GreenFaces)
            union{
                #for( Index, 0, dimension_size(GreenFaces, 1) - 1 )
                    #local FaceArray = GreenFaces[Index];
                    #local LenOfFaceArray = dimension_size(FaceArray, 1);
                    polygon{ LenOfFaceArray,
                        #for(VertexIndexInFace, 0, LenOfFaceArray-1)
                            P[FaceArray[VertexIndexInFace]]
                        #end
                    }
                #end
                pigment{color rgbt FaceGreen}
            }
        #end

    transform{Transform}

    }

#end
