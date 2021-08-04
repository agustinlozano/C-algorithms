#ifndef CARTAS
#define CARTAS

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 40
#define MAXIMOS_JUGADORES_POSIBLES 5
#define MINIMOS_JUGADORES_POSIBLES 1
#define MAXIMA_CANTIDAD_RONDAS 4

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

#define SIETE_Y_MEDIO 15/2.0
#define CINCO_Y_MEDIO 11/2.0
#define NULO 0
#define DESCALIFICADO -1

// Definir tipo
typedef int Baraja[LENGTH];

void barajar(Baraja mazo, int lengthMazo);
int generarNumeroRandom();
void ordenar(Baraja mazo, int lengthMazo);

// Funciones principales
int manejarRonda(Baraja mazo, int numeroJugadores, int saldos[], int tesoroBancaPrincipal, int ronda);
int repartirCarta(Baraja mazo, int indice);
int validarMonto(int monto);
float obtenerPuntaje(int cartas[], int numeroApuestas);
float evaluarPuntaje(float puntaje);
int clasificarPremio(int cartasDelJugador[], int numeroDeCartas, float puntaje);
int chequearSieteyMedias(int cartasDelJugador[]);

// Finalizar ronda
float definirGanadoresPerdedores(float puntajes[], float puntajeBanca, int apuestas[], int indice);
int repartirPremio(int saldos[], int premios[], int apuestas[], int jugador, int tesoroBanca);
int aumentarTesoroBanca(int apuestas[], int jugador, int tesoroBanca);
int mostrarMenuEstadistica();

// Clasificar naipes
float clasificarNaipe(int cartas[], int indice);
void nombrarCarta(int cartas[], int indice);

// Menus
void ejecutarMenuPresentacion();
int determinarJugadores();
void mostrarCarta(int cartas[], int indice);
int ejecutarMenuApuesta(int saldos[], int jugador);
int ejecutarMenuDesiciones();

// Tools
void imprimirArreglo(int arreglo[], int length);
void imprimirPosicionesArr(int arreglo[], int length);
void imprimirPosicionesArrFloat(float arreglo[], int length);
void separarBloque();
#endif

