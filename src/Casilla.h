//lista para gestionar las piezas
#ifndef CASILLA_H
#define CASILLA_H

#include "Pieza.h"
#define MAX 100

//Gestiona una lista de piezas, permitiendo agregar, quitar o eliminar
//piezas creadas externamiente
class Casilla 
{
public:
	Casilla();
	virtual ~Casilla();
	bool agregar(Pieza* p);
	void dibujar();
	void destruirContenido();
	Pieza* seleccionar(int x, int y);//nuevo
	bool mover(int x, int y);//nuevo


private:
	int tam;
	Pieza* piezas[MAX];
/*//mantiene una lista con los sitios de memoria en donde se encuentra cada una de las destintas Piezas*/


};



#endif
