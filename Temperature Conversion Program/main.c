#include <stdio.h>
#include <stdlib.h>

        /* Formulas
         * Celsius to Fahr ( °C × 9/5) + 32 =  °F
         * Fahr to Celsius ( °F − 32) × 5/9 =  °C
         */

int main (void) {
    float celsius, fahrenheit;
    int decisionDeUsuario;

    printf("Ingrese el tipo de conversion que desee realizar \n");
    printf("Para celsius to Fahr ingrese el numero: 1 \n");
    printf("Para Fahrenheit to celsius ingrese el numero: 2 \n");

    printf("Su decision es: "); scanf("%d", &decisionDeUsuario);

    if (decisionDeUsuario == 1) {
        printf("Ingrese por favor el valor en grados celsius: "); scanf("%f", &celsius);

        fahrenheit = (celsius * 9/5) + 32;
        printf("El valor en grados fahrenheit para, los %.1f grados celsius ingresados es: %.1f \n", celsius, fahrenheit);

    }else if (decisionDeUsuario == 2) {
        printf("Ingrse por favor el valor en grados fahrenheit: "); scanf("%f", &fahrenheit);

        celsius = ((fahrenheit - 32) * 5) / 9;
        printf("El valor en grados celsius para, los %.1f grados fahrenheit ingresados es: %.1f \n", fahrenheit, celsius);
    } else {
        printf("Es posible que usted haya ingresado un valor incorrecto \n");
    }

    return EXIT_SUCCESS;
}
