#include "light_utils.h"

/*
 * STATIC
 */
bool red(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool green(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool blue(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool rainbowHorizontal(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool rainbowVertical(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool miamiNights(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);

/*
 * ANIMATED
 */
bool animatedRainbowVertical(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool animatedRainbowFlow(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool animatedRainbowWaterfall(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool animatedBreathing(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool animatedSpectrum(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool animatedWave(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);

/*
 * ANIMATED - responding to key presses
 */
bool reactiveFade(led_t *ledColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void reactiveFadeKeypress(led_t *ledColors, uint8_t row, uint8_t col,
                          uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void reactiveFadeInit(led_t *ledColors);

/*
 * Profile Init functions
 */
void resetColAnimOffset(led_t *currentKeyLedColors);