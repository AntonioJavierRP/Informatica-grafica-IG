#include <iostream>
#include "vertex.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>

using namespace std;

class Objeto3D{
public:
	vector<_vertex3f> Vertices;
	Objeto3D(){};
	void draw_points();
};

class O3D: public Objeto3D{
public:
	vector<_vertex3i> Triangles;
	vector<pair<_vertex3f*, _vertex3f*> > Edges;
	O3D(){};
	void draw_edges();
	void draw_solid();
	void draw_solid_chess();
};

class Cubo: public O3D{
public:
	Cubo();
	Cubo(float size);				// Size ==> Tamaño del lado
};

class Tetraedro: public O3D{
public:
	Tetraedro();
	Tetraedro(float size);			// Size ==> Tamaño del lado
};

