#ifndef CARTAS
#define CARTAS

#include <stdio.h>
#include <stdlib.h>

#define MAXIMOS_JUGADORES_POSIBLES 5
#define LENGTH 40
#define SI 'y'
#define MINIMA_APUESTA 100
#define MAXIMA_APUESTA 1500
#define BANCA 1
#define POSIBLES_CARTAS_JUGADOR 8
#define SIETE_Y_MEDIO 15/2.0

// Definir tipo
typedef int Baraja[LENGTH];

// Prototipo de funciones
void ejecutarMenuPresentacion();
void barajar(Baraja mazo, int length);
int generarNumeroRandom();
void ordenar(Baraja mazo, int length);

// Tools
void imprimirArreglo(int arreglo[], int length);
void imprimirPosicionesArr(int arreglo[], int length);
void imprimirPosicionesArrFloat(float arreglo[], int length);
void separarBloque();
//int calcularLongArreglo(int arreglo[], int LENGTH);

int determinarJugadores();
void validarJugadores(int participantes);

// Funciones principales
void ejecutarJuego(Baraja mazo, int length, int numJugadores, int saldos[], int tesoroBanca);
int repartirCarta(Baraja mazo, int length, int index);
void mostrarCarta(int arreglo[], int length, int indice, char respuesta);
int ejecutarMenuApuesta(int saldos[], int jugador);
int ejecutarMenuDesiciones();
int validarMonto(int monto);
float obtenerPuntaje(int cartas[], int length, int numeroApuestas);
int obtenerPremioCorrespondiente(int cartas[], int length, float puntaje);
float clasificarNaipe(int arreglo[], int length, int indice);
void nombrarCarta(int cartas[], int length, int indice);
float evaluarPuntaje(float puntaje);
int clasificarPremio(int cartasDelJugador[], int indiceJugador, float puntaje);
int chequearSieteyMedias(int cartasDelJugador[], int indiceJugador);

// Finalizar ronda
float definirGanadoresPerdedores(float puntajes[], int numeroJugadores, float puntajeBanca, int indice);
void repartirPremio(int saldos[], int premios[], int apuestas[], int jugador);
#endif

