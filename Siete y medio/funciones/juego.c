#include "cartas.h"

void ejecutarJuego(Baraja mazo, int length, int numJugadores) {
    int cartasPosibles = POSIBLES_CARTAS_JUGADOR*numJugadores;
    int cartasPartida[cartasPosibles], apuestas[numJugadores], premios[numJugadores];

    float puntajes[numJugadores];
    int respuestaApuesta, indiceMazo, ganador = 0;
    float puntaje, puntajeBanca = 0;
    char respuestaCarta = 'c';


    //ordenar(mazo, LENGTH);
    //barajar(mazo, LENGTH);

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
        int indiceJugador = 0;
        int cartasDelJugador[POSIBLES_CARTAS_JUGADOR];

        cartasDelJugador[indiceJugador] = cartasPartida[j];
        indiceJugador++;

        printf("\n\nEs el turno del jugador %d", j+1);
        mostrarCarta(cartasPartida, cartasPosibles, j, respuestaCarta);

        // Apuesta
        apuestas[j] = 0;
        printf("\n\n\tLlego la hora de apostar");
        apuestas[j] = apuestas[j] + ejecutarMenuApuesta();

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
                apuestas[j] = apuestas[j] + ejecutarMenuApuesta();
            }
        }
        respuestaApuesta = 0;

            /* Recolectar los putantajes y cartas de los correspondientes jugadores
             * en un arreglo, para poder hacer las comparaciones entre ellos y la banca,
             * determinar el ganador y luego con cumplir los items adicionales
             */
        puntajes[j] = puntaje;

        //Esto 'contiene' las cartas de cada cugador
        premios[j] = clasificarPremio(cartasDelJugador, indiceJugador, puntaje);
        printf("\nEl premio del jugador %d es: %d\n", j+1, premios[j]);

        separarBloque();
    }
        // FIN SEGUNDO FOR

        // BANCA
    printf("\nEl puntaje de la banca es: %.1f\n", puntajeBanca);
    nombrarCarta(cartasPartida, cartasPosibles, numJugadores);

    while(puntajeBanca){
        if(puntajeBanca < 11/2.0){
             printf("\nPedir carta, puntaje menor a 5.5"); //QUITAR en version fial
             cartasPartida[indiceMazo] = repartirCarta(mazo, length, indiceMazo);
             printf("\n");
             nombrarCarta(cartasPartida, cartasPosibles, indiceMazo);
             puntajeBanca = puntajeBanca + clasificarNaipe(cartasPartida, cartasPosibles, indiceMazo);
             puntajes[numJugadores] = puntajeBanca;
             indiceMazo++;
        }
        if(puntajeBanca == 11/2.0) {
            cartasPartida[indiceMazo] = repartirCarta(mazo, length, indiceMazo);
            printf("\n");
            nombrarCarta(cartasPartida, cartasPosibles, indiceMazo);
            puntajeBanca = puntajeBanca + clasificarNaipe(cartasPartida, cartasPosibles, indiceMazo);
            puntajes[numJugadores] = puntajeBanca;
            indiceMazo++;
            break;
        }
        if(puntajeBanca >= 6 && puntajeBanca < 15/2.0) {
             printf("\nPlantarse, puntaje mayor a 6\n");
             puntajes[numJugadores] = puntajeBanca;
             break;
        }
        if(puntajeBanca > 15/2.0) {
            printf("\nLa banca se paso, paga a los jugadores.\n");
            puntajes[numJugadores] = 0;
            break;
        }
    }
    separarBloque();

        //ACABAR LA RONDA
    ganador = definirGanadoresPerdedores(puntajes, numJugadores);
    printf("\nEl ganador de esta ronda es el jugador %d\n", ganador);
    //repartirPremio(ganador, );

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
}
