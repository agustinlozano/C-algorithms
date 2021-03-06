#include "cartas.h"

void ejecutarMenuPresentacion() {
    printf("\n\tSiete y medio");
    printf("\nEl juego consiste en un numero minimo de dos rondas y maximo cuatro,");
    printf("\ncada jugador debe disponer de $5000 para poder ingresar a una partida.\n");
}

int determinarJugadores() {
    int respuesta;

    printf("\n\nCuantos jugadores habra en la partida? Maximo 5");
    printf("\nIngrese el numero de jugadores: ");
    scanf(" %d", &respuesta);

    return respuesta;
}

void mostrarCarta(int cartas[], int indice) {
    char respuesta = 'c';
    printf("\nPara ver su carta presione la tecla: [s]");
    printf("\nSu respuesta: ");
    scanf(" %c", &respuesta);

    if (respuesta == MOSTRAR) {
        nombrarCarta(cartas, indice);
    } else {
        printf("La carta permanece oculta./n");
    }
}

int ejecutarMenuApuesta(int saldos[], int jugador) {
    int montoDinero = 0, saldoJugador;

    printf("\nCuanto desea apostar? MAXIMO $1200, MINIMO $100");
    printf("\nIngrese cero si no quiere apostar.");
    printf("\nEl monto ingresado: ");
    scanf(" %d", &montoDinero);

    montoDinero = validarMonto(montoDinero);
    saldoJugador = saldos[jugador];

    if ((saldoJugador-montoDinero)<0) {
        montoDinero = APUESTA_INVALIDA;
    } else {
        saldos[jugador] = saldos[jugador] - montoDinero;
    }

    return montoDinero;
}

int ejecutarMenuDesiciones() {
    int eleccion;
    printf("\nUsted puede elegir una de las siguientes opciones:");
    printf("\n1. Pedir carta");
    printf("\n2. Plantarse");
    printf("\nSu eleccion: ");
    scanf(" %d", &eleccion);

    return eleccion;
}

int mostrarMenuEstadisticaRonda() {
    int eleccion;
    printf("\n\n\tInformacion de la ronda");
    printf("\nPor favor, elija una de las siguientes opciones:");
    printf("\n1. Mostrar saldos");
    printf("\n2. Mostrar apuestas");
    printf("\n3. Mostrar puntajes");
    printf("\n4. Mostrar tesoro de la banca");
    printf("\n0. Pasar de las estadisticas");
    printf("\nSu respuesta: ");
    scanf(" %d", &eleccion);

    return eleccion;
}
int mostrarMenuEstadisticaPartida() {
    int eleccion;
    printf("\n\n\tEstadisticas de la partida");
    printf("\nPor favor, elija una de las siguientes opciones:");
    printf("\n1. Mostrar estadisticas de la partida");
    printf("\n0. Pasar de las estadisticas");
    printf("\nSu respuesta: ");
    scanf(" %d", &eleccion);

    return eleccion;
}
