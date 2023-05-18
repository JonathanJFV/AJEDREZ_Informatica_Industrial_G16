#include "Reina.h"

Reina::Reina()
{
	tipo = Pieza::REINA;
	Color = Pieza::NS;
	posx = -1;
	posy = -1;
	seleccionado = false;

	//un gráfico de reina blanca
	sprite_reina_blanco.setCenter(1, 0);
	sprite_reina_blanco.setSize(0.9, 0.9);

	//un gráfico de reina negra
	sprite_reina_negro.setCenter(1, 0);
	sprite_reina_negro.setSize(0.9, 0.9);
}
Reina::Reina(Pieza::COLOR c, int x, int y)
{
	tipo = Pieza::REINA;
	Color = c;
	posx = x;
	posy = y;
	seleccionado = false;
	//un gráfico de reina blanca
	sprite_reina_blanco.setCenter(1, 0);
	//como z de la pieza es 1, se establece una relacion entre casilla y pieza de 1:0.9
	sprite_reina_blanco.setSize(0.9, 0.9);
	//un gráfico de reina negra
	sprite_reina_negro.setCenter(1, 0);
	sprite_reina_negro.setSize(0.9, 0.9);
}
Reina::~Reina()
{
}


//Constructor que pasa los parametros al clase base

void Reina::print()
{
	/*string Color;
	switch (Color)
	{
	case Pieza::BLANCO:
		Color = "BLANCO";
		break;
	case Pieza::NEGRO:
		Color = "NEGRO";
		break;
	default:
		Color = "NS";
	}
	cout << "[REINA " << Color << " " << posx + 1 << "," << posy + 1 << "]" << endl;*/
	
}

void Reina::dibujar()
{
	//compara todos los piezas, solo hay que cambiar el gráfico
	if (Color == Pieza::BLANCO)
	{
		//dibujar una reina blanca
		glPushMatrix();
		glTranslatef(1.325 + posx * 0.925, 0.325 + posy * 0.925, 1);
		/*z = 1 para que la figura se ponga por encima del tablero,
					(1.325, 0.325, 1) es la posición de la primera casilla para el sprite que estamos usado ,
					+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_reina_blanco.draw();
		glPopMatrix();
	}

	if (Color == Pieza::NEGRO)
	{
		//dibujar una reina negra
		glPushMatrix();
		glTranslatef(1.325 + posx * 0.925, 0.325 + posy * 0.925, 1);
		/*z = 1 para que la figura se ponga por encima del tablero,
					(1.325, 0.325, 1) es la posicion de la primera casilla para el sprite que estamos usado ,
					+-0.925 es la el valor hay que sumar en x e/u y para cambiar de casilla */
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite_reina_negro.draw();
		glPopMatrix();
	}
}

bool Reina::mover(int x, int y)
{
	if (seleccionado = false)
		return false;
	else
	{
		print();
		return true;
	}
}

bool Reina::seleccionar(int x, int y)
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
