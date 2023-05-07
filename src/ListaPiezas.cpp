#include "ListaPiezas.h"

/*Se asegura que al principio la lista de piezas no contenga informaci�n alguna. 
Para ello, al crear una instancia de la clase Pieza es necesario dar valor cero al 
atributo numero. De igual forma, es conveniente indicar que ning�n puntero apunta de 
momento a nada, puesto que no se ha agregado ninguna pieza al conjunto. Esto se hace 
poniendo a cero el valor de cada uno de los 100 punteros. Para codificar la inicializaci�n, 
l�gicamente, rellenaremos el c�digo del constructor por defecto */
ListaPiezas::ListaPiezas()
{
	for (int i = 0; i < MAX; i++)
		piezas[i] = nullptr;
}
ListaPiezas::~ListaPiezas()
{
}

/*Se almacena la direcci�n en el �ltimo puesto del vector sin rellenar,
verificando que no se ha superado la capacidad m�xima del contenedor.
Se indica que el n�mero de piezas apuntadas por el contenedor
se ha incrementado en uno*/
bool ListaPiezas::agregar(Pieza* p)//para agregar piezas
{
	if (tam < MAX)
		piezas[tam++] = p; //ultimo puesto sin rellenar
	else 
		return false;
	return true;
}

void ListaPiezas::dibujar()
{
	for (int i = 0; i < tam; i++)
		piezas[i]->dibujar();
/*Lo que se almacenan son direcciones, para poder acceder a la ejecuci�n
de una pieza apuntada, es necesario el operador ->*/
}

bool ListaPiezas::mover(int x, int y)
{
	bool retorno = false;
	Pieza* aux = 0;
	aux = seleccionar(x, y);
	if (aux == 0)
		return retorno;
	retorno = aux->mover(x, y);
	return retorno;
}

///////////////////////COMPROBANDO
void ListaPiezas::moverPiezaHasta(int xini, int yini, int xfin, int yfin)
{
	Pieza* piece = nullptr;
	piece = elegirPieza(xini, yini);
	if (piece!=nullptr)
	{
		piece->muevePos(xini, yini, xfin, yfin);
	}
}


void ListaPiezas::destruirContenido()
{
	for (int i = 0; i < tam; i++) //destruccion de piezas contenidas
		delete piezas[i];
	tam = 0;					//inicializa la lista
}



Pieza* ListaPiezas::seleccionar(int x, int y)
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

/////////
Pieza* ListaPiezas::elegirPieza(int _x, int _y)
{
		Pieza* aux = nullptr;
	for (int i = 0; i < tam; i++)
	{
		bool var = piezas[i]->seleccionar(_x, _y);
		if (var == true)
			 aux = piezas[i];
	}
	return aux;
}





