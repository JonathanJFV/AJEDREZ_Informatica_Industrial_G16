#include "Tablero.h"
#include "freeglut.h"
#pragma warning( disable : 26451 )

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

void Tablero::setColor(unsigned char r, unsigned char v, unsigned char a,
    unsigned char _r, unsigned char _v, unsigned char _a) {
    rojo = r, _rojo = _r;
    verde = v, _verde = _v;
    azul = a, _azul = _a;
}