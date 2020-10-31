#ifndef _REVOLUCION_H_
#define _REVOLUCION_H_
#include "O3D.h"

class Revolucion: public O3D{
public:
	Revolucion();
	Revolucion(vector <_vertex3f> puntos_ply);
	void Revolucionar(vector <_vertex3f> perfil, int nlados);
	void RevolucionarSeccion(vector <_vertex3f> perfil, int nlados, float alfa, float beta);

};

#endif
