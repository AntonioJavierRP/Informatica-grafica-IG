#include "objects3D.h"
#include <iostream>
#include <cmath>

using namespace std;

void Objeto3D::draw_points(){
	glBegin(GL_POINTS);
	for(int i = 0; i < Vertices.size(); i++){
		glVertex3f(Vertices[i].x, Vertices[i].y, Vertices[i].z);
	}
	glEnd();
}

void O3D::draw_edges(){
	glBegin(GL_LINE_STRIP);
	//int vertice1, vertice2, vertice3;
	for(int i = 0; i < Edges.size(); i++){
		glVertex3f(Edges[i].first->x, Edges[i].first->y, Edges[i].first->z);
		//cout<<Edges[i].first->x<<endl;
		glVertex3f(Edges[i].second->x, Edges[i].second->y, Edges[i].second->z);
	}
	glEnd();
}

void O3D::draw_solid(){
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
	glPolygonMode(GL_FRONT, GL_FILL);
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
}

Cubo::Cubo(float size){
	Vertices.resize(8);
	Vertices[0] = _vertex3f(-size/2.0, size/2.0, size/2.0);		// Front side, left, up(FLU).
	Vertices[1] = _vertex3f(size/2.0, size/2.0, size/2.0);		// FRU
	Vertices[2] = _vertex3f(-size/2.0, size/2.0, -size/2.0);	// FLD
	Vertices[3] = _vertex3f(size/2.0, size/2.0, -size/2.0);		// FRD
	Vertices[4] = _vertex3f(-size/2.0, -size/2.0, size/2.0);	// BLU
	Vertices[5] = _vertex3f(size/2.0, -size/2.0, size/2.0);		// BRU
	Vertices[6] = _vertex3f(-size/2.0, -size/2.0, -size/2.0);	// BLD
	Vertices[7] = _vertex3f(size/2.0, -size/2.0, -size/2.0);	// BRD

	Edges.resize(12);
	Edges[0].first = &Vertices[0];
	Edges[1].first = &Vertices[1];
	Edges[2].first = &Vertices[3];
	Edges[3].first = &Vertices[2];
	Edges[4].first = &Vertices[0];
	Edges[5].first = &Vertices[1];
	Edges[6].first = &Vertices[3];
	Edges[7].first = &Vertices[2];
	Edges[8].first = &Vertices[4];
	Edges[9].first = &Vertices[5];
	Edges[10].first = &Vertices[7];
	Edges[11].first = &Vertices[6];
	Edges[0].second = &Vertices[1];
	Edges[1].second = &Vertices[3];
	Edges[2].second = &Vertices[2];
	Edges[3].second = &Vertices[0];
	Edges[4].second = &Vertices[4];
	Edges[5].second = &Vertices[5];
	Edges[6].second = &Vertices[7];
	Edges[7].second = &Vertices[6];
	Edges[8].second = &Vertices[5];
	Edges[9].second = &Vertices[7];
	Edges[10].second = &Vertices[6];
	Edges[11].second = &Vertices[4];

	Triangles.resize(12);
	Triangles[0]= _vertex3i(0,1,2);
	Triangles[1]= _vertex3i(1,2,3);
	Triangles[2]= _vertex3i(0,1,4);
	Triangles[3]= _vertex3i(1,4,5);
	Triangles[4]= _vertex3i(1,5,3);
	Triangles[5]= _vertex3i(3,5,7);
	Triangles[6]= _vertex3i(2,3,6);
	Triangles[7]= _vertex3i(3,6,7);
	Triangles[8]= _vertex3i(0,2,4);
	Triangles[9]= _vertex3i(2,4,6);
	Triangles[10]= _vertex3i(4,5,6);
	Triangles[11]= _vertex3i(5,6,7);


}

Tetraedro::Tetraedro(float size){
	Vertices.resize(4);
	Vertices[0] = _vertex3f(0, (size*(sqrt(6.0)/3.0))/2.0, 0);			// Punta
	Vertices[1] = _vertex3f(0, -(size*(sqrt(6.0)/3.0))/2.0, (2.0*size)/3.0);
	Vertices[2] = _vertex3f(-size/2.0, -(size*(sqrt(6.0)/3.0))/2.0, -size/3.0);
	Vertices[3] = _vertex3f(size/2.0, -(size*(sqrt(6.0)/3.0))/2.0, -size/3.0);

	Edges.resize(6);
	Edges[0].first = &Vertices[0];
	Edges[1].first = &Vertices[0];
	Edges[2].first = &Vertices[1];
	Edges[3].first = &Vertices[1];
	Edges[4].first = &Vertices[0];
	Edges[5].first = &Vertices[2];
	Edges[0].second = &Vertices[1];
	Edges[1].second = &Vertices[2];
	Edges[2].second = &Vertices[2];
	Edges[3].second = &Vertices[3];
	Edges[4].second = &Vertices[3];
	Edges[5].second = &Vertices[3];

	Triangles.resize(4);
	Triangles[0]= _vertex3i(0,1,2);
	Triangles[1]= _vertex3i(1,2,3);
	Triangles[2]= _vertex3i(0,1,3);
	Triangles[3]= _vertex3i(0,2,3);
}