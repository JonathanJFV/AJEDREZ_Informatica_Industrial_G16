#pragma once
#ifndef ALFIL_H
#define ALFIL_H
#include "Pieza.h"

class Alfil :public Pieza
{
private:
	//con la libreria de etsidi añade el dibujo de ALFIL
	SpriteSequence sprite_alfil_blanco{ "bin/imagenes/alfil_blanco.png", 1 };
	SpriteSequence sprite_alfil_negro{ "bin/imagenes/alfil_negro.png", 1 };

public:
	Alfil();
	Alfil(Pieza::COLOR c, int x = -1, int y = -1);
	virtual ~Alfil();
	void print();
	void dibujar();
	bool mover(int x, int y);//new
	bool seleccionar(int x, int y);
};





#endif