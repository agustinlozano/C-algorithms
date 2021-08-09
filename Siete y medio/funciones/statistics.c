#include "cartas.h"

int ejecutarEstadisticaFinal(int ganancias[], int mayorApuesta[], int tesoroBanca, const int numeroJugadores) {
    obtenerMayorGanacia(ganancias, tesoroBanca, numeroJugadores);
    printf("\nLa mayor apuesta fue de $%d y el jugador fue %d\n", mayorApuesta[POSICION_APUESTA], mayorApuesta[POSICION_JUGADOR]+1);

    return 0;
}

void obtenerMayorGanacia(int ganancias[], int tesoroBanca, const int numeroJugadores) {
    int gananciaBanca = 0, mayorGanancia = 0, posicionJugador, ganancia;

    gananciaBanca = tesoroBanca - TESORO_INICIAL_BANCA;
    ganancias[numeroJugadores] = gananciaBanca;

    for (int i = 0; i<=numeroJugadores; i++) {
        ganancia = ganancias[i];
        if (ganancia>=mayorGanancia) {
            mayorGanancia = ganancia;
            posicionJugador = i;
        }
    }

    if (ganancia == gananciaBanca && posicionJugador == numeroJugadores) {
        printf("\nLa mayor ganancia fue $%d, y fue lograda por la banca.\n", mayorGanancia);
    } else {
        printf("\nLa mayor ganancia fue $%d, y fue lograda por el jugador %d\n", mayorGanancia, posicionJugador+1);
    }
}

void obtenerMayorApuesta(int apuestas[], const int numeroJugadores) {
    int mayorApuesta = 0, apuesta, posicionJugador;

    for (int i = 0; i<=numeroJugadores; i++) {
        apuesta = apuestas[i];
        if (apuesta>=mayorApuesta) {
            mayorApuesta = apuesta;
            posicionJugador = i;
        }
    }
    printf("\nLa mayor apuesta fue de $%d, y fue realizada por el jugador %d\n", mayorApuesta, posicionJugador+1);
}

