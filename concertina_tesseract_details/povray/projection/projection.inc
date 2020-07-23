#version 3.6;
global_settings { assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 conserve_energy}}

#include "colors.inc"
#include "math.inc"
#include "textures.inc"

#include "projection_tetrahedral.inc"
//#include "projection_bilinski.inc"


light_source{ <-400, 500, -300> color White*0.9 shadowless}
light_source{ <400, 200, 100> color White*0.4 shadowless}
light_source{ Camera_Position  color rgb<0.9,0.9,1>*0.2 shadowless}
sky_sphere{ pigment{ White } }

/////////////////////////////////////////////////////////////////////////////////////////////////

#declare Factor = 7;

#declare NormalEdgeColor = <.5, .5, .5, 0>;
#declare EdgeColorsByCount = array[4]{ <.5, .5, .5, .95>, NormalEdgeColor, <.15, .15, .15, 0>, <0, 0, 0, 0> };

#declare LightVertexColor = <.5, .8*.5, .65*.5, 0>;
#declare DarkVertexColor  = <.2, .8*.2, .65*.2, 0>;
#declare TransparentLightVertexColor = <.5, .8*.5, .65*.5, .95>;
#declare TransparentDarkVertexColor  = <.2, .8*.2, .65*.2, .95>;

#declare BlueFaceColor = <0, 0, 1, .8>;  // as in File:Concertina tesseract with blue faces.png

// red, yellow, blue, green
#declare FaceColorsByType  = array[4]{ <1, .03, .03, .18>, <1, .65, 0, .18>, <.05, .05, 1, .18>, <0, .7, 0, .18> }

/////////////////////////////////////////////////////////////////////////////////////////////////

#declare VertexRanks = array[150]{ 0, 1, 2, 1, 2, 3, 2, 3, 2, 4, 3, 4, 1, 5, 2, 3, 2, 4, 3, 4, 3, 4, 5, 4, 5, 6, 2, 3, 2, 4, 3, 4, 3, 4, 5, 3, 4, 5, 6, 6, 2, 4, 5, 4, 5, 3, 4, 3, 6, 4, 7, 6, 7, 4, 5, 6, 5, 6, 7, 1, 5, 6, 6, 7, 5, 6, 5, 6, 8, 6, 7, 6, 8, 7, 8, 2, 3, 2, 4, 3, 4, 2, 4, 5, 4, 5, 3, 4, 4, 5, 9, 3, 4, 5, 4, 5, 6, 3, 4, 3, 6, 4, 7, 6, 7, 5, 6, 5, 6, 8, 4, 4, 5, 6, 7, 5, 6, 7, 6, 7, 6, 8, 7, 8, 4, 5, 6, 5, 6, 7, 6, 7, 6, 8, 7, 8, 5, 9, 6, 7, 6, 8, 7, 8, 7, 8, 9, 8, 9, 10 }

#declare VertexRankParities = array[150]{ 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0 }

