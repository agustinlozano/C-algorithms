#include "cartas.h"

int main(void) {
    Baraja mazoPartida;
    int cantidadJugadores;
    char respuesta;

    /* Menu de presentacion del juego (opcional)
     * El juego consiste en un num minimo de dos rondas y maximo de 4
     */


        // Determinar numero de jugadores
    cantidadJugadores = determinarJugadores();
    //printf("\nEl numero de jugadores es %d\n", jugadores);

        //Validar le numero de jugadores
    if (cantidadJugadores > 0 && cantidadJugadores < 6) {
        printf("El numero de jugadores para esta partida es %d\n", cantidadJugadores);
    } else {
        printf("ERROR: Usted ha ingresado un valor incorrecto\n");
        printf("Desea volver al menu principal? [y/n]\n");
        scanf(" %c", &respuesta);
        if (respuesta == SI) {
            main();
        }
        return 0;
    }
        //printf("\nEl numero de jugadores es %d\n", jugadores);




    comenzarJuego(mazoPartida, LENGTH, cantidadJugadores);


    return 0;
}

