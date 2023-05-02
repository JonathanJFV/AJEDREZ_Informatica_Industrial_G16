#include "Casilla.h"

Casilla::~Casilla()
{
}

void Casilla::destruirContenido()
{
	for (int i = 0;i < tam;i++)
	{
		piez[i] = 0;
	}
	tam = 0;
}

Pieza* Casilla::seleccionar(int x, int y)
{
	bool var;
	Pieza* aux=0;
	for (int i = 0;i < tam;i++)
	{
		var = piez[i]->seleccionar(x, y);
		if (var == true)
			aux = piez[i];
	}
	return aux;
}

bool Casilla::mover(int x, int y)
{
	bool retorno=false;
	Pieza* aux = 0;
	aux = seleccionar(x, y);
	if (aux == 0)
		return retorno;
	retorno = aux->mover(x, y);
	return retorno;
}



bool Casilla::agregar(Pieza* p)//para agregar piezas
{
	if (tam < MAX)
	{
		piez[tam++] = p;
		return true;
	}
	else return false;
}

void Casilla::dibujar()
{
	for (int i = 0;i < tam;i++)
		piez[i]->dibujar();
}
