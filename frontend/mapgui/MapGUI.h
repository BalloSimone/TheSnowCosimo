#include "../../backend/components/map/Level.h"
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
    void drawBorders( int x1, int y1, int x2, int y2);
};

