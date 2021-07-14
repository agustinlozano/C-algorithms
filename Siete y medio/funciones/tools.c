#include "cartas.h"

void imprimirArreglo(int arreglo[], int length) {
    printf("\n{");
    for (int l = 0; l<length; l++) {
        if (l == (length-1)) {
            printf("%d}\n", arreglo[l]);
            break;
        }
        printf("%d", arreglo[l]);
    }


    //printf("\nEl arreglo en la posicion %d vale: %d \n", 2, arreglo[2]);
}

void imprimirPosicionesArr(int arreglo[], int length) {
    printf("\n");
    for (int i = 0; i<length; i++) {
        printf("Posicion %d es : %d\n", i, arreglo[i]);
    }
}


