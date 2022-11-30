#ifndef PLAYER_H
#define PLAYER_H

#include "../Entity.hpp"

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
    int _getFloorY(int coordX);
    void _inputMovements();

    int lastYTick;
    int jumpTick;
    bool isJumping;
    int shownHealth;  // health shown in bar
    int shownCoins;   // don't re-render
    int shownLives;   // don't re-render
    int *pressedKey;

   public:
    Player(WINDOW *win, int coordX, int coordY, int *ticks, MapGUI *mapGUIPtr, int *pressedKey);
    void move(int addX, int addY);
    void tick();
    void jump();
    void collectCoins();
    bool isOnFloor();
    int health;  // 0 - 100
    int coins;   // 0 - 100
    int lives;   // 1 - 99
};

#endif