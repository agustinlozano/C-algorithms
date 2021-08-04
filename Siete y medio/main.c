#include "cartas.h"

int main(void) {
    Baraja mazoPartida = {7, 27, 37, 16, 24, 5, 10, 28, 18, 33, 21, 32, 12};
    int tesoroBanca = 100000, ronda = 0, cantidadJugadores;
    int saldos[MAXIMOS_JUGADORES_POSIBLES];

    ejecutarMenuPresentacion();

    cantidadJugadores = determinarJugadores();

    if (cantidadJugadores>=MINIMOS_JUGADORES_POSIBLES && cantidadJugadores<=MAXIMOS_JUGADORES_POSIBLES) {
        printf("El numero de jugadores se ingreso correctamente.\n");
    } else {
        char respuesta;
        printf("ERROR: Usted ha ingresado un valor incorrecto.\n");
        printf("Desea volver al menu principal? [y/n]\n");
        scanf(" %c", &respuesta);
        if (respuesta == SI) {
            main();
        }
    }

    for (int i = 0; i<cantidadJugadores; i++) {
        saldos[i] = 5000;
        printf("\nSe ha acreditado $5000 en el saldo del jugador %d", i+1);
    }

    printf("\n\nTodo listo para comenzar la partida!");
    separarBloque();

    for(int index = 0; index<=MAXIMA_CANTIDAD_RONDAS; index++){
        ronda++;

        if (index == MAXIMA_CANTIDAD_RONDAS) {
            printf("\n\n\tFin de la partida!");
        } else if (index == MAXIMA_CANTIDAD_RONDAS-1) {
            printf("\n\n\tUltima ronda!");
            tesoroBanca = manejarRonda(mazoPartida, cantidadJugadores, saldos, tesoroBanca, ronda);
        } else {
            printf("\n\n\tRonda numero %d\n", ronda);
            tesoroBanca = manejarRonda(mazoPartida, cantidadJugadores, saldos, tesoroBanca, ronda);

            printf("\nMomento de la siguiente ronda!\n");
        }

        separarBloque();
    }

    return EXIT_SUCCESS;
}

