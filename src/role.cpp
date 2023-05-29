/**
 * @file role.cpp
 * @author @1chooo
 * @brief 
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "role.h"
#include <ncurses.h>

Role::Role(const char **body, int height, int width)
    : myBody(body), myHeight(height), myWidth(width) {}

void Role::draw(int y, int x) const {
    for (int i = 0; i < myHeight; i++) {
        mvprintw(y + i, x, "%s", myBody[i]);
    }
}

int MAX_X = 127;
int MAX_Y = 39;

const char *tankBody[7] = {
  "       \\                ",
  "       _\\______         ",
  "      /        \\=======D",
  " ____|_HUA_TANK_\\_____  ",
  "/ ___WHERE_ARE_YOU?__ \\ ",
  "\\/ _===============_ \\/ ",
  "  \\-===============-/   ",
};

const char *gameBogy[3] = {
  "(\\_/)",
  "|O\vO|",
  "|_|_|",
};

const char *bogyBody[5] = {
  " (\\_/) ",
  " |O\vO| ",
  "/ === \\", 
  "\\| X |/", 
  " |_|_| ",
};

const char *firstAnimationBogy[5] = {
  " \' (\\_/) ",
  "' /X_X/  ",
  "/ === \\  ",
  "\\| X |/  ",
  " |_|_|   ",
};

const char *secondAnimationBogy[5] = {
  " \'    (\\_/) ",
  "\' \\|'/X_X/  ",
  "/ === \\     ",
  "\\| X |/     ",
  " |_|_|      ",
};

const char *thirdAnimationBogy[5] = {
  " \\ | / (\\_/) ",
  "\' \\|/ '/X_X/ ",
  "/ === \\      ",
  "\\| X |/      ",
  " |_|_|       ",
};

const char *forthAnimationBogy[5] = {
  " \' | \'  \'        ",
  "\' \\|/ \'  \'\\X_X\\  ",
  "/ === \\    (/ \\) ",
  "\\| X |/          ",
  " |_|_|           ",
};

const char *fifthAnimationBogy[5] = {
  " \' \' \'           ",
  "  \\|/            ",
  "/ === \\    \\X_X\\ ",
  "\\| X |/    (/ \\) ",
  " |_|_|           ",
};
const char *sixthAniamtionBogy[6] = {
  "                   ",
  "  \'|\'              ",
  "/ === \\            ",
  "\\| X |/      \\X_X\\ ",
  " |_|_|       (/ \\) ",
};