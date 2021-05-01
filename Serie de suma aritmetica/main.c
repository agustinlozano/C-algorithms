/* Un programa que suma todos los numeros desde
 * el uno hasta el n utilizando la suma aritme-
 * tica de Gauss.
 */

#include <stdio.h>
#include <stdlib.h>

#define SI 'y'
#define NO 'n'


// Prototipado
int menu();
int sumarHasta(int valorMaximo);
void regresarAlMenu();

// Funcion Main
int main(void) {
  int valorMaximo = menu();

  int resultado = sumarHasta(valorMaximo);

  printf("\nEl resultado de la serie suma es: %d \n", resultado);

  regresarAlMenu();

  return EXIT_SUCCESS;
}

// Definicion de funciones
int menu() {
  int numeroUsuario;

  printf("\n\tSerie de suma artimetica\n");
  printf("\nEste programa se encarga de sumar los enteros desde");
  printf("\nel uno (inclusive) hasta el numero que usted quiera!\n");
  printf("\nIngrese por favor el numero hasta el que desee sumar: ");
  scanf(" %d", &numeroUsuario);

  return numeroUsuario;
}

int sumarHasta(int valorMaximo){
  
  /* Formula:
   * (n(n+1)) / 2
   */
  return (valorMaximo * (valorMaximo + 1)) / 2;
}

void regresarAlMenu() {
  char decisionUsuario;
  printf("\nDesea usted realizar la operacion con otro numero? [y/n] ");
  scanf(" %c", &decisionUsuario);

  if (decisionUsuario == SI) {
    main();
  } else if (decisionUsuario == NO) {
    EXIT_SUCCESS;
  } else {
    printf("ERROR: usted ingreso una opcion invalida!\n");
    EXIT_SUCCESS;
  }
}
