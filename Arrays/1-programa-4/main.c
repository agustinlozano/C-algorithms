#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int main(void) {
   float array[SIZE];
   float elemento;
   float temp;

   /* Rellenar arreglo */ 
   printf("\nIngrese los valores del arreglo\n");
   for (int k = 0; k<SIZE; k++) {
      printf("Ingrese el valor para la posicion %d: ", k);
      scanf(" %f", &elemento);
      array[k] = elemento;
   }
   
   
   /* Ordeno el arreglo de forma ascendente */ 
   for (int i = 0; i<SIZE; i++) {
      for (int j = (i+1); j<SIZE; j++) {
	 if (array[j] < array[i]) {
	    temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	 } 
      }
   }  


   /* Mostrar arreglo como un cojunto de elementos */
   printf("\n{");
   for (int l = 0; l<SIZE; l++) {
      if (l == (SIZE-1)) {
	 printf("%.1f}\n", array[l]);
	 break;
      }
      printf("%.1f, ", array[l]);
   }

   return EXIT_SUCCESS;
}
