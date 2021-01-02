#include "light_utils.h"

/*
 * STATIC
 */
void red(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void green(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void blue(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void rainbowHorizontal(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void rainbowVertical(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void miamiNights(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);

/*
 * ANIMATED
 */
void animatedRainbowVertical(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void animatedRainbowFlow(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void animatedRainbowWaterfall(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void animatedBreathing(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void animatedSpectrum(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void animatedWave(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);

/*
 * ANIMATED - responding to key presses
 */
void reactiveFade(led_t *ledColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void reactiveFadeKeypress(led_t *ledColors, uint8_t row, uint8_t col,
                          uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void reactiveFadeInit(led_t *ledColors);

/*
 * Profile Init functions
 */
void resetColAnimOffset(led_t *currentKeyLedColors);