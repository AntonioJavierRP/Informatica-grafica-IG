#include "cuerpo.h"

Cuerpo::Cuerpo(){}

void Cuerpo::draw(Modo mode, float rotacion){
	float R = rotacion;	 // Rotacion parte media
	if(R>32)
		R = 32;
	if(R<0)
		R = 0;
	float R2 = -(R*1.5);			 // Rotacion parte de arriba

	float altura;		// lo que subira el bloque dependiendo de la posicion de sus brazos.
	altura = rotacion*0.41;



	if(altura>13){
		altura = 13;
	}
	if(altura <0)
		altura = 0;

	glPushMatrix();

	glTranslatef(0,altura,0);		// Lo desplazamos hacia arriba hasta altura.
	mitad.draw(mode, R);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,16,0);
	arriba.draw(mode,R2);

	glPopMatrix();

}