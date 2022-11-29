//
// Created by Simone Ballo on 23/11/22.
//

#include "MapGUI.hpp"
#define SCALE 1
#define TOP_PADDING 15

MapGUI::MapGUI() {
    drawMap();
}


void MapGUI::drawMap() {
    drawFloors();   //draw floors
    drawPlatforms(); //draw platforms
    //box(stdscr, ACS_VLINE, ACS_HLINE); //draw the borders of a window


}

void MapGUI::drawFloors(){
    int maxY;
    maxY = getmaxy(stdscr);

    // DEBUG
    /*
    printw("Array: ");
    for(int i=0; i<N_CHUNKS; i++){
        for(int k=0; k<CHUNK_DIMENSION; k++)
            printw("%d ", level.chunks[i].floor_y[k]);
    }
    */

    int x = 0;
    //DRAW FLOOR
    for(Chunk chunk : level.chunks){

        for(int i=0; i<CHUNK_DIMENSION; i++){
            int k=0;
            while(k<SCALE){
                //print floor
                mvaddch(((maxY + TOP_PADDING) - chunk.floor_y[i]), x, ACS_HLINE);

                //print walls
                int h = abs(chunk.floor_y[i-1] - chunk.floor_y[i]);
                bool up = (chunk.floor_y[i-1] > chunk.floor_y[i]);
                int j = 0;

                if(up) j = chunk.floor_y[i-1];
                else j = chunk.floor_y[i];

                if (h>0 && i > 0){

                    if(up) mvaddch(((maxY + TOP_PADDING) - j), x, ACS_URCORNER);
                    else mvaddch(((maxY + TOP_PADDING) - j), x, ACS_ULCORNER);
                    h--;
                    j--;
                    while(h > 0){
                        mvaddch(((maxY + TOP_PADDING) - j), x, ACS_VLINE);
                        h--;
                        j--;
                    }
                    if(up) mvaddch(((maxY + TOP_PADDING) - j), x, ACS_LLCORNER);
                    else mvaddch(((maxY + TOP_PADDING) - j), x, ACS_LRCORNER);
                }
                k++;
                x++;
            }
        }
    }
}

void MapGUI::drawPlatforms(){
    int maxY = getmaxy(stdscr), x = 0;

    for(Chunk chunk : level.chunks){
        for(int i = 0; i < CHUNK_DIMENSION; i++){
            if(chunk.platform_y[i] != 0){

                mvaddch(maxY + TOP_PADDING - chunk.platform_y[i], x, ACS_HLINE);
                mvaddch(maxY + TOP_PADDING - chunk.platform_y[i] + chunk.platform_height[i], x, ACS_HLINE);
            }
            x++;
        }
    }
}

void MapGUI::getLevel() {

}
