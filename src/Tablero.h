#pragma once
#include "Rey.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#include "Caballo.h"
#include "Peon.h"
#include "ETSIDI.h"

//////////////////////
#include"Casilla.h"

#define N_FILAS 8
#define N_COLUMNAS 8

class Tablero
{
protected:
	int tam;
	Pieza* tab[N_FILAS][N_COLUMNAS];
	//Casilla casillaTest[8][8];
	Casilla *t[8][8];
	Casilla Comidas[100];

	int PComidas;


	unsigned char rojo, _rojo;
	unsigned char verde, _verde;
	unsigned char azul, _azul;

public:
	Tablero();
	Pieza* operator[](Pieza pos) const { return tab[pos.fila][pos.columna]; }

	void cambioEstado(Casilla inicio, Casilla final);
	
	void movimientoEstado(Casilla inicio, Casilla final);

	void inicializa();

	// funcion principal que dibuja el Tablero
	void dibuja();
	void setColor(unsigned char r, unsigned char v, unsigned char a,
		unsigned char _r, unsigned char _v, unsigned char _a);
	
};


