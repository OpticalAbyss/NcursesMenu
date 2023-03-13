#include <ncurses.h>
#include <aio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>

#include "include/windows.h" 

int main(int argc, char** argv)
{
  initscr();
  noecho();
  cbreak();
  //Enables Function Keys
  curs_set(0);

  //Terminal Width
  int terminal_Max_X, initx;
  //Terminal Height
  int terminal_Max_Y, inity;

  getmaxyx(stdscr, terminal_Max_Y, terminal_Max_X);
  initx = terminal_Max_X;
  inity = terminal_Max_Y;


  WINDOW * outputBox = newwin(
    (int)(terminal_Max_Y) / 4,
    (int)(terminal_Max_X) * 0.92, 
    (int)(terminal_Max_Y) * 0.75,
    (int)(terminal_Max_X) * 0.04 
  );
  

  WINDOW * playBox = newwin(
    (int)(terminal_Max_Y) * 0.75,
    (int)(terminal_Max_X) * 0.92, 
    (int)(terminal_Max_Y) * 0,
    (int)(terminal_Max_X) * 0.04 
  );

  // WINDOW** box = malloc(sizeof(WINDOW*) * 3);
  // box[0] = outputBox;
  // box[1] = playBox;
  // box[2] = NULL;

  keypad(outputBox , 1);

  char* c1[] = {"Home", "Options", "Exit"};
  int choice;
  uint32_t highlight;

  while(1)
  {
    getmaxyx(stdscr, terminal_Max_X, terminal_Max_Y);
    // Checks to See if Terminal Has been resized
    if(terminal_Max_X != initx || terminal_Max_Y != inity)
    {
      wresize(outputBox,
        getmaxy(stdscr) / 4 ,
        getmaxx(stdscr) * 0.92
      );

      mvwin(outputBox,
        getmaxy(stdscr) * 0.75,
        getmaxx(stdscr) * 0.04
      );

      wresize(playBox,
        getmaxy(stdscr) * 0.75,
        getmaxx(stdscr) * 0.92
      );

      mvwin(playBox,
        getmaxy(stdscr) * 0,
        getmaxx(stdscr) * 0.04
      );

      initx = terminal_Max_X;
      inity = terminal_Max_Y;
      clear();
      refresh();
      wclear(playBox);
      box(playBox, 0 , 0);
      wclear(outputBox);
      box(outputBox, 0 , 0);
    }
    // resizeBox(box, stdscr);


    //Button Drawer
    int i;
    for(i = 0 ; i < 3 ; i++)
    {
      if(highlight == i)
        wattron(outputBox, A_REVERSE);
      mvwprintw(outputBox, i + 1, 1 , "%d. %s %c", i + 1, c1[i] , '\0');
      wattroff(outputBox, A_REVERSE);
    }

    choice = wgetch(outputBox);


    //Button selector
    switch(choice)
    {
      case KEY_UP:
        highlight--;
        if(highlight > 2)
          highlight = 0;
        break;
      case KEY_DOWN:
        highlight++;
        if(highlight > 2)
          highlight = 2;
        break;
      default:
        break;
    }

    //Open Respective Menu
    if(choice == 10)
    {
      switch(highlight)
      {
        case 0:
          wclear(playBox);
          box(playBox, 0 , 0);
          mvwprintw(playBox, 1, (getmaxx(playBox) / 2) - 4, "Home%c", '\0');
          
          break;

        case 1:
          wclear(playBox);
          box(playBox, 0 , 0);
          mvwprintw(playBox, 1, (getmaxx(playBox) / 2) - 4, "Options%c", '\0');
          break;

        case 2:
          goto exit_seq;
          break;
      }
      wrefresh(playBox);
    }
  }
  exit_seq: ;
  
  // free(box);
  endwin();
  return 0;    
}