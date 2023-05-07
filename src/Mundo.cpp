#pragma warning( disable : 26451 )
/* Desbordamiento aritmético: uso del operador "operator" en un valor de byte de tamaño-a y, a continuación,
conversión del resultado en un valor de byte de tamaño-b.
Convierta el valor en el tipo más amplio antes de llamar al operador "operator"para evitar el desbordamiento
*/
#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
/*
* void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
*/

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_obs, y_obs, z_obs,    // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);        // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
		

	chessboard.dibuja();
	chessboard.setColor(119, 79, 56,
	                   230, 181, 126); //tablero de color café

	
	piezas.dibujar();
}

void Mundo::mueve()
{
	if (piezaSeleccionada && click)
	{
		piezas.moverPiezaHasta(posInicialx, posInicialy, ratonx, ratony);
	}

//piezas.mover(ratonx, ratony);
	//ratonx = -1;
	//ratony = -1;

}

void Mundo::inicializa()
{
	x_ojo = 4; y_ojo = 4; z_ojo = 16;
	x_obs = 4; y_obs = 4; z_obs = 0;

	ratonx = -1;
	ratony = -1;

	//piezaSeleccionada = false;
	click = false;

	
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
	}
	
	
}

void Mundo::raton(int boton, int estado, int _x, int _y)
{
	if (boton == GLUT_LEFT_BUTTON && estado == GLUT_DOWN)
	{	
		//comprueba si el click del raton está fuera del tablero
		if ((_x < 194 || _x > 594) || (_y < 94 || _y > 494))
		{
			click = false;
			ratonx = ratony = -1; //para posiciones fuera del tablero
		}
		else
		/*Se obtienen coordenadas relativas a la pantalla
		Cursor_x y Cursor_y representan las posiciones
		tamaño de casilla (194, 94)
		                  (244, 144)*/
		for (int i = 0; i < 8; i++)
		{
			if (_x > (i + 2) * 50 + 94 && _x < (i + 3) * 50 + 94)
			{
				ratonx = i;
				for (int j = 0; j < 8; j++)
				{
					if (_y > j * 50 + 94 && _y < (j + 1) * 50 + 94)
						ratony = 7 - j;
				}
				click = true;
			}
		}

		Pieza* p = piezas.elegirPieza(ratonx, ratony);
		if (p == nullptr)
		{
			cout << "casilla vacia" << endl;
			piezaSeleccionada = false;
			if (piezaSeleccionada)
			{
				posFinalx = ratonx;
				posFinaly = ratony;
			}

		}
		else
		{
			posInicialx = ratonx;
			posInicialy = ratony;
			cout << "casilla con pieza" << endl;
			piezaSeleccionada = true;
		}

		//cout << _x << "," << _y << endl;
		cout << ratonx << "," << ratony << endl;
		cout << "posGuardada INICIAL: ";
		cout << posInicialx << "," << posInicialy << endl;
		cout << "posicion FINAL: ";
		cout << posFinalx << "," << posFinaly << endl;
		//cout << click << endl; //true si hace click dentro del tablero
	}


		//AUUN POR COMPROBAR POSIBLES INTERACCIONES CON OTOS BOTONES DEL RATON

}

Mundo::~Mundo()
{
	piezas.destruirContenido();
}

void Mundo::tecla(unsigned char key)
{

}
