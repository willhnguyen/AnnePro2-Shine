#pragma once

#include "light_utils.h"
#include "profiles.h"

/*
 * Active profiles
 * Add profiles from source/profiles.h in the profile array
 */
typedef void (*lighting_callback)(led_t *, uint8_t);

/*
 * keypress handler
 */
typedef void (*keypress_handler)(led_t *colors, uint8_t row, uint8_t col,
                                 uint8_t intensity);

typedef void (*profile_init)(led_t *colors);

typedef struct {
  // callback function implementing the lighting effect
  lighting_callback callback;
  // For static effects, their `callback` is called only once.
  // For dynamic effects, their `callback` is called in a loop.
  // This field controls the animation speed by specifying
  // how many iterations of the loop to skip before calling this again.
  // For example, 8000 in the array means that `callback` is called on every
  // 8000th iteration. Different 4 values can be specified to allow different
  // speeds of the same effect. For static effects, the array must contain {0,
  // 0, 0, 0}.
  uint16_t animationSpeed[4];
  // In case the profile is reactive, it responds to each keypress.
  // This callback is called with the locations of the pressed keys.
  keypress_handler keypressCallback;
  // Some profiles might need additional setup when just enabled.
  // This callback defines such logic if needed.
  profile_init profileInit;
} profile;

profile profiles[12] = {
    {red, {0, 0, 0, 0}, NULL, NULL},
    {green, {0, 0, 0, 0}, NULL, NULL},
    {blue, {0, 0, 0, 0}, NULL, NULL},
    {rainbowHorizontal, {0, 0, 0, 0}, NULL, NULL},
    {rainbowVertical, {0, 0, 0, 0}, NULL, NULL},
    {animatedRainbowVertical, {15000, 10000, 6000, 3000}, NULL, NULL},
    {animatedRainbowFlow, {5000, 2000, 1000, 700}, NULL, NULL},
    {animatedRainbowWaterfall, {8000, 6000, 4000, 2000}, NULL, NULL},
    {animatedBreathing, {8000, 6000, 4000, 2000}, NULL, NULL},
    {animatedWave, {6000, 4000, 2000, 1000}, NULL, NULL},
    {animatedSpectrum, {8000, 6000, 4000, 2000}, NULL, NULL},
    {reactiveFade,
     {8000, 6000, 4000, 2000},
     reactiveFadeKeypress,
     reactiveFadeInit},
};