
#include "OperatingModes.h"
#include "ui_drawing.hpp"

OperatingMode gui_GameJam_Shake(const ButtonState buttons, guiContext *cxt) {
    ui_draw_gamejam_shake();
    return OperatingMode::GameJamShake;
}