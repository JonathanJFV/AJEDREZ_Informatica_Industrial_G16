#ifndef TORRE_H
#define TORRE_H
#include "Pieza.h"

class Torre : public Pieza
{
private:
    //con la libreria de etsidi añade el dibujo de TORRE
    SpriteSequence sprite_caballo_blanco{ "bin/imagenes/torre_blanco.png", 1 };
  	SpriteSequence sprite_caballo_negro{ "bin/imagenes/torre_negro.png", 1 };
public:
  Torre();
	Torre(Pieza::COLOR c, int x = -1, int y = -1);
	virtual ~Torre();
	void print();
	void dibujar();
	bool mover(int x, int y);//new
	bool seleccionar(int x, int y);
};
