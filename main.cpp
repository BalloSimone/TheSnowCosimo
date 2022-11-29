#include <iostream>
#include "frontend/Gui.hpp"

int main(){
    srand(time(nullptr));
    initscr();
    refresh();
    WINDOW *win = newwin(64, 240, 0, 0);
    box(win, 0, 0);
    Gui gui(win);


    int key = -1;
    while(key != 'q'){
        key = wgetch(win);
        wrefresh(win);
    }



    endwin();
    return 0;
}
