#include "Pieza.h"


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

bool Pieza::mover(int x, int y)
{
	return false;
}

bool Pieza::seleccionar(int x, int y)
{
	return false;
}
