#include "tetraedro.h"


Tetraedro::Tetraedro(float size){
	Vertices.resize(4);
	Vertices[0] = _vertex3f(0, (size*(sqrt(6.0)/3.0))/2.0, 0);			// Punta
	Vertices[1] = _vertex3f(0, -(size*(sqrt(6.0)/3.0))/2.0, (2.0*size)/3.0);
	Vertices[2] = _vertex3f(-size/2.0, -(size*(sqrt(6.0)/3.0))/2.0, -size/3.0);
	Vertices[3] = _vertex3f(size/2.0, -(size*(sqrt(6.0)/3.0))/2.0, -size/3.0);

	Triangles.resize(4);
	Triangles[0]= _vertex3i(0,1,2);
	Triangles[1]= _vertex3i(1,2,3);
	Triangles[2]= _vertex3i(0,1,3);
	Triangles[3]= _vertex3i(0,2,3);
}
