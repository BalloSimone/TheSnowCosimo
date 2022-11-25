#ifndef GUI_H
#include "mapgui/MapGUI.h"

#define GUI_H

#define WIN_LENGTH 128
#define WIN_HEIGTH 32

struct ListLevel {
    MapGUI level;
    ListLevel *prec;
    ListLevel *succ;
};
typedef ListLevel *Levels;

class Gui {
   protected:
    MapGUI level;
    void initMap();

   public:
    WINDOW *screen;
    Gui(WINDOW *win);
    void succLevel();
    void precLevel();
};

#endif