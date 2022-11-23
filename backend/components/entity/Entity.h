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

    void _undrawPlayer();

    void _drawPlayer();

    void _gravity();

   public:
    Entity(WINDOW* win, int coordX, int coordY, int velocityX, int velocityY, const int maxXVel, const int maxYVel, int* ticks);
    void move(int addX, int addY);
    void tick();
};