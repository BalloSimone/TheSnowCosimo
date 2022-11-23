#include <ncurses.h>

#include <iostream>

class Entity {
   protected:
    static int clamp(const int val, const int min, const int max) {
        return val < min ? min : val > max ? max
                                           : val;
    }

    WINDOW* win;
    int coordX;
    int coordY;
    int velocityX;
    int velocityY;
    int maxXVel;
    int maxYVel;

    int* ticks = NULL;
    int lastYTick = -1;
    int jumpTick = -1;
    bool isJumping = false;
    int shownHealth = 0;  // health shown in bar
    int shownCoins = -1;  // don't re-render
    int shownLives = -1;  // don't re-render

    void _undrawPlayer();
    void _drawPlayer();
    void _gravity();
    void _displayHealth();
    void _displayCoins();
    void _displayLives();

   public:
    Entity(WINDOW* win, int coordX, int coordY, int velocityX, int velocityY, const int maxXVel, const int maxYVel, int* ticks);
    void move(int addX, int addY);
    void tick();
    void jump();
    void collectCoins();
    int health = 100;  // 0 - 100
    int coins = 0;     // 0 - 100
    int lives = 5;     // 1 - 99
};