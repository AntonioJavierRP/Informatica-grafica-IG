#include "base.h"

Base::Base(){}

void Base::draw(Modo mode, float velocidad){

	float vel = velocidad;			
	

	glPushMatrix();

	glTranslatef(0,1,0);
	glScalef(18,2,18);
	cubo.draw(mode);

	glPopMatrix();

	glPushMatrix();

	glRotatef(vel,0,1,0);
	glTranslatef(0,17,0);		// En caso de que mida 30 -->(15 + 2).
	glScalef(1.25,30,1.25);
	c.draw(mode);

	glPopMatrix();
}