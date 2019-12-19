
#include <ncurses.h>
typedef struct{short int x, y, c; bool movhor, movver;} object;

main() {
  object scr; int i = 0,cont=0; bool end=false;
  initscr();
  start_color();
  init_pair(1,COLOR_WHITE,COLOR_BLACK);
  keypad(stdscr,true);
  noecho();
  curs_set(0);
  getmaxyx(stdscr,scr.y,scr.x);
  object b1={scr.x-2,scr.y/2,0,false,false},b2={1,scr.y/2,0,false,false},b={scr.x/2,scr.y/2,0,false,false};
