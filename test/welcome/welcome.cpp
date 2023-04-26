#include <ncurses.h>
#include <string>

class Role {
public:
    Role(const char** body, int height, int width) : 
        myBody(body), 
        myHeight(height), 
        myWidth(width) {}
    void draw(int y, int x) const {
        for (int i = 0; i < myHeight; i++) {
            mvprintw(y + i, x, "%s", myBody[i]);
        }
    }
private:
    const char** myBody;
    int myHeight;
    int myWidth;
};

const char *tank_body[7] = {
  "       \\                ",
  "       _\\______         ",
  "      /        \\=======D",
  " ____|_HUA_TANK_\\_____  ",
  "/ ___WHERE_ARE_YOU?__ \\ ",
  "\\/ _===============_ \\/ ",
  "  \\-===============-/   ",
};

int main(void) {
    initscr();
    box(stdscr, '*', '*');

    // 取得螢幕的行數和列數
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    // 計算正中央的座標
    int y = (max_y - 7) / 2;  // 7 是 *tank 的行數
    int x = (max_x - 23) / 2; // 23 是 *tank 中最長的一行的長度

    // 在正中央印出 *tank
    Role tank(tank_body, 7, 23);
    tank.draw(y, x);

    // 刷新螢幕以顯示訊息
    refresh();
    while (getch() != 'q');

    endwin();
    return 0;
}
