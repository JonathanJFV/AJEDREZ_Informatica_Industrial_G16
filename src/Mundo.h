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

	////////////////////////SOLO COMPROBACION
	//Vector2D posMouse(int button, int state, int _x, int _y) { return posIni; }

	float x_ojo, y_ojo, z_ojo;
	float x_obs, y_obs, z_obs;
	
protected: 
	int ratonx, ratony;
	//Vector2D posIni;
	int posInicialx, posInicialy;
	Tablero chessboard;
	Casilla piezas;

	bool piezaSeleccionada; //true si la se ha seleccionado una pieza
	bool click; //true si se aplasta el boton izquierdo del raton


};
