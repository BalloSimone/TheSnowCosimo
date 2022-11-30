//
// Created by Simone Ballo on 24/11/22.
//

#include "Gui.hpp"

Gui::Gui(WINDOW *win) : mapGui(win) {
    screen = win;
    this->mapGui.screen = win;
    this->mapGui.drawMap();
}

void Gui::precLevel() {
}

void Gui::succLevel() {
}