#include <windows.h>
#include <ncurses.h>

uint8_t window_resize(window_t win)
{
  return wresize(win.win , getmaxy(win.parent) * win.win_Height , getmaxx(win.parent) * win.win_Width);
}

uint8_t window_move(window_t win)
{
  return wmove(win.win , getmaxy(win.parent) * win.win_startY , getmaxx(win.parent) * win.win_startX);
}

window_t window_create(WINDOW* parent ,double height,double width,double start_Y,double start_X)
{
  window_t win;
  
  win.win = newwin(getmaxy(parent) * height, getmaxx(parent) * width, getmaxy(parent) * start_Y, getmaxx(parent) * start_X);
  
  win.parent = parent;
  
  win.win_Height = height;
  win.win_Width = width;
  win.win_startX = start_X;
  win.win_startY = start_Y;

  return win;
}

void window_destory(window_t win)
{
  delwin(win.win);
}

uint8_t window_clear(window_t win)
{
  wrefresh(win.win);
  wclear(win.win);
}

void window_create_box(window_t win, uint8_t y, uint8_t x)
{
  box(win.win, y , x);
}