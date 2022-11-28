#ifndef MAPGUI_HPP
#define MAPGUI_HPP

#include "../../backend/components/map/Level.hpp"
#include <ncurses.h>
#define MAP_LENGTH 32
#define MAP_HEIGHT 32



class MapGUI {
    protected:
        Level level;

    public:
        MapGUI();
        void getLevel();
        void drawMap();

private:

};

#endif
