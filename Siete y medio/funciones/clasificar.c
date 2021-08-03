#include "cartas.h"

float clasificarNaipe(int cartas[], int indice) {
    int naipe = cartas[indice];
    float naipeDecimal = 1/2.0;
    int divisor = 0;

    if (naipe>=1 && naipe<=7) {
        return naipe;
    }
    if (naipe>=11 && naipe<=17) {
        divisor = 10;
        naipe = naipe % divisor;
        return naipe;
    }
    if (naipe>=21 && naipe<=27) {
        divisor = 20;
        naipe = naipe % divisor;
        return naipe;
    }
    if (naipe>=31 && naipe<=37) {
        divisor = 30;
        naipe = naipe % divisor;
        return naipe;
    }
    if(naipe == 8 || naipe == 9 || naipe == 10 || naipe == 18 || naipe == 19 || naipe == 20 || naipe == 28 || naipe == 29 || naipe == 30 || naipe == 38 || naipe == 39  || naipe == 40 ) {
        return naipeDecimal;
    }

    return 0;
}

void nombrarCarta(int cartas[], int indice) {
    int naipe = cartas[indice];

    switch(naipe){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            if(naipe<8) {
                printf("La carta es un %d de oro\n", naipe);
            }

            if(naipe == 8) {
                printf("La carta es una sota de oro\n");
            }

            if(naipe == 9) {
                printf("La carta es un caballo de oro\n");
            }

            if(naipe == 10) {
                printf("La carta es un rey de oro\n");
            }
            break;

        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            if(naipe<18) {
                printf("La carta es un %d de espada\n", naipe%10);
            }

            if(naipe == 18) {
                printf("La carta es una sota de espada\n");
            }

            if(naipe == 19) {
                printf("La carta es un caballo de espada\n");
            }

            if(naipe == 20) {
                printf("La carta es un rey de espada\n");
            }
            break;

        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
            if(naipe<28) {
                printf("La carta es un %d de copas\n", naipe%20);
            }

            if(naipe == 28) {
                printf("La carta es una sota de copas\n");
            }

            if(naipe == 29) {
                printf("La carta es un caballo de copas\n");
            }

            if(naipe == 30) {
                printf("La carta es un rey de copas\n");
            }
            break;

        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
            if(naipe<38) {
                printf("La carta es un %d de basto\n", naipe%30);
            }

            if(naipe == 38) {
                printf("La carta es una sota de basto\n");\
            }

            if(naipe == 39) {
                printf("La carta es un caballo de basto\n");
            }

            if(naipe == 40) {
                printf("La carta es un rey de basto\n");
            }
            break;
    }
}
