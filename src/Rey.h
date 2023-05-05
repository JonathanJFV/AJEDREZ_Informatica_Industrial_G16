#ifndef REY_H
#define REY_H
#include "Pieza.h"

class Rey : public Pieza
{
private:
    //con la libreria de etsidi añade el dibujo de REY
    SpriteSequence sprite_rey_blanco{ "bin/imagenes/rey_blanco.png", 1 };
  	SpriteSequence sprite_rey_negro{ "bin/imagenes/rey_negro.png", 1 };
public:
  Rey();
	Rey(Pieza::COLOR c, int x = -1, int y = -1);
	virtual ~Rey();
	void print();
	void dibujar();
	bool mover(int x, int y);//new
	bool seleccionar(int x, int y);
};
