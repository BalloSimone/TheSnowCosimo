
#include "MapGUI.hpp"
#define SCALE 1
#define TOP_PADDING 20

MapGUI::MapGUI(WINDOW* scr) {
    screen = scr;
    drawMap();
}

MapGUI::MapGUI() {
}

void MapGUI::drawMap() {
    drawFloors();   //draw floors
    drawPlatforms(); //draw platforms
    box(screen, ACS_VLINE, ACS_HLINE); //draw the borders of a window
    debug(); //print debug things (for developers)
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
                mvwaddch(screen, ((maxY + TOP_PADDING) - chunk.floor_y[i]), x, ACS_HLINE);

                //print walls
                int h = abs(chunk.floor_y[i-1] - chunk.floor_y[i]);
                bool up = (chunk.floor_y[i-1] > chunk.floor_y[i]);
                int j = 0;

                if(up) j = chunk.floor_y[i-1];
                else j = chunk.floor_y[i];

                if (h>0 && i > 0){

                    if(up) mvwaddch(screen, ((maxY + TOP_PADDING) - j), x, ACS_URCORNER);
                    else mvwaddch(screen, ((maxY + TOP_PADDING) - j), x, ACS_ULCORNER);
                    h--;
                    j--;
                    while(h > 0){
                        mvwaddch(screen, ((maxY + TOP_PADDING) - j), x, ACS_VLINE);
                        h--;
                        j--;
                    }
                    if(up) mvwaddch(screen, ((maxY + TOP_PADDING) - j), x, ACS_LLCORNER);
                    else mvwaddch(screen, ((maxY + TOP_PADDING) - j), x, ACS_LRCORNER);
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

                mvwaddch(screen, maxY + TOP_PADDING - chunk.platform_y[i], x, ACS_HLINE);
                mvwaddch(screen, maxY + TOP_PADDING - chunk.platform_y[i] + chunk.platform_height[i], x, ACS_HLINE);

                if(chunk.platform_y[i-1] != chunk.platform_y[i] ) {
                    int h = chunk.platform_height[i];
                    mvwaddch(screen, maxY + TOP_PADDING - chunk.platform_y[i] + h, x, ACS_LLCORNER);
                    h--;
                    while(h > 0){
                        mvwaddch(screen, maxY + TOP_PADDING - chunk.platform_y[i] + h, x, ACS_VLINE);
                        h--;
                    }
                    mvwaddch(screen, maxY + TOP_PADDING - chunk.platform_y[i] + h, x, ACS_ULCORNER);
                }

                if(chunk.platform_y[i+1] != chunk.platform_y[i])  {
                    int h = chunk.platform_height[i];
                    mvwaddch(screen, maxY + TOP_PADDING - chunk.platform_y[i] + h, x, ACS_LRCORNER);
                    h--;
                    while(h > 0){
                        mvwaddch(screen, maxY + TOP_PADDING - chunk.platform_y[i] + h, x, ACS_VLINE);
                        h--;
                    }
                    mvwaddch(screen, maxY + TOP_PADDING - chunk.platform_y[i] + h, x, ACS_URCORNER);
                }

            }
            x++;
        }
    }
}

void MapGUI::debug(){
    wmove(screen, 0, 0);
    int cont_chunk = 0;
    for(Chunk chunk : level.chunks ){
        cont_chunk++;
        wprintw(screen, "FLOOR %d:   ", cont_chunk);
        for(int i=0; i<CHUNK_DIMENSION; i++){
            wprintw(screen, "%d ", chunk.floor_y[i]);
        }
        wprintw(screen, "\n");

        wprintw(screen, "PLAT %d:   ", cont_chunk);
        for(int i=0; i<CHUNK_DIMENSION; i++){
            wprintw(screen, "%d ", chunk.platform_y[i]);
        }
        wprintw(screen, "\n");

        wprintw(screen, "PLAT_HEIGHT %d:   ", cont_chunk);
        for(int i=0; i<CHUNK_DIMENSION; i++){
            wprintw(screen, "%d ", chunk.platform_height[i]);
        }
        wprintw(screen, "\n");
    }
}

Level MapGUI :: getLogicLevel() {
    return this->level;
}

void MapGUI :: changeLevel(int dir){ //+1 in avanti , -1 in dietro
    if(dir == 1) this->level = this->level.next_level;
    else if(dir == -1 && this->level.prec_level != nullptr) this->level = this->level.prec_level;
    //redraw map
}