#include "Pieza.h"
#include "Tablero.h"
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

/*
bool Pieza::seleccionar(int x, int y)
{
	return false;
}*/


bool Pieza::mLineal(Pieza inicio, Pieza fin)
{
	if ((fin.fila != inicio.fila && fin.columna == inicio.columna) || (fin.columna != inicio.columna && fin.fila == inicio.fila)) return true;
	return false;
}

//Movimiento diagonal (Alfil y Reina)
bool Pieza::mDiagonal(Pieza inicio, Pieza fin)
{
	if (((abs(fin.fila - inicio.fila) + abs(fin.columna - fin.columna)) % 2 == 0) && (abs(fin.fila - inicio.fila) == abs(fin.columna - inicio.columna))) return true;
	return false;
}

//Algoritmo matematico para la condicion diagonal del calculo de trayectorias "no saltar"
bool Pieza::noSaltarDiagonal(Pieza inicio, Pieza fin)
{
	if ((fin.columna - inicio.columna == fin.fila - inicio.fila) && fin.columna != inicio.columna && fin.fila != inicio.fila) return true;
	return false;
}

bool Pieza::mover(Pieza inicio, Pieza fin, Tablero& t)
{
	int aux;

	//Se revisa si la casilla está ocupada por una pieza del mismo color que el turno 
	if (t[fin] != nullptr && t[fin]->getColor() == NS) return false;

	//COMPROBACION DE TRAYECTORIA. Objetivo: no saltar entre piezas
	//LINEAL EN FILAS 
	if (fin.fila != inicio.fila && fin.columna == inicio.columna)
	{
		aux = (fin.fila - inicio.fila) / abs(fin.fila - inicio.fila);
		while (abs(fin.fila - inicio.fila) > 1)
		{
			inicio.fila = inicio.fila + aux;
			if (t[inicio] != nullptr) return false;
		}
	}

	//LINEAL EN COLUMNAS
	else if (fin.columna != inicio.columna && fin.fila == inicio.fila)
	{
		aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
		while (abs(fin.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			if (t[inicio] != nullptr) return false;
		}
	}

	//DIAGONAL DE IZQUIERDA A DERECHA
	else if (Pieza::noSaltarDiagonal(inicio, fin) == true)
	{
		aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
		while (abs(fin.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			inicio.fila = inicio.fila + aux;
			if (t[inicio] != nullptr) return false;
		}
	}

	//DIAGONAL DE DERECHA A IZQUIERDA
	else if (fin.columna != inicio.columna && fin.fila != inicio.fila)
	{
		aux = (fin.columna - inicio.columna) / abs(fin.columna - inicio.columna);
		while (abs(fin.columna - inicio.columna) > 1)
		{
			inicio.columna = inicio.columna + aux;
			inicio.fila = inicio.fila - aux;
			if (t[inicio] != nullptr) return false;
		}
	}

	return true;
}

