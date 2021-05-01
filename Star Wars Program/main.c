/* Un programa con un menu donde el usuario pueda elegir
 * el episodio de una pelicula del universo de Star Wars,
 * y programa muestre el nombre correspondiente, mas un
 * poco de informacion.
 */

#include <stdio.h>
#include <stdlib.h>

#define PRIMERA_OPCION 1
#define ULTIMA_OPCION 9

#define SI 'y'
#define NO 'n'

// Prototipado
int evaluarMenu();
void regresarAlMenu();
void mostrarContenidoSegun(int decisionUsusario);

// Main
int main(void) {
  int decisionUsusario;
 
  decisionUsusario = evaluarMenu();
  mostrarContenidoSegun(decisionUsusario);

  return EXIT_SUCCESS;
}

// Definicion de funciones
int evaluarMenu() {

  int respuesta;
  printf("\tEl universo de Star Wars y sus peliculas \n");
  printf("\n1- Star Wars: Episodio I");
  printf("\n2- Star Wars: Episodio II");
  printf("\n3- Star Wars: Episodio III");
  printf("\n4- Star Wars: Episodio IV");
  printf("\n5- Star Wars: Episodio V");
  printf("\n6- Star Wars: Episodio VI");
  printf("\n7- Star Wars: Episodio VII");
  printf("\n8- Star Wars: Episodio VIII");
  printf("\n9- Star Wars: Episodio IX\n");
  
   
  printf("\nPor favor, ingrese la opcion correspondiente para la pelicula que desee conocer: ");
  scanf(" %d", &respuesta);

  return respuesta;
}


void regresarAlMenu() {
  char decisionUsusario3;

  printf("\nDesea volver al menu principal? [y/n] ");
  scanf(" %c", &decisionUsusario3);

  if (decisionUsusario3 == SI) {
    main();
  } else if (decisionUsusario3 == NO) {
    EXIT_SUCCESS;
  } else {
    printf("ERROR: usted ingreso una opcion invalida!\n");
    EXIT_SUCCESS;
  }
}

void mostrarContenidoSegun(int decisionUsusario) {
  char decisionUsusario2;

  if (decisionUsusario >= PRIMERA_OPCION && decisionUsusario <= ULTIMA_OPCION) {
    switch(decisionUsusario) {
      case 1: printf("\nStar Wars: Episode I - The Phantom Menace\n");
	      printf("\nDesea, usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == SI) {
		printf("\nLa pelicula se estreno mundialmente en 1999, ademas,\n");	
		printf("llego a recaudar 1027 millones de dolares.\n");
		regresarAlMenu();

	      } else if (decisionUsusario2 == NO) {
		EXIT_SUCCESS;

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }

      break;

      case 2: printf("\nStar Wars: Episode II – Attack of the Clones\n");
	      printf("\nDesea, usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == SI) {
		printf("\nLa pelicula se estreno mundialmente en 2002, ademas,\n");	
		printf("llego a recaudar 649 millones de dolares.\n");
		regresarAlMenu();

	      } else if (decisionUsusario2 == NO) {
		EXIT_SUCCESS;

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }

      break;

      case 3: printf("\nStar Wars: Episode III – Revenge of the Sith\n");
	      printf("\nDesea, usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == SI) {
		printf("\nLa pelicula se estreno mundialmente en 2005, ademas,\n");	
		printf("llego a recaudar 848 millones de dolares.\n");
		regresarAlMenu();

	      } else if (decisionUsusario2 == NO) {
		EXIT_SUCCESS;

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }

      break;

      case 4: printf("\nStar Wars: Episode IV A New Hope\n");
	      printf("\nDesea, usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == SI) {
		printf("\nLa pelicula se estreno mundialmente en 1977, ademas,\n");	
		printf("llego a recaudar 775,8 millones de dolares.\n");
		regresarAlMenu();

 	      } else if (decisionUsusario2 == NO) {
		EXIT_SUCCESS;

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }     
      
      break;

      case 5: printf("\nStar Wars: Episode V - The Empire Strikes Back\n");
	      printf("\nDesea, usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == SI) {
		printf("\nLa pelicula se estreno mundialmente en 1980, ademas,\n");	
		printf("llego a recaudar 550,9 millones de dolares.\n");
		regresarAlMenu();

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();	
	      }


      break;

      case 6: printf("\nStar Wars: Episode VI - Return of the Jedi\n");
	      printf("\nDesea, usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == SI) {
		printf("\nLa pelicula se estreno mundialmente en 1983, ademas,\n");	
		printf("llego a recaudar 475 millones de dolares.\n");
		regresarAlMenu();

	      } else if (decisionUsusario2 == NO) {
		EXIT_SUCCESS;

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      } 
      break;

      case 7: printf("\nStar Wars: Episode VII – The Force Awakens\n");
	      printf("\nDesea, usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == SI) {
		printf("\nLa pelicula se estreno mundialmente en 2015, ademas,\n");	
		printf("llego a recaudar 2066 millones de dolares.\n");
		regresarAlMenu();

	      } else if (decisionUsusario2 == NO) {
		EXIT_SUCCESS;

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      } 

      break;

      case 8: printf("\nStar Wars: Episode VIII - The Last Jedi\n");
	      printf("\nDesea, usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == SI) {
		printf("\nLa pelicula se estreno mundialmente en 2017, ademas,\n");	
		printf("llego a recaudar 1333 millones de dolares.\n");
		regresarAlMenu();

	      } else if (decisionUsusario2 == NO) {
		EXIT_SUCCESS;

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      } 

      break;

      case 9: printf("\nStar Wars: Episode IX: The Rise of Skywalker\n");
	      printf("\nDesea, usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == SI) {
		printf("\nLa pelicula se estreno mundialmente en 2019, ademas,\n");	
		printf("llego a recaudar 1074 millones de dolares.\n");
		regresarAlMenu();

	      } else if (decisionUsusario2 == NO) {
		EXIT_SUCCESS;

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      } 

      break;

    }

  } else {
    printf("\nError: Usted ha ingresado una opcion invalida.\n");
    regresarAlMenu();
  }

}
