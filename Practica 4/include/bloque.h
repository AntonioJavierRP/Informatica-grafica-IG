#ifndef _BLOQUE_H_
#define _BLOQUE_H_
#include "cubo.h"

class Bloque{
private:
	Cubo centro;
	Cubo c;
public:
	Bloque();
	void draw(Modo mode);
};

#endif