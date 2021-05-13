#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

#define TICKRATE 100

#define ANCHO_MUNDO 50
#define ALTURA_MUNDO 20 

#define SNAKEY_LENGTH 40

enum direccion {UP, DOWM, LEFT, RIGHT};

typedef struct spart {
   int x;
   int y;
} snakeypart;

int move_snakey(WINDOW *win, int direccion,
	        snakeypart snakey[]);

int main(int argc, char *argv[]) {
   WINDOW *snakeysWorld;
   int offsetx, offsety, i, ch;

   initscr();
   noecho();
   cbreak();
   timeout(TICKRATE);
   keypad(stdscr, true);

   printw("PieceOfCakeSnake v. 1.0 - Press x to quit!");

   refresh();

   offsetx = (COLS - ANCHO_MUNDO) / 2;
   offsety = (LINES - ALTURA_MUNDO) / 2;

   snakeysWorld = newwin(ALTURA_MUNDO,
			 ANCHO_MUNDO,
			 offsety,
			 offsetx);

   snakeypart snakey[SNAKEY_LENGTH];

   int sbegx = (ANCHO_MUNDO - SNAKEY_LENGTH) / 2;
   int sbegy = (ALTURA_MUNDO - 1) / 2;
   for (int i = 0; i < SNAKEY_LENGTH; i++) {
      snakey[i].x = sbegx + 1;
      snakey[i].y = sbegy;
   }

   int cur_dir = RIGHT;

   while ((ch = getch()) != 'x') {
      move_snakey(snakeysWorld, cur_dir, snakey);
      if (ch != ERR) {
	 switch (ch) {
	    case KEY_UP:
	       cur_dir = UP;
	       break;
	    case KEY_DOWN:
	       cur_dir = DOWM;
	       break;
	    case KEY_RIGHT:
	       cur_dir = RIGHT;
	       break;
	    case KEY_LEFT:
	       cur_dir = LEFT;
	    default:
	       break;
	 }
      }
   }

   delwin(snakeysWorld);

   endwin();

   return 0;
}

int move_snakey(WINDOW *win, int direccion,
	        snakeypart snakey[]) {

   wclear(win);

   for (int i = 0; i < SNAKEY_LENGTH - 1; i++) {
      snakey[i] = snakey[i + 1];
      mvwaddch(win, snakey[i].y, snakey[i].x, '#');
   }

   int x = snakey[SNAKEY_LENGTH - 1].x;
   int y = snakey[SNAKEY_LENGTH -1].y;
   switch (direccion) {
      case UP:
	 y - 1 == 0 ? y = ALTURA_MUNDO - 2 : y--;
	 break;
      case DOWM:
	 y + 1 == ALTURA_MUNDO - 1 ? y = 1 : y++;
	 break;
      case RIGHT:
	 x + 1 == ANCHO_MUNDO - 1 ? x = 1 : x++;
	 break;
      case LEFT:
	 x - 1 == 0 ? x = ANCHO_MUNDO - 2 : x--;
	 break;
      default:
	 break;
   }

   snakey[SNAKEY_LENGTH - 1].x = x;
   snakey[SNAKEY_LENGTH - 1].y = y;

   mvwaddch(win, y, x, '#');

   box(win, 0, 0);

   wrefresh(win);

   return EXIT_SUCCESS;
}
