#include "cartas.h"

int main(void) {
    Baraja mazoPartida;

    int tesoroBanca = TESORO_INICIAL, ronda = 0;

    int saldos[MAXIMOS_JUGADORES],
        ganancias[MAXIMOS_JUGADORES],
        mayorApuesta[POSICIONES_MAYOR_APUESTA];

    char respuesta;
    printf("\nDesea ver el menu de presentacion? [y/n]");
    printf("\nSu respuesta: ");
    scanf(" %c", &respuesta);

    if (respuesta == SI) {
        ejecutarMenuPresentacion();
    }

    const int cantidadJugadores = determinarJugadores();

    if (cantidadJugadores>=MINIMOS_JUGADORES && cantidadJugadores<=MAXIMOS_JUGADORES) {
        printf("El numero de jugadores se ingreso correctamente.\n");
    } else {
        char respuesta;
        printf("\nERROR: Usted ha ingresado un valor incorrecto.\n");
        printf("Desea volver al menu principal? [y/n]\n");
        scanf(" %c", &respuesta);
        if (respuesta == SI) {
            main();
        }
    }

    for (int i = 0; i<cantidadJugadores; i++) {
        saldos[i] = SALDO_INICIAL;
        printf("\nSe ha acreditado $5000 en el saldo del jugador %d", i+1);
    }

    rellenarArreglo(ganancias, MAXIMOS_JUGADORES, GANANCIA_INICIAL);

    mayorApuesta[POSICION_APUESTA] = 0;
    mayorApuesta[POSICION_JUGADOR] = 0;

    printf("\n\nTodo listo para comenzar la partida!");
    separarBloque();

    for (int index = 0; index<=MAXIMAS_RONDAS; index++) {
        ronda++;

        if (index == MAXIMAS_RONDAS) {
            printf("\n\n\tFin de la partida!");
        } else if (index == MAXIMAS_RONDAS-1) {
            printf("\n\n\tUltima ronda!");
            tesoroBanca = manejarRonda(
                mazoPartida,
                cantidadJugadores,
                saldos,
                ganancias,
                mayorApuesta,
                tesoroBanca,
                ronda
            );
        } else {
            printf("\n\n\tRonda numero %d\n", ronda);
            tesoroBanca = manejarRonda(
                mazoPartida,
                cantidadJugadores,
                saldos,
                ganancias,
                mayorApuesta,
                tesoroBanca,
                ronda
            );

            printf("\nMomento de la siguiente ronda!\n");
        }

        separarBloque();
    }

    return EXIT_SUCCESS;
}

