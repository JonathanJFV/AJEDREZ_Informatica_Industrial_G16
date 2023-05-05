#include"Tablero.h"
#include "Casilla.h"
#include "Peon.h"
#include "Alfil.h"
#include "Caballo.h"

class Mundo
{
public: 
	
	~Mundo();
	void tecla(unsigned char key);
	void inicializa();
	//void rotarOjo(); ///no es necesario, se puede eliminar
	void mueve();
	void dibuja();
	void raton(int buton, int estado, int _x, int _y);

	float x_ojo, y_ojo, z_ojo;
	float x_obs, y_obs, z_obs;
	
protected: 
	int ratonx,ratony;
	Tablero chessboard;
	Casilla piezas;
};
