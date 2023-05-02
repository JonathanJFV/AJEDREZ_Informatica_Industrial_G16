#include"Tablero.h"
#include "Casilla.h"
#include "Peon.h"

class Mundo
{
public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;

	float x_obs;
	float y_obs;
	float z_obs;

	Tablero chessboard;
	Casilla piezas;
};
