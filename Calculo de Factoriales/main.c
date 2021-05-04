#include <stdio.h>
#include <stdlib.h>

#define SI 'y'
#define NO 'n'

// Prototipado
int evaluarMenu();
unsigned long long int calcularFactorial(int numero, unsigned long long int resultado);
void regresarAlMenu();

// Main
int main(void) {
    int numeroUsuario;
    unsigned long long int resultado = 0;

    numeroUsuario = evaluarMenu();
    resultado = calcularFactorial(numeroUsuario, resultado);
    
    printf("\nEl factorial de %d es %llu \n",numeroUsuario ,resultado);

    regresarAlMenu();

    return EXIT_SUCCESS;
}

// Definicion de funciones
int evaluarMenu() {
    int respuesta;
    printf("\n\tCalculo de factoriales\n");
    printf("\nIngrese el valor entero al cual desea calcular su factorial: ");
    scanf(" %d", &respuesta);

    return respuesta;
}

unsigned long long int calcularFactorial(int numeroUsuario, unsigned long long int resultado) {
    resultado = numeroUsuario;   

    for(int index = (numeroUsuario - 1); index > 0; index--) {
       resultado = resultado * index;
    }

    return resultado;
}

void regresarAlMenu() {
  char decisionUsuario;
  
  printf("\nDesea regresar al menu principal y operar con otro numero? [y/n] ");
  scanf(" %c", &decisionUsuario);
  
  if (decisionUsuario == SI) {
    main();
  } else if (decisionUsuario == NO) {
    EXIT_SUCCESS;
  } else {
    printf("\nERROR: usted ha ingresado una opcion incorrecta\n");
    EXIT_SUCCESS;
  }
}
