#pragma warning( disable : 26451 )
/* Desbordamiento aritmético: uso del operador "operator" en un valor de byte de tamaño-a y, a continuación,
conversión del resultado en un valor de byte de tamaño-b.
Convierta el valor en el tipo más amplio antes de llamar al operador "operator"para evitar el desbordamiento
*/
#include "Mundo.h"

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

	chessboard.dibuja();
	chessboard.setColor(119, 79, 56,
	                   230, 181, 126); //tablero de color café

	
	piezas.dibujar();
}

void Mundo::mueve()
{
piezas.mover(ratonx, ratony);
	ratonx = -1;
	ratony = -1;
}

void Mundo::inicializa()
{
	ratonx = -1;
	ratony = -1;
	
	x_ojo=4;
	y_ojo=4;
	z_ojo=16;

	x_obs = 4;
	y_obs = 4;
	z_obs = 0;
	
		for (int i = 0;i<8;i++)
	{
		Peon* aux1 = new Peon(Pieza::BLANCO, i, 1);
		piezas.agregar(aux1);
		Peon* aux2 = new Peon(Pieza::NEGRO, i, 6);
		piezas.agregar(aux2);
	}
	
	
}

void Mundo::raton(int boton, int estado, int _x, int _y)
{
	if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
	{
		//cout << _x << "," << _y<< endl;

		for (int i = 0; i < 8; i++)
		{
			if (_x > i * 50 + 194 && _x < (i+1) * 50 + 194 + 69) {
				ratonx = i;
				for (int j = 0; j < 8; j++)
				{
					if (_y > j * 50 + 94 && _y < (j+1) * 50 + 94 + 69)
						ratony = 7 - j;
				}
			}
		}
		cout << _x << "," << _y << endl;
		cout << ratonx << "," << ratonx << endl;

	}
}

Mundo::~Mundo()
{
	piezas.destruirContenido();
}

void Mundo::tecla(unsigned char key)
{

}
