#include "base.h"
#include "cuerpo.h"

class Regulador{
private:
	Base base;
	Cuerpo body;

public:
	Regulador();
	void draw(Modo mode, float velocidad, float rotacion, float inc);
};