#include <ncurses.h>

int main() {
  // 初始化 ncurses 函式庫
  initscr();

  // 設定邊框
  int height = 3;
  int width = 16;
  int y = (LINES - height) / 2;
  int x = (COLS - width) / 2;
  box(stdscr, '*', '*');

  // 在框內顯示 "Hello, World!"
  mvprintw(y + 1, x + 3, "Hello, World!");

  // 刷新螢幕以顯示訊息
  refresh();

  // 等待用戶按下 'q' 鍵
  while (getch() != 'q')
    ;

  // 關閉 ncurses 函式庫
  endwin();

  return 0;
}
