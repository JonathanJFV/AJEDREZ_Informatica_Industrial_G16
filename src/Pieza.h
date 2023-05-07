//es la clase base de todas las piezas 

#ifndef PIEZA_H
#define PIEZA_H

#include "ETSIDI.h"
#include "freeglut.h"
#include <string>
#include <iostream>

using namespace std;
using namespace ETSIDI;

class Pieza
{

  
 public:
//color de la pieza
  enum COLOR { NS = -1, BLANCO, NEGRO };
  //tipo de la pieza
	enum TIPO{NF = -1, PEON, ALFIL, CABALLO};
  
    Pieza();
    Pieza(TIPO t, COLOR c, int x, int y);
   
  	virtual void print();
	  virtual void dibujar();
	  virtual bool mover(int x, int y);//new
	  virtual bool seleccionar(int x,int y);

	/////////////////////////////
	  virtual bool validarMovimiento(int _x, int _y) { return false; }
	  virtual int getPosX() { return posx; }
	  virtual int getPosY() { return posy; }
	  virtual void muevePos(int _xini, int yini, int xfin, int yfin){ }
	  //////////////////////////
  
protected:
  bool seleccionado;
  int posx;
  int posy;
  TIPO tipo;
  COLOR Color;

};

#endif
