
#include "Entity.hpp"

#include <ncurses.h>

#include <iostream>

#include "frontend/Gui.hpp"

Entity::Entity(WINDOW* win, int coordX, int coordY, int* ticks) {
    this->win = win;
    this->coordX = coordX;
    this->coordY = coordY;
    this->ticks = ticks;
}

int Entity::clamp(int val, int min, int max) {
    return val < min ? min : val > max ? max
                                       : val;
}
