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
