#ifndef MAPGUI_HPP
#define MAPGUI_HPP

#include <ncurses.h>

#include "../../backend/components/map/Level.hpp"

#define MAP_LENGTH 32
#define MAP_HEIGHT 32

#define SCALE 1
#define TOP_PADDING 15

class MapGUI {
   public:
    Level level;
    int maxY;
    MapGUI(WINDOW* scr);
    WINDOW* screen;
    void getLevel();
    void drawMap();

   private:
    void drawFloors();
    void drawPlatforms();
};

#endif
