#include "cartas.h"

int main(void) {
    Baraja mazoPartida = { 10, 20, 39, 16, 2, 35, 7, 17, 27, 22, 3, 32 };
    //Baraja mazoPartida;
    int tesoroBanca = 100000, ronda = 0;
    int saldos[MAXIMOS_JUGADORES_POSIBLES];

    ejecutarMenuPresentacion();

    const int cantidadJugadores = determinarJugadores();

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
        saldos[i] = SALDO_TEST;
        printf("\nSe ha acreditado $5000 en el saldo del jugador %d", i+1);
    }

    printf("\n\nTodo listo para comenzar la partida!");
    separarBloque();

    for(int index = 0; index<=RONDAS_TEST; index++){
        ronda++;

        if (index == RONDAS_TEST) {
            printf("\n\n\tFin de la partida!");
        } else if (index == RONDAS_TEST-1) {
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

