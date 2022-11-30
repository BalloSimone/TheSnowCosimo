#include <cstdlib>
#include "Chunk.hpp"
#include <ncurses.h>

Chunk::Chunk() {
}

void Chunk::create_chunk(int startHeight) {
    spawn_floor(startHeight);
    spawn_platforms();
    //debug();
}

void Chunk::spawn_platforms() {
    int i = 0;

    while(i < CHUNK_DIMENSION){
        bool plat = ((rand() % 100 + 1) < PLAT_PERC);
        if(plat && ((CHUNK_DIMENSION - i) > (MIN_PLAT_LEN * CHUNK_DIMENSION / 100))){
            int l = rand() % (MAX_PLAT_LEN * CHUNK_DIMENSION / 100) + (MIN_PLAT_LEN * CHUNK_DIMENSION / 100);
            int app = 0;


            //nel caso in cui la piattaforma sia sopra una buca, si fa riferimento all'altezza della piattaforma precedente
            if(floor_y[i] == 0){
                for(int k = i; floor_y[k] == 0; k--)
                    app = floor_y[k];
            }else app = floor_y[i];

            int h = app + (rand() % (DIST_FROM_FLOOR_MAX - DIST_FROM_FLOOR_MIN) + DIST_FROM_FLOOR_MIN);
            int plat_h = rand() % (H_PLAT_MAX - H_PLAT_MIN) + H_PLAT_MIN;

            while(l > 0 && (h - floor_y[i]) > DIST_FROM_FLOOR_MIN){
                platform_y[i] = h;
                platform_height[i] = plat_h;
                i++;
                l--;
            }
            i--;
        }else{
            platform_y[i] = 0;
            platform_height[i] = 0;
            i++;
        }

    }
}

void Chunk::spawn_floor(int startCoord) {

    int l = 0, h = 0, i = 0, lastH = rand() % CHUNK_DIMENSION / 2 + CHUNK_DIMENSION / 3;
    bool pit;

    if(startCoord != -1) {
        l = rand() % (CHUNK_DIMENSION * LEN_NO_PIT / 100) + (MIN_LUNG_FLOOR * CHUNK_DIMENSION / 100);
        while(l > 0 && i < CHUNK_DIMENSION){
            floor_y[i] = startCoord;
            i++;
            l--;
        }
        lastH = startCoord;
    }

    while (i < CHUNK_DIMENSION){

        //pit
        pit = false;
        if(rand() % 100 + 1 < PERC_PIT) pit = true;

        //length
        if(pit) l = rand() % (CHUNK_DIMENSION * LEN_PIT / 100) + (MIN_LUNG_FLOOR * CHUNK_DIMENSION / 100);
        else l = rand() % (CHUNK_DIMENSION * LEN_NO_PIT / 100) + (MIN_LUNG_FLOOR * CHUNK_DIMENSION / 100);

        //height
        if(pit && (i != 0) && l+i < CHUNK_DIMENSION - 1) h = 0;
        else if(h <= DIFF_BEET_FLOOR) h = (rand() % DIFF_BEET_FLOOR  + 1) + lastH;
        else h = (rand() % DIFF_BEET_FLOOR * 2 - DIFF_BEET_FLOOR) + lastH;

        if(h < 0) h = 0;
        if(!pit && h != 0) lastH = h;

        while(l > 0 && i < CHUNK_DIMENSION){
            floor_y[i] = h;
            i++;
            l--;
        }

    }
}

void Chunk::debug(){
    printw("PLAT:     ");
    for (int i = 0; i < CHUNK_DIMENSION; i++) {
        printw("%d ", platform_y[i]);
    }
    printw("\n");

    printw("H_PLAT:   ");
    for (int i = 0; i < CHUNK_DIMENSION; i++) {
        printw("%d ", platform_height[i]);
    }
    printw("\n");
}
