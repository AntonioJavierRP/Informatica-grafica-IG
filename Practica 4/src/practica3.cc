//**************************************************************************
// Práctica 1
//
// Domingo Martin Perandres 2013-2016
//
// Nombre: Antonio Javier Rodríguez Pérez		DNI: 50643240T
// 
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "vertex.h"
#include "cubo.h"
#include "tetraedro.h"
#include "poligonoR.h"
#include "ply_reader.h"
#include "revolucion.h"
#include "cilindro.h"
#include "vaso.h"
#include "vaso_inv.h"
#include "cono.h"
#include "tubo.h"
#include "piramide.h"
#include "esfera.h"
#include "micro.h"
#include "partearriba.h"
#include "bloque.h"
#include "partemedia.h"
#include "cuerpo.h"
#include "base.h"
#include "regulador.h"


enum Figura { cubo, tetraedro, poligonoR, ply, revolucionar, cilindro, cono, tubo, vaso, vaso_invertido, piramide, esfera, micro, partearriba, bloque, partemedia, cuerpo, base, regulador};
// tamaño de los ejes
const int AXIS_SIZE=5000;

Modo mode;
Figura figure;

Cubo cube;
Tetraedro tetrahedron(1);
PoligonoR polygon(5);
PlyReader aux_ply("perfil.ply");
PlyReader objeto_ply("beethoven.ply");
Cilindro cilinder;
Vaso glass;
VasoInvertido inv_glass;
Cono cone;
Tubo tube;
Piramide pyramid;
Revolucion rev(aux_ply.Vertices);
Esfera sphere;
Micro m;
ParteArriba p;
Bloque mitad;
ParteMedia middle;
Cuerpo body;
Base bottom;
Regulador regulador_watt;
float rotation = 0, incremento = 1.2;		// En grados.(Rotacion brazo)
float velocidad = 0;
float inc_velocidad = 0.3;		// Velocidad e incremento del cilindro de la base.
float velocidad_minima = 0.5, velocidad_maxima = 10;
float bajada_minima = 0, subida_maxima = 32;







// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=1000,UI_window_height=1000;

//**************************************************************************
//
//***************************************************************************

void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects()
{
	glPointSize(6);
	glLineWidth(2);
	switch(figure){
		// Dibujar cubo
		case cubo:
			cube.draw(mode);
			break;
		// Dibujar tetraedro
		case tetraedro:
			tetrahedron.draw(mode);
			break;
		// Dibujar poligonoR
		case poligonoR:
			polygon.draw(mode);
			break;
		// Dibujar archivo ply	
		case ply:
			objeto_ply.draw(mode);
			break;
		// Dibujar cilindro
		case cilindro:
			cilinder.draw(mode);
			break;
		// Dibujar tubo
		case tubo:
			tube.draw(mode);
			break;
		// Dibujar cono
		case cono:
			cone.draw(mode);
			break;
		// Dibujar vaso
		case vaso:
			glass.draw(mode);
			break;
		// Dibujar vaso invertido
		case vaso_invertido:
			inv_glass.draw(mode);
			break;
		// Dibujar perfil revolucionado
		case revolucionar:
			rev.draw(mode);
			break;

		// Dibujar piramide
		case piramide:
			pyramid.draw(mode);
			break;

		// Dibujar esfera
		case esfera:
			sphere.draw(mode);
			break;


		case micro:
			m.draw(mode);
			break;
		case partearriba:
			p.draw(mode, rotation);
			break;
		case bloque:
			mitad.draw(mode);
			break;
		case partemedia:
			middle.draw(mode,rotation);
			break;
		case cuerpo:
			body.draw(mode,rotation);
			break;
		case base:
			bottom.draw(mode, velocidad);
			break;
		case regulador:
			regulador_watt.draw(mode, velocidad, rotation, inc_velocidad);
			break;
		default:
			cout<<"Pulse una tecla para cambiar de modo"<<endl;
			break;
	}


	glEnd();
}


//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{

clear_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y){
	unsigned char tecla = toupper(Tecla1);
	switch(tecla){
		case 'Q':
			exit(1);
			break;
		case 'P':
			mode = puntos;
			break;
		case 'A':
			mode = aristas;
			break;
		case 'S':
		  mode = solido;
			break;
		case 'C':
		  mode = ajedrez;
			break;
		case 'T':
			mode = todo;
			break;
		case '1':
			figure = micro;
			break;
		case '2':
			figure = partearriba;
			break;
		case '3':
			figure = bloque;
			break;
		case '4':
			figure = partemedia;
			break;
		case '5':
			figure = cuerpo;
			break;
		case '6':
			figure = base;
			break;
		case '7':
			figure = regulador;
			break;
		case 'K':
			rotation-=incremento;
			if(rotation <= bajada_minima)
				rotation = bajada_minima;
			inc_velocidad -= 0.3;
			if(inc_velocidad <= velocidad_minima)
				inc_velocidad = velocidad_minima;
			break;
		case 'L':
			rotation+=incremento;
			if(rotation >= subida_maxima)
				rotation = subida_maxima;
			inc_velocidad += 0.3;
			if(inc_velocidad >= velocidad_maxima)
				inc_velocidad = velocidad_maxima;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{

switch (Tecla1){
	case GLUT_KEY_F1: figure = tetraedro;break;		// Tetraedro
	case GLUT_KEY_F2: figure = cubo;break;		// Cubo
	case GLUT_KEY_F3: figure = ply;break;		// Leer archivo ply
	case GLUT_KEY_F4: figure = revolucionar;break;		// Leer archivo ply
	case GLUT_KEY_F5: figure = cilindro; break;	// Polígono
	case GLUT_KEY_F6: figure = cono; break;
	case GLUT_KEY_F7: figure = tubo; break;
	case GLUT_KEY_F8: figure = vaso; break;
	case GLUT_KEY_F9: figure = vaso_invertido; break;
	case GLUT_KEY_F10: figure = piramide; break;
	case GLUT_KEY_F11: figure = esfera; break;
	case GLUT_KEY_F12: figure = poligonoR; break;
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}
glutPostRedisplay();
}


// Para animar.
void idle(){
	velocidad+=inc_velocidad;
	/*
	if(rotation > 31)
		rotation = 32;
	if(rotation < 0)
		rotation = 0;
		*/


	glutPostRedisplay();
}




//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Window_width=0.5;
Window_height=0.5;
Front_plane=1;
Back_plane=1000;

// se inicia la posicion del observador, en el eje z
Observer_distance=2*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color
 //para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
//
change_projection();
//
glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("Práctica 3");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

glutIdleFunc(idle);		// Animación

// funcion de inicialización
initialize();



// inicio del bucle de eventos
glutMainLoop();
return 0;
}
