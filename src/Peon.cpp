#include "Peon.h"

Peon::Peon()
{
	tipo = Pieza::PEON;
	Color = Pieza::NS;
	//posx = -1; 
	//posy = -1;
	seleccionado = false;

	//un gráfico de peon blanco
	sprite_peon_blanco.setCenter(1, 0);
	sprite_peon_blanco.setSize(0.9, 0.9);

	//un gráfico de peon negro
	sprite_peon_negro.setCenter(1, 0);
	sprite_peon_negro.setSize(0.9, 0.9);
}
Peon::Peon(Pieza::COLOR c, int x, int y)
{
	tipo = Pieza::PEON;
	Color = c;
	posx = x;
	posy = y;
	seleccionado = false;
	//un gráfico de peon blanco
	sprite_peon_blanco.setCenter(1, 0);
  //como z de la pieza es 1, se establece una relacion entre casilla y pieza de 1:0.9
	sprite_peon_blanco.setSize(0.9, 0.9);
	//un gráfico de peon negro
	sprite_peon_negro.setCenter(1, 0);
	sprite_peon_negro.setSize(0.9, 0.9);
}
Peon::~Peon()
{
}


//Constructor que pasa los parametros al clase base

void Peon::print()
{
	string color;
	switch (Color)
	{
	case Pieza::BLANCO:
		color = "BLANCO";
		break;
	case Pieza::NEGRO:
		color = "NEGRO";
		break;
	default:
		color = "NS";
	}
	cout << "[PEON " << color <<" "<< posx << "," << posy << "]" << endl;
}

void Peon::dibujar()
{
	//compara todas los piezas, solo hay que cambiar el gráfico
	if (Color == Pieza::BLANCO) 
	{
		//dibujar un peon blanco
		glPushMatrix();
		glTranslatef(1.325 + posx * 0.925, 0.325 + posy * 0.925, 1);
    /*z = 1 para que la figura se ponga por encima del tablero,
				(1.325, 0.325, 1) es la posición de la primera casilla para el sprite que estamos usado , 
				+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_peon_blanco.draw();
		glPopMatrix();
	}

	if(Color == Pieza::NEGRO)
	{
		//dibujar un peon negro
		glPushMatrix();
		glTranslatef(1.325 + posx * 0.925, 0.325 + posy * 0.925, 1);
    /*z = 1 para que la figura se ponga por encima del tablero,
				(1.325, 0.325, 1) es la posicion de la primera casilla para el sprite que estamos usado ,
				+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_peon_negro.draw();
		glPopMatrix();
	}
}

bool Peon::mover(int x, int y)
{
	if(seleccionado == false)
	return false;
	else
	{
		print();
		return true;
	}
}

//devuelve true si se ha seleccionado un peón
bool Peon::seleccionar(int _x, int _y)
{
	if (posx == _x && posy == _y)
	{
		if (seleccionado == false)
			seleccionado = true;
		else
			seleccionado = false;
	}
	return seleccionado;
}

/////////////////////////////////////////////
void Peon::muevePos(int xini, int yini, int xfin, int yfin)
{
	if (validarMovimiento(xfin, yfin))
	{
		posx += xfin;
		posy += yfin;
	}
}


bool Peon::validarMovimiento(int _x, int _y)
{
//si la posicion de la pieza es igual a la elegida por el raton devuelve true
	if (posx == _x && posy == _y)
		return false; 
	if ((posx - _x) == 0 && (posy - _y) < 2)
	{
		return true;
	}
	///validad primer movimiento dos casillas////
}

///////////////////////////////////////////