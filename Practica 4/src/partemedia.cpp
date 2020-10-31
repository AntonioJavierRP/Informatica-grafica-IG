#include "partemedia.h"

ParteMedia::ParteMedia(){}

void ParteMedia::draw(Modo mode, float rotacion){
	float Z = 45;		// Posicion inicial de los brazos de la parte media.

	Z = Z + rotacion;
	
	
	glPushMatrix();

	b.draw(mode);

	glPopMatrix();

	glPushMatrix();

	
	glTranslatef(2,0,0);
	glRotatef(-Z,0,0,1);
	glTranslatef(0,4.5,0);
	glScalef(0.8,9,0.8);
	c.draw(mode);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-2,0,0);
	glRotatef(Z,0,0,1);
	glTranslatef(0,4.5,0);
	glScalef(0.8,9,0.8);
	c.draw(mode);

	glPopMatrix();
}