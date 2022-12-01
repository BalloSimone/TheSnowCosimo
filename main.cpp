#include <iostream>
#include "backend/Game.hpp"

int main(){
    srand(time(nullptr));
    initscr();
    refresh();
    WINDOW *win = newwin(64, 240, 0, 0);
    Game ga


    int key = -1;
    while(key != 'q'){
        key = wgetch(win);
        wrefresh(win);
    }



    endwin();
    return 0;
}
