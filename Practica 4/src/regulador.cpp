#include "regulador.h"

Regulador::Regulador(){}

void Regulador::draw(Modo mode,float velocidad, float rotacion, float inc){
	float R = rotacion;
	float V = velocidad;		// Velocidad de giro.
	

	glPushMatrix();

	base.draw(mode,V);

	glPopMatrix();

	glPushMatrix();
	glRotatef(V,0,1,0);
	glTranslatef(0,17,0);
	body.draw(mode, R);

	glPopMatrix();
	
}