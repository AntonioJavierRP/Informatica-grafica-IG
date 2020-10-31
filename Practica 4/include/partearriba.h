#ifndef _PARTEARRIBA_H_
#define _PARTEARRIBA_H_
#include "micro.h"
#include "cubo.h"

class ParteArriba{
private:
	Micro m;
	Cubo c;
public:
	ParteArriba();
	void draw(Modo mode, float rotacion);
};


#endif