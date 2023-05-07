//lista para gestionar las piezas
#ifndef CASILLA_H
#define CASILLA_H

#include "Pieza.h"
#define MAX 100

//Gestiona una lista de piezas, permitiendo agregar, quitar o eliminar
//piezas creadas externamiente
class ListaPiezas 
{
public:
	ListaPiezas();			//OK
	virtual ~ListaPiezas(); //
	bool agregar(Pieza* p); //OK
	void dibujar();			//OK
	void destruirContenido();
	Pieza* seleccionar(int x, int y);//nuevo
	Pieza* elegirPieza(int _x, int _y); ///CONFIRMAR PARA ELIMINAR EL DE ARRIBA
	bool mover(int x, int y);//nuevo

	///////////////////////////////
	void moverPiezaHasta(int xini, int yini, int xfin, int yfin);
	/////////////////////////////
private:
	int tam;
	Pieza* piezas[MAX];
/*//mantiene una lista con los sitios de memoria en donde se encuentra cada una de las destintas Piezas*/


};



#endif
