#ifndef PEON_H
#define PEON_H
#include "Pieza.h"
#include "Tablero.h

class Peon:public Pieza  
{
private:
//con la libreria de etsidi añade el dibujo de PEON
	SpriteSequence sprite_peon_blanco{ "bin/imagenes/peon_blanco.png", 1 };
	SpriteSequence sprite_peon_negro{ "bin/imagenes/peon_negro.png", 1 };
  
public:
	Peon();
	Peon(Pieza::COLOR c, int x = -1, int y = -1);
	virtual ~Peon();
	void print();
	void dibujar();
	bool mover(int x, int y);//new
	bool seleccionar(int x, int y);
};





#endif
