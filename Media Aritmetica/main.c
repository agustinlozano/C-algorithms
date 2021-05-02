#include <stdio.h>
#include <stdlib.h>

#define SI 'y'
#define NO 'n'

// Prototipado
char evaluarMenu();
float manejarInputsUsuario(char desicionUsuario);

// Main
int main(void) {
  char desicionUsuario = evaluarMenu();
  float resultado;


  if (desicionUsuario == SI) {
    resultado = manejarInputsUsuario(desicionUsuario);
    printf("\nEl resultado es: %.2f\n", resultado);

  } else if (desicionUsuario == NO) {
    EXIT_SUCCESS;

  } else {
    printf("\nERROR: usted ha ingresado una opcion incorrecta!");
  }
  

  return EXIT_SUCCESS;
}

// Definicion de funciones
char evaluarMenu() {
  char respuesta;
  printf("\n\tMedia Aritmetica\n");
  printf("\nPara comenzar el programa ingrese [y/n] ");
  scanf(" %c", &respuesta);

  return respuesta;
}

float manejarInputsUsuario(char desicionUsuario) {
  float numeroIngresado;
  float suma = 0;
  int lengthSumandos = 0;

  
  while(desicionUsuario) {
    printf("\nIngrese un nuevo numero: ");
    scanf(" %f", &numeroIngresado);

    suma = suma + numeroIngresado;
    lengthSumandos = lengthSumandos + 1.0;
 
    printf("\nDesea ingresar otro numero? [y/n] ");
    scanf(" %c", &desicionUsuario);

    if (desicionUsuario == NO) {
      break;
    }
  }
  
  return suma / lengthSumandos;
}

