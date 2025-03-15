#include <stdio.h>

#define ANCHO_MATRIZ 90
#define ALTO_MATRIZ 24
#define ANCHO_CARTA 13
#define ALTO_CARTA 8
#define POS_1_ANCHO 2
#define POS_1_ALTO 2

void dorsoCarta(int carta[ALTO_CARTA][ANCHO_CARTA]);

void pantalla(  int panio[ALTO_MATRIZ][ANCHO_MATRIZ], 
                int carta[ALTO_CARTA][ANCHO_CARTA]);

void imprimirPantalla(int panio[ALTO_MATRIZ][ANCHO_MATRIZ]);

int main()
{
    int panio[ALTO_MATRIZ][ANCHO_MATRIZ];
    int carta[ALTO_CARTA][ANCHO_CARTA];

    pantalla(panio, carta);
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

void pantalla(int panio[ALTO_MATRIZ][ANCHO_MATRIZ], int carta[ALTO_CARTA][ANCHO_CARTA])
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
                panio[i][j] = 32;
            } 
        }
    }

    panio[0][0] = 201;
    panio[0][ANCHO_MATRIZ - 1] = 187;
    panio[ALTO_MATRIZ - 1][0] = 200;
    panio[ALTO_MATRIZ - 1][ANCHO_MATRIZ - 1] = 188;

    for (int i = 0+POS_1_ANCHO; i < ALTO_CARTA+POS_1_ANCHO; i++)
    {
        for (int j = 0+POS_1_ALTO; j < ANCHO_CARTA+POS_1_ALTO; j++)
        {
            if (j == 0 || j == ANCHO_CARTA - 1)
            {
                panio[i][j] = 179;
            }
            else if (i == 0 || i == ALTO_CARTA - 1)
            {
                panio[i][j] = 196;            
            }
            else
            {
                panio[i][j] = 177;
            } 
        }
    }

    carta[0+POS_1_ALTO][0+POS_1_ANCHO] = 218;
    carta[0+POS_1_ALTO][ANCHO_CARTA - 1+POS_1_ANCHO] = 191;
    carta[ALTO_CARTA - 1+POS_1_ALTO][0+POS_1_ANCHO] = 192;
    carta[ALTO_CARTA - 1+POS_1_ALTO][ANCHO_CARTA - 1+POS_1_ANCHO] = 217;
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