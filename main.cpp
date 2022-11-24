
#include <iostream>

#include "backend/components/entity/Entity.h"
#include "frontend/Gui.h"

#define WIDTH 128
#define HEIGHT 32

#include <iostream>

int main() {
    srand(time(nullptr));
    Chunk chunk;

    WINDOW *win = newwin(WIN_LENGTH, WIN_HEIGTH, 0, 0);
    initscr();
    Gui gameGui(win);

    refresh();

    // global settings
    noecho();
    curs_set(0);

    if (!has_colors()) {
        printw("Colori non supportati");
        getch();
        return 1;
    }
    start_color();

    // win settings
    cbreak();
    nodelay(win, true);
    timeout(10);

    box(win, 0, 0);
    wrefresh(win);

    mvwprintw(win, 1, 1, "DEBUG");

    int *ticks = new int;
    *ticks = 0;

    Entity entity(win, 30, 10, 0, 0, 10, 10, ticks);

    int key = -1;
    while (key != 'q') {
        key = getch();
        if (key == 'a') {
            entity.move(-1, 0);
        } else if (key == 'd') {
            entity.move(1, 0);
        } else if (key == ' ') {
            entity.jump();
        } else if (key == 'e') {
            // attacca eugenio
        } else if (key == 'c') {
            // DEBUG
            entity.coins += 5;
        } else if (key == 'v') {
            // DEBUG
            entity.lives += 1;
        }
        mvwprintw(win, 1, 8, "Tick:%04d", *ticks);
        wrefresh(win);
        (*ticks)++;
        entity.tick();

        endwin();
        return 0;
    }
}
