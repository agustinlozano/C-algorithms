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

int determinarJugadores() {
    int respuesta;

    printf("\nCuantos jugadores habra en la partida?");
    printf("\nIngrese el numero de jugadores: ");
    scanf(" %d", &respuesta);

    return respuesta;
}


// FUNCIONES DEL JUEGO
int repartirCarta(Baraja mazo, int length, int index) {
    return mazo[index];
}

void mostrarCarta(int arreglo[], int length, int indice, char respuesta) {
    printf("\nPara ver su carta presione la tecla: [s]");
    printf("\nSu respuesta: ");
    scanf(" %c", &respuesta);

    if(respuesta == 's') {
        nombrarCarta(arreglo, length, indice);
    } else {
        printf("La carta permanece oculta/n");
    }
}

int ejecutarMenuApuesta() {
    int montoDinero = 0;

    printf("\nCuanto desea apostar? MAXIMO $1200, MINIMO $100");
    printf("\nIngrese cero si no quiere apostar");
    printf("\nEl monto ingresado: ");
    scanf(" %d", &montoDinero);

    montoDinero = validarMonto(montoDinero);


    return montoDinero;
}

int ejecutarMenuDesiciones() {
    int eleccion;
    printf("\nUsted puede elegir una de las siguientes opciones");
    printf("\n1. Pedir carta");
    printf("\n2. Plantarse");
    printf("\nSu eleccion: ");
    scanf(" %d", &eleccion);

    return eleccion;
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
    /*
int obtenerPremioCorrespondiente(int cartas[], int length, float puntaje) {
    int numero;
    if (puntaje == 15/2) {
        switch(cartas) {

        }
    }
    if (puntaje < 15/2) {
        numero = 25;
    }
    return numero;
}
    */


float evaluarPuntaje(float puntaje) {
    float premio = puntaje;
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
        premio = 0;
    }

    return premio;
}

    /*
int definirGanadoresPerdedores(float puntajes, int length, ) {
    int ganador;



    return ganador;
} */
