#include "Casilla.h"

/*Se asegura que al principio la lista de piezas no contenga información alguna. 
Para ello, al crear una instancia de la clase Pieza es necesario dar valor cero al 
atributo numero. De igual forma, es conveniente indicar que ningún puntero apunta de 
momento a nada, puesto que no se ha agregado ninguna pieza al conjunto. Esto se hace 
poniendo a cero el valor de cada uno de los 100 punteros. Para codificar la inicialización, 
lógicamente, rellenaremos el código del constructor por defecto */
Casilla::Casilla()
{
	for (int i = 0; i < MAX; i++)
		piezas[i] = NULL;
}
Casilla::~Casilla()
{
}

/*Se almacena la dirección en el último puesto del vector sin rellenar,
verificando que no se ha superado la capacidad máxima del contenedor.
Se indica que el número de piezas apuntadas por el contenedor
se ha incrementado en uno*/
bool Casilla::agregar(Pieza* p)//para agregar piezas
{
	if (tam < MAX)
	{
		piezas[tam++] = p;
		return true;
	}
	else return false;
}


void Casilla::destruirContenido()
{
	for (int i = 0;i < tam;i++)
	{
		piezas[i] = 0;
	}
	tam = 0;
}

Pieza* Casilla::seleccionar(int x, int y)
{
	bool var;
	Pieza* aux=0;
	for (int i = 0;i < tam;i++)
	{
		var = piezas[i]->seleccionar(x, y);
		if (var == true)
			aux = piezas[i];
	}
	return aux;
}

Pieza* Casilla::elegirPieza(int _x, int _y)
{
		Pieza* aux = 0;
	for (int i = 0; i < tam; i++)
	{
		bool var = piezas[i]->seleccionar(_x, _y);
		if (var == true)
			 aux = piezas[i];
	}
	return aux;

}

bool Casilla::mover(int x, int y)
{
	bool retorno=false;
	Pieza* aux = 0;
	aux = seleccionar(x, y);
	if (aux == 0)
		return retorno;
	retorno = aux->mover(x, y);
	return retorno;
}




void Casilla::dibujar()
{
	for (int i = 0;i < tam;i++)
		piezas[i]->dibujar();
}
