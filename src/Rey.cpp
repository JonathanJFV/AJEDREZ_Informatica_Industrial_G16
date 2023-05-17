#include "Rey.h"

Rey::Rey()
{
	tipo = Pieza::REY;
	Color = Pieza::NS;
	posx = -1;
	posy = -1;
	seleccionado = false;

	//un gráfico de rey blanco
	sprite_rey_blanco.setCenter(1, 0);
	sprite_rey_blanco.setSize(0.9, 0.9);

	//un gráfico de rey negro
	sprite_rey_negro.setCenter(1, 0);
	sprite_rey_negro.setSize(0.9, 0.9);
}
Rey::Rey(Pieza::COLOR c, int x, int y)
{
	tipo = Pieza::REY;
	Color = c;
	posx = x;
	posy = y;
	seleccionado = false;
	//un gráfico de rey blanco
	sprite_rey_blanco.setCenter(1, 0);
	//como z de la pieza es 1, se establece una relacion entre casilla y pieza de 1:0.9
	sprite_rey_blanco.setSize(0.9, 0.9);
	//un gráfico de rey negro
	sprite_rey_negro.setCenter(1, 0);
	sprite_rey_negro.setSize(0.9, 0.9);
}
Rey::~Rey()
{
}


//Constructor que pasa los parametros al clase base

void Rey::print()
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
	cout << "[REY " << color << " " << posx + 1 << "," << posy + 1 << "]" << endl;
}

void Rey::dibujar()
{
	//compara todos los piezas, solo hay que cambiar el gráfico
	if (Color == Pieza::BLANCA)
	{
		//dibujar un rey blanco
		glPushMatrix();
		glTranslatef(1.325 + posx * 0.925, 0.325 + posy * 0.925, 1);
		/*z = 1 para que la figura se ponga por encima del tablero,
					(1.325, 0.325, 1) es la posición de la primera casilla para el sprite que estamos usado ,
					+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_rey_blanco.draw();
		glPopMatrix();
	}

	if (Color == Pieza::NEGRA)
	{
		//dibujar un rey negro
		glPushMatrix();
		glTranslatef(1.325 + posx * 0.925, 0.325 + posy * 0.925, 1);
		/*z = 1 para que la figura se ponga por encima del tablero,
					(1.325, 0.325, 1) es la posicion de la primera casilla para el sprite que estamos usado ,
					+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_rey_negro.draw();
		glPopMatrix();
	}
}

bool Rey::mover(int x, int y)
{
	if (seleccionado = false)
		return false;
	else
	{
		print();
		return true;
	}
}

bool Rey::seleccionar(int x, int y)
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
