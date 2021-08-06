#include "cartas.h"
#include <time.h>

void ordenar(Baraja mazo, int lenghtMazo) {

    for(int i = 0; i<lenghtMazo; i++) {
        mazo[i] = (i+1);
    }
}

int generarNumeroRandom() {
    int numero;

    time_t tiempo;
    srand((unsigned) time(&tiempo));
    numero = rand();

    return ((numero % 41) + 1);
}

// FUNCIONES RONDA
int repartirCarta(Baraja mazo, int indice) {
    return mazo[indice];
}

int validarMonto(int monto) {
    if(monto>=MINIMA_APUESTA && monto<=MAXIMA_APUESTA){
        printf("\nUsted pretende ingresar un monto por $%d\n", monto);
    } else if (monto == APUESTA_NULA) {
        printf("\nUsted ha decidido no apostar.\n");
    } else {
        printf("\nERROR: su apuesta corresponde a un monto invalido.\n");
        monto = APUESTA_NULA;
    }

    return monto;
}

float obtenerPuntaje(int cartas[], int numeroApuestas) {
    float suma = 0;
    for(int i = 0; i<numeroApuestas; i++){
        nombrarCarta(cartas, i);
        suma = suma + clasificarNaipe(cartas, i);
    }

    return suma;
}

float evaluarPuntaje(float puntaje) {
    if(puntaje<1){
        printf("\nUps! Parece que algo salio mal, el puntaje es invalido.\n");
    } else if (puntaje>=1 && puntaje<15/2.0) {
        printf("\nSigue jugando, no pierde la apuesta.\n");
    } else if (puntaje == 15/2.0) {
        printf("\nSigue jugando, no pierde la apuesta.\n");
    }
    else {
        printf("\nParece que te has pasado de siete y medio. Perdes la apuesta.\n");
        puntaje = NULO;
    }

    return puntaje;
}

int clasificarPremio(int cartasDelJugador[], int numeroDeCartas, float puntaje) {
    int premio;

    if (puntaje!=NULO && numeroDeCartas>2) {
        premio = 25;
    } else if (puntaje!=NULO && numeroDeCartas == 2) {
        if (puntaje == 15/2.0) {
            premio = chequearSieteyMedias(cartasDelJugador);
        } else {
            premio = 25;
        }
    } else if (puntaje!=NULO && numeroDeCartas == 1) {
        premio = 25;
    } else if (puntaje == NULO) {
        premio = NULO;
    } else {
        printf("\nERROR: Al parecer hubo un problema.");
    }

    return premio;
}

int chequearSieteyMedias(int cartasDelJugador[]) {
    int premio, primerCarta, segundaCarta;

    primerCarta = cartasDelJugador[0];
    segundaCarta = cartasDelJugador[1];


    if (primerCarta == 7 || primerCarta == 17 || primerCarta == 27 || primerCarta == 37) {
        // La primera carta es un siete de algun tipo
        // y la segunda debe ser necesariamente una figura

        if (primerCarta == 7 && segundaCarta == 10) {
            premio = 100;
        } else if (primerCarta == 7 && (segundaCarta == 7 || segundaCarta == 8 || segundaCarta == 9 || segundaCarta == 10)) {
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

    } else if (primerCarta == 8 || primerCarta == 9 || primerCarta == 10) {
        // La primera carta es una figura de oro
        if (primerCarta == 10 && segundaCarta == 7) {
            premio = 100;
        } else if (segundaCarta == 7) {
            premio = 75;
        } else {
            premio = 50;
        }

    } else if (primerCarta == 18 || primerCarta == 19 || primerCarta == 20) {
        // La primera carta es una figura de espada
        if (segundaCarta == 17) {
            premio = 75;
        } else {
            premio = 50;
        }

    } else if (primerCarta == 28 || primerCarta == 29 || primerCarta == 30) {
        // La primera carta es una figura de copas
        if (segundaCarta == 27) {
            premio = 75;
        } else {
            premio = 50;
        }

    } else if (primerCarta == 38 || primerCarta == 39 || primerCarta == 40) {
        // La primera carta es una figura de basto
        if (segundaCarta == 37) {
            premio = 75;
        } else {
            premio = 50;
        }
    }

    return premio;
}

    // Finalizar la ronda
float definirGanadoresPerdedores(float puntajes[], float puntajeBanca, int apuestas[], int jugador) {
    float diferenciaJugador = 0, diferenciaBanca = 0, puntajeJugador, resultado;

    puntajeJugador = puntajes[jugador];

    if (puntajeJugador == DESCALIFICADO) {
        printf("\nEste jugador no participo en la ronda.");
        resultado = DESCALIFICADO;
    } else if (puntajeJugador == NULO) {
        printf("\nEl jugador %d pierde la apuesta por pasarse.", jugador+1);
        resultado = puntajeBanca;
    } else {
        printf("\nPuntaje del jugador: %.1f", puntajeJugador);
        printf("\nLa suma de sus apuestas en la ronda fue de $%d\n", apuestas[jugador]);

        diferenciaJugador = SIETE_Y_MEDIO - puntajeJugador;
        diferenciaBanca = SIETE_Y_MEDIO - puntajeBanca;

        if(diferenciaBanca<diferenciaJugador){
            printf("\nEl jugador %d pierde su apuesta contra la banca.", jugador+1);
            resultado = puntajeBanca;
        } else if (diferenciaJugador<diferenciaBanca) {
            printf("\nLa banca debe pagar al jugador %d.", jugador+1);
            resultado = puntajeJugador;
        } else if (diferenciaBanca == diferenciaJugador) {
            printf("\nPor empate gana la banca,");
            resultado = puntajeBanca;
        } else {
            printf("\nAl parecer hubo un error.\n");
            resultado = puntajeBanca;
        }
    }

    return resultado;
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
    printf("\nSe le paga a la banca un total de $%d y el tesoro aumenta a $%d\n\n", apuestas[jugador], tesoroBanca);

    return tesoroBanca;
}

