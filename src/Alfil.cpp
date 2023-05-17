#include "Alfil.h"

Alfil::Alfil()
{
	tipo = Pieza::ALFIL;
	Color = Pieza::NS;
	posx = -1;
	posy = -1;
	seleccionado = false;

	//un gráfico de alfil blanco
	sprite_alfil_blanco.setCenter(1, 0);
	sprite_alfil_blanco.setSize(0.9, 0.9);

	//un gráfico de alfil negro
	sprite_alfil_negro.setCenter(1, 0);
	sprite_alfil_negro.setSize(0.9, 0.9);
}
Alfil::Alfil(Pieza::COLOR c, int x, int y)
{
	tipo = Pieza::ALFIL;
	Color = c;
	posx = x;
	posy = y;
	seleccionado = false;
	//un gráfico de alfil blanco
	sprite_alfil_blanco.setCenter(1, 0);
	//como z de la pieza es 1, se establece una relacion entre casilla y pieza de 1:0.9
	sprite_alfil_blanco.setSize(0.9, 0.9);
	//un gráfico de alfil negro
	sprite_alfil_negro.setCenter(1, 0);
	sprite_alfil_negro.setSize(0.9, 0.9);
}
Alfil::~Alfil()
{
}


//Constructor que pasa los parametros al clase base

void Alfil::print()
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
	cout << "[ALFIL " << color << " " << posx + 1 << "," << posy + 1 << "]" << endl;
}

void Alfil::dibujar()
{
	//compara todos los piezas, solo hay que cambiar el gráfico
	if (Color == Pieza::BLANCA)
	{
		//dibujar un alfil blanco
		glPushMatrix();
		glTranslatef(1.325 + posx * 0.925, 0.325 + posy * 0.925, 1);
		/*z = 1 para que la figura se ponga por encima del tablero,
					(1.325, 0.325, 1) es la posición de la primera casilla para el sprite que estamos usado ,
					+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_alfil_blanco.draw();
		glPopMatrix();
	}

	if (Color == Pieza::NEGRA)
	{
		//dibujar un alfil negro
		glPushMatrix();
		glTranslatef(1.325 + posx * 0.925, 0.325 + posy * 0.925, 1);
		/*z = 1 para que la figura se ponga por encima del tablero,
					(1.325, 0.325, 1) es la posicion de la primera casilla para el sprite que estamos usado ,
					+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_alfil_negro.draw();
		glPopMatrix();
	}
}

bool Alfil::mover(int x, int y)
{
	if (seleccionado = false)
		return false;
	else
	{
		print();
		return true;
	}
}

bool Alfil::seleccionar(int x, int y)
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
