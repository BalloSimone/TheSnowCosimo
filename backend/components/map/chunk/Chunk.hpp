#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <ctime>
#include <cstdlib>
#define CHUNK_DIMENSION 32

//parametri per la generazione della mappa
#define MIN_LUNG_PLAT 10
#define PERC_PIT 70
#define DIFF_BEET_PLAT 3
#define LEN_NO_PIT 70 //percent of the chunk dimension
#define LEN_PIT 60 //percent of the chunk dimension

class Chunk {

    public:
    int floor_y[CHUNK_DIMENSION];
    Chunk();
    void create_chunk(int startHeight);

    private:
        void spawn_floor(int startCoord);
        void spawn_platforms();
};

#endif


