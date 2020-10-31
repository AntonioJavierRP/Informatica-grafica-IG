#ifndef _MICRO_H_
#define _MICRO_H_
#include "cilindro.h"
#include "esfera.h"


class Micro{
	
private:
	 Cilindro c;
	 Esfera e;
public:
	Micro();
	void draw(Modo mode);

};

#endif