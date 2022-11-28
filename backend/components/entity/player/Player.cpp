#include "Player.h"

#include <frontend/Gui.h>

#include "../Entity.h"

#define JUMP_TICKS 10
#define JUMP_HEIGHT 4

Player::Player(WINDOW *win, int coordX, int coordY, int *ticks)
    : Entity(win, coordX, coordY, ticks) {
    this->health = 100;  // 0 - 100
    this->coins = 0;     // 0 - 100
    this->lives = 5;     // 1 - 99

    // these have a default value
    this->lastYTick = -1;
    this->jumpTick = -1;
    this->isJumping = false;
    this->shownHealth = 0;  // health shown in bar
    this->shownCoins = -1;  // don't re-render
    this->shownLives = -1;  // don't re-render
}

void Player::tick() {
    this->_gravity();
    this->_displayHealth();
    this->_displayCoins();
    this->_displayLives();
    // mvwprintw(win, 1, 20, "%d", *(this->ticks));
    mvwprintw(win, 1, 18, "yPos:%d", this->coordY);
    mvwprintw(win, 1, 24, "xPos:%d", this->coordX);
    mvwprintw(win, 1, 32, "jmpTick:%04d", this->jumpTick);
    mvwprintw(win, 1, 45, "isJmp:%d", this->isJumping);
}

void Player::_undrawEntity() {
    mvwaddch(this->win, coordY + 2, coordX, ' ');
    mvwaddch(this->win, coordY + 1, coordX, ' ');
    mvwaddch(this->win, coordY, coordX, ' ');
}

void Player::_drawEntity() {
    mvwaddch(this->win, coordY + 2, coordX, '.');
    mvwaddch(this->win, coordY + 1, coordX, '|');
    mvwaddch(this->win, coordY, coordX, 'O');
}

void Player::_gravity() {
    // DEBUG: get floor && remove hardcoded max y value && check player is not in the air
    if (*this->ticks - this->jumpTick > JUMP_TICKS) {
        this->isJumping = false;
    }
    if (
        (this->lastYTick == -1 || (*this->ticks - this->lastYTick) > GRAVITY_TICKS) && (this->coordY < 27) && !this->isJumping) {
        this->lastYTick = *this->ticks;
        this->_undrawEntity();
        this->coordY += 1;
        this->_drawEntity();
    }
}

void Player::jump() {
    // check not in the air
    if (!this->isJumping && (this->jumpTick == -1 || *this->ticks - this->jumpTick > JUMP_TICKS)) {
        this->isJumping = true;
        this->jumpTick = *this->ticks;
        this->move(0, -JUMP_HEIGHT);
    }
}

void Player::_displayHealth() {
    if (this->health == this->shownHealth) return;
    if (this->health > this->shownHealth) {
        this->shownHealth++;
    } else {
        this->shownHealth--;
    }

    // xp bar
    mvwprintw(this->win, 2, 1, "Hp: ");
    // 1 = bianco su nero
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // 2 = xp bar bianca
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
    // 3 = xp bar rossa
    init_pair(3, COLOR_RED, COLOR_RED);
    wattron(this->win, COLOR_PAIR(3));
    for (int i = 0; i < this->shownHealth / 10; i++) {
        wprintw(this->win, " ");
    }
    wattron(this->win, COLOR_PAIR(2));
    for (int i = 0; i < 10 - (this->shownHealth / 10); i++) {
        wprintw(this->win, " ");
    }
    wattron(this->win, COLOR_PAIR(1));
    wprintw(this->win, " %d", this->shownHealth);
    wprintw(this->win, "%%");
}

void Player::_displayCoins() {
    if (this->coins == this->shownCoins) return;
    if (this->coins > this->shownCoins) {
        this->shownCoins++;
    } else {
        this->shownCoins--;
    }

    // coin bar
    mvwprintw(this->win, 2, 24, "Monete: ");
    wprintw(this->win, "%02d", this->shownCoins);
}

void Player::_displayLives() {
    if (this->lives == this->shownLives) return;

    // animation not needed for lives
    this->shownLives = this->lives;

    // lives bar
    mvwprintw(this->win, 2, 38, "Vite: ");
    wprintw(this->win, "%02d", this->shownLives);
}

void Player::move(int addX, int addY) {
    this->_undrawEntity();
    this->coordX = this->clamp(this->coordX + addX, 1, WIN_LENGTH - 2);
    this->coordY = this->clamp(this->coordY + addY, 1, WIN_HEIGTH - 2);
    this->_drawEntity();
}
