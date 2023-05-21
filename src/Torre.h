#ifndef TORRE_H
#define TORRE_H
#include "Pieza.h"

class Torre : public Pieza
{
private:
    //con la libreria de etsidi añade el dibujo de TORRE
    SpriteSequence sprite_torre_blanco{ "bin/imagenes/torre_blanco.png", 1 };
  	SpriteSequence sprite_torre_negro{ "bin/imagenes/torre_negro.png", 1 };
public:
  Torre();
	Torre(Pieza::COLOR c, int x = -1, int y = -1);
	virtual ~Torre();
	void print();
	void dibujar();
	virtual bool mover(Pieza inicio, Pieza fin, Tablero& t);
	bool seleccionar(int x, int y);
};

#endif
