#include <stdio.h>

int main(void) {
  int array[] = {5, 10, 33, 8, 69};
  int elementoIzquierda;
  int elementoDerecha;

  for(int index = 0; index < 5; index++) {
    for(elementoIzquierda = 0, elementoDerecha = 1; elementoDerecha < 5; elementoIzquierda++, elementoDerecha++){
      
      if(array[elementoIzquierda] > array[elementoDerecha]) {
	int varTemporal = array[elementoDerecha];
	array[elementoDerecha] = array[elementoIzquierda];
	array[elementoIzquierda] = varTemporal;
      }	
    }
  }
  
  for (int j = 0; j < 5; j++) {
    printf("El array en posicion %d vale: %d\n", j, array[j]);
  }
  return 0;
} 
