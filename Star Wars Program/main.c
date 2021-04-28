/* Un programa que muestre un menu
 * donde el usuario pueda elegir
 * el episodio de una pelicula del
 * universo de Star Wars, y el pro-
 * grama muestre el nombre corres-
 * pondiente.
 */

#include <stdio.h>
#include <stdlib.h>

#define PRIMERA_OPCION 1
#define ULTIMA_OPCION 10
#define Si 'y'
#define No 'n'

// Prototipado
int menu();
void regresarAlMenu();

// Main
int main(void) {
  int decisionUsusario;
  char decisionUsusario2;
  
  decisionUsusario = menu();

  if (decisionUsusario >= PRIMERA_OPCION && decisionUsusario < ULTIMA_OPCION) {
    switch(decisionUsusario) {
      case 1: printf("\nStar Wars: Episode I - The Phantom Menace\n");
	      printf("\nDesea usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == Si || decisionUsusario2 == No) {
		printf("\nLa pelicula se estreno mundialmente en 1999,\n");	
		printf("ademas, llego a recaudar 1027 millones de dolares.\n");
		regresarAlMenu();

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }
      break;

      case 2: printf("\nStar Wars: Episode II – Attack of the Clones\n");
	      printf("\nDesea usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == Si || decisionUsusario2 == No) {
		printf("\nLa pelicula se estreno mundialmente en 2002,\n");	
		printf("ademas, llego a recaudar 649 millones de dolares.\n");
		regresarAlMenu();

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();	
	      }

      break;

      case 3: printf("\nStar Wars: Episode III – Revenge of the Sith\n");
	      printf("\nDesea usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == Si || decisionUsusario2 == No) {
		printf("\nLa pelicula se estreno mundialmente en 2005,\n");	
		printf("ademas, llego a recaudar 848 millones de dolares.\n");
		regresarAlMenu();

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
	        regresarAlMenu();
	      }
      break;

      case 4: printf("\nStar Wars: Episode IV A New Hope\n");
	      printf("\nDesea usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == Si || decisionUsusario2 == No) {
		printf("\nLa pelicula se estreno mundialmente en 1977,\n");	
		printf("ademas, llego a recaudar 775,8 millones de dolares.\n");
		regresarAlMenu();

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }
      break;

      case 5: printf("\nStar Wars: Episode V - The Empire Strikes Back\n");
	      printf("\nDesea usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == Si || decisionUsusario2 == No) {
		printf("\nLa pelicula se estreno mundialmente en 1980,\n");	
		printf("ademas, llego a recaudar 550,9 millones de dolares.\n");
		regresarAlMenu();

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }
      break;

      case 6: printf("\nStar Wars: Episode VI - Return of the Jedi\n");
	      printf("\nDesea usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == Si || decisionUsusario2 == No) {
		printf("\nLa pelicula se estreno mundialmente en 1983,\n");	
		printf("ademas, llego a recaudar 475 millones de dolares.\n");
		regresarAlMenu();

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }
      break;

      case 7: printf("\nStar Wars: Episode VII – The Force Awakens\n");
	      printf("\nDesea usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == Si || decisionUsusario2 == No) {
		printf("\nLa pelicula se estreno mundialmente en 2015,\n");	
		printf("ademas, llego a recaudar 2066 millones de dolares.\n");
		regresarAlMenu();

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }

      break;

      case 8: printf("\nStar Wars: Episode VIII - The Last Jedi\n");
	      printf("\nDesea usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == Si || decisionUsusario2 == No) {
		printf("\nLa pelicula se estreno mundialmente en 2017,\n");	
		printf("ademas, llego a recaudar 1333 millones de dolares.\n");
		regresarAlMenu();

	      } else {
		printf("Error: Usted ha ingresado una opcion invalida.");	
		regresarAlMenu();
	      }

      break;

      case 9: printf("\nStar Wars: Episode IX: The Rise of Skywalker\n");
	      printf("\nDesea usted, saber mas sobre la pelicula? [y/n] ");
	      scanf(" %c", &decisionUsusario2);
	      
	      if (decisionUsusario2 == Si || decisionUsusario2 == No) {
		printf("\nLa pelicula se estreno mundialmente en 2019,\n");	
		printf("ademas, llego a recaudar 1074 millones de dolares.\n");
		regresarAlMenu();

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

  
  return EXIT_SUCCESS;
}

int menu() {

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

  if (decisionUsusario3 == Si) {
    main();
  } else {
    EXIT_SUCCESS;
  }

}
