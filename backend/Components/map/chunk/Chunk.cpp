
#include "Chunk.h"

void initializeChunk(int x[], int y[], int lenCoord){
    for(int i=0; i<lenCoord; i++) {x[i] = 0; y[i] = 0;}
}

void Chunk::randomChunk() {
    initializeChunk(x, y, chunkDimension);
}