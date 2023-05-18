#pragma warning( disable : 26451 )
/* Desbordamiento aritmético: uso del operador "operator" en un valor de byte de tamaño-a y, a continuación,
conversión del resultado en un valor de byte de tamaño-b.
Convierta el valor en el tipo más amplio antes de llamar al operador "operator"para evitar el desbordamiento
*/
#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_obs, y_obs, z_obs,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	chessboard.dibuja();
	chessboard.setColor(119, 79, 56,
	                   230, 181, 126); //tablero de color café

	//piezas.dibujar();
}

void Mundo::mueve()
{
//piezas.mover(ratonx, ratony);
	ratonx = -1;
	ratony = -1;
}

void Mundo::inicializa()
{
	ratonx = -1;
	ratony = -1;
	
	x_ojo=4, y_ojo=4, z_ojo=16;
	x_obs = 4, y_obs = 4, z_obs = 0;
	

	/*
	for (int i = 0;i<8;i++)
	{
		Peon* aux1 = new Peon(Pieza::BLANCO, i, 1);
		piezas.agregar(aux1);
		Peon* aux2 = new Peon(Pieza::NEGRO, i, 6);
		piezas.agregar(aux2);
		if (i == 2 || i == 5)
		{
			Alfil* aux1 = new Alfil(Pieza::BLANCO, i, 0);
			piezas.agregar(aux1);
			Alfil* aux2 = new Alfil(Pieza::NEGRO, i, 7);
			piezas.agregar(aux2);
		}
		if (i == 1 || i == 6)
		{
			Caballo* aux1 = new Caballo(Pieza::BLANCO, i, 0);
			piezas.agregar(aux1);
			Caballo* aux2 = new Caballo(Pieza::NEGRO, i, 7);
			piezas.agregar(aux2);
		}
		if (i == 4)
		{
			Reina * aux1 = new Reina(Pieza::BLANCO, i, 0);
			piezas.agregar(aux1);
			Reina* aux2 = new Reina(Pieza::NEGRO, i, 7);
			piezas.agregar(aux2);
		}


		if (i == 3)
		{
			Rey* aux1 = new Rey(Pieza::BLANCO, i, 0);
			piezas.agregar(aux1);
			Rey* aux2 = new Rey(Pieza::NEGRO, i, 7);
			piezas.agregar(aux2);
		}

		if (i == 0 || i == 7)
		{
			Torre* aux1 = new Torre(Pieza::BLANCO, i, 0);
			piezas.agregar(aux1);
			Torre* aux2 = new Torre(Pieza::NEGRO, i, 7);
			piezas.agregar(aux2);
		}
	}
	
	
	*/
		
	
}

void Mundo::raton(int boton, int estado, int _x, int _y)
{
	if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
	{
		//cout << _x << "," << _y<< endl;

		for (int i = 0; i < 8; i++)
		{
			if (_x > i * 69 + 125 && _x < i * 69 + 125 + 69) {
				ratonx = i;
				for (int j = 0; j < 8; j++)
				{
					if (_y > j * 69 + 25 && _y < j * 69 + 25 + 69)
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
	//piezas.destruirContenido();
}

void Mundo::tecla(unsigned char key)
{

}
