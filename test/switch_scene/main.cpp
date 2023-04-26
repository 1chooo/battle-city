#include <ncurses.h>
#include "screen1.h"
#include "screen2.h"

void clearScreen(WINDOW* win)
{
    // 清除窗口中的內容
    wclear(win);
    wrefresh(win);
}

int main()
{
    // 初始化 ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // 創建兩個窗口
    WINDOW* win1 = newwin(LINES, COLS, 0, 0);
    WINDOW* win2 = newwin(LINES, COLS, 0, 0);

    // 繪製畫面 1 的內容
    drawScreen1(win1);

    // 刷新屏幕
    wrefresh(win1);

    // 等待用戶按下任意按鍵
    getch();

    // 清除畫面 1 的內容，切換到畫面 2
    clearScreen(win1);
    drawScreen2(win2);
    wmove(win2, 0, 0);

    // 刷新屏幕
    wrefresh(win2);

    // 等待用戶按下任意按鍵
    getch();

    // 清除畫面 2 的內容，切換回畫面 1
    clearScreen(win2);
    drawScreen1(win1);
    wmove(win1, 0, 0);

    // 刷新屏幕
    wrefresh(win1);

    // 等待用戶按下任意按鍵
    getch();

    // 釋放資源，
    delwin(win1);
    delwin(win2);
    endwin();
    return 0;
}
