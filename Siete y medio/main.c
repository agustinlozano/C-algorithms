#include "cartas.h"

int main(void) {
    Baraja mazoPartida = {10, 7, 1, 13, 6, 9, 28, 11, 17, 23, 37, 29, 33, 47, 8};
    int tesoroBanca = 100000;
    int saldos[MAXIMOS_JUGADORES_POSIBLES];
    int cantidadJugadores;
    char respuesta;

    ejecutarMenuPresentacion();


        // Determinar numero de jugadores
    cantidadJugadores = determinarJugadores();

        //Validar le numero de jugadores
    if (cantidadJugadores > 0 && cantidadJugadores < 6) {
        printf("El numero de jugadores se ingreso correctamente.\n");
    } else {
        printf("ERROR: Usted ha ingresado un valor incorrecto\n");
        printf("Desea volver al menu principal? [y/n]\n");
        scanf(" %c", &respuesta);
        if (respuesta == SI) {
            main();
        }
    }

    for (int i = 0; i<cantidadJugadores; i++) {
        saldos[i] = 5000;
        printf("\nSe ha acreditado $5000 en el saldo del jugador %d", i+1);
    }

    printf("\n\nTodo listo para comenzar la partida!");
    separarBloque();
    ejecutarJuego(mazoPartida, LENGTH, cantidadJugadores);
    /* Rondas
    for(int index = 0; index<cantidadJugadores; index++){
        printf("\n\tRonda numero %d!\n", index);
        comenzarJuego(mazoPartida, LENGTH, cantidadJugadores);
    }
        */

    return 0;
}

