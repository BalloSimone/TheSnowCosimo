#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "chunk/Chunk.hpp"
#define N_CHUNKS 4

class Level {

    typedef Level* t_level;

    protected:
        void generateLevel();

    public:
        Level();
        Level(t_level p_level);
        void createNewLevel();
        Chunk chunks[N_CHUNKS];
        t_level next_level;
        t_level prec_level;

};

#endif

