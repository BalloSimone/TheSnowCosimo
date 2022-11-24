#include <iostream>
#include "frontend/Gui.cpp"

int main(){
    WINDOW *win = newwin(WIN_LENGTH, WIN_HEIGTH, 0, 0);
    initscr();
    Gui gameGui(win);



    endwin();
    return 0;
}
