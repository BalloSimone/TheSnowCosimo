#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "chunk/Chunk.hpp"
#define N_CHUNKS 8

class Level {

protected:
    void generateLevel();
public:
    Level();
    Chunk chunks[N_CHUNKS];

};

#endif

