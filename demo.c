#include <stdlib.h>      // stdlib needed for getch
#include <ncurses.h>     // ncurses library
/* Internal function declarations   */
int food1 ();
int  snake ();           
int reload();

/* main function */

int main(void) {
  initscr();
  noecho();
  curs_set(FALSE);
  snake();

  
  // reload();

  

  endwin();
  return 0;
} 

/* internal functions  */
int reload()
{	
refresh();
  getch();
}

int row = 10, column = 33;
int  snake (){
char  body[] = "***";

  for(column=33;column<2000;column++){
	food1();
	mvprintw(row, column, body);
	reload();
	clear();
	
        if (column == 35){
        char body[]= "****";
	int food1() {
	mvprintw(10,50,"*");
	}
	reload();
	clear();
	}

}
}
int  food1 (){
  mvprintw(10, 38,"*");
}

