#ifndef ENTITY_H
#define ENTITY_H

#define GRAVITY_TICKS 4

#include <ncurses.h>

#include <frontend/mapgui/MapGUI.hpp>
#include <iostream>

class Entity {
   protected:
    int clamp(const int val, const int min, const int max);

    WINDOW *win;
    int coordX;
    int coordY;

    int *ticks;

    MapGUI *mapGUIPtr;

    virtual void _undrawEntity() = 0;
    virtual void _drawEntity() = 0;
    // void _displayHealth();
    // void _displayCoins();
    // void _displayLives();

   public:
    Entity(WINDOW *win, int coordX, int coordY, int *ticks, MapGUI *mapGUIPtr);
    // virtual void move(int addX, int addY) = 0;
    virtual void tick() = 0;
    virtual bool isOnFloor() = 0;
    // void jump();
    // void collectCoins();
    // int health;  // 0 - 100
    // int coins;   // 0 - 100
    // int lives;   // 1 - 99
};

#endif