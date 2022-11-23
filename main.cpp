#include <ncurses.h>

#include "backend/components/entity/Entity.h"

#define WIDTH 128
#define HEIGHT 32

#include <iostream>

int main() {
    initscr();

    WINDOW* win = newwin(HEIGHT, WIDTH, 0, 0);
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
    nodelay(win, true);
    timeout(10);

    // xp bar
    mvwprintw(win, 1, 1, "prova prova");
    mvwprintw(win, 2, 1, "XP: ");
    // 1 = bianco su nero
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // 2 = xp bar bianca
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
    // 3 = xp bar rossa
    init_pair(3, COLOR_RED, COLOR_RED);
    wattron(win, COLOR_PAIR(3));
    wprintw(win, "       ");
    wattron(win, COLOR_PAIR(2));
    wprintw(win, "   ");
    wattron(win, COLOR_PAIR(1));
    wprintw(win, " 70%%");

    box(win, 0, 0);
    wrefresh(win);

    int* ticks = new int;
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
            entity.move(0, -1);
        } else if (key == 'e') {
            // attacca eugenio
        }
        mvwprintw(win, 1, 13, "%d", *ticks);
        wrefresh(win);
        *ticks++;
        entity.tick();
    }

    endwin();
    return 0;
}
