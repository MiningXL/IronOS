#include "OperatingModes.h"
#include "ui_drawing.hpp"

OperatingMode gui_GameJam_TempAdjust(const ButtonState buttonIn, guiContext *cxt) {

  currentTempTargetDegC              = 0; // Turn off heater while adjusting temp
  uint16_t   *waitForRelease         = &(cxt->scratch_state.state1);
  ButtonState buttons                = buttonIn;
  if (*waitForRelease == 0) {
    // When we first enter we wait for the user to release buttons before enabling changes
    if (buttons != BUTTON_NONE) {
      buttons = BUTTON_NONE;
    } else {
      (*waitForRelease)++;
    }
  }

  int16_t delta = 0;
  switch (buttons) {
  case BUTTON_B_SHORT:
    delta = -getSettingValue(SettingsOptions::TempChangeLongStep);
    break;
  case BUTTON_F_SHORT:
    delta = getSettingValue(SettingsOptions::TempChangeLongStep);
    break;
  default:
    break;
  }
  // If buttons are flipped; flip the delta
  if (getSettingValue(SettingsOptions::ReverseButtonTempChangeEnabled)) {
    delta = -delta;
  }
  if (delta != 0) {
    // constrain between the set temp limits, i.e. 10-450 C
    int16_t newTemp = getSettingValue(SettingsOptions::SolderingTemp);
    newTemp += delta;
    // Round to nearest increment of delta
    delta   = abs(delta);
    newTemp = (newTemp / delta) * delta;

    setSettingValue(SettingsOptions::SolderingTemp, (uint16_t)newTemp);
  }
  ui_draw_temperature_change();

  return OperatingMode::GameJamTemperatureAdjist; // Stay in temp adjust
}
