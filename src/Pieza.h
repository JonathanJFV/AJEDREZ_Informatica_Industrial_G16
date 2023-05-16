#ifndef PIEZA_H
#define PIEZA_H

#include "ETSIDI.h"
#include "freeglut.h"
#include <string>
#include <iostream>

using namespace std;
using namespace ETSIDI;

class Tablero;
class Pieza
{
 public:
//color de la pieza
  enum COLOR { NS = -1, BLANCA, NEGRA };
  //tipo de la pieza
	enum TIPO{NF = -1, PEON, ALFIL, CABALLO, REINA, REY, TORRE};
	int fila = 0, columna = 0;

    Pieza();
    Pieza(TIPO t, COLOR c, int x, int y);
	Pieza(int fila, int columna) :fila(fila), columna(columna) {}
  	  virtual void print();
	  virtual void dibujar();
	  //virtual bool seleccionar(int x,int y);
	  static bool mLineal(Pieza inicio, Pieza fin);
	  static bool mDiagonal(Pieza inicio, Pieza fin);
  
protected:
  bool seleccionado;
  int posx;
  int posy;
  TIPO tipo;
  COLOR Color;

};

#endif
