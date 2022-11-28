#ifndef GUI_HPP
#define GUI_HPP


#include "mapgui/MapGUI.hpp"
#define WIN_LENGTH 1024
#define WIN_HEIGTH 768




struct ListLevel{
    MapGUI level;
    ListLevel* prec;
    ListLevel* succ;
};
typedef ListLevel* Levels;


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