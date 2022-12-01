

#include "Gui.hpp"

Gui::Gui(WINDOW *win) {
  screen = win;
  level = MapGUI(win);
}


void Gui::precLevel() {

}

void Gui::succLevel() {
    level.setLogicLevel()
}