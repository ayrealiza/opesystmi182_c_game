#include <ncurses.h>
int main(int argc, char ** argv )
{
 initscr();
 cbreak();
 noecho();

 int height, width,start_y, start_x;
 height = 100;
 width = 150;
 start_y = start_x = 0;

 WINDOW * win =  newwin(height, width, start_y, start_x);
 refresh();

 char c = 'g';
 wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
 mvwprintw(win,1,1, "this is my box");
 wrefresh(win);
 getch();
 getch();
 endwin();

 return 0;

}
