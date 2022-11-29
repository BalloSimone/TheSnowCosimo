#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <ctime>
#include <cstdlib>
#define CHUNK_DIMENSION 64

//parametri per la generazione della mappa
//pavimenti
#define MIN_LUNG_FLOOR 10 //lunghezza minima piattaforma in percentuale
#define PERC_PIT 70 //percentuale di presenza di una buca
#define DIFF_BEET_FLOOR 2 //differenza di altezza tra due piattaforme adiacenti
#define LEN_NO_PIT 70 //lunghezza massima piattaforma in percentuale
#define LEN_PIT 80 //lunghezza massima buca in percentuale (sulla grandezza totale del chunk)

//piattaforme
#define PLAT_PERC 5 //presenza delle piattaforme nella mappa
#define MAX_PLAT_LEN 60
#define MIN_PLAT_LEN 30
#define DIST_FROM_FLOOR_MIN 7
#define DIST_FROM_FLOOR_MAX 20
#define H_PLAT_MIN 1
#define H_PLAT_MAX 4

class Chunk {

    public:
    int platform_y[CHUNK_DIMENSION];
    int platform_height[CHUNK_DIMENSION];
    int floor_y[CHUNK_DIMENSION];
    Chunk();
    void create_chunk(int startHeight);

    private:
        void spawn_floor(int startCoord);
        void spawn_platforms();
        void debug();
};

#endif


