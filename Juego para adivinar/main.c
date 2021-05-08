#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define SALTO printf("\n");

// Prototipado
void mostrarMenu();
int ejecutarJuego();
void evaluarRespuestaUsuario(int respuesta);
int generarNumeroRandom();

// Main
int main(void) { 
   mostrarMenu();
   ejecutarJuego();

   return EXIT_SUCCESS;
}

// Definicion de funciones
void mostrarMenu() {
   SALTO
   printf("\tAdivina el numero!");
   SALTO
   SALTO
   printf("Usted debera ingresar un numero entero del uno al diez, luego");
   SALTO
   printf("el programa elegira otro, si usted acierta entonces gana!"); 
   SALTO
}

int ejecutarJuego() {
   int numeroRandom;
   int eleccionUsuario;

   while (eleccionUsuario) {
      SALTO
      printf("Ingrese un numero por teclado: ");
      scanf(" %d", &eleccionUsuario);
      evaluarRespuestaUsuario(eleccionUsuario);

      numeroRandom = generarNumeroRandom();

      if (eleccionUsuario == numeroRandom) {
	 printf("Ganaste! el numero %d que ingresaste es igual a %d", eleccionUsuario, numeroRandom);
	 SALTO
	 break;
      } else {
	 printf("Perdiste! el numero %d que ingresaste es distinto a %d", eleccionUsuario, numeroRandom);
	 SALTO
      }
   }
   return EXIT_SUCCESS;
}

void evaluarRespuestaUsuario(int eleccionUsuario) {
   if (eleccionUsuario >= 1 && eleccionUsuario <= 10) {
      //Esta todo bien!
   } else {
      printf("Error: su respuesta esta fuera del rango!");
      SALTO
      ejecutarJuego();
   }
}

int generarNumeroRandom() {
   int numero;
   time_t tiempo;

   srand((unsigned int) time(&tiempo));
   numero = rand();
   
   numero = numero % 11;

   if (numero == 0) {
      generarNumeroRandom();
   }

   return numero;
}

