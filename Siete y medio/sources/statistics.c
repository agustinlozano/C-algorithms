#include "cartas.h"

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
        printf("\nLa mayor ganancia fue $%d, y fue lograda por la banca.\n",
            mayorGanancia);
    } else {
        printf("\nLa mayor ganancia fue $%d, y fue lograda por el jugador %d\n",
            mayorGanancia, posicionJugador+1);
    }
}

void obtenerMayorApuesta(int mayorApuesta[]) {
    printf("\nLa mayor apuesta fue de $%d, y fue efectuada por el jugador %d\n",
        mayorApuesta[POSICION_APUESTA], mayorApuesta[POSICION_JUGADOR]+1);
}

void obtenerGananciaTotal(int ganancias[], int tesoroBanca, const int numeroJugadores) {
    int gananciaTotalJugadores = 0, gananciaBanca = 0, diferenciaGanacia;

    gananciaBanca = TESORO_INICIAL_BANCA - tesoroBanca;

    for (int i = 0; i<numeroJugadores; i++) {
        gananciaTotalJugadores = gananciaTotalJugadores + ganancias[i];
    }

    diferenciaGanacia = gananciaBanca - gananciaTotalJugadores;

    if (diferenciaGanacia == 0) {
        printf("\nLa banca gano tanto dinero como el conjunto de jugadores,");
        printf("\ny su ganancia total fue de $%d\n\n", gananciaBanca);
    } else if (diferenciaGanacia>0) {
        printf("\nLa banca gano mas dinero que el conjunto de jugadores,");
        printf("\ny su ganancia total fue de $%d\n\n", gananciaBanca);
    } else {
        printf("\nLos jugadores le ganan a la banca!");
        printf("\nY su ganancia total fue de $%d\n\n", gananciaTotalJugadores);
    }
}

