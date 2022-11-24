#include <ctime>
#include <cstdlib>
#define CHUNK_DIMENSION 32

//parametri per la generazione della mappa
#define PERC_PIT 30
#define DIFF_BEET_PLAT 4
#define LEN_NO_PIT 20 //percent of the chunk dimension
#define LEN_PIT 15 //percent of the chunk dimension

class Chunk {

    public:
    int floor_y[CHUNK_DIMENSION];
    Chunk();

    protected:
        void randomChunk();

    private:
        void spawn_floor();
        void spawn_platforms();
};


