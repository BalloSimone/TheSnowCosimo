#include <ctime>
#include <cstdlib>
#define chunkDimension 32

class Chunk {

    public:
    int floor_y[chunkDimension]{};
    Chunk(){
        randomChunk();
    }
    protected:
        void randomChunk();

    private:
        void spawn_floor();
        void spawn_platforms();
};


