#include <cstdlib>
#include "Chunk.hpp"


Chunk::Chunk() {
}

void Chunk::create_chunk(int startHeight) {
    spawn_floor(startHeight);
}

void Chunk::spawn_platforms() {
}

void Chunk::spawn_floor(int startCoord) {
    int l = 0, h, i = 0, lastH = rand() % CHUNK_DIMENSION / 2 + CHUNK_DIMENSION / 3;
    bool pit;

    if(startCoord != -1) {
        l = rand() % (CHUNK_DIMENSION * LEN_NO_PIT / 100) + MIN_LUNG_PLAT;
        while(l > 0 && i < CHUNK_DIMENSION){
            floor_y[i] = h;
            i++;
            l--;
        }
    }

    while (i < CHUNK_DIMENSION){

        //pit
        pit = false;
        if(rand() % 100 + 1 < PERC_PIT) pit = true;

        //length
        if(pit) l = rand() % (CHUNK_DIMENSION * LEN_PIT / 100) + MIN_LUNG_PLAT;
        else l = rand() % (CHUNK_DIMENSION * LEN_NO_PIT / 100) + MIN_LUNG_PLAT;

        //height
        if(pit && (i != 0) && l+i < CHUNK_DIMENSION) h = 0;
        else if(h <= DIFF_BEET_PLAT) h = (rand() % DIFF_BEET_PLAT  + 1) + lastH;
        else h = (rand() % DIFF_BEET_PLAT * 2 - DIFF_BEET_PLAT) + lastH;

        if(h < 0) h = 0;
        if(!pit && h != 0) lastH = h;

        while(l > 0 && i < CHUNK_DIMENSION){
            floor_y[i] = h;
            i++;
            l--;
        }

    }


}