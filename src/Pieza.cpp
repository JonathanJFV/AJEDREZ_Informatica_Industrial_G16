#include "Pieza.h"
#include "freeglut.h"

void Pieza::setPos(int x, int y)
{
  x = posx;
  y = posy;
}

float Pieza::getPos(float pos)
{
  if (pos == 1) return x;
	if (pos == 2) return y;
}
