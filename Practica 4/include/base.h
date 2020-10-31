#ifndef _BASE_H_
#define _BASE_H_

#include "cubo.h"
#include "cilindro.h"

class Base{
private:
	Cubo cubo;
	Cilindro c;

public:
	Base();
	void draw(Modo mode,  float velocidad);
};

#endif