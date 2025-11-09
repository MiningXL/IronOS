#include "ui_drawing.hpp"
#ifdef OLED_96x16

void ui_draw_gamejam_home(void) {

  OLED::setCursor(0, 0);
  OLED::print(GameJamStrings[0], FontStyle::LARGE);
}
#endif