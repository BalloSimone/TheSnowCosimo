#include <iostream>
#include <ncurses.h>
#include "backend/components/map/chunk/Chunk.h"

int main(){
    srand(time(nullptr));
    Chunk chunk;

    for (int i = 0; i < 32; i++) {
        std::cout << chunk.floor_y[i] << " ";
    }

    return 0;
}


