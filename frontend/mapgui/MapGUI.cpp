//
// Created by Simone Ballo on 23/11/22.
//

#include "MapGUI.hpp"
#define SCALE 1

MapGUI::MapGUI() {
    drawMap();
}


void MapGUI::drawMap() {
    int maxX, maxY;
    maxX = getmaxx(stdscr);
    maxY = getmaxy(stdscr);

    box(stdscr, ACS_VLINE, ACS_HLINE); //draw the borders of a window



    int x = 0;
    for(Chunk chunk : level.chunks){

        for(int y : chunk.floor_y){
            int i=0;
            while(i<SCALE){ mvaddch( maxY - y, x, '-'); i++; x++;}
        }
    }
}

void MapGUI::getLevel() {

}
