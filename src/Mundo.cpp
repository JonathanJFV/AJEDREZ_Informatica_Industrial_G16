#pragma warning( disable : 26451 )
/* Desbordamiento aritm�tico: uso del operador "operator" en un valor de byte de tama�o-a y, a continuaci�n,
conversi�n del resultado en un valor de byte de tama�o-b.
Convierta el valor en el tipo m�s amplio antes de llamar al operador "operator"para evitar el desbordamiento
*/
#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_obs, y_obs, z_obs,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	
	/*
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex3f(-5.0f,0,-5.0f);
		glVertex3f(-5.0f,0,5.0f);
		glColor3ub(255,255,0);
		glVertex3f(5.0f,0,5.0f);	
		glVertex3f(5.0f,0,-5.0f);
	glEnd();
	glEnable(GL_LIGHTING);
	*/

	chessboard.dibuja();
	chessboard.setColor(119, 79, 56,
	                   230, 181, 126); //tablero de color caf�

}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	x_ojo=4;
	y_ojo=4;
	z_ojo=16;

	x_obs = 4;
	y_obs = 4;
	z_obs = 0;
}

void Mundo::tecla(unsigned char key)
{

}
