#include <cstdlib>
#include "Chunk.h"
#include <iostream>



void Chunk::randomChunk() {
    spawn_floor();

}

void Chunk::spawn_platforms() {



}

void Chunk::spawn_floor() {
    int i=0, l, h;
    bool pit;
    int lNotPit = chunkDimension / 2;
    int lPit = chunkDimension / 4;
    while(i < chunkDimension){
        pit = false;

        //is there a pit or not?
        if((rand() % (chunkDimension)+1) > (chunkDimension - chunkDimension/3)) pit = true;

        //calculate length
        if(pit) l = rand() % lPit + 1;
        else l = rand() % lNotPit + 1;


        //calculate height
        if(pit && (i != 0) && (i+l < chunkDimension)) h = 0;
        else h = rand() % lNotPit + 1;

        //insert the block in the array
        while(l>0 && i<chunkDimension){
            floor_y[i] = h;
            l--;
            i++;
        }
    }

}
