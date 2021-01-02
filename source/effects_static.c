#include "miniFastLED.h"
#include "string.h"

/**
 * @brief Sets all LEDs the same color
 */
void static_color(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength) {
  if (colorPalette == NULL) {
    return;
  }

  setAllKeysColor(currentKeyLedColors, colorPalette[0], intensity);
}

/**
 * @brief Sets two colors for Mod and non-Mod keys 
 */
void static_colors_mod_keys(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength) {
  if (colorPalette == NULL) {
    return;
  }

  setAllKeysColor(currentKeyLedColors, colorPalette[0], intensity);

  if (colorPaletteLength == 2) {
    setModKeysColor(currentKeyLedColors, colorPalette[1], intensity);
  }
}

/**
 * @brief Sets each row with a different color
 */
void static_palette_horizontal(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength) {
  if (colorPalette == NULL) {
    return;
  }

  for (uint16_t i = 0; i < NUM_ROW; ++i) {
    for (uint16_t j = 0; j < NUM_COLUMN; ++j) {
      setKeyColor(&currentKeyLedColors[i * NUM_COLUMN + j],
                  colorPalette[i % colorPaletteLength], intensity);
    }
  }
}

/**
 * @brief Sets each column with a different color
 */
void static_palette_vertical(led_t *currentKeyLedColors, uint8_t intensity, const uint32_t *colorPalette, const uint32_t colorPaletteLength) {
  if (colorPalette == NULL) {
    return;
  }

  for (uint16_t i = 0; i < NUM_ROW; ++i) {
    for (uint16_t j = 0; j < NUM_COLUMN; ++j) {
      setKeyColor(&currentKeyLedColors[i * NUM_COLUMN + j],
                  colorPalette[j % colorPaletteLength], intensity);
    }
  }
}