#declare EdgeArrays = array[344]{ array[2]{0, 1}, array[2]{1, 2}, array[2]{0, 3}, array[2]{3, 4}, array[2]{4, 5}, array[2]{2, 5}, array[2]{1, 6}, array[2]{2, 7}, array[2]{6, 7}, array[2]{3, 8}, array[2]{5, 9}, array[2]{7, 9}, array[2]{8, 10}, array[2]{4, 10}, array[2]{10, 11}, array[2]{5, 11}, array[2]{0, 12}, array[2]{9, 13}, array[2]{11, 13}, array[2]{12, 14}, array[2]{14, 15}, array[2]{6, 15}, array[2]{12, 16}, array[2]{7, 17}, array[2]{15, 17}, array[2]{16, 18}, array[2]{8, 18}, array[2]{18, 19}, array[2]{10, 19}, array[2]{14, 20}, array[2]{16, 20}, array[2]{20, 21}, array[2]{15, 21}, array[2]{17, 22}, array[2]{21, 22}, array[2]{18, 23}, array[2]{20, 23}, array[2]{19, 24}, array[2]{23, 24}, array[2]{13, 25}, array[2]{22, 25}, array[2]{24, 25}, array[2]{1, 26}, array[2]{2, 27}, array[2]{26, 27}, array[2]{3, 28}, array[2]{27, 29}, array[2]{5, 29}, array[2]{28, 30}, array[2]{4, 30}, array[2]{30, 31}, array[2]{5, 31}, array[2]{26, 32}, array[2]{6, 32}, array[2]{27, 33}, array[2]{7, 33}, array[2]{32, 33}, array[2]{29, 34}, array[2]{9, 34}, array[2]{33, 34}, array[2]{8, 35}, array[2]{28, 35}, array[2]{35, 36}, array[2]{10, 36}, array[2]{30, 36}, array[2]{36, 37}, array[2]{31, 37}, array[2]{11, 37}, array[2]{13, 38}, array[2]{34, 38}, array[2]{37, 39}, array[2]{13, 39}, array[2]{12, 40}, array[2]{15, 41}, array[2]{32, 41}, array[2]{17, 42}, array[2]{33, 42}, array[2]{41, 42}, array[2]{18, 43}, array[2]{35, 43}, array[2]{36, 44}, array[2]{43, 44}, array[2]{19, 44}, array[2]{40, 45}, array[2]{14, 45}, array[2]{15, 46}, array[2]{45, 46}, array[2]{40, 47}, array[2]{16, 47}, array[2]{22, 48}, array[2]{42, 48}, array[2]{47, 49}, array[2]{18, 49}, array[2]{25, 50}, array[2]{38, 50}, array[2]{48, 50}, array[2]{24, 51}, array[2]{44, 51}, array[2]{39, 52}, array[2]{25, 52}, array[2]{51, 52}, array[2]{47, 53}, array[2]{45, 53}, array[2]{20, 53}, array[2]{46, 54}, array[2]{21, 54}, array[2]{53, 54}, array[2]{54, 55}, array[2]{22, 55}, array[2]{53, 56}, array[2]{23, 56}, array[2]{49, 56}, array[2]{24, 57}, array[2]{56, 57}, array[2]{55, 58}, array[2]{25, 58}, array[2]{57, 58}, array[2]{0, 59}, array[2]{29, 60}, array[2]{31, 60}, array[2]{34, 61}, array[2]{60, 61}, array[2]{60, 62}, array[2]{37, 62}, array[2]{39, 63}, array[2]{62, 63}, array[2]{38, 63}, array[2]{61, 63}, array[2]{41, 64}, array[2]{46, 64}, array[2]{42, 65}, array[2]{64, 65}, array[2]{43, 66}, array[2]{49, 66}, array[2]{66, 67}, array[2]{44, 67}, array[2]{52, 68}, array[2]{63, 68}, array[2]{50, 68}, array[2]{54, 69}, array[2]{64, 69}, array[2]{69, 70}, array[2]{48, 70}, array[2]{55, 70}, array[2]{65, 70}, array[2]{66, 71}, array[2]{56, 71}, array[2]{58, 72}, array[2]{50, 72}, array[2]{70, 72}, array[2]{71, 73}, array[2]{51, 73}, array[2]{57, 73}, array[2]{67, 73}, array[2]{73, 74}, array[2]{58, 74}, array[2]{52, 74}, array[2]{59, 75}, array[2]{75, 76}, array[2]{26, 76}, array[2]{59, 77}, array[2]{76, 78}, array[2]{27, 78}, array[2]{77, 79}, array[2]{28, 79}, array[2]{79, 80}, array[2]{30, 80}, array[2]{59, 81}, array[2]{32, 82}, array[2]{76, 82}, array[2]{33, 83}, array[2]{82, 83}, array[2]{78, 83}, array[2]{35, 84}, array[2]{79, 84}, array[2]{80, 85}, array[2]{84, 85}, array[2]{36, 85}, array[2]{40, 86}, array[2]{81, 86}, array[2]{86, 87}, array[2]{45, 87}, array[2]{86, 88}, array[2]{47, 88}, array[2]{88, 89}, array[2]{53, 89}, array[2]{87, 89}, array[2]{68, 90}, array[2]{74, 90}, array[2]{72, 90}, array[2]{77, 91}, array[2]{75, 91}, array[2]{91, 92}, array[2]{76, 92}, array[2]{78, 93}, array[2]{92, 93}, array[2]{91, 94}, array[2]{79, 94}, array[2]{94, 95}, array[2]{80, 95}, array[2]{60, 96}, array[2]{93, 96}, array[2]{95, 96}, array[2]{75, 97}, array[2]{81, 97}, array[2]{97, 98}, array[2]{76, 98}, array[2]{77, 99}, array[2]{81, 99}, array[2]{93, 100}, array[2]{83, 100}, array[2]{99, 101}, array[2]{79, 101}, array[2]{61, 102}, array[2]{96, 102}, array[2]{100, 102}, array[2]{85, 103}, array[2]{95, 103}, array[2]{96, 104}, array[2]{103, 104}, array[2]{62, 104}, array[2]{98, 105}, array[2]{82, 105}, array[2]{83, 106}, array[2]{105, 106}, array[2]{84, 107}, array[2]{101, 107}, array[2]{107, 108}, array[2]{85, 108}, array[2]{104, 109}, array[2]{102, 109}, array[2]{63, 109}, array[2]{86, 110}, array[2]{97, 110}, array[2]{86, 111}, array[2]{99, 111}, array[2]{110, 112}, array[2]{87, 112}, array[2]{64, 113}, array[2]{112, 113}, array[2]{105, 113}, array[2]{65, 114}, array[2]{113, 114}, array[2]{106, 114}, array[2]{88, 115}, array[2]{111, 115}, array[2]{66, 116}, array[2]{115, 116}, array[2]{107, 116}, array[2]{116, 117}, array[2]{67, 117}, array[2]{108, 117}, array[2]{112, 118}, array[2]{89, 118}, array[2]{118, 119}, array[2]{113, 119}, array[2]{69, 119}, array[2]{115, 120}, array[2]{89, 120}, array[2]{114, 121}, array[2]{70, 121}, array[2]{119, 121}, array[2]{116, 122}, array[2]{71, 122}, array[2]{120, 122}, array[2]{117, 123}, array[2]{73, 123}, array[2]{122, 123}, array[2]{99, 124}, array[2]{91, 124}, array[2]{97, 124}, array[2]{124, 125}, array[2]{98, 125}, array[2]{92, 125}, array[2]{93, 126}, array[2]{125, 126}, array[2]{94, 127}, array[2]{124, 127}, array[2]{101, 127}, array[2]{127, 128}, array[2]{95, 128}, array[2]{96, 129}, array[2]{128, 129}, array[2]{126, 129}, array[2]{105, 130}, array[2]{125, 130}, array[2]{130, 131}, array[2]{106, 131}, array[2]{100, 131}, array[2]{126, 131}, array[2]{127, 132}, array[2]{107, 132}, array[2]{102, 133}, array[2]{129, 133}, array[2]{131, 133}, array[2]{128, 134}, array[2]{132, 134}, array[2]{103, 134}, array[2]{108, 134}, array[2]{129, 135}, array[2]{134, 135}, array[2]{104, 135}, array[2]{110, 136}, array[2]{124, 136}, array[2]{111, 136}, array[2]{109, 137}, array[2]{135, 137}, array[2]{133, 137}, array[2]{136, 138}, array[2]{112, 138}, array[2]{113, 139}, array[2]{130, 139}, array[2]{138, 139}, array[2]{136, 140}, array[2]{115, 140}, array[2]{139, 141}, array[2]{114, 141}, array[2]{131, 141}, array[2]{116, 142}, array[2]{132, 142}, array[2]{140, 142}, array[2]{142, 143}, array[2]{134, 143}, array[2]{117, 143}, array[2]{120, 144}, array[2]{138, 144}, array[2]{118, 144}, array[2]{140, 144}, array[2]{144, 145}, array[2]{119, 145}, array[2]{139, 145}, array[2]{121, 146}, array[2]{145, 146}, array[2]{141, 146}, array[2]{142, 147}, array[2]{122, 147}, array[2]{144, 147}, array[2]{147, 148}, array[2]{143, 148}, array[2]{123, 148}, array[2]{90, 149}, array[2]{137, 149}, array[2]{148, 149}, array[2]{146, 149} }

