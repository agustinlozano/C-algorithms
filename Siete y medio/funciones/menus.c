#include "cartas.h"

void ejecutarMenuPresentacion() {
    char respuesta;
    printf("\nDesea ver el menu de presentacion? [y/n]");
    printf("\nSu respuesta: ");
    scanf(" %c", &respuesta);

    if (respuesta == SI) {
        printf("\n\tSiete y medio");
        printf("\nEl juego consiste en un numero minimo de dos rondas y maximo cuatro,");
        printf("\ncada jugador debe disponer de $5000 para poder ingresar a una partida.\n");
    }
}

int determinarJugadores() {
    int respuesta;

    printf("\n\nCuantos jugadores habra en la partida? Maximo 5");
    printf("\nIngrese el numero de jugadores: ");
    scanf(" %d", &respuesta);

    return respuesta;
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
