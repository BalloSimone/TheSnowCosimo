#include "Entity.h"

#include <ncurses.h>

#include <iostream>

Entity::Entity(WINDOW* win, int coordX, int coordY, int velocityX, int velocityY, const int maxXVel, const int maxYVel, int* ticks) {
    this->win = win;
    this->coordX = coordX;
    this->coordY = coordY;
    this->velocityX = velocityX;
    this->velocityY = velocityY;
    this->maxXVel = maxXVel;
    this->maxYVel = maxYVel;
    this->ticks = ticks;
}

void Entity::_undrawPlayer() {
    mvwaddch(this->win, coordY + 2, coordX, ' ');
    mvwaddch(this->win, coordY + 1, coordX, ' ');
    mvwaddch(this->win, coordY, coordX, ' ');
}

void Entity::_drawPlayer() {
    mvwaddch(this->win, coordY + 2, coordX, '.');
    mvwaddch(this->win, coordY + 1, coordX, '|');
    mvwaddch(this->win, coordY, coordX, 'O');
}

void Entity::move(int addX, int addY) {
    this->_undrawPlayer();
    this->coordX += addX;
    this->coordY += addY;
    this->_drawPlayer();
}

void Entity::_gravity() {
    if (this->lastYTick == -1 || ((*this->ticks / 10) - this->lastYTick) > 10) {
        this->lastYTick = (*this->ticks / 10);
        this->_undrawPlayer();
        this->coordY += 1;
        this->_drawPlayer();
    }
}

void Entity::tick() {
    this->_gravity();
    mvwprintw(win, 1, 20, "%d", *(this->ticks));
}
