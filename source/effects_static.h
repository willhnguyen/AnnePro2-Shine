#include "light_utils.h"

// void red(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
// void green(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
// void blue(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
// void miamiNights(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);

void static_color(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void static_colors_mod_keys(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void static_palette_horizontal(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
void static_palette_vertical(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
