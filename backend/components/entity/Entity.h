#ifndef ENTITY_H
#define ENTITY_H

#include <ncurses.h>

#include <iostream>

class Entity {
   protected:
    int clamp(const int val, const int min, const int max);

    WINDOW *win;
    int coordX;
    int coordY;
    int velocityX;
    int velocityY;
    int maxXVel;
    int maxYVel;

    int *ticks;
    int lastYTick;
    int jumpTick;
    bool isJumping;
    int shownHealth;  // health shown in bar
    int shownCoins;   // don't re-render
    int shownLives;   // don't re-render

    void _undrawPlayer();
    void _drawPlayer();
    void _gravity();
    void _displayHealth();
    void _displayCoins();
    void _displayLives();

   public:
    Entity(WINDOW *win, int coordX, int coordY, int velocityX, int velocityY, const int maxXVel, const int maxYVel, int *ticks);
    void move(int addX, int addY);
    void tick();
    void jump();
    void collectCoins();
    int health;  // 0 - 100
    int coins;   // 0 - 100
    int lives;   // 1 - 99
};

#endif