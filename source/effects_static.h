#include "light_utils.h"

bool static_color(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool static_colors_mod_keys(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool static_palette_horizontal(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
bool static_palette_vertical(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength);
