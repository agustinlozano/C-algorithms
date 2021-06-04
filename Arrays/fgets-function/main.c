#include <stdio.h>
//#include <>
#define SIZE 50

int main() {
   char frase[SIZE];
   int longDeFrase;
   int contador = 0;
   
   printf("Introduzca una frase al programa: \n");
   printf("Este programa admite 50 caracteres. Los espacios cuentan!\n");
   fgets(frase, SIZE, stdin);


      /* Averiguar la longitud */
   for (int i = 0; i<SIZE; i++) {
      char aux = frase[i];
      if (aux == '\0') {
	 contador = contador - 1;
	 break; 
      }
      contador++;
   }
    

      /* Mostrar arreglo por pantalla */
   printf("\n\t'");
   for (int l = 0; l<contador; l++) {
      if (l == (contador-1)) {
	 printf("%c'\n", frase[l]);
	 break;
      }
      printf("%c", frase[l]);
   }

    
   printf("\nTu frase contiene %d caracteres\n", contador);

   return 0;
}
