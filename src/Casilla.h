//lista para gestionar las piezas
#ifndef CASILLA_H
#define CASILLA_H

#include "Pieza.h"
#define MAX 100

class Casilla
{
private:
	int tam;
	Pieza* piez[MAX];
public:
	Casilla() :tam(0)
	{
		for (int i = 0;i < MAX;i++)
			piez[i] = NULL;
	}
	virtual ~Casilla();
	bool agregar(Pieza* p);
	void dibujar();
	void destruirContenido();
	Pieza* seleccionar(int x, int y);//nuevo
	bool mover(int x,int y);//nuevo
};



#endif