#declare FaceArrays = array[252]{ array[6]{2, 1, 0, 3, 4, 5}, array[4]{6, 1, 2, 7}, array[4]{7, 2, 5, 9}, array[4]{8, 3, 4, 10}, array[4]{10, 4, 5, 11}, array[4]{11, 5, 9, 13}, array[6]{6, 1, 0, 12, 14, 15}, array[4]{15, 6, 7, 17}, array[6]{8, 3, 0, 12, 16, 18}, array[4]{18, 8, 10, 19}, array[4]{16, 12, 14, 20}, array[4]{20, 14, 15, 21}, array[4]{21, 15, 17, 22}, array[4]{20, 16, 18, 23}, array[4]{23, 18, 19, 24}, array[6]{13, 9, 7, 17, 22, 25}, array[6]{13, 11, 10, 19, 24, 25}, array[6]{22, 21, 20, 23, 24, 25}, array[4]{26, 1, 2, 27}, array[4]{27, 2, 5, 29}, array[4]{28, 3, 4, 30}, array[4]{30, 4, 5, 31}, array[4]{26, 1, 6, 32}, array[4]{27, 2, 7, 33}, array[4]{32, 6, 7, 33}, array[4]{32, 26, 27, 33}, array[4]{29, 5, 9, 34}, array[4]{33, 27, 29, 34}, array[4]{33, 7, 9, 34}, array[4]{28, 3, 8, 35}, array[4]{35, 8, 10, 36}, array[4]{30, 4, 10, 36}, array[4]{35, 28, 30, 36}, array[4]{36, 30, 31, 37}, array[4]{31, 5, 11, 37}, array[4]{36, 10, 11, 37}, array[4]{34, 9, 13, 38}, array[4]{37, 11, 13, 39}, array[4]{32, 6, 15, 41}, array[4]{33, 7, 17, 42}, array[4]{41, 32, 33, 42}, array[4]{41, 15, 17, 42}, array[4]{35, 8, 18, 43}, array[4]{43, 35, 36, 44}, array[4]{36, 10, 19, 44}, array[4]{43, 18, 19, 44}, array[4]{40, 12, 14, 45}, array[4]{45, 14, 15, 46}, array[4]{40, 12, 16, 47}, array[4]{42, 17, 22, 48}, array[4]{47, 16, 18, 49}, array[4]{38, 13, 25, 50}, array[6]{38, 34, 33, 42, 48, 50}, array[4]{48, 22, 25, 50}, array[4]{44, 19, 24, 51}, array[4]{39, 13, 25, 52}, array[6]{39, 37, 36, 44, 51, 52}, array[4]{51, 24, 25, 52}, array[4]{47, 40, 45, 53}, array[4]{45, 14, 20, 53}, array[4]{47, 16, 20, 53}, array[4]{46, 15, 21, 54}, array[4]{53, 20, 21, 54}, array[4]{53, 45, 46, 54}, array[4]{54, 21, 22, 55}, array[4]{53, 20, 23, 56}, array[4]{53, 47, 49, 56}, array[4]{49, 18, 23, 56}, array[4]{56, 23, 24, 57}, array[4]{55, 22, 25, 58}, array[6]{55, 54, 53, 56, 57, 58}, array[4]{57, 24, 25, 58}, array[4]{31, 5, 29, 60}, array[4]{60, 29, 34, 61}, array[4]{60, 31, 37, 62}, array[4]{62, 37, 39, 63}, array[4]{39, 13, 38, 63}, array[4]{62, 60, 61, 63}, array[4]{61, 34, 38, 63}, array[4]{46, 15, 41, 64}, array[4]{64, 41, 42, 65}, array[4]{49, 18, 43, 66}, array[4]{66, 43, 44, 67}, array[4]{63, 39, 52, 68}, array[4]{63, 38, 50, 68}, array[4]{52, 25, 50, 68}, array[4]{64, 46, 54, 69}, array[4]{55, 22, 48, 70}, array[4]{69, 54, 55, 70}, array[4]{69, 64, 65, 70}, array[4]{65, 42, 48, 70}, array[4]{66, 49, 56, 71}, array[4]{58, 25, 50, 72}, array[4]{70, 48, 50, 72}, array[4]{70, 55, 58, 72}, array[4]{57, 24, 51, 73}, array[4]{71, 56, 57, 73}, array[4]{71, 66, 67, 73}, array[4]{67, 44, 51, 73}, array[4]{73, 57, 58, 74}, array[4]{73, 51, 52, 74}, array[4]{58, 25, 52, 74}, array[6]{26, 1, 0, 59, 75, 76}, array[4]{76, 26, 27, 78}, array[6]{28, 3, 0, 59, 77, 79}, array[4]{79, 28, 30, 80}, array[4]{76, 26, 32, 82}, array[4]{82, 32, 33, 83}, array[4]{78, 27, 33, 83}, array[4]{82, 76, 78, 83}, array[4]{79, 28, 35, 84}, array[4]{84, 79, 80, 85}, array[4]{84, 35, 36, 85}, array[4]{80, 30, 36, 85}, array[6]{40, 12, 0, 59, 81, 86}, array[4]{86, 40, 45, 87}, array[4]{86, 40, 47, 88}, array[4]{88, 47, 53, 89}, array[4]{87, 45, 53, 89}, array[4]{88, 86, 87, 89}, array[4]{74, 52, 68, 90}, array[4]{72, 50, 68, 90}, array[4]{74, 58, 72, 90}, array[4]{77, 59, 75, 91}, array[4]{91, 75, 76, 92}, array[4]{92, 76, 78, 93}, array[4]{91, 77, 79, 94}, array[4]{94, 79, 80, 95}, array[6]{60, 29, 27, 78, 93, 96}, array[6]{60, 31, 30, 80, 95, 96}, array[6]{93, 92, 91, 94, 95, 96}, array[4]{81, 59, 75, 97}, array[4]{97, 75, 76, 98}, array[4]{81, 59, 77, 99}, array[4]{93, 78, 83, 100}, array[4]{99, 77, 79, 101}, array[4]{96, 60, 61, 102}, array[6]{61, 34, 33, 83, 100, 102}, array[4]{100, 93, 96, 102}, array[4]{95, 80, 85, 103}, array[4]{103, 95, 96, 104}, array[6]{62, 37, 36, 85, 103, 104}, array[4]{96, 60, 62, 104}, array[4]{98, 76, 82, 105}, array[4]{105, 82, 83, 106}, array[4]{101, 79, 84, 107}, array[4]{107, 84, 85, 108}, array[4]{104, 96, 102, 109}, array[4]{104, 62, 63, 109}, array[4]{102, 61, 63, 109}, array[4]{97, 81, 86, 110}, array[4]{99, 81, 86, 111}, array[4]{110, 86, 87, 112}, array[6]{64, 46, 45, 87, 112, 113}, array[6]{64, 41, 32, 82, 105, 113}, array[6]{105, 98, 97, 110, 112, 113}, array[4]{113, 64, 65, 114}, array[4]{113, 105, 106, 114}, array[6]{65, 42, 33, 83, 106, 114}, array[4]{111, 86, 88, 115}, array[6]{66, 49, 47, 88, 115, 116}, array[6]{107, 101, 99, 111, 115, 116}, array[6]{66, 43, 35, 84, 107, 116}, array[4]{116, 66, 67, 117}, array[4]{116, 107, 108, 117}, array[6]{67, 44, 36, 85, 108, 117}, array[4]{112, 87, 89, 118}, array[4]{118, 112, 113, 119}, array[4]{113, 64, 69, 119}, array[6]{69, 54, 53, 89, 118, 119}, array[4]{115, 88, 89, 120}, array[4]{114, 65, 70, 121}, array[4]{119, 113, 114, 121}, array[4]{119, 69, 70, 121}, array[4]{116, 66, 71, 122}, array[4]{120, 115, 116, 122}, array[6]{71, 56, 53, 89, 120, 122}, array[4]{117, 67, 73, 123}, array[4]{122, 116, 117, 123}, array[4]{122, 71, 73, 123}, array[4]{99, 77, 91, 124}, array[4]{99, 81, 97, 124}, array[4]{97, 75, 91, 124}, array[4]{124, 97, 98, 125}, array[4]{98, 76, 92, 125}, array[4]{124, 91, 92, 125}, array[4]{125, 92, 93, 126}, array[4]{124, 91, 94, 127}, array[4]{124, 99, 101, 127}, array[4]{101, 79, 94, 127}, array[4]{127, 94, 95, 128}, array[4]{128, 95, 96, 129}, array[6]{126, 125, 124, 127, 128, 129}, array[4]{126, 93, 96, 129}, array[4]{125, 98, 105, 130}, array[4]{130, 105, 106, 131}, array[4]{106, 83, 100, 131}, array[4]{130, 125, 126, 131}, array[4]{126, 93, 100, 131}, array[4]{127, 101, 107, 132}, array[4]{129, 96, 102, 133}, array[4]{131, 100, 102, 133}, array[4]{131, 126, 129, 133}, array[4]{132, 127, 128, 134}, array[4]{128, 95, 103, 134}, array[4]{132, 107, 108, 134}, array[4]{108, 85, 103, 134}, array[4]{134, 128, 129, 135}, array[4]{129, 96, 104, 135}, array[4]{134, 103, 104, 135}, array[4]{124, 97, 110, 136}, array[4]{111, 86, 110, 136}, array[4]{124, 99, 111, 136}, array[4]{135, 104, 109, 137}, array[4]{133, 102, 109, 137}, array[4]{135, 129, 133, 137}, array[4]{136, 110, 112, 138}, array[4]{130, 105, 113, 139}, array[6]{130, 125, 124, 136, 138, 139}, array[4]{138, 112, 113, 139}, array[4]{136, 111, 115, 140}, array[4]{139, 113, 114, 141}, array[4]{139, 130, 131, 141}, array[4]{131, 106, 114, 141}, array[4]{132, 107, 116, 142}, array[6]{132, 127, 124, 136, 140, 142}, array[4]{140, 115, 116, 142}, array[4]{142, 132, 134, 143}, array[4]{142, 116, 117, 143}, array[4]{134, 108, 117, 143}, array[4]{138, 112, 118, 144}, array[4]{120, 89, 118, 144}, array[4]{140, 115, 120, 144}, array[4]{140, 136, 138, 144}, array[4]{144, 118, 119, 145}, array[4]{144, 138, 139, 145}, array[4]{139, 113, 119, 145}, array[4]{145, 119, 121, 146}, array[4]{145, 139, 141, 146}, array[4]{141, 114, 121, 146}, array[4]{142, 116, 122, 147}, array[4]{144, 140, 142, 147}, array[4]{144, 120, 122, 147}, array[4]{147, 142, 143, 148}, array[4]{143, 117, 123, 148}, array[4]{147, 122, 123, 148}, array[6]{90, 68, 63, 109, 137, 149}, array[6]{90, 74, 73, 123, 148, 149}, array[6]{137, 135, 134, 143, 148, 149}, array[6]{90, 72, 70, 121, 146, 149}, array[6]{137, 133, 131, 141, 146, 149}, array[6]{146, 145, 144, 147, 148, 149} }

