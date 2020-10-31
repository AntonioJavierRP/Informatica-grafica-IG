#include "partearriba.h"

ParteArriba::ParteArriba(){}

void ParteArriba::draw(Modo mode, float rotacion){
	float Z = 145;			// Z inicializado a la posicion inicial.(90+45).
	Z = Z + rotacion;		// Añadir condiciones para que sea una rotacion dentro de los limites necesarios.

	// Condiciones de rotacion de brazos:
	// Creo que hará falta una variable como atributo de clase para ir almacenando el valor de lo que vamos incrementando o decrementando.

	glPushMatrix();

	glScalef(5,3,3);
	c.draw(mode);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(2.0,0,0);
	glRotatef(-Z,0,0,1);
	m.draw(mode);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-2.0,0,0);
	glRotatef(Z,0,0,1);
	m.draw(mode);

	glPopMatrix();	


}
