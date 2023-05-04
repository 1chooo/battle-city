/**
 * @file welcome.cpp
 * @author @1chooo
 * @brief Welcome Page
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "role.h"
#include "welcome.h"
#include "rule.h"
#include <ncurses.h>

extern int MAX_X;
extern int MAX_Y;
extern void drawRuleScene();


// SCREEN* drawTest() {

//   SCREEN* scr = newterm(NULL, stdout, stdin);
//   return scr;
// }

void drawWelcomeScene() {

  // 取得當前終端機的大小
  int maxX, maxY;
  getmaxyx(stdscr, maxY, maxX);

  // 設定終端機大小
  MAX_X = maxX > 127 ? 127 : maxX;
  MAX_Y = maxY > 39 ? 39 : maxY;
  resize_term(MAX_Y, MAX_X);

  // 繪製歡迎畫面
  clear();
  box(stdscr, '*', '*');

  int y = (MAX_Y - 7) / 2;  // 7 是 *tank 的行數
  int x = (MAX_X - 23) / 2; // 23 是 *tank 中最長的一行的長度

  Role tank(tankBody, 7, 23);
  tank.draw(y, x);
  mvprintw(MAX_Y-2, 1, "x:%2d y:%2d", MAX_X, MAX_Y);

  refresh();
  
  while (true) {
    int ch = getch();

    if (ch == 'q') 
      break;
    else if (ch == 'n') 
      drawRuleScene();
      break;
  }

  endwin();
}


// void drawWelcomeScene() {

//   initscr();
//   wresize(stdscr, MAX_Y, MAX_X);
//   box(stdscr, '*', '*');

//   int y = (MAX_Y - 7) / 2;  // 7 是 *tank 的行數
//   int x = (MAX_X - 23) / 2; // 23 是 *tank 中最長的一行的長度

//   Role tank(tankBody, 7, 23);
//   tank.draw(y, x);

//   refresh();
  
//   while (true) {
//     int ch = getch();

//     if (ch == 'q') 
//       break;
//     else if (ch == 'n') 
//       drawRuleScene();
//   }

//   endwin();
// }


/*
void initialWelcomeScene(WINDOW* win) {
  wresize(win, MAX_Y, MAX_X);
  box(win, '*', '*');

  int y = (MAX_Y - 7) / 2;
  int x = (MAX_X - 23) / 2;

  Role tank(tankBody, 7, 23);
  tank.draw(y, x);

  wrefresh(win);
  while (getch() != 'q')
    ;
}
*/