#declare FaceTypes = array[252]{ 0, 1, 2, 1, 2, 1, 0, 2, 0, 2, 1, 2, 1, 2, 1, 0, 0, 0, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, 2, 3, 3, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 1, 3, 2, 2, 0, 2, 3, 2, 0, 2, 1, 1, 1, 1, 2, 2, 3, 2, 2, 1, 3, 2, 0, 2, 1, 3, 3, 1, 1, 1, 1, 1, 3, 1, 3, 2, 2, 1, 3, 1, 1, 1, 1, 3, 1, 2, 2, 1, 1, 1, 1, 2, 2, 1, 0, 2, 0, 2, 2, 2, 2, 1, 2, 1, 2, 2, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 0, 0, 0, 1, 2, 1, 3, 2, 2, 0, 2, 3, 2, 0, 2, 1, 3, 1, 3, 1, 2, 2, 2, 2, 1, 0, 0, 0, 2, 2, 0, 1, 0, 0, 0, 2, 2, 0, 3, 2, 2, 0, 3, 2, 1, 2, 2, 2, 0, 2, 1, 2, 1, 1, 1, 2, 1, 2, 3, 2, 2, 1, 3, 2, 0, 2, 3, 1, 1, 1, 1, 3, 1, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 3, 2, 0, 2, 3, 1, 2, 2, 2, 0, 2, 2, 1, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0 }

