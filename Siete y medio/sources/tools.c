#include "cartas.h"

void rellenarArreglo(int arreglo[], int length, int value) {
    for (int i = 0; i<length; i++) {
        arreglo[i] = value;
    }
}

void rellenarMazoNulo(int mazo[], int lenght) {
    for(int i = 0; i<lenght; i++) {
        mazo[i] = NULO;
    }
}

void imprimirArreglo(int arreglo[], int length) {
    printf("\n{");
    for (int l = 0; l<length; l++) {
        if (l == (length-1)) {
            printf("%d}\n", arreglo[l]);
            break;
        }
        printf("%d", arreglo[l]);
    }
}

void imprimirPosicionesArr(int arreglo[], int length) {
    printf("\n");
    for (int i = 0; i<length; i++) {
        printf("Posicion %d es: %d\n", i, arreglo[i]);
    }
}

void imprimirPosicionesArrFloat(float arreglo[], int length) {
    printf("\n");
    for (int i = 0; i<length; i++) {
        printf("Posicion %d es: %.1f\n", i, arreglo[i]);
    }
}

void imprimirEstadisticaInt(int arreglo[], int length) {
    int valor;

    printf("\n");
    for (int i = 0; i<length; i++) {
        valor = arreglo[i];
        if (valor == NULO) {
            printf("Valor nulo para el jugador %d\n", i+1);
            continue;
        } else {
            printf("Para el jugador %d es: %d\n", i+1, valor);
        }
    }
}

void imprimirEstadisticaFloat(float arreglo[], int length) {
    float valor;

    printf("\n");
    for (int i = 0; i<length; i++) {
        valor = arreglo[i];
        if (i == length-1) {
            if (valor == NULO) {
                printf("El puntaje de la banca nulo\n");
            } else {
                printf("El puntaje de la banca fue: %.1f\n", valor);
            }
            continue;
        } else if (valor == DESCALIFICADO) {
            printf("El jugador %d ha sido descalificado.\n", i+1);
            continue;
        } else if (valor == NULO) {
            printf("Valor nulo para el jugador %d\n", i+1);
            continue;
        } else {
            printf("Para el jugador %d es: %.1f\n", i+1, valor);
        }
    }
}

void separarBloque() {
    char respuesta;
    printf("\nPara continuar presione una tecla.");
    printf("\nSu respuesta: ");
    scanf(" %c", &respuesta);
}


