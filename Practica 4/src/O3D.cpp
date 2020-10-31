#include "O3D.h"


void O3D::draw_edges(){
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glBegin(GL_TRIANGLES);
	glColor3f(1,0,1);			// Aristas en rosa.
	int vertice1, vertice2, vertice3;
	for(int i = 0; i < Triangles.size(); i++){
		vertice1 = Triangles[i].x;
		vertice2 = Triangles[i].y;
		vertice3 = Triangles[i].z;
		glVertex3fv((GLfloat*) & Vertices[vertice1]);
		glVertex3fv((GLfloat*) & Vertices[vertice2]);
		glVertex3fv((GLfloat*) & Vertices[vertice3]);
	}
	glEnd();
}

void O3D::draw_solid(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0,0,1);		// Caras en azul
	glBegin(GL_TRIANGLES);
	int vertice1, vertice2, vertice3;
	for(int i = 0; i < Triangles.size(); i++){
		vertice1 = Triangles[i].x;
		vertice2 = Triangles[i].y;
		vertice3 = Triangles[i].z;
		glVertex3fv((GLfloat*) & Vertices[vertice1]);
		glVertex3fv((GLfloat*) & Vertices[vertice2]);
		glVertex3fv((GLfloat*) & Vertices[vertice3]);
	}
	glEnd();
}

void O3D::draw_solid_chess(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);
	int vertice1, vertice2, vertice3;
	for(int i = 0; i < Triangles.size(); i++){
		if(i%2 == 0)
			glColor3f(1,0,0);    		// Rojo
		else
			glColor3f(0,0,0);			// Negro
		vertice1 = Triangles[i].x;
		vertice2 = Triangles[i].y;
		vertice3 = Triangles[i].z;
		glVertex3fv((GLfloat*) & Vertices[vertice1]);
		glVertex3fv((GLfloat*) & Vertices[vertice2]);
		glVertex3fv((GLfloat*) & Vertices[vertice3]);
	}
	glEnd();
}

void O3D::draw(Modo mode){
	switch(mode){
				case puntos:
					this->draw_points();
					break;
				case aristas:
					this->draw_edges();
					break;
				case solido:
					this->draw_solid();
					break;
				case ajedrez:
					this->draw_solid_chess();
					break;
				case todo:
					this->draw_points();
					this->draw_edges();
					this->draw_solid();
					break;
				default:
					break;
			}
}
