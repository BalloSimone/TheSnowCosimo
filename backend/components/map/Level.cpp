#include "Level.hpp"

Level::Level() {
    generateLevel();
}

void Level::generateLevel() {
    int app = -1;
    for (int i = 0; i < N_CHUNKS; i++) {
        chunks[i].create_chunk(app);
        app = chunks[i].floor_y[CHUNK_DIMENSION - 1];
    }
}