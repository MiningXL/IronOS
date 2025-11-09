
#include "OperatingModes.h"
#include "ui_drawing.hpp"

OperatingMode gui_GameJam_Home(const ButtonState buttons, guiContext *cxt) {
    ui_draw_gamejam_home();
    return OperatingMode::GameJamHome;
}