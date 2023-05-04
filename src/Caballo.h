#pragma once
#ifndef CABALLO_H
#define CABALLO_H
#include "Pieza.h"

class Caballo :public Pieza
{
private:
	//con la libreria de etsidi añade el dibujo de ALFIL
	SpriteSequence sprite_caballo_blanco{ "bin/imagenes/caballo_blanco.png", 1 };
	SpriteSequence sprite_caballo_negro{ "bin/imagenes/caballo_negro.png", 1 };

public:
	Caballo();
	Caballo(Pieza::COLOR c, int x = -1, int y = -1);
	virtual ~Caballo();
	void print();
	void dibujar();
	bool mover(int x, int y);//new
	bool seleccionar(int x, int y);
};





#endif