#include <ncurses.h>

void resizeBox(WINDOW** box, WINDOW* mainWin)
{
  static int initx = 0, inity = 0;
  int T_x, T_y;
  getmaxyx(mainWin, T_x, T_y);
  // Checks to See if Terminal Has been resized

  if(T_x != initx || T_y != inity)
  {
    WINDOW* increment = NULL;
    int i = 0;
    // for(increment = box[0] ; increment != NULL ; increment++)
    for(i = 0 ; i < sizeof(box) / sizeof(WINDOW*) ; i++)
    {
      // if(increment)
      // {
      //   wresize(increment,
      //     getmaxy(mainWin) / 4 ,
      //     getmaxx(mainWin) * 0.92
      //   );
        
      //   mvwin(increment,
      //     getmaxy(mainWin) * 0.75,
      //     getmaxx(mainWin) * 0.04
      //   );
      // }
      wresize(box[i],
          getmaxy(mainWin) / 4 ,
          getmaxx(mainWin) * 0.92
        );
        
        mvwin(box[i],
          getmaxy(mainWin) * 0.75,
          getmaxx(mainWin) * 0.04
        );
    }

    initx = T_x;
    inity = T_y;
    wclear(mainWin);
    wrefresh(mainWin);

    // for(increment = box[0] ; increment != NULL ; increment++)
    for(i = 0 ; i < sizeof(box) / sizeof(WINDOW*) ; i++)
    {
      // if(increment)
      // {
      //   // wclear(increment);
      //   // box(increment, 0 , 0);
      // }
      wclear(box[i]);
      box(box[i], 0 , 0);
    }
  }
}
