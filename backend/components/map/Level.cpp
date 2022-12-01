#include "Level.hpp"

Level::Level() {
    generateLevel();
    prec_level = nullptr;
    next_level = nullptr;
}

Level::Level(t_level prec_level) {
    generateLevel();
    this->prec_level = prec_level;
    next_level = nullptr;

}


void Level::generateLevel() {
    int app = -1;
    for(int i=0; i<N_CHUNKS; i++){
        chunks[i].create_chunk(app);
        app = chunks[i].floor_y[CHUNK_DIMENSION-1];
    }
}

void Level::createNewLevel(){
    next_level = new Level(this);
};

