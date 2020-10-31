#ifndef _CUERPO_H_
#define _CUERPO_H_

#include "partemedia.h"
#include "partearriba.h"

class Cuerpo{
private:
	ParteMedia mitad;
	ParteArriba arriba;


public:
	Cuerpo();
	void draw(Modo mode, float rotacion);
};

#endif