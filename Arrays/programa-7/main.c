#include <stdio.h>
#include <ctype.h>

int main(void) {
   char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
   int contadorVocales = 0;
   int size;
   int vocalActual;


      /* Ingresar cadena */
   printf("\nVamos a ingresar una cadena de texto\n");
   printf("\nIngrese la cantidad de letras que tiene la cadena: ");
   scanf(" %d", &size);
   char cadena[size];

   for(int index = 0; index<size; index++) {
      printf("\nIngrese el valor de la posicion %d: ", index);
      scanf(" %c", &cadena[index]);
   }

      /* Pasar a lowercase */
   for(int k = 0; k<size; k++) {
      cadena[k] = tolower(cadena[k]);
   }
   
      /* Contar las vocales */
   for(int i = 0; i<size; i++) {
      for(int j = 0; j<5; j++) {
	 char aux = cadena[i]; 
	 if(aux == vocales[j]) {
	    vocales[j] = 0;
	    contadorVocales++;
	 }
      }
   }
  

      /* Informar el resultado */
   if (contadorVocales == 1) {
      printf("\nLa cadena contiene %d vocal\n", contadorVocales);
   } else {
      printf("\nLa cadena contiene %d vocales\n", contadorVocales);
   }


      /* Mostrar arreglo como un cojunto de elementos */
   printf("\n{");
   for (int l = 0; l<size; l++) {
      if (l == (size-1)) {
	 printf("%c}\n", cadena[l]);
	 break;
      }
      printf("%c", cadena[l]);
   }

   return 0;
}
