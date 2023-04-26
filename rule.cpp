/**
 * @file rule.cpp
 * @author @1chooo
 * @brief 
 * @version 0.1
 * @date 2023-04-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "role.h"
#include "welcome.h"
#include "rule.h"
#include <ncurses.h>

void clearWelcomeScene() {
  clear();

  wresize(stdscr, MAX_Y, MAX_X);
  box(stdscr, '*', '*');
}

// void drawRuleScene() {

//   clearWelcomeScene();
  
//   mvprintw(MAX_Y / 2, MAX_X / 2 - 5, "RULE");
//   refresh();

//   while (true) {
//     int ch = getch();

//     if (ch == 'q') 
//       break;
//   }
//   endwin();
// }

void drawRuleScene() {

  clear();

  int maxX, maxY;
  getmaxyx(stdscr, maxY, maxX);

  // 設定終端機大小
  MAX_X = maxX > 127 ? 127 : maxX;
  MAX_Y = maxY > 39 ? 39 : maxY;
  resize_term(MAX_Y, MAX_X);

  clear();
  box(stdscr, '*', '*');

  int y = (MAX_Y - 7) / 2;  // 7 是 *tank 的行數
  int x = (MAX_X - 23) / 2; // 23 是 *tank 中最長的一行的長度

  mvprintw(MAX_Y / 2, MAX_X / 2 - 5, "RULE");
  mvprintw(MAX_Y-2, 1, "x:%2d y:%2d", MAX_X, MAX_Y);

  refresh();

  bool running = true;
  while (running) {
    int ch = getch();

    if (ch == 'q') 
      running = false;
  }

}