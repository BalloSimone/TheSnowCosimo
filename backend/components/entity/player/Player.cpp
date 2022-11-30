#include "Player.hpp"

#include <frontend/Gui.hpp>
#include <frontend/mapgui/MapGUI.hpp>

#include "../Entity.hpp"

Player::Player(WINDOW *win, int coordX, int coordY, int *ticks, MapGUI *mapGUIPtr, int *pressedKey)
    : Entity(win, coordX, coordY, ticks, mapGUIPtr) {
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

    this->pressedKey = pressedKey;

    this->move(0, -this->coordY - 4 + this->mapGUIPtr->level.chunks->floor_y[10]);
}

void Player::tick() {
    this->_gravity();
    this->_displayHealth();
    this->_displayCoins();
    this->_displayLives();
    this->_inputMovements();
    // mvwprintw(win, 1, 20, "%d", *(this->ticks));
    mvwprintw(win, 1, 19, "yPos:%d", this->coordY);
    mvwprintw(win, 1, 27, "xPos:%d", this->coordX);
    mvwprintw(win, 1, 35, "jmpTick:%04d", this->jumpTick);
    mvwprintw(win, 1, 50, "isJmp:%d", this->isJumping);
    mvwprintw(win, 1, 58, "ticks:%d", *this->ticks);
    mvwprintw(win, 1, 71, "lastYTick:%d", this->lastYTick);
    mvwprintw(win, 1, 88, "isOnFloor:%d", this->isOnFloor());
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
    if (this->lastYTick == -1) this->lastYTick = *this->ticks;
    if (
        ((*this->ticks - this->lastYTick) > GRAVITY_TICKS) && !this->isOnFloor() && !this->isJumping) {
        this->lastYTick = *this->ticks;
        this->_undrawEntity();
        this->move(0, 1);
        this->_drawEntity();
    }
}

void Player::jump() {
    // check not in the air
    if (!this->isJumping && (this->jumpTick == -1 || *this->ticks - this->jumpTick > JUMP_TICKS)) {
        this->isJumping = true;
        this->jumpTick = *this->ticks;
        if (this->coordY > this->_getFloorY(this->coordX) + 2) {
            this->move(0, this->_getFloorY(this->coordX) - this->coordY + 1);
        } else {
            this->move(0, -JUMP_HEIGHT);
        }
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

    if (this->_getFloorY(this->coordX + addX + (addX > 0 ? 0 : -1)) + 1 >= this->coordY) {
        this->coordX = this->clamp(this->coordX + addX, 1, WIN_LENGTH - 2);
    }
    this->coordY = this->clamp(this->coordY + addY, 1, this->mapGUIPtr->maxY - 3);
    this->_drawEntity();
}

int Player::_getFloorY(int coordX) {
    return this->mapGUIPtr->maxY + TOP_PADDING - this->mapGUIPtr->level.chunks->floor_y[coordX] - 4;
}

bool Player::isOnFloor() {
    // if (*this->ticks % 5 == 0)
    mvwprintw(this->win, 3, 7, "Floor[%003d]=%003d floorY-1=%d floorY+1=%d", this->coordX, this->_getFloorY(this->coordX), this->_getFloorY(this->coordX - 1), this->_getFloorY(this->coordX + 1));
    return this->coordY > this->_getFloorY(this->coordX) || this->coordY > this->_getFloorY(this->coordX - 1);
}

void Player::_inputMovements() {
    if (this->pressedKey == NULL) return;

    if (*this->pressedKey == 'a') {
        this->move(-1, 0);
        mvwprintw(win, 4, 1, "left ");
    } else if (*this->pressedKey == 'd') {
        this->move(1, 0);
        mvwprintw(win, 4, 1, "right");
    } else if (*this->pressedKey == ' ') {
        this->jump();
        mvwprintw(win, 4, 1, "jump ");
    } else if (*this->pressedKey == 'e') {
        // attacca eugenio
    } else if (*this->pressedKey == 'c') {
        // DEBUG
        this->coins += 5;
    } else if (*this->pressedKey == 'v') {
        // DEBUG
        this->lives += 1;
    }
}