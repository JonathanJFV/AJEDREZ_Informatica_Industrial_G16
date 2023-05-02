#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza()
{
  tipo = NF;
	Color = NS;
	pos_x = -1;
	pos_y = -1;
}

Pieza:: Pieza(TIPO t, COLOR c, int x, int y)
{
  tipo = t;
	Color = c;
	pos_x = x;
	pos_y = y;
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
