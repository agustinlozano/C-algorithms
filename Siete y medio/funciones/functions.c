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
void comenzarJuego(Baraja mazo, int length, int numJugadores) {
    int cartasPartida[numJugadores];
    int apuestas[numJugadores];
    int respuestaApuesta;
    char respuestaCarta = '0';
    int puntaje = 0;


    ordenar(mazo, LENGTH);
    //barajar(mazo, LENGTH);

    for(int i = 0; i<(numJugadores + BANCA); i++){
        if(i == numJugadores) {
            printf("\nLa banca recibio su carta");
        } else {
            cartasPartida[i] = repartirCarta(mazo, length, i);
            printf("\nJugador %d recibio su carta", (i+1));
        }
    }
        // COMIENZO SEGUNDO FOR
    printf("\n");
    for(int j = 0; j<numJugadores; j++) {
        int cartasDelJugador[CARTAS_POSIBLES];
        cartasDelJugador[0] = cartasPartida[j];

        printf("\n\nEs el turno del jugador %d", j+1);
        mostrarCarta(cartasPartida, numJugadores, j, respuestaCarta);

        // Apuesta
        printf("\n\n\tLlego la hora de apostar");
        apuestas[j] = ejecutarMenuApuesta();

        // El jugador debe tomar una desicion
        printf("\t\nEs momento para tomar una desicion!");
        respuestaApuesta = ejecutarMenuDesiciones();

        switch(respuestaApuesta){
            case 1:
                /*
                    Existencia de numeros magicos
                */
                cartasDelJugador[1] = repartirCarta(mazo, length, (numJugadores+BANCA+j));
                printf("\nVeamos sus cartas y luego calculemos el puntaje\n");
                puntaje = obtenerPuntaje(cartasDelJugador, CARTAS_POSIBLES, 2);
                printf("Y su puntaje es: %d\n", puntaje);
                break;
            case 2:
                printf("\nVeamos sus cartas y luego calculemos el puntaje\n");
                puntaje = obtenerPuntaje(cartasDelJugador, CARTAS_POSIBLES, 1);
                printf("Y su puntaje es: %d\n", puntaje);
                break;
        }
            // Comprobacion de puntaje
        if(puntaje<1){
            // Hubo error
        } else if (puntaje >= 1 && puntaje <= 15/2) {
            // Jugador no pierde su apuesta
        } else {
            // Jugador descalificado, pierde la apuesta
        }

        /*
            Resetear arreflo de apuestas y cartas?
        */
    }
        // FIN SEGUNDO FOR

    //printf("/nEl valor de la respuesta es %d", respuestaApuesta);






    /* HASTA  AQUI
     * Construi un arreglo con las respectivas apuestas de los jugadores
     */
    imprimirPosicionesArr(apuestas, numJugadores);
    //printf()
}

int repartirCarta(Baraja mazo, int length, int index) {

    /* Esto funciona como espero

       ImprimirPosiciones me da el arreglo mazo 'desordenado' (Buscar otra opcion para barajar).
       El printf con los jugadores establecidos al principio es correcto.
       La funcion repartir cartas aun no pense que tipo de valor debe devolver.

       imprimirPosicionesArr(mazo, LENGTH);
       printf("\nEl numero de jugadores es %d\n", numJugadores);
    */
    return mazo[index];

}

void mostrarCarta(int arreglo[], int length, int indice, char respuesta) {
    printf("\nPara ver su carta presione la tecla: [s]");
    printf("\nSu respuesta: ");
    scanf(" %c", &respuesta);

    if(respuesta == 's') {
        printf("El jugador %d tiene la carta %d\n", indice+1, arreglo[indice]);
    } else {
        printf("La carta permanece oculta/n");
    }
}

int ejecutarMenuApuesta() {
    int montoDinero = 0;

    printf("\nCuanto desea apostar? MAXIMO $1200, MINIMO $100");
    printf("\nEl monto ingresado: ");
    scanf(" %d", &montoDinero);

    montoDinero = validarMonto(montoDinero);


    return montoDinero;
}

int ejecutarMenuDesiciones() {
    int eleccion;
    printf("\n\tUsted puede elegir una de las siguientes opciones");
    printf("\n1. Pedir carta");
    printf("\n2. Plantarse");
    printf("\nSu eleccion: ");
    scanf(" %d", &eleccion);

    return eleccion;
}

int validarMonto(int monto) {
    if(monto>=MINIMA_APUESTA && monto<=MAXIMA_APUESTA){
        printf("Exito: su apuesta fue efectuada.\n");
    } else {
        printf("\nERROR: su apuesta corresponde a un monto invalido.");
        monto = 0;
    }

    return monto;
}

float obtenerPuntaje(int cartas[], int length, int numeroApuestas) {
    float suma = 0;
    for(int i = 0; i<numeroApuestas; i++){
        suma = suma + clasificarPorNaipe(cartas, length, i);
    }

    return suma;
}

float clasificarPorNaipe(int array[], int length, int indice) {
    int naipe = array[indice];
    float naipeDecimal = 1/2.0;

    switch(naipe){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            if(naipe<8) {
                printf("La carta es un %d de oro\n", naipe);
            }

            if(naipe == 8) {
                printf("La carta es una zota de oro\n");
            }

            if(naipe == 9) {
                printf("La carta es un caballo de oro\n");
            }

            if(naipe == 10) {
                printf("La carta es un rey de oro\n");
            }
            break;

        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            if(naipe<18) {
                printf("La carta es un %d de espada\n", naipe);
            }

            if(naipe == 18) {
                printf("La carta es una zota de espada\n");
            }

            if(naipe == 19) {
                printf("La carta es un caballo de espada\n");
            }

            if(naipe == 20) {
                printf("La carta es un rey de espada\n");
            }
            break;

        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
            if(naipe<28) {
                printf("La carta es un %d de copas\n", naipe);
            }

            if(naipe == 28) {
                printf("La carta es una zota de copas\n");
            }

            if(naipe == 29) {
                printf("La carta es un caballo de copas\n");
            }

            if(naipe == 30) {
                printf("La carta es un rey de copas\n");
            }
            break;

        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
            if(naipe<38) {
                printf("La carta es un %d de basto\n", naipe);
            }

            if(naipe == 38) {
                printf("La carta es una zota de basto\n");\
            }

            if(naipe == 39) {
                printf("La carta es un caballo de basto\n");
            }

            if(naipe == 40) {
                printf("La carta es un rey de basto\n");
            }
            break;
    }

    if(naipe == 8 || naipe == 9 || naipe == 10 || naipe == 18 || naipe == 19 || naipe == 20 || naipe == 28 || naipe == 29 || naipe == 30 || naipe == 38 || naipe == 39  || naipe == 40 ) {
        //printf("naipeDecimal vale: %.1f\n", naipeDecimal);
        return naipeDecimal;
    } else {
        //printf("naipe vale: %d\n", naipe);
        return naipe;
    }
}
