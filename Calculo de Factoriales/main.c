#include <stdio.h>
#include <stdlib.h>

// Prototipado
int evaluarMenu();
unsigned long long int calcularFactorial(int numero, unsigned long long int resultado);

// Main
int main(void) {
    int numeroUsuario;
    unsigned long long int = resultado;

    numeroUsuario = evaluarMenu();
    calcularFactorial(numeroUsuario, resultado);
    
    printf("El factorial de %d es %llu", resultado);

    return EXIT_SUCCESS;
}

// Definicion de funciones
int evaluarMenu() {
    int respuesta;
    printf("\n\tCalculo de factoriales\n");
    printf("\nIngrese el valor entero al cual desea calcular su factorial");
    scanf(" %d", respuesta);

    return respuesta;
}

unsigned long long int calcularFactorial(int numeroUsuario, unsigned long long int resultado) {

    for(int index = numeroUsuario; index > 0; --index) {
       resultado = numeroUsuario * index;
    }

    return resultado;
}
