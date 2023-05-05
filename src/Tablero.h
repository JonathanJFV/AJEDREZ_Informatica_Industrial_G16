#pragma once
#include "Mundo.h"

#define FILAS 8
#define COLUMNAS 8

class Tablero
{
	unsigned char rojo, _rojo;
	unsigned char verde, _verde;
	unsigned char azul, _azul;

public:
	Pieza* Comidas[30];
	int PComidas = 0;
	Pieza* operator[](Casilla pos) const { return t[pos.fila][pos.columna]; }
	void cambioEstado(Casilla inicio, Casilla final);
	void movimientoEstado(Casilla inicio, Casilla final);
	// funcion principal que dibuja el Tablero
	void dibuja();
	void setColor(unsigned char r, unsigned char v, unsigned char a,
		unsigned char _r, unsigned char _v, unsigned char _a);
	
};

