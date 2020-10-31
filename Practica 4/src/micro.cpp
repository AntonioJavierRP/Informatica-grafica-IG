#include "micro.h"
Micro::Micro(){}

void Micro::draw(Modo mode){
	glPushMatrix();

	glTranslatef(0,7.5,0);
	glScalef(1,15,1);
	c.draw(mode);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,18,0);
	glScalef(6,6,6);
	e.draw(mode);

	glPopMatrix();
}