//
// Created by Simone Ballo on 23/11/22.
//

#ifndef LEVEL_H
#define LEVEL_H

#include "chunk/Chunk.h"
#define N_CHUNCKS 4

class Level {
    Chunk chunks[N_CHUNCKS];

   protected:
    void generateLevel();
};

#endif