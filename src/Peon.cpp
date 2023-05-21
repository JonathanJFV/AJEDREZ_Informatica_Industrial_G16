#include "Peon.h"
#include "Tablero.h"

Peon::Peon()
{
	tipo = Pieza::PEON;
	Color = Pieza::NS;
	posx = -1;
	posy = -1;
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
	case Pieza::BLANCA:
		color = "BLANCO";
		break;
	case Pieza::NEGRA:
		color = "NEGRO";
		break;
	default:
		color = "NS";
	}
	cout << "[PEON " << color <<" "<< posx + 1 << "," << posy + 1 << "]" << endl;
}

void Peon::dibujar()
{
	//compara todos los piezas, solo hay que cambiar el gráfico
	if (Color == Pieza::BLANCA) 
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

	if(Color == Pieza::NEGRA)
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


bool Peon::mover(Pieza origen, Pieza destino, Tablero& tablero)
{
	if (color == BLANCA)
	{
		if (origen.fila == 1)
		{
			if ((Pieza::primermPeonblanco(origen, destino) == true && tablero[destino] == nullptr)|| (Pieza::mPeonblanco(origen, destino) == true && tablero[destino] == nullptr) || ((Pieza::comePeonblanco(origen, destino) == true) && tablero[destino] != nullptr && tablero[destino]->getColor() != color))
				return Pieza::mover(origen, destino, tablero);

		}

		else if (origen.fila != 1)
		{
			if ((Pieza::mPeonblanco(origen, destino) == true) && tablero[destino] == nullptr)
				return Pieza::mover(origen, destino, tablero);

			else if ((Pieza::comePeonblanco(origen, destino) == true) && tablero[destino] != nullptr)
				return Pieza::mover(origen, destino, tablero);
		}
	}

	else if (color == NEGRA)
	{
		if (origen.fila == 6)
		{
			if ((Pieza::primermPeonnegro(origen, destino) == true && tablero[destino] == nullptr) || (Pieza::mPeonnegro(origen, destino) == true && tablero[destino] == nullptr) || ((Pieza::comePeonnegro(origen, destino) == true) && tablero[destino] != nullptr && tablero[destino]->getColor() != color))
				return Pieza::mover(origen, destino, tablero);
		}

		else if (origen.fila != 6)
		{
			if ((Pieza::mPeonnegro(origen, destino) == true) && tablero[destino] == nullptr)
				return Pieza::mover(origen, destino, tablero);

			else if ((Pieza::comePeonnegro(origen, destino) == true) && tablero[destino] != nullptr)
				return Pieza::mover(origen, destino, tablero);
		}
	}

	return false;
}

bool Peon::seleccionar(int x, int y)
{
	if (posx == x && posy == y)
	{
		if (seleccionado == false)
			seleccionado = true;
		else
			seleccionado = false;
	}
	return seleccionado;
}
