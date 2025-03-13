#include <stdio.h>

#define ANCHO_MATRIZ 90
#define ALTO_MATRIZ 24
#define ANCHO_CARTA 13
#define ALTO_CARTA 8

void dorsoCarta(int carta[ALTO_CARTA][ANCHO_CARTA]);
void pantalla(int panio[ALTO_MATRIZ][ANCHO_MATRIZ]);
void imprimirPantalla(int panio[ALTO_MATRIZ][ANCHO_MATRIZ]);

int main()
{
    int panio[ALTO_MATRIZ][ANCHO_MATRIZ];

    pantalla(panio);
    imprimirPantalla(panio);
    
    return 0;
}

void dorsoCarta(int carta[ALTO_CARTA][ANCHO_CARTA])
{
    for (int i = 0; i < ALTO_CARTA; i++)
    {
        for (int j = 0; j < ANCHO_CARTA; j++)
        {
            if (j == 0 || j == ANCHO_CARTA - 1)
            {
                carta[i][j] = 179;
            }
            else if (i == 0 || i == ALTO_CARTA - 1)
            {
                carta[i][j] = 196;            
            }
            else
            {
                carta[i][j] = 177;
            } 
        }
    }
    
    carta[0][0] = 218;
    carta[0][ANCHO_CARTA - 1] = 191;
    carta[ALTO_CARTA - 1][0] = 192;
    carta[ALTO_CARTA - 1][ANCHO_CARTA - 1] = 217;
}

void pantalla(int panio[ALTO_MATRIZ][ANCHO_MATRIZ])
{
    for (int i = 0; i < ALTO_MATRIZ; i++)
    {
        for (int j = 0; j < ANCHO_MATRIZ; j++)
        {
            if (j == 0 || j == ANCHO_MATRIZ - 1)
            {
                panio[i][j] = 186;
            }
            else if (i == 0 || i == ALTO_MATRIZ - 1)
            {
                panio[i][j] = 205;        
            }
            else
            {
                panio[i][j] = 176;
            } 
        }
    }

    panio[0][0] = 201;
    panio[0][ANCHO_MATRIZ - 1] = 187;
    panio[ALTO_MATRIZ - 1][0] = 200;
    panio[ALTO_MATRIZ - 1][ANCHO_MATRIZ - 1] = 188;
}

void imprimirPantalla(int panio[ALTO_MATRIZ][ANCHO_MATRIZ])
{
    for (int i = 0; i < ALTO_MATRIZ; i++)
    {
        for (int j = 0; j < ANCHO_MATRIZ; j++)
        {
            printf("%c", panio[i][j]);
        }
        printf("\n");
    }
}