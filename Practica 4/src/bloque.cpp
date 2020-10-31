#include "bloque.h"

Bloque::Bloque(){}

void Bloque::draw(Modo mode){
	glPushMatrix();

	glScalef(5,3,3);
	centro.draw(mode);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-1.5, -6.5, 0);
	glScalef(0.7, 12, 0.7);
	c.draw(mode);

	glPopMatrix();
}