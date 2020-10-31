#ifndef _O3D_H_
#define _O3D_H_

#include "objeto3D.h"
const double PI = 3.141516;
enum Modo { puntos, aristas, solido, ajedrez, todo };

class O3D: public Objeto3D {
public:
	vector<_vertex3i> Triangles;
	O3D(){};
	void draw_edges();
	void draw_solid();
	void draw_solid_chess();
	void draw(Modo mode);
};

#endif
