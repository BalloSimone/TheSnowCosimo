#include <iostream>
#include "frontend/Gui.hpp"

int main(){
    WINDOW *win = newwin(64, 64, 0, 0);
    srand(time(nullptr));
    initscr();
    Gui gui(win);




    int key = -1;
    while(key != 'q'){
        key = getch();
        refresh();
    }



    endwin();
    return 0;
}
