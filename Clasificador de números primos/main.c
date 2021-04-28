/* Un programa que lea inputs
 * del teclado del usuario y
 * que se fije si es primo o
 * no
 */

#include <stdio.h>
#include <stdlib.h>

#define VALOR_MINIMO 1
#define SI 'y'
#define NO 'n'

// Prototipado
int clasificarNumero(int numero);
int menu();

//funcion main
int main(void) {
  int numeroIngresado;
  
  numeroIngresado = menu(numeroIngresado);
  clasificarNumero(numeroIngresado);
  
  return EXIT_SUCCESS;
}


// Definiciones de funciones
int clasificarNumero(int numeroIngresado) {
  int divisor;
  int resto; 
  int contadorDeRestos = 0;
  char decisionUsuario;

  divisor = numeroIngresado;

  for(int index = numeroIngresado; index >= VALOR_MINIMO; --index) {
    resto = (numeroIngresado % divisor);

    if (resto == 0) {
      ++contadorDeRestos; 
    }
    --divisor;
  }
  
  printf("\nContador de restos es igual a: %d\n", contadorDeRestos);
  if (contadorDeRestos > 2) {
    printf("numero analizado no es primo\n");
    printf("\nDesea probar otro numero? [y/n] ");
    scanf(" %c", &decisionUsuario);

    if(decisionUsuario == SI) {
      main();  
    } else {
      EXIT_SUCCESS;
    }
  } else {
    printf("El numero analizado es primo\n");
    printf("\nDesea probar otro numero? [y/n] ");
    scanf(" %c", &decisionUsuario);

    if(decisionUsuario == SI) {
      main();  
    } else {
      EXIT_SUCCESS;
    }
  }

  return 0;
}

int menu() {
  int numeroIngresado;
  printf("\t Numeros primos\n");
  printf("\n Ingrese por favor un numero entero, el cual desee analizar: ");
  scanf(" %d", &numeroIngresado);
  
  return numeroIngresado;
}
