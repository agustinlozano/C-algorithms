#include <stdio.h>
#include <stdlib.h>

#define SIZE 19 

int main (void) {
   char array[SIZE] = {"constitucionalmente"};
   char aux;
   int iteraciones;


      /* Muestro el array */
   for (int i = 0; i<SIZE; i++) {
      printf(" %c\n", array[i]);
   }


      /* Determino las iteraciones */
   if (SIZE % 2 == 0) {
      iteraciones = SIZE - (SIZE / 2);
   } else {
      iteraciones = SIZE - (SIZE / 2) - 1;
   }
 

      /* Cambio el orden del arreglo */
   for(int i = 0; i<iteraciones; i++) {
	  aux = array[i];
	  array[i] = array[(SIZE-1)-i];
	  array[(SIZE-1)-i] = aux; 
   }


      /* Mostrar arreglo como un cojunto de elementos */
   printf("\n{");
   for (int l = 0; l<SIZE; l++) {
      if (l == (SIZE-1)) {
	 printf("%c}\n", array[l]);
	 break;
      }
      printf("%c, ", array[l]);
   }


   return EXIT_SUCCESS;
} 
