#include <stdio.h>
//#include <>
#define SIZE 50

int main() {
    char frase[SIZE];

    printf("Introduzca una frase al programa: \n");
    fgets(frase, SIZE, stdin);

    /* Mostrar arreglo por pantalla */
    printf("\n{");
    for (int l = 0; l<SIZE; l++) {
      if (l == (SIZE-1)) {
        printf("%c}", frase[l]);
        break;
      }
      printf("%c", frase[l]);
    }
    return 0;
}
