#ifndef CARTAS
#define CARTAS

#include <stdio.h>
#include <stdlib.h>

#define MAXIMOS_JUGADORES_POSIBLES 5
#define LENGTH 40

#define SI 'y'
#define MOSTRAR 's'

#define MINIMA_APUESTA 100
#define MAXIMA_APUESTA 1500
#define APUESTA_INVALIDA -1
#define APUESTA_NULA 0
#define PLANTARSE 2

#define BANCA 1
#define POSIBLES_CARTAS_JUGADOR 8
#define SIETE_Y_MEDIO 15/2.0
#define NULO 0
#define DESCALIFICADO -1

// Definir tipo
typedef int Baraja[LENGTH];

void barajar(Baraja mazo, int lengthMazo);
int generarNumeroRandom();
void ordenar(Baraja mazo, int lengthMazo);

// Funciones principales
int manejarRonda(Baraja mazo, int length, int numeroJugadores, int saldos[], int tesoroBancaPrincipal);
int repartirCarta(Baraja mazo, int indice);
int validarMonto(int monto);
float obtenerPuntaje(int cartas[], int numeroApuestas);
float evaluarPuntaje(float puntaje);
int clasificarPremio(int cartasDelJugador[], int numeroDeCartas, float puntaje);
int chequearSieteyMedias(int cartasDelJugador[]);

// Finalizar ronda
float definirGanadoresPerdedores(float puntajes[], float puntajeBanca, int indice);
int repartirPremio(int saldos[], int premios[], int apuestas[], int jugador, int tesoroBanca);
int aumentarTesoroBanca(int apuestas[], int jugador, int tesoroBanca);

// Clasificar naipes
float clasificarNaipe(int cartas[], int indice);
void nombrarCarta(int cartas[], int indice);

// Menus
void ejecutarMenuPresentacion();
int determinarJugadores();
void mostrarCarta(int cartas[], int indice, char respuesta);
int ejecutarMenuApuesta(int saldos[], int jugador);
int ejecutarMenuDesiciones();

// Tools
void imprimirArreglo(int arreglo[], int length);
void imprimirPosicionesArr(int arreglo[], int length);
void imprimirPosicionesArrFloat(float arreglo[], int length);
void separarBloque();
#endif

