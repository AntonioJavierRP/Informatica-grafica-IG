#include "esfera.h"

Esfera::Esfera(){
	//Vertices.resize(10);
	//Vertices[0] = _vertex3f(0, 0.5, 0);
	Vertices.push_back(_vertex3f(0, 0.5, 0));
	float angulo_b = 360.0/40.0;
    float angulo = (angulo_b*PI)/180;
    angulo_b = angulo;
    //angulo = 0;
    float c1,c2;
    for(int i = 0; i < 19; i++){
    	c1 = cos(angulo)*0.5;
        c2 = sin(angulo)*0.5;
        Vertices.push_back(_vertex3f(c2,c1,0));
        angulo += angulo_b;
    }
    Vertices.push_back(_vertex3f(0, -0.5, 0));


    this->Revolucionar(Vertices, 30);
}
