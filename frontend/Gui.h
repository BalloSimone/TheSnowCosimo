#include "mapgui/MapGUI.cpp"
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
