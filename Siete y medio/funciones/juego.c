#include "cartas.h"

int manejarRonda(Baraja mazo, int lengthMazo, int numeroJugadores, int saldos[], int tesoroBancaPrincipal) {
    int cartasPosibles = POSIBLES_CARTAS_JUGADOR*numeroJugadores;
    int cartasPartida[cartasPosibles], apuestas[numeroJugadores], premios[numeroJugadores];

    float puntajes[numeroJugadores];
    int respuestaApuesta = 0, montoApuesta, indiceMazo = 0;
    float puntaje = 0, puntajeBanca = 0, resultado = 0;
    char respuestaCarta = 'c';

    int tesoroBancaLocal = tesoroBancaPrincipal;


    //ordenar(mazo, LENGTH);
    //barajar(mazo, LENGTH);
    //imprimirPosicionesArr(saldos, numJugadores);
    //printf("\nEl tesoro de la banca es igual a: %d", tesoroBanca);

    for(int i = 0; i<(numeroJugadores + BANCA); i++){
        if(i == numeroJugadores) {
            cartasPartida[i] = repartirCarta(mazo, i);
            puntajeBanca = clasificarNaipe(cartasPartida, i);
            printf("\nLa banca recibio su carta");
        } else {
            cartasPartida[i] = repartirCarta(mazo, i);
            printf("\nJugador %d recibio su carta", (i+1));
        }
        indiceMazo++;
    }

        // COMIENZO SEGUNDO FOR
    printf("\n");
    for(int j = 0; j<numeroJugadores; j++) {

     if (saldos[j] < 100) {
        printf("\nEl jugador %d no tiene dinero suficiente para jugar esta ronda.\n", j+1);
        puntajes[j] = DESCALIFICADO;
        apuestas[j] = DESCALIFICADO;
        premios[j] = NULO;
        separarBloque();
     } else {
        int indiceJugador = 0;
        int cartasDelJugador[POSIBLES_CARTAS_JUGADOR];

        cartasDelJugador[indiceJugador] = cartasPartida[j];
        indiceJugador++;

        printf("\n\n\tEs el turno del jugador %d", j+1);
        mostrarCarta(cartasPartida, j, respuestaCarta);

        // Apuesta
        apuestas[j] = 0;
        printf("\n\n\tLlego la hora de apostar");
        printf("\nSu saldo actual es de $%d\n", saldos[j]);

        montoApuesta = ejecutarMenuApuesta(saldos, j);

        if (montoApuesta == APUESTA_INVALIDA) {
            printf("ERROR: no puede realizar esta apuesta a causa de que no tiene dinero suficiente.\n");
            apuestas[j] = apuestas[j] + APUESTA_NULA;
        } else if (montoApuesta == APUESTA_NULA) {
            printf("No se realiza ninguna apuesta.\n");
            apuestas[j] = apuestas[j] + APUESTA_NULA;
        }else {
            apuestas[j] = apuestas[j] + montoApuesta;
            printf("Exito: su desicion para la apuesta fue efectuada.\n");
            printf("\nEl saldo del jugador %d ahora es: %d\n", j+1, saldos[j]);
        }

        printf("\n\tEs momento para tomar una desicion!");
        while(respuestaApuesta != PLANTARSE) {

            respuestaApuesta = ejecutarMenuDesiciones();

            switch(respuestaApuesta){
                case 1:
                    cartasDelJugador[indiceJugador] = repartirCarta(mazo, indiceMazo);
                    cartasPartida[indiceMazo] = cartasDelJugador[indiceJugador];

                    indiceMazo++;
                    indiceJugador++;

                    printf("\nVeamos sus cartas y luego calculemos el puntaje\n");
                    puntaje = obtenerPuntaje(cartasDelJugador, indiceJugador);
                    break;
                case 2:
                    // Quitar codigo duplicado y ser mas especifico mediante los printf acerca
                    // de lo que pasa en cada case, en alto nivel
                    printf("\nVeamos sus cartas y luego calculemos el puntaje\n");
                    puntaje = obtenerPuntaje(cartasDelJugador, indiceJugador);
                    break;
            }

            printf("Y su puntaje es: %.1f\n", puntaje);
            puntaje = evaluarPuntaje(puntaje);

            if (puntaje == NULO || respuestaApuesta == PLANTARSE) {
                break;
            } else {
                printf("\nDesea seguir apostando?");

                montoApuesta = ejecutarMenuApuesta(saldos, j);

                if (montoApuesta == APUESTA_INVALIDA) {
                    printf("\nERROR: no puede realizar esta apuesta a causa de que no tiene dinero suficiente.\n");
                    apuestas[j] = apuestas[j] + APUESTA_NULA;
                } else {
                    apuestas[j] = apuestas[j] + montoApuesta;
                    printf("Exito: su desicion para la apuesta fue efectuada.\n");
                    printf("\nEl saldo del jugador %d ahora es: %d\n", j+1, saldos[j]);
                }
            }
        }
        respuestaApuesta = 0;
        puntajes[j] = puntaje;

        //Esto 'contiene' las cartas de cada cugador
        premios[j] = clasificarPremio(cartasDelJugador, indiceJugador, puntaje);

        if (premios[j] == 0) {
            printf("\nEl usuario se paso, su bonificacion es cero.");
        } else {
            printf("\nLa bonificacion del jugador %d por su combinacion de cartas es: %d\n", j+1, premios[j]);
        }
        separarBloque();
     }

    }
        // FIN SEGUNDO FOR
        printf("\n");
        printf("El arreglo de premios contiene");
        imprimirPosicionesArr(premios, numeroJugadores);  // QUITAR EN VERISON FINAL

        // BANCA
    printf("\n\n\tTurno de de la banca.");
    printf("\nEl puntaje correspondiente es: %.1f\n", puntajeBanca);

    nombrarCarta(cartasPartida, numeroJugadores);

    printf("\n\tAhora debera tomar una desicion...");
    while(puntajeBanca){
        if(puntajeBanca < 11/2.0){
             printf("\nLa banca pide carta.");
             cartasPartida[indiceMazo] = repartirCarta(mazo, indiceMazo);
             printf("\n");
             nombrarCarta(cartasPartida, indiceMazo);
             puntajeBanca = puntajeBanca + clasificarNaipe(cartasPartida, indiceMazo);
             indiceMazo++;
        }
        if(puntajeBanca == 11/2.0) {
            cartasPartida[indiceMazo] = repartirCarta(mazo, indiceMazo);
            printf("\n");
            nombrarCarta(cartasPartida, indiceMazo);
            puntajeBanca = puntajeBanca + clasificarNaipe(cartasPartida, indiceMazo);
            indiceMazo++;
            break;
        }
        if(puntajeBanca >= 6 && puntajeBanca < 15/2.0) {
             printf("\nLa banca se planta.\n");
             break;
        }
        if(puntajeBanca > 15/2.0) {
            puntajeBanca = 0;
            break;
        }
    }
    separarBloque();

        //ACABAR LA RONDA
    printf("\nFinalmente la banca suma un puntaje de %1.f puntos.\n", puntajeBanca);
    if (puntajeBanca == 0) {
        printf("\n\tLa banca se paso, paga a los jugadores!\n");
        for (int i = 0; i<numeroJugadores; i++) {
            printf("\nJugador %d recibe su pago.", i+1);
            tesoroBancaLocal = repartirPremio(saldos, premios, apuestas, i, tesoroBancaLocal);
        }
    } else {
        for (int i = 0; i<numeroJugadores; i++) {
            printf("\n\tVeamos como le fue al jugador %d con respecto a la banca:", i+1);
            resultado = definirGanadoresPerdedores(puntajes, puntajeBanca, i);

            if (resultado == puntajeBanca) {
                tesoroBancaLocal = aumentarTesoroBanca(apuestas, i, tesoroBancaLocal);
            } else if (resultado == DESCALIFICADO) {
                printf("\n.\n");
            } else {
                printf("\ny la bonificacion correspondiente para el es: %d\n", premios[i]);
                tesoroBancaLocal = repartirPremio(saldos, premios, apuestas, i, tesoroBancaLocal);
            }
        }
    }

    separarBloque();
    // Imprimir informacipn de los arreglos principales
    printf("\nLas cartas en juego para esta ronda fueron: \n");
    for(int i = 0; i<indiceMazo; i++){
        nombrarCarta(cartasPartida, i);
    }
    printf("\n");
    printf("\nEl arreglo de apuestas contiene: \n");
    imprimirPosicionesArr(apuestas, numeroJugadores);
    printf("\n");
    printf("El arreglo de puntajes contiene: \n");
    imprimirPosicionesArrFloat(puntajes, numeroJugadores+BANCA);
    printf("\n");
    printf("El arreglo de premios contiene");
    imprimirPosicionesArr(premios, numeroJugadores);
    printf("\n");
    printf("\nIndice mazo vale: %d", indiceMazo);
    printf("\n");
    printf("\nEl arreglo de saldos contiene");
    imprimirPosicionesArr(saldos, numeroJugadores);
    printf("\n\nEl tesoro de la banca local es igual a: %d\n", tesoroBancaLocal);

    return tesoroBancaLocal;
}
