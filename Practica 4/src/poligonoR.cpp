#include "poligonoR.h"


void PoligonoR::draw_polygon(){
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1,0,1);
    int vertice1, vertice2, vertice3;
	for(int i = 0; i < Triangles.size(); i++){
		vertice1 = Triangles[i].x;
		vertice2 = Triangles[i].y;
		vertice3 = Triangles[i].z;
		glVertex3fv((GLfloat*) & Vertices[vertice1]);
		glVertex3fv((GLfloat*) & Vertices[vertice2]);
		glVertex3fv((GLfloat*) & Vertices[vertice3]);
	}
}

PoligonoR::PoligonoR(unsigned int lados){
    float angulo_b = 360.0/(float)lados;
    float angulo = (angulo_b*PI)/180;
    angulo_b = angulo;
    float c1,c2;

	Vertices.resize(lados+1);
    Vertices[0] = _vertex3f(0,0,0);
    for(int i = 1 ; i <= lados; i++){
        c1 = cos(angulo);
        c2 = sin(angulo);
        Vertices[i] = _vertex3f(c1, 0, c2);
        angulo += angulo_b;

    }

    Triangles.resize(lados);
    for(int i = 0 ; i < lados; i++){
        Triangles[i] = _vertex3i(1,i,i+1);
    }

}
