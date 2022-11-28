#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity.h"

#define JUMP_TICKS 10
#define JUMP_HEIGHT 4

class Player : public virtual Entity {
    // overridden methods
   protected:
    void _undrawEntity();
    void _drawEntity();

    void _displayHealth();
    void _displayCoins();
    void _displayLives();
    void _gravity();

    int lastYTick;
    int jumpTick;
    bool isJumping;
    int shownHealth;  // health shown in bar
    int shownCoins;   // don't re-render
    int shownLives;   // don't re-render

   public:
    Player(WINDOW *win, int coordX, int coordY, int *ticks);
    void move(int addX, int addY);
    void tick();
    void jump();
    void collectCoins();
    int health;  // 0 - 100
    int coins;   // 0 - 100
    int lives;   // 1 - 99
};

#endif