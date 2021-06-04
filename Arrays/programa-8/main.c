#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int main(void) {
   char frase[SIZE];
   int longDeFrase;
   int contador = 0;
   int contadorMayus;
   
   printf("\n\nEste programa admite 50 caracteres. Los espacios cuentan!\n");
   printf("\nIntroduzca una frase al programa: ");
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
   printf("\n\nLa frase que ingresaste es la siguiente: ");
   printf("\n\t'");
   for (int l = 0; l<contador; l++) {
      if (l == (contador-1)) {
	 printf("%c'\n", frase[l]);
	 break;
      }
      printf("%c", frase[l]);
   }


      /* Realizar la busqueda de mayusculas */
   for(int j = 0; j<contador; j++) {
      int valorNumericoDelChar = (int)frase[j];
      if (valorNumericoDelChar >= 65 && valorNumericoDelChar <= 90) {
	 frase[j] = '0';
	 contadorMayus++;
      }
   }
   
   printf("\nTu frase contiene %d mayusculas, ademas", contadorMayus); 
   printf("\nesta misma cuenta con %d caracteres\n", contador);
 

   return EXIT_SUCCESS;
}
