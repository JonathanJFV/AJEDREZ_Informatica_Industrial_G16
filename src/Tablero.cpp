#include "Tablero.h"
#include "freeglut.h"

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
                glColor3ub(112, 79, 56); //casilla "negra"
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
                glColor3ub(255, 255, 255); //casilla de color blanco
                glVertex3d(fila, columna, 0);
                glVertex3d(fila, columna + 1, 0);
                glVertex3d(fila + 1, columna + 1, 0);
                glVertex3d(fila + 1, columna, 0);
                glEnd();
                glEnable(GL_LIGHTING);
            }
        }
    }


}
