//lista para gestionar las piezas
#ifndef CASILLA_H
#define CASILLA_H

#include "Pieza.h"
#define MAX 100

class Casilla
{
private:
	bool ocupada;
	int tam;
	Pieza* piez[MAX];

	Pieza* listaPiezas[8][8];
	

public:
	int fila;    
	int columna; 
	int Color;

	/*
		Casilla(int fila, int columna, int color): fila(fila), columna(columna), color(color), ocupada(false), tam(0)
	{
		//for (int i = 0; i < MAX; i++)
		//	piez[i] = NULL;
		for (int fila = 0; fila < 8; fila++)
		{
			for (int columna = 0; columna < 8; columna++)
			{
				listaPiezas[fila][columna] = nullptr;
			}
		}
	}
	*/

	Casilla() {
		for (int fila = 0; fila < 8; fila++)
		{
			for (int columna = 0; columna < 8; columna++)
			{
				listaPiezas[fila][columna] = nullptr;
			}
		}
	}



	virtual ~Casilla(){}
	bool agregar(Pieza* p);
	void dibujar();
	void destruirContenido();
	Pieza* seleccionar(int x, int y);//nuevo
	bool mover(int x, int y);
	//Casilla(int fila, int columna) :fila(fila), columna(columna) {}
	static bool mLineal(Casilla inicio, Casilla final);
	static bool mDiagonal(Casilla inicio, Casilla final);
	static bool noSaltarDiagonal(Casilla inicio, Casilla final);
};



#endif
