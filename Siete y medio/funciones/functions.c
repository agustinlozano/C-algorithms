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
        premio = 25;
    } else if (puntaje != 0 && indiceJugador == 2) {
        if (puntaje == 15/2.0) {
            premio = chequearSieteyMedias(cartasDelJugador, indiceJugador);
        } else {
            premio = 25;
        }
    } else if (puntaje != 0 && indiceJugador == 1) {
        premio = 25;
    } else if (puntaje == 0) {
        premio = 0;
    } else {
        printf("\nERROR: Al parecer hubo un problema.");
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
float definirGanadoresPerdedores(float puntajes[], int numeroJugadores, float puntajeBanca, int indice) {
    float diferenciaJugador = 0, diferenciaBanca = 0, puntajeJugador, ganador;

    puntajeJugador = puntajes[indice];
    if (puntajeJugador == 0) {
        printf("\nEl jugador %d pierde la apuesta por pasarse\n", indice+1);
        ganador = puntajeBanca;
    } else {
        printf("\nPuntaje del jugador: %.1f", puntajeJugador);

        diferenciaJugador = SIETE_Y_MEDIO - puntajeJugador;
        diferenciaBanca = SIETE_Y_MEDIO - puntajeBanca;

        if(diferenciaBanca < diferenciaJugador){
            printf("\nEl jugador %d pierde su apuesta contra la banca,", indice+1);
            ganador = puntajeBanca;
        } else if (diferenciaJugador < diferenciaBanca) {
            printf("\nLa banca debe pagar al jugador %d,", indice+1);
            ganador = puntajes[indice];
        } else if (diferenciaBanca == diferenciaJugador) {
             printf("\nPor empate gana la banca,");
             ganador = puntajeBanca;
        }else {
            printf("\nAl parecer hubo un error.\n");
            ganador = puntajeBanca;
        }
    }

    return ganador;
}

int repartirPremio(int saldos[], int premios[], int apuestas[], int jugador, int tesoroBanca) {
    int gananciaJugador, saldojugador;

    gananciaJugador = (premios[jugador] * apuestas[jugador]) / 100;
    tesoroBanca = tesoroBanca - gananciaJugador;
    saldojugador = saldos[jugador] + apuestas[jugador];

    saldos[jugador] = saldojugador + gananciaJugador;

    printf("\nSu ganancia ha sido de $%d y su saldo final aumenta a $%d.\n", gananciaJugador, saldos[jugador]);
    printf("\nla banca disminuye su tesoro a $%d\n\n", tesoroBanca);

    return tesoroBanca;
}

int aumentarTesoroBanca(int apuestas[], int jugador, int tesoroBanca) {
    tesoroBanca = apuestas[jugador] + tesoroBanca;
    printf("\nse le paga a la banca un total de $%d y el tesoro aumenta a $%d\n\n", apuestas[jugador], tesoroBanca);

    return tesoroBanca;
}

