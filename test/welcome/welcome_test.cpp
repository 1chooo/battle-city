#include <ncurses.h>
#include "role.h"

const char *tank[100] = {
  "       \\                ",
  "       _\\______         ",
  "      /        \\=======D",
  " ____|_HUA_TANK_\\_____  ",
  "/ ___WHERE_ARE_YOU?__ \\ ",
  "\\/ _===============_ \\/ ",
  "  \\-===============-/   ",
};

void initialize() {
  
  initscr();
  box(stdscr, '*', '*');

  // 取得螢幕的行數和列數
  int max_y, max_x;
  getmaxyx(stdscr, max_y, max_x);

  // 計算正中央的座標
  int y = (max_y - 7) / 2;  // 7 是 *tank 的行數
  int x = (max_x - 23) / 2; // 23 是 *tank 中最長的一行的長度

  // 在正中央印出 *tank
  for (int i = 0; i < 7; i++) {
    mvprintw(y + i, x, "%s", tank[i]);
  }

  // 刷新螢幕以顯示訊息
  refresh();
  while (getch() != 'q')
    ;

  endwin();
}

int main(void) {

  initialize();
  return 0;
}
