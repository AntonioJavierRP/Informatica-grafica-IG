#include "cubo.h"


Cubo::Cubo(){
	float size = 1.0;
	Vertices.resize(8);
	Vertices[0] = _vertex3f(-size/2.0, size/2.0, size/2.0);		// Front side, left, up(FLU).
	Vertices[1] = _vertex3f(size/2.0, size/2.0, size/2.0);		// FRU
	Vertices[2] = _vertex3f(-size/2.0, size/2.0, -size/2.0);	// FLD
	Vertices[3] = _vertex3f(size/2.0, size/2.0, -size/2.0);		// FRD
	Vertices[4] = _vertex3f(-size/2.0, -size/2.0, size/2.0);	// BLU
	Vertices[5] = _vertex3f(size/2.0, -size/2.0, size/2.0);		// BRU
	Vertices[6] = _vertex3f(-size/2.0, -size/2.0, -size/2.0);	// BLD
	Vertices[7] = _vertex3f(size/2.0, -size/2.0, -size/2.0);	// BRD

	Triangles.resize(12);
	Triangles[0]= _vertex3i(0,1,2);
	Triangles[1]= _vertex3i(1,2,3);
	Triangles[2]= _vertex3i(0,1,4);
	Triangles[3]= _vertex3i(1,4,5);
	Triangles[4]= _vertex3i(4,6,5);
	Triangles[5]= _vertex3i(6,5,7);
	Triangles[6]= _vertex3i(0,4,6);
	Triangles[7]= _vertex3i(0,2,6);
	Triangles[8]= _vertex3i(2,6,3);
	Triangles[9]= _vertex3i(3,6,7);
	Triangles[10]= _vertex3i(3,7,5);
	Triangles[11]= _vertex3i(3,1,5);


}

/*
Cubo::Cubo(){
	*this = Cubo(1.0);
}
*/