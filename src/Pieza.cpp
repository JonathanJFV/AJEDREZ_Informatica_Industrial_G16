#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza()
{
  tipo = NF;
	Color = NS;
	posx = -1;
	posy = -1;
}

Pieza:: Pieza(TIPO t, COLOR c, int x, int y)
{
  tipo = t;
	Color = c;
	posx = x;
	posy = y;
}

void Pieza::print()
{
}

void Pieza::dibujar()
{
}

bool Pieza::mover(Casilla incio, Casilla final, Tablero& t)
{
	int aux;

	//Se revisa si la casilla está ocupada por una pieza del mismo color que el turno 
	if (t[final] != nullptr && t[final]->getColor() == color) return false;

	//COMPROBACION DE TRAYECTORIA. 
	//LINEAL EN FILAS 
	if (final.fila != inicio.fila && final.columna == inicio.columna)
	{
		aux = (final.fila - inicio.fila) / abs(final.fila - inicio.fila);
		while (abs(final.fila - inicio.fila) > 1)
		{
			inicio.fila = inicio.fila + aux;
			if (t[inicio] != nullptr) return false;
		}
	}

	//LINEAL EN COLUMNAS
	else if (final.columna != final.columna && final.fila == inicio.fila)
	{
		aux = (final.columna - incio.columna) / abs(final.columna - incio.columna);
		while (abs(final.columna - incio.columna) > 1)
		{
			incio.columna = incio.columna + aux;
			if (t[incio] != nullptr) return false;
		}
	}

	//DIAGONAL DE IZQUIERDA A DERECHA
	else if (Casilla::noSaltarDiagonal(incio,final) == true)
	{
		aux = (final.columna - incio.columna) / abs(final.columna - incio.columna);
		while (abs(final.columna - incio.columna) > 1)
		{
			incio.columna = incio.columna + aux;
			incio.fila = incio.fila + aux;
			if (t[incio] != nullptr) return false;
		}
	}

	//DIAGONAL DE DERECHA A IZQUIERDA
	else if (final.columna != incio.columna && final.fila != incio.fila)
	{
		aux = (final.columna - incio.columna) / abs(final.columna - incio.columna);
		while (abs(final.columna - incio.columna) > 1)
		{
			incio.columna = incio.columna + aux;
			incio.fila = incio.fila - aux;
			if (t[incio] != nullptr) return false;
		}
	}

	return true;
}

bool Pieza::seleccionar(int x, int y)
{
	return false;
}
