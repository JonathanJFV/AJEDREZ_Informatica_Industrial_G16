#ifndef REINA_H
#define REINA_H
#include "Pieza.h"

class Reina : public Pieza
{
private:
    //con la libreria de etsidi añade el dibujo de REINA
    SpriteSequence sprite_reina_blanco{ "bin/imagenes/reina_blanco.png", 1 };
  	SpriteSequence sprite_reina_negro{ "bin/imagenes/reina_negro.png", 1 };
public:
  Reina();
	Reina(Pieza::COLOR c, int x = -1, int y = -1);
	virtual ~Reina();
	void print();
	void dibujar();
	bool mover(int x, int y);//new
	bool seleccionar(int x, int y);
};
