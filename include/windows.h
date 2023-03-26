#ifndef INCLUDE_WINDOWS_H
#define INCLUDE_WINDOWS_H

#include <ncurses.h>
#include <float.h>

typedef struct Window{
  
  WINDOW* parent;
  WINDOW* win;

  double win_Height;
  double win_Width;
  double win_startY;
  double win_startX;
} window_t;

/* Resizes the window according to the specified ration in win_height and win_Width */
uint8_t window_resize(window_t win);

/* Resizes the window according to the specified ratio in win_start_Y and win_start_X */
uint8_t window_move(window_t win);

// Creates a Window Object
window_t window_create(WINDOW* parent ,double height,double width,double start_Y,double start_X);

// Deletes a Window Object
void window_destory(window_t win);

uint8_t window_clear(window_t win); // Clears Window

void window_create_box(window_t win, uint8_t y, uint8_t x);


#endif //WINDOW.H