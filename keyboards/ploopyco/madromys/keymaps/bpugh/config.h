/* Copyright 2024 Brian Pugh
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* ═══════════════════════════════════════════════════════════════════════════
 * DPI/CPI Settings
 * DPI_CONFIG keycode cycles through these options (saved to EEPROM)
 * ═══════════════════════════════════════════════════════════════════════════
 */
#define PLOOPY_DPI_OPTIONS {400, 800, 1200, 1600, 2400}
#define PLOOPY_DPI_DEFAULT 2 // Index into array above (1200 DPI)

/* ═══════════════════════════════════════════════════════════════════════════
 * Drag Scroll Settings
 * DRAG_SCROLL keycode converts trackball movement into scrolling
 * ═══════════════════════════════════════════════════════════════════════════
 */
// #define PLOOPY_DRAGSCROLL_MOMENTARY        // Hold-to-scroll (default is toggle)
#define PLOOPY_DRAGSCROLL_DIVISOR_H 128.0 // Horizontal sensitivity (higher = slower)
#define PLOOPY_DRAGSCROLL_DIVISOR_V 128.0 // Vertical sensitivity (higher = slower)
#define PLOOPY_DRAGSCROLL_INVERT          // Reverse scroll direction

/* ═══════════════════════════════════════════════════════════════════════════
 * Pointing Device / Sensor Settings
 * ═══════════════════════════════════════════════════════════════════════════
 */
// #define POINTING_DEVICE_INVERT_X           // Invert X axis (already set: INVERT_Y)
// #define ROTATIONAL_TRANSFORM_ANGLE 0       // Rotate sensor (-180 to 180 degrees)
// #define PMW33XX_LIFTOFF_DISTANCE 0x00      // Liftoff distance (0x00-0x0F, lower = less)

/* ═══════════════════════════════════════════════════════════════════════════
 * Mouse Key Settings (for MS_* keycodes)
 * ═══════════════════════════════════════════════════════════════════════════
 */
// #define MOUSEKEY_DELAY 10                  // Delay before cursor moves (ms)
// #define MOUSEKEY_INTERVAL 20               // Time between cursor movements (ms)
// #define MOUSEKEY_MOVE_DELTA 8              // Cursor movement step size
// #define MOUSEKEY_MAX_SPEED 10              // Max cursor speed
// #define MOUSEKEY_TIME_TO_MAX 30            // Time to reach max speed
// #define MOUSEKEY_WHEEL_DELAY 10            // Delay before scroll starts (ms)
// #define MOUSEKEY_WHEEL_INTERVAL 80         // Time between scroll events (ms)
// #define MOUSEKEY_WHEEL_MAX_SPEED 8         // Max scroll speed
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40      // Time to reach max scroll speed

/* ═══════════════════════════════════════════════════════════════════════════
 * Scroll Wheel Settings (for devices with encoder/scroll ring)
 * ═══════════════════════════════════════════════════════════════════════════
 */
// #define PLOOPY_SCROLL_DEBOUNCE 5           // ms between scroll events
// #define PLOOPY_SCROLL_BUTTON_DEBOUNCE 100  // Ignore scroll after pressing wheel (ms)
// #define PLOOPY_IGNORE_SCROLL_CLICK         // Ignore scroll wheel if pressed down

/* ═══════════════════════════════════════════════════════════════════════════
 * RGB Lighting Settings (NeoPixel LEDs)
 * ═══════════════════════════════════════════════════════════════════════════
 */
#define RGB_DI_PIN GP12
#define WS2812_PIO_USE_PIO1
#define RGBLIGHT_LAYERS
#define RGBLIGHT_DEFAULT_HUE 0   // (ignored when sat=0)
#define RGBLIGHT_DEFAULT_SAT 0   // 0 = white
#define RGBLIGHT_DEFAULT_VAL 255 // Brightness
#define RGBLIGHT_SLEEP           // Turn off when host sleeps
#define RGBLIGHT_LAYERS_RETAIN_VAL
