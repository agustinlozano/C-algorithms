/* Que rellene un array con números enteros y los muestre en pantalla en orden
 * ascendente y luego descendente.
 */

#include <stdlib.h>
#include <stdio.h>

// Prototipado
int evaluarMenu();
int conformarArray(int arreglo[], int numeroEntero);
void mostrarSucesionAscendente(int arreglo[], int lenght);
void mostrarSucesionDescendente(int arreglo[], int lenght);

// Main
int main(void) {
  int valorMaximoSucesion;
  int lenghtArreglo;
  
  valorMaximoSucesion = evaluarMenu();

  int sucesionDeNumeros[valorMaximoSucesion];
  conformarArray(sucesionDeNumeros, valorMaximoSucesion);

  lenghtArreglo = valorMaximoSucesion;
  
  printf("\nElementos del conjunto de manera ascendente\n");
  mostrarSucesionAscendente(sucesionDeNumeros, lenghtArreglo);
  
  printf("\nElementos del conjunto de manera descendente\n");
  mostrarSucesionDescendente(sucesionDeNumeros, lenghtArreglo);

  return EXIT_SUCCESS;
}

// Definicion de funciones
int evaluarMenu() {
  int respuestaUsuario;
  printf("\n\tconjuntos de numeros naturales\n");
  printf("\nIngrese el valor entero mas alto de la sucesion de numeros ");
  scanf(" %d", &respuestaUsuario);

  return respuestaUsuario;
}

int conformarArray(int sucesionDeNumeros[], int valorMaximoSucesion) {
  for(int index = 0; index <= valorMaximoSucesion; index++) {
    sucesionDeNumeros[index] = index;
  }

  return 0;
}

void mostrarSucesionAscendente(int sucesionDeNumeros[], int lenghtArreglo) {
  for(int index = 0; index <= lenghtArreglo; index++) {
    printf("Array value position[%d]: %d\n", index, sucesionDeNumeros[index]);
  }
}

void mostrarSucesionDescendente(int sucesionDeNumeros[], int lenghtArreglo) {
  for(int index = lenghtArreglo; index >= 0; index--) {
    printf("Array value position[%d]: %d\n", index, sucesionDeNumeros[index]);
  } 
} 
