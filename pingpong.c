 	 	
#include <ncurses.h>
typedef struct{short int x, y, c; bool movhor, movver;} object;

main(){
	


  object scr; int i = 0, cont=0; bool end=false;
  initscr();
  start_color(); //for  colors
  init_pair(1,COLOR_CYAN,COLOR_CYAN);
  init_pair(2,COLOR_CYAN,COLOR_BLACK);
  keypad(stdscr,true);
  noecho();
  curs_set(0);
  getmaxyx(stdscr,scr.y,scr.x);
  object b1={scr.x-5,scr.y/5,0,false,false},b2={4,scr.y/5,0,false,false},b={scr.x/5,scr.y/5,0,false,false};
  mvprintw(4,0,    //startup screen (controls)
  "\t \tCONTROLS\n"
  "\t \n"
  "\t \tPlayer 1: UP = 'a'   \n"
  "\t \tPlayer 1: DOWN = 'z' \n"
  "\t \n"
  "\t \tPlayer 2: UP = up arrow\n"
  "\t \tPlayer 2: DOWN  = down arrow\n"
  "\t \n"
  "\t \tPress ANY key to start \n"
  "\t \tPress 'p' for pause \n"
  "\t \tPress ESC to quit");
  getch();
  //how snake move
  for (nodelay(stdscr,1); !end; usleep(2000)) {
    if (++cont%16==0){
      if ((b.y==scr.y-1)||(b.y==1))
        b.movver=!b.movver;
      if ((b.x>=scr.x-5)||(b.x<=5)){
        b.movhor=!b.movhor;
        if ((b.y==b1.y-1)||(b.y==b2.y-1)) {
          b.movver=false;
        } else if ((b.y==b1.y+1)||(b.y==b2.y+1)) {
          b.movver=true;
        } else if ((b.y != b1.y) && (b.y != b2.y)) {
          (b.x>=scr.x-2) ? b1.c++: b2.c++;
          b.x=scr.x/2;
          b.y=scr.y/2;
        }
      }
      b.x=b.movhor ? b.x+1 : b.x-1;
      b.y=b.movver ? b.y+1 : b.y-1;

      if (b1.y<=1)
        b1.y=scr.y-2;
      if (b1.y>=scr.y-1)
        b1.y=2;
      if (b2.y<=1)
        b2.y=scr.y-2;
      if (b2.y>=scr.y-1)
        b2.y=2;
    }
    switch (getch()) {   //key controls
      case KEY_DOWN: b1.y++; break;
      case KEY_UP:   b1.y--; break;
      case 'a':      b2.y--; break;
      case 'z':      b2.y++; break;
      case 'p':      getchar(); break;
      case 0x1B:    endwin(); end++; break;
    }
    erase();
    attron(COLOR_PAIR(2)); //color for score
    mvprintw(2,scr.x/2-2,"%i | %i",b1.c,b2.c); //output of score
    attron(COLOR_PAIR(1)); //color for 
    mvvline(0,scr.x/2,ACS_VLINE,scr.y);//line divider
    attron(COLOR_PAIR(2)); // color for food
    mvprintw(b.y,b.x,"(o)"); //print food
      for(i=-1;i<2;i++){
      attron(COLOR_PAIR(2)); //color for paddles
      mvprintw(b1.y+i,b1.x,"[>"); //player2 paddle
      mvprintw(b2.y+i,b2.x,"<]"); //player1 paddle
     
    }
  }
}
