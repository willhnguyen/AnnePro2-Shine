#pragma once

#include "light_utils.h"
#include "profiles.h"
#include "effects_static.h"
#include "effects_animated.h"
#include "effects_reactive.h"

#define LEN(a) (sizeof(a) / sizeof(*a))

/*
 * Active profiles
 * Add profiles from source/profiles.h in the profile array
 */
typedef void (*lighting_callback)(led_t *, uint8_t, const uint32_t *, const uint32_t);
 
/*
 * keypress handler
 */
typedef void (*keypress_handler)(led_t *colors, uint8_t row, uint8_t col,
                                 uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);

typedef void (*profile_init)(led_t *colors);

typedef struct
{
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
  // Set custom color palettes
  const uint32_t *colorPalette;
  const uint32_t colorPaletteLength;
} profile;

static const uint32_t redPalette[] = {0xFF0000};
static const uint32_t greenPalette[] = {0x00FF00};
static const uint32_t bluePalette[] = {0x0000FF};
static const uint32_t miamiNightsPalette[] = {0x00979c, 0x9c008f};
static const uint32_t rainbowPalette[] = {0x9c0000, 0x9c9900, 0x1f9c00,
                                          0x00979c, 0x003e9c, 0x39009c,
                                          0x9c008f};

profile profiles[13] = {
    // {red, {0, 0, 0, 0}, NULL, NULL, NULL},
    // {green, {0, 0, 0, 0}, NULL, NULL, NULL},
    // {blue, {0, 0, 0, 0}, NULL, NULL, NULL},
    {static_color, {0, 0, 0, 0}, NULL, NULL, redPalette, LEN(redPalette)},
    {static_color, {0, 0, 0, 0}, NULL, NULL, greenPalette, LEN(greenPalette)},
    {static_color, {0, 0, 0, 0}, NULL, NULL, bluePalette, LEN(bluePalette)},
    // {miamiNights, {0, 0, 0, 0}, NULL, NULL, NULL},
    {static_colors_mod_keys, {0, 0, 0, 0}, NULL, NULL, miamiNightsPalette, LEN(miamiNightsPalette)},
    // {rainbowHorizontal, {0, 0, 0, 0}, NULL, NULL, NULL},
    // {rainbowVertical, {0, 0, 0, 0}, NULL, NULL, NULL},
    {static_palette_horizontal, {0, 0, 0, 0}, NULL, NULL, rainbowPalette, LEN(rainbowPalette)},
    {static_palette_vertical, {0, 0, 0, 0}, NULL, NULL, rainbowPalette, LEN(rainbowPalette)},

    {animatedRainbowVertical, {15000, 10000, 6000, 3000}, NULL, resetColAnimOffset, rainbowPalette, LEN(rainbowPalette)},
    {animatedRainbowFlow, {5000, 2000, 1000, 700}, NULL, NULL, NULL, 0},
    {animatedRainbowWaterfall, {8000, 6000, 4000, 2000}, NULL, NULL, NULL, 0},
    {animatedBreathing, {8000, 6000, 4000, 2000}, NULL, NULL, NULL, 0},
    {animatedWave, {6000, 4000, 2000, 1000}, NULL, NULL, NULL, 0}, // Seems incorrect...
    {animatedSpectrum, {8000, 6000, 4000, 2000}, NULL, NULL, NULL, 0},

    {reactiveFade,
     {8000, 6000, 4000, 2000},
     reactiveFadeKeypress,
     reactiveFadeInit,
     NULL, 0},
};
