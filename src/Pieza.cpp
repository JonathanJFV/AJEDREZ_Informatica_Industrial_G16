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

bool Pieza::mover(Casilla inicio, Casilla final, Tablero& t)
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
	else if (inicio.columna != final.columna && final.fila == inicio.fila)
	{
		aux = (final.columna - inicio.columna) / abs(final.columna - inicio.columna);
		while (abs(final.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			if (t[inicio] != nullptr) return false;
		}
	}

	//DIAGONAL DE IZQUIERDA A DERECHA
	else if (Casilla::noSaltarDiagonal(inicio,final) == true)
	{
		aux = (inicio.columna - inicio.columna) / abs(final.columna - inicio.columna);
		while (abs(inicio.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			inicio.fila = inicio.fila + aux;
			if (t[inicio] != nullptr) return false;
		}
	}

	//DIAGONAL DE DERECHA A IZQUIERDA
	else if (final.columna != inicio.columna && final.fila != inicio.fila)
	{
		aux = (final.columna - inicio.columna) / abs(final.columna - inicio.columna);
		while (abs(final.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			inicio.fila = inicio.fila - aux;
			if (t[inicio] != nullptr) return false;
		}
	}

	return true;
}

bool Pieza::seleccionar(int x, int y)
{
	return false;
}
