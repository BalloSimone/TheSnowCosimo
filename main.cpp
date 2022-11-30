
#include <iostream>

#include "backend/components/entity/player/Player.hpp"
#include "frontend/Gui.hpp"

int kbhit(void) {
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(nullptr));
    initscr();
    refresh();
    WINDOW *win = newwin(64, 240, 0, 0);
    box(win, 0, 0);
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
    // box(win, 0, 0);
    // wrefresh(win);

    mvwprintw(win, 1, 1, "DEBUG");

    int *ticks = new int;
    *ticks = 0;

    int *key = new int;
    *key = -1;

    Player player(win, 30, 10, ticks, &gui.mapGui, key);

    while (*key != 'q') {
        int _ch = getch();
        *key = (_ch == ERR ? NULL : _ch);
        // mvwprintw(win, 1, 8, "Tick:%04d", *ticks);
        mvwprintw(win, 3, 1, "Key:%c", (char)*key);
        wrefresh(win);
        (*ticks)++;
        player.tick();
    }

    endwin();
    return 0;
}
