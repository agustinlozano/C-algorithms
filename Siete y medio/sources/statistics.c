#include "cartas.h"

void obtenerMayorGanacia(int ganancias[], int tesoroBanca, const int numeroJugadores) {
    int gananciaBanca = 0, mayorGanancia = 0, posicionJugador, ganancia;

    gananciaBanca = tesoroBanca - TESORO_INICIAL;
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

    gananciaBanca = tesoroBanca - TESORO_INICIAL;

    if (gananciaBanca == 0) {
        //La banca no gano ni perdio
        for (int i = 0; i<numeroJugadores; i++) {
        gananciaTotalJugadores = gananciaTotalJugadores + ganancias[i];
        }

        if (gananciaTotalJugadores == 0) {
            printf("\nEn esta partida la banca no tuvo ganancias y los jugadores tampoco.\n\n");
        }else if (gananciaTotalJugadores>0) {
            printf("\nEl conjunto de jugadores logro mas ganancias que la banca.");
            printf("\nY su ganancia total fue de $%d\n\n", gananciaTotalJugadores);
        } else {
            printf("\nEn esta partida la banca no tuvo ganancias y los jugadores perdidas.\n\n");
        }
    } else if (gananciaBanca>0) {
        //la banca gano plata
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
            printf("\nEl conjunto de jugadores logro mas ganancias que la banca.");
            printf("\nY su ganancia total fue de $%d\n\n", gananciaTotalJugadores);
        }
    } else {
        //La banca perdio plata
        for (int i = 0; i<numeroJugadores; i++) {
            gananciaTotalJugadores = gananciaTotalJugadores + ganancias[i];
        }

        if (gananciaTotalJugadores == 0) {
            printf("\nEn esta partida la banca tuvo perdidas y los jugadores no ganaron nada.\n\n");
        }else if (gananciaTotalJugadores>0) {
            printf("\nEl conjunto de jugadores logro mas ganancias que la banca.");
            printf("\nY su ganancia total fue de $%d\n\n", gananciaTotalJugadores);
        } else {
            printf("\nEn esta partida la banca tuvo perdidas y los jugadores tambien.\n\n");
        }
    }
}

