#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOPE_PUNTAJE 30

/////// encapsular el codigo en tres archivos: main, truco, envido y gráficos, con sus respectivas funciones y archivos de encabezado

 typedef struct
{
    char nombre[50];
    int cartas[3][2];
    int puntaje;
} player;

void repartirCartas(player *jugador);
void compararCartasIguales(player *jugadorA, player *jugadorB);
void darCartas(player *jugadorA, player *jugadorB);
int dispararJugada();

int main()
{
    srand(time(NULL));

    player player1;
    player maquinolla;

    player1.puntaje=0;
    maquinolla.puntaje=0;

//    int *ptrJugador = &jugador1;
    int quienEsMano = rand()%2;
    int eleccion;
    int puntaje = 0;

    // extern jugador.nombre="hola"; 


    // bucle principal, termina en 30
    do
    {
        /////intercalar mano
        if(quienEsMano%2==0)
        {
            dispararJugada();
            printf("responder jugada\n") ;
            scanf("%d", &puntaje);
        }
        else
        {
            printf("El jugador es mano\n");
            printf("Ingrese un puntaje\n");
            scanf("%d", &puntaje);
            if(puntaje<30)
            {
                printf("El puntaje es menor a 30\n");
            }
        }   
        quienEsMano++;
        ////////
        
    } while (puntaje < TOPE_PUNTAJE);

    printf("\nEl puntaje es mayor o igual a 30, fin del juego \n");

    //repartirCartas(&player1); // & pasa la dirección de memoria de la estructura(puntero);

    return 0;
}

void mostrarAtributo(player *jugador)
{
    printf("%d\n", jugador->puntaje);
}

void repartirCartas(player *jugador)
{   
    for(int i=0;i<3;i++)
    {
        jugador->cartas[i][0]=rand()%4;
        jugador->cartas[i][1]=rand()%12+1;
        while (jugador->cartas[i][1]==8||jugador->cartas[i][1]==9)
        {
            jugador->cartas[i][1]=rand()%12+1; 
        }  
    }
}

void compararCartasIguales(player *jugadorA, player *jugadorB)
{   
    for(int i=0;i<3;i++)
    {
        for (int j=0; j < 3; j++)
        {
            if (jugadorA->cartas[i][0]==jugadorB->cartas[j][0]
                &&jugadorA->cartas[i][1]==jugadorB->cartas[j][1])
            {
                jugadorB->cartas[j][0]=rand()%4;
                jugadorB->cartas[j][1]=rand()%12+1;
                while (jugadorB->cartas[j][1]==8||jugadorB->cartas[j][1]==9)
                {
                    jugadorB->cartas[j][1]=rand()%12+1; 
                }  
                compararCartasIguales(jugadorA,jugadorB);
            }   
        }  
    }
}

void darCartas(player *jugadorA, player *jugadorB)
{
    repartirCartas(jugadorA);
    repartirCartas(jugadorB);
    compararCartasIguales(jugadorA, jugadorB);
}

int mano(/*jugador1,jugador2*/)
{
    // juega envido;
    // juega truco;
}

int dispararJugada()
{
    printf("\nLa maquina es mano\n");
}