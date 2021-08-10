#ifndef CARTAS
#define CARTAS

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 40
#define MAXIMOS_JUGADORES_POSIBLES 5
#define MINIMOS_JUGADORES_POSIBLES 1
#define GANANCIA_INICIAL 0
#define MAXIMA_CANTIDAD_RONDAS 4
#define RONDAS_TEST 2

#define TESORO_INICIAL_BANCA 100000
#define SALDO_INICIAL_JUGADOR 5000
#define SALDO_TEST 1000

#define BANCA 1
#define POSIBLES_CARTAS_JUGADOR 8

#define SI 'y'
#define MOSTRAR 's'

#define MINIMA_APUESTA 100
#define MAXIMA_APUESTA 1500
#define APUESTA_INVALIDA -1
#define APUESTA_NULA 0
#define PEDIR_CARTA 1
#define PLANTARSE 2

#define POSICION_APUESTA 0
#define POSICION_JUGADOR 1

#define VALOR_FIGURA 1/2.0
#define SIETE_Y_MEDIO 15/2.0
#define CINCO_Y_MEDIO 11/2.0
#define NULO 0
#define DESCALIFICADO -1

#define SALIR_MENU_ESTADISTICA 0
#define VALOR_INICIAL_RESPUESTA 1

// Definir tipo
typedef int Baraja[LENGTH];

void ordenar(Baraja mazo, int lengthMazo);
void mezclarMazo(Baraja mazo);

// Funciones principales
int manejarRonda(Baraja mazo, const int numeroJugadores, int saldos[], int ganancias[], int mayorApuestas[], int tesoroBancaPrincipal, int ronda);
int repartirCarta(Baraja mazo, int indice);
int validarMonto(int monto);
float obtenerPuntaje(int cartas[], int numeroApuestas);
float evaluarPuntaje(float puntaje);
int clasificarPremio(int cartasDelJugador[], int numeroDeCartas, float puntaje);
int chequearSieteyMedias(int cartasDelJugador[]);

// Finalizar ronda
float definirGanadoresPerdedores(float puntajes[], float puntajeBanca, int apuestas[], int indice);
int repartirPremio(int saldos[], int premios[], int apuestas[], int ganancias[], int jugador, int tesoroBanca);
int aumentarTesoroBanca(int apuestas[], int jugador, int tesoroBanca);

// Estadistica final
void obtenerMayorGanacia(int ganancias[], int tesoroBanca, const int numeroJugadores);

// Clasificar naipes
float clasificarNaipe(int cartas[], int indice);
void nombrarCarta(int cartas[], int indice);

// Menus
void ejecutarMenuPresentacion();
int determinarJugadores();
void mostrarCarta(int cartas[], int indice);
int ejecutarMenuApuesta(int saldos[], int jugador);
int ejecutarMenuDesiciones();
int mostrarMenuEstadisticaRonda();
int mostrarMenuEstadisticaPartida();

// Tools
    //Para construir el porgrama
void imprimirArreglo(int arreglo[], int length);
void imprimirPosicionesArr(int arreglo[], int length);
void imprimirPosicionesArrFloat(float arreglo[], int length);
    //Para el usuario final
void rellenarArreglo(int arreglo[], int length, int value);
void rellenarMazoNulo(int mazo[], int lenght);
void imprimirEstadisticaInt(int arreglo[], int length);
void imprimirEstadisticaFloat(float arreglo[], int length);
void separarBloque();
#endif

