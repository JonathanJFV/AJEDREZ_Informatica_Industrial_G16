#pragma once
class Tablero
{
	unsigned char rojo, _rojo;
	unsigned char verde, _verde;
	unsigned char azul, _azul;

public:
	// funcion principal que dibuja el Tablero
	void dibuja();
	void setColor(unsigned char r, unsigned char v, unsigned char a,
		unsigned char _r, unsigned char _v, unsigned char _a);
};

