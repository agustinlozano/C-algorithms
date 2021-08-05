#include "cartas.h"

void rellenarMazoNulo(int mazo[], int lenght) {
    for(int i = 0; i<lenght; i++) {
        mazo[i] = NULL_VALUE;
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
        printf("Posicion %d es : %d\n", i, arreglo[i]);
    }
}

void imprimirPosicionesArrFloat(float arreglo[], int length) {
    printf("\n");
    for (int i = 0; i<length; i++) {
        printf("Posicion %d es: %.1f\n", i, arreglo[i]);
    }
}

void separarBloque() {
    char respuesta;
    printf("\nPara continuar presione una tecla.");
    printf("\nSu respuesta: ");
    scanf(" %c", &respuesta);
}


