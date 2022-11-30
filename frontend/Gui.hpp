#ifndef GUI_HPP
#define GUI_HPP

#include "mapgui/MapGUI.hpp"

#define WIN_LENGTH 128
#define WIN_HEIGTH 32

struct ListLevel {
    MapGUI level;
    ListLevel *prec;
    ListLevel *succ;
};
typedef ListLevel *Levels;

class Gui {
   public:
    MapGUI mapGui;
    WINDOW *screen;
    Gui(WINDOW *win);
    void succLevel();
    void precLevel();
};

#endif
