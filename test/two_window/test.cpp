#include <ncurses.h>

int main() {
    initscr(); // 初始化ncurses庫
    cbreak(); // 禁用行緩衝
    noecho(); // 不顯示輸入字符
    curs_set(0); // 隱藏游標

    int maxX, maxY;
    getmaxyx(stdscr, maxY, maxX); // 獲取終端機大小

    WINDOW *mainWin = newwin(maxY-3, maxX, 0, 0); // 創建主遊戲畫面
    WINDOW *statusWin = newwin(3, maxX, maxY-3, 0); // 創建狀態區塊

    wborder(statusWin, '|', '|', '-', '-', '+', '+', '+', '+'); // 為狀態區塊添加邊框
    mvwprintw(statusWin, 1, 1, "Status: "); // 在狀態區塊中顯示文字

    int ch;
    do {
        wclear(mainWin); // 清空主遊戲畫面
        mvwprintw(mainWin, 1, 1, "Main Game Screen"); // 在主遊戲畫面中顯示文字
        wrefresh(mainWin); // 刷新主遊戲畫面

        ch = wgetch(statusWin); // 等待用户在狀態區塊中輸入字符
        mvwprintw(statusWin, 1, 9, "%c", ch); // 在狀態區塊中顯示用户輸入的字符
        wrefresh(statusWin); // 刷新狀態區塊
    } while (ch != 'q');

    endwin(); // 關閉ncurses庫
    return 0;
}


// int ch;
// while ((ch = wgetch(statusWin))) {
//     wclear(mainWin);
//     mvwprintw(mainWin, 1, 1, "Main Game Screen");
//     mvwprintw(statusWin, 1, 9, "%c", ch); // 在狀態區塊中顯示使用者輸入的字符
//     wborder(statusWin, '|', '|', '-', '-', '+', '+', '+', '+');
//     mvwprintw(statusWin, 1, 1, "Status: ");
//     wrefresh(mainWin);
//     wrefresh(statusWin);
//     if (ch == 'q') {
//         break;
//     }
// }
