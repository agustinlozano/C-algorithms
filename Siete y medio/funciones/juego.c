#include "cartas.h"

int ejecutarJuego(Baraja mazo, int length, int numJugadores, int saldos[], int tesoroBancaPrincipal) {
    int cartasPosibles = POSIBLES_CARTAS_JUGADOR*numJugadores;
    int cartasPartida[cartasPosibles], apuestas[numJugadores], premios[numJugadores];

    float puntajes[numJugadores];
    int respuestaApuesta = 0, indiceMazo = 0;
    float puntaje = 0, puntajeBanca = 0, puntajeGanador = 0;
    char respuestaCarta = 'c';

    int tesoroBancaLocal = tesoroBancaPrincipal;


    //ordenar(mazo, LENGTH);
    //barajar(mazo, LENGTH);
    //imprimirPosicionesArr(saldos, numJugadores);
    //printf("\nEl tesoro de la banca es igual a: %d", tesoroBanca);

    for(int i = 0; i<(numJugadores + BANCA); i++){
        if(i == numJugadores) {
            cartasPartida[i] = repartirCarta(mazo, length, i);
            puntajeBanca = clasificarNaipe(cartasPartida, cartasPosibles, i);
            printf("\nLa banca recibio su carta");
        } else {
            cartasPartida[i] = repartirCarta(mazo, length, i);
            printf("\nJugador %d recibio su carta", (i+1));
        }
        indiceMazo++;
    }

        // COMIENZO SEGUNDO FOR
    printf("\n");
    for(int j = 0; j<numJugadores; j++) {

     if (saldos[j] < 100) {
        printf("\nEl jugador %d no tiene dinero suficiente para jugar esta ronda.", j+1);
     } else {
        int indiceJugador = 0;
        int cartasDelJugador[POSIBLES_CARTAS_JUGADOR];

        cartasDelJugador[indiceJugador] = cartasPartida[j];
        indiceJugador++;

        printf("\n\nEs el turno del jugador %d", j+1);
        mostrarCarta(cartasPartida, cartasPosibles, j, respuestaCarta);

        // Apuesta
        apuestas[j] = 0;
        printf("\n\n\tLlego la hora de apostar");
        apuestas[j] = apuestas[j] + ejecutarMenuApuesta(saldos, j);
        printf("\nEl saldo del jugador %d es: %d\n", j+1, saldos[j]);

        printf("\n\tEs momento para tomar una desicion!");
        while(respuestaApuesta != 2) {

            respuestaApuesta = ejecutarMenuDesiciones();

            switch(respuestaApuesta){
                case 1:
                    cartasDelJugador[indiceJugador] = repartirCarta(mazo, length, indiceMazo);
                    cartasPartida[indiceMazo] = cartasDelJugador[indiceJugador];

                    indiceMazo++;
                    indiceJugador++;

                    printf("\nVeamos sus cartas y luego calculemos el puntaje\n");
                    puntaje = obtenerPuntaje(cartasDelJugador, POSIBLES_CARTAS_JUGADOR, indiceJugador);
                    break;
                case 2:
                    // Quitar codigo duplicado y ser mas especifico mediante los printf acerca
                    // de lo que pasa en cada case, en alto nivel
                    printf("\nVeamos sus cartas y luego calculemos el puntaje\n");
                    puntaje = obtenerPuntaje(cartasDelJugador, POSIBLES_CARTAS_JUGADOR, indiceJugador);
                    break;
            }
            printf("Y su puntaje es: %.1f\n", puntaje);
            puntaje = evaluarPuntaje(puntaje);
            if (puntaje == 0 || respuestaApuesta == 2) {
                break;
            } else {
                printf("\nDesea seguir apostando?");
                apuestas[j] = apuestas[j] + ejecutarMenuApuesta(saldos, j);
                printf("\nEl saldo del jugador %d es: %d\n", j+1, saldos[j]);
            }
        }
        respuestaApuesta = 0;
        puntajes[j] = puntaje;

        //Esto 'contiene' las cartas de cada cugador
        premios[j] = clasificarPremio(cartasDelJugador, indiceJugador, puntaje);

        if (premios[j] == 0) {
            printf("\nEl usuario se paso, su bonificacion es cero.");
        } else {
            printf("\nLa bonificacion del jugador %d es: %d\n", j+1, premios[j]);
        }
        separarBloque();
     }

    }
        // FIN SEGUNDO FOR
        printf("\n");
        printf("El arreglo de premios contiene");
        imprimirPosicionesArr(premios, numJugadores);  // QUITAR EN VERISON FINAL

        // BANCA
    printf("\n\nTurno de de la banca.");
    printf("\nEl puntaje correspondiente es: %.1f\n", puntajeBanca);

    nombrarCarta(cartasPartida, cartasPosibles, numJugadores);

    printf("\nAhora debera tomar una desicion...");
    while(puntajeBanca){
        if(puntajeBanca < 11/2.0){
             printf("\nLa banca pide carta.");
             cartasPartida[indiceMazo] = repartirCarta(mazo, length, indiceMazo);
             printf("\n");
             nombrarCarta(cartasPartida, cartasPosibles, indiceMazo);
             puntajeBanca = puntajeBanca + clasificarNaipe(cartasPartida, cartasPosibles, indiceMazo);
             indiceMazo++;
        }
        if(puntajeBanca == 11/2.0) {
            cartasPartida[indiceMazo] = repartirCarta(mazo, length, indiceMazo);
            printf("\n");
            nombrarCarta(cartasPartida, cartasPosibles, indiceMazo);
            puntajeBanca = puntajeBanca + clasificarNaipe(cartasPartida, cartasPosibles, indiceMazo);
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
        for (int i = 0; i<numJugadores; i++) {
            printf("\nJugador %d recibe su pago.", i+1);
            tesoroBancaLocal = repartirPremio(saldos, premios, apuestas, i, tesoroBancaLocal);
        }
    } else {
        for (int i = 0; i<numJugadores; i++) {
            printf("\n\tVeamos como le fue al jugador %d con respecto a la banca:", i+1);
            puntajeGanador = definirGanadoresPerdedores(puntajes, numJugadores, puntajeBanca, i);

            if(puntajeGanador != puntajeBanca){
                printf("\ny la bonificacion correspondiente para el es: %d\n", premios[i]);
                tesoroBancaLocal = repartirPremio(saldos, premios, apuestas, i, tesoroBancaLocal);
            } else {
                tesoroBancaLocal = aumentarTesoroBanca(apuestas, i, tesoroBancaLocal);
            }
        }
    }

    separarBloque();
    // Imprimir informacipn de los arreglos principales
    printf("\nLas cartas en juego para esta ronda fueron: \n");
    for(int i = 0; i<indiceMazo; i++){
        nombrarCarta(cartasPartida, cartasPosibles, i);
    }
    printf("\n");
    printf("\nEl arreglo de apuestas contiene: \n");
    imprimirPosicionesArr(apuestas, numJugadores);
    printf("\n");
    printf("El arreglo de puntajes contiene: \n");
    imprimirPosicionesArrFloat(puntajes, numJugadores+BANCA);
    printf("\n");
    printf("El arreglo de premios contiene");
    imprimirPosicionesArr(premios, numJugadores);
    printf("\n");
    printf("\nIndice mazo vale: %d", indiceMazo);
    printf("\n");
    printf("\nEl arreglo de saldos contiene");
    imprimirPosicionesArr(saldos, numJugadores);
    printf("\n\nEl tesoro de la banca local es igual a: %d\n", tesoroBancaLocal);

    return tesoroBancaLocal;
}
