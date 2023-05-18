#include "Tablero.h"
#include "freeglut.h"
#pragma warning( disable : 26451 )

Tablero::Tablero()
{
    for (int fila = 0; fila < N_FILAS; fila++)
    {
        for (int columna = 0; columna < N_COLUMNAS; columna++)
        {
           // tab[fila][columna] = nullptr;
            t[fila][columna] = nullptr;
        }
    }
    //tab[0][4] = new Rey(Pieza::BLANCO);
}

// funcion principal que dibuja el Tablero
void Tablero::dibuja() {
    // TODO: Agregar aquí el código de implementación.

    for (int fila = 0; fila < 8; fila++)
    {
        for (int columna = 0; columna < 8; columna++) 
        {
            int suma = fila + columna;
            if ((suma % 2) == 0) 
            {
                glDisable(GL_LIGHTING);
                glBegin(GL_POLYGON);
                glColor3ub(rojo, verde, azul); //casilla para -negras-
                glVertex3d(fila, columna, 0);
                glVertex3d(fila, columna + 1, 0);
                glVertex3d(fila + 1, columna + 1, 0);
                glVertex3d(fila + 1, columna, 0);
                glEnd();
                glEnable(GL_LIGHTING);

            }
            else
            {
                glDisable(GL_LIGHTING);
                glBegin(GL_POLYGON);
                glColor3ub(_rojo, _verde, _azul); //casilla para -blancas-
                glVertex3d(fila, columna, 0);
                glVertex3d(fila, columna + 1, 0);
                glVertex3d(fila + 1, columna + 1, 0);
                glVertex3d(fila + 1, columna, 0);
                glEnd();
                glEnable(GL_LIGHTING);
            }
        }
    }

    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3ub(192, 64, 0); 
    //glColor3ub(184, 115, 51);
    glVertex3d(-1, -1, -2);
    glVertex3d(-1, 9, -2);
    glColor3ub(184, 115, 51);
    //glColor3ub(192, 64, 0);
    glVertex3d(9, 9, -2);
    glVertex3d(9, -1, -2);
    glEnd();

}

//movimiento de las piezas del tablero
void Tablero::cambioEstado(Casilla inicio, Casilla final)
{
	//PIEZAS COMIDAS
	if (t[final.fila][final.columna] != nullptr)
	{
		//Comidas[PComidas++] = t[final.fila][final.columna];
	}
	//CAMBIAR A NORMAL 
	else
		movimientoEstado(inicio, final);
}
//Cambiar el estado del tablero 
void Tablero::movimientoEstado(Casilla inicio, Casilla final) 
{
	t[final.fila][final.columna] = t[inicio.fila][inicio.columna];
	t[inicio.fila][inicio.columna] = nullptr;
}



void Tablero::setColor(unsigned char r, unsigned char v, unsigned char a,
    unsigned char _r, unsigned char _v, unsigned char _a) {
    rojo = r, _rojo = _r;
    verde = v, _verde = _v;
    azul = a, _azul = _a;
}

void Tablero::inicializa()
{
    PComidas = 0;

    /*
    tab[0][4] = new Rey(Pieza::BLANCO);
    tab[7][4] = new Rey(Pieza::NEGRO);
    tab[0][0] = new Torre(Pieza::BLANCO);
    tab[0][7] = new Torre(Pieza::BLANCO);
    tab[7][0] = new Torre(Pieza::NEGRO);
    tab[7][7] = new Torre(Pieza::NEGRO);
    tab[0][2] = new Alfil(Pieza::BLANCO);
    tab[0][5] = new Alfil(Pieza::BLANCO);
    tab[7][2] = new Alfil(Pieza::NEGRO);
    tab[7][5] = new Alfil(Pieza::NEGRO);
    tab[0][3] = new Reina(Pieza::BLANCO);
    tab[7][3] = new Reina(Pieza::NEGRO);
    tab[0][1] = new Caballo(Pieza::BLANCO);
    tab[0][6] = new Caballo(Pieza::BLANCO);
    tab[7][1] = new Caballo(Pieza::NEGRO);
    tab[7][6] = new Caballo(Pieza::NEGRO);
    for (int i = 0; i < 8; i++)
    {
        tab[1][i] = new Peon(Pieza::BLANCO);
        tab[6][i] = new Peon(Pieza::NEGRO);
    }*/
    
}