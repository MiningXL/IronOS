#include "ui_drawing.hpp"
#ifdef OLED_96x16

void ui_draw_gamejam_shake(void) {

  OLED::setCursor(0, 0);
  OLED::print(GameJamStrings[1], FontStyle::LARGE);
}
#endif