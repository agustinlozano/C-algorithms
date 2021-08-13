#include "cartas.h"
#include <time.h>

void mezclarMazo(Baraja mazo) {
    int naipeAleatorio, indice = 0;
    time_t tiempo;

    // rellenar mazo nulo
    rellenarMazoNulo(mazo, LENGTH);

    srand((unsigned) time(&tiempo));

    while (indice<LENGTH) {
        // Genero un naipe entre 1 y 40, luego lo almaceno en una varible.
        int numero = rand();
        naipeAleatorio = (numero % 40) + 1;

        // Corroboro que este naipe no exista aun en el mazo
        int count = 0;
        for (int i = 0; i<LENGTH; i++) {
            // Si existe no lo agrego
            if (naipeAleatorio == mazo[i]) {
                break;
            } else {
                count++;
            }

            // Si no existia lo agrego
            if (count == LENGTH-1) {
                mazo[indice] = naipeAleatorio;
                indice++;
                break;
            }
        }
    }
}
