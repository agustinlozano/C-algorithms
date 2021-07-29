#include "cartas.h"
#include <time.h>


// Definicion de funciones
void ordenar(Baraja mazo, int lenght) {

    for(int i = 0; i<(lenght); i++) {
        mazo[i] = (i+1);
    }
}

void barajar(Baraja mazo, int length) {
    int aux, indice;

    // Almacenar una carta en cada position
    for(int i = 0; i<length; i++) {

        //Genero un numero random
        indice = generarNumeroRandom();
        printf("\nRandom number: %d\n", indice);

        //Intercambio valores
        aux = mazo[i];
        mazo[i] = mazo[indice];
        mazo[indice] = aux;
    }
}

int generarNumeroRandom() {
    int numero;

    time_t tiempo;
    srand((unsigned) time(&tiempo));
    numero = rand();

    return (numero % 41) + 1;
}

// FUNCIONES DEL JUEGO
int repartirCarta(Baraja mazo, int length, int index) {
    return mazo[index];
}

int validarMonto(int monto) {
    if(monto>=MINIMA_APUESTA && monto<=MAXIMA_APUESTA){
        printf("Exito: su apuesta fue efectuada.\n");
    } else if (monto == 0) {
        printf("Usted ha decidido no apostar\n");
    } else {
        printf("\nERROR: su apuesta corresponde a un monto invalido.");
        monto = 0;
    }

    return monto;
}

float obtenerPuntaje(int cartas[], int length, int numeroApuestas) {
    float suma = 0;
    for(int i = 0; i<numeroApuestas; i++){
        nombrarCarta(cartas, length, i);
        suma = suma + clasificarNaipe(cartas, length, i);
    }

    return suma;
}

float evaluarPuntaje(float puntaje) {
    if(puntaje<1){
        printf("Ups! Parece que algo salio mal, el puntaje es invalido.\n");
    } else if (puntaje >= 1 && puntaje < 15/2.0) {
        printf("Sigue jugando, no pierde la apuesta.\n");
        //obtenerPremioCorrespondiente(int cartas[], int length, float puntaje);
    } else if (puntaje == 15/2.0) {
        printf("Sigue jugando, no pierde la apuesta.\n");
    }
    else {
        printf("Parece que te has pasado de siete y medio. Perdes la apusta.\n");
        puntaje = 0;
    }

    //ACA HUBO CAMBIOS EN VALIABLES

    return puntaje;
}

int clasificarPremio(int cartasDelJugador[], int indiceJugador, float puntaje) {
    int premio;

    if (puntaje != 0 && indiceJugador > 2 ) {
        printf("\nPuntaje != 0 y mas de dos cartas");
        premio = 25;
    } else if (puntaje != 0 && indiceJugador == 2) {
        if (puntaje == 15/2.0) {
            // Significa que una es un siete y la otra una figura.
            premio = chequearSieteyMedias(cartasDelJugador, indiceJugador);
        } else {
            printf("\nPuntaje distinto a 0 con dos cartas pero puntaje != siete y medio");
            premio = 25;
        }
    } else if (puntaje != 0 && indiceJugador == 1) {
        printf("\nPuntaje distinto a 0 con una sola carta");
        premio = 25;
    }else {
        printf("\nPuntaje es igual a 0");
        premio = 0;
    }

    return premio;
}

int chequearSieteyMedias(int cartasDelJugador[], int indiceJugador) {
    int premio, primerCarta, segundaCarta;

    primerCarta = cartasDelJugador[0];
    segundaCarta = cartasDelJugador[1];


    if (primerCarta == 7 && segundaCarta == 10) {
        premio = 100;
    } else if (primerCarta == 7 && (segundaCarta == 8 || segundaCarta == 9 || segundaCarta == 10)) {
        premio = 75;
    } else if (primerCarta == 17 && (segundaCarta == 18 || segundaCarta == 19 || segundaCarta == 20)) {
        premio = 75;
    } else if (primerCarta == 27 && (segundaCarta == 28 || segundaCarta == 29 || segundaCarta == 30)) {
        premio = 75;
    } else if (primerCarta == 37 && (segundaCarta == 38 || segundaCarta == 39 || segundaCarta == 40)) {
        premio = 75;
    } else {
        premio = 50;
    }

    return premio;
}

// Finalizar la ronda
int definirGanadoresPerdedores(float puntajes[], int numeroJugadores) {
    int ganador, comparador;

    comparador = 0;
    for (int i = 0; i<=numeroJugadores; i++) {
        float aux = puntajes[i];

        if (aux == 0.0) {
            // El jugador en la posicion i esta descalificado
        }

        if (aux > comparador) {
            comparador = aux;
            ganador = i+1;
        }

    }

    return ganador;
}