/////////////////////////////////////////////////////////////////////////////////////////////////

#macro SelectionOfCellsUnion(Faces, EdgesByCount, VerticesByCount)

    union{

        // TRANSPARENT VERTICES AND EDGES
        merge{
            #local Vertices = VerticesByCount[0];
            union{
                #for( i, 0, dimension_size(Vertices, 1)-1 )
                    #local VertexIndex = Vertices[i];
                    #local Rank = VertexRanks[VertexIndex];
                    #local Rad = RankToVertexRad(Rank);
                    sphere{ VertexPoints[VertexIndex]*Factor, Rad 
                        #if(VertexRankParities[VertexIndex])
                            pigment{color rgbt TransparentDarkVertexColor}
                        #else
                            pigment{color rgbt TransparentLightVertexColor}
                        #end
                    }
                #end
            }

            #local Edges = EdgesByCount[0];
            #local EdgeColor = EdgeColorsByCount[0];
            union{
                #for( i, 0, dimension_size(Edges, 1)-1 )
                    #local EdgeIndex = Edges[i];
                    #local EdgeArray = EdgeArrays[EdgeIndex];
                    #local VertexIndex1 = EdgeArray[0];
                    #local VertexIndex2 = EdgeArray[1];
                    #local Point1 = VertexPoints[VertexIndex1]*Factor;
                    #local Point2 = VertexPoints[VertexIndex2]*Factor;
                    #local Rank1 = VertexRanks[VertexIndex1];
                    #local Rank2 = VertexRanks[VertexIndex2];
                    #local Rad1 = RankToEdgeRad(Rank1);
                    #local Rad2 = RankToEdgeRad(Rank2);
                    cone{ Point1, Rad1, Point2, Rad2 }
                #end
                pigment{color rgbt EdgeColor}
            }
        }

        // SOLID VERTICES
        #local Vertices = VerticesByCount[1];
        union{
            #for( i, 0, dimension_size(Vertices, 1)-1 )
                #local VertexIndex = Vertices[i];
                #local Rank = VertexRanks[VertexIndex];
                #local Rad = RankToVertexRad(Rank);
                sphere{ VertexPoints[VertexIndex]*Factor, Rad 
                    #if(VertexRankParities[VertexIndex])
                        pigment{color rgbt DarkVertexColor}
                    #else
                        pigment{color rgbt LightVertexColor}
                    #end
                }
            #end
        }

        // SOLID EDGES
        #for( Count, 1, dimension_size(EdgesByCount, 1)-1 )
            #local Edges = EdgesByCount[Count];
            #local EdgeColor = EdgeColorsByCount[Count];
            union{
                #for( i, 0, dimension_size(Edges, 1)-1 )
                    #local EdgeIndex = Edges[i];
                    #local EdgeArray = EdgeArrays[EdgeIndex];
                    #local VertexIndex1 = EdgeArray[0];
                    #local VertexIndex2 = EdgeArray[1];
                    #local Point1 = VertexPoints[VertexIndex1]*Factor;
                    #local Point2 = VertexPoints[VertexIndex2]*Factor;
                    #local Rank1 = VertexRanks[VertexIndex1];
                    #local Rank2 = VertexRanks[VertexIndex2];
                    #local Rad1 = RankToEdgeRad(Rank1);
                    #local Rad2 = RankToEdgeRad(Rank2);
                    cone{ Point1, Rad1, Point2, Rad2 }
                #end
                pigment{color rgbt EdgeColor}
            }
        #end

        // FACES
        #for( i, 0, dimension_size(Faces, 1)-1 )
            #local FaceIndex = Faces[i];
            #local FaceType = FaceTypes[FaceIndex];
            #local FaceColor = FaceColorsByType[FaceType];
            #local FaceArray = FaceArrays[FaceIndex];
            #local LenOfFaceArray = dimension_size(FaceArray, 1);
            polygon{ LenOfFaceArray,
                #for(VertexIndexInFace, 0, LenOfFaceArray-1)
                    #local VertexIndexInPolytope = FaceArray[VertexIndexInFace];
                    VertexPoints[VertexIndexInPolytope]*Factor
                #end
                pigment{color rgbt FaceColor}
            }
        #end

        
        Rotate()
    }

#end

