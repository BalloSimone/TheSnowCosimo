
#include <iostream>

#include "backend/components/entity/player/Player.hpp"
#include "frontend/Gui.hpp"

int main() {
    WINDOW *win = newwin(64, 64, 0, 0);
    srand(time(nullptr));
    initscr();
    Gui gui(win);

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

    Player player(win, 30, 10, ticks);

    int key = -1;
    while (key != 'q') {
        key = getch();
        if (key == 'a') {
            player.move(-1, 0);
        } else if (key == 'd') {
            player.move(1, 0);
        } else if (key == ' ') {
            player.jump();
        } else if (key == 'e') {
            // attacca eugenio
        } else if (key == 'c') {
            // DEBUG
            player.coins += 5;
        } else if (key == 'v') {
            // DEBUG
            player.lives += 1;
        }
        mvwprintw(win, 1, 8, "Tick:%04d", *ticks);
        wrefresh(win);
        (*ticks)++;
        player.tick();
    }

    endwin();
    return 0;
}
