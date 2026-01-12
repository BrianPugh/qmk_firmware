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

/* DPI/CPI Settings
 * DPI_CONFIG keycode cycles through these options (saved to EEPROM)
 */
#define PLOOPY_DPI_OPTIONS { 400, 800, 1200, 1600, 2400 }
#define PLOOPY_DPI_DEFAULT 2  // Index into array above (1200 DPI)

/* Drag Scroll Settings
 * DRAG_SCROLL keycode converts trackball movement into scrolling
 */
// #define PLOOPY_DRAGSCROLL_MOMENTARY     // Uncomment for hold-to-scroll (default is toggle)
#define PLOOPY_DRAGSCROLL_DIVISOR_H 8.0    // Horizontal scroll sensitivity (higher = slower)
#define PLOOPY_DRAGSCROLL_DIVISOR_V 8.0    // Vertical scroll sensitivity (higher = slower)
// #define PLOOPY_DRAGSCROLL_INVERT        // Uncomment to reverse scroll direction
