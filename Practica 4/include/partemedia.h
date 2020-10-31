#ifndef _PARTEMEDIA_H_
#define _PARTEMEDIA_H_
#include "bloque.h"
#include "cilindro.h"

class ParteMedia{
private:
	Cilindro c;
	Bloque b;
public:
	ParteMedia();
	void draw(Modo mode, float rotacion);
};

#endif