//
// Created by Simone Ballo on 24/11/22.
//

#include "Gui.hpp"

Gui::Gui(WINDOW *win) {
  screen = win;
  level.screen = win;
  level.drawMap();
}


void Gui::precLevel() {

}

void Gui::succLevel() {

}