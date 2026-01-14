/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
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
#include QMK_KEYBOARD_H

/*
 * ═══════════════════════════════════════════════════════════════════════════
 * QMK Mouse Button Keycodes (directly mapped to USB HID buttons):
 *   MS_BTN1  - Left click (primary)
 *   MS_BTN2  - Right click (secondary)
 *   MS_BTN3  - Middle click (often scroll wheel click)
 *   MS_BTN4  - Back (browser/app back)
 *   MS_BTN5  - Forward (browser/app forward)
 *   MS_BTN6  - Button 6 (application-specific)
 *   MS_BTN7  - Button 7 (application-specific)
 *   MS_BTN8  - Button 8 (application-specific)
 *
 * QMK Mouse Wheel Keycodes:
 *   MS_WHLU  - Scroll wheel up
 *   MS_WHLD  - Scroll wheel down
 *   MS_WHLL  - Scroll wheel left (horizontal)
 *   MS_WHLR  - Scroll wheel right (horizontal)
 *
 * Ploopy-Specific Keycodes:
 *   DRAG_SCROLL - Toggle/momentary drag scroll mode (ball movement = scroll)
 *                 Config: PLOOPY_DRAGSCROLL_MOMENTARY (hold vs toggle)
 *                         PLOOPY_DRAGSCROLL_DIVISOR_H/V (sensitivity)
 *                         PLOOPY_DRAGSCROLL_INVERT (reverse direction)
 *   DPI_CONFIG  - Cycle through DPI options (default: 600, 900, 1200, 1600, 2400)
 *                 Config: PLOOPY_DPI_OPTIONS, PLOOPY_DPI_DEFAULT in config.h
 * ═══════════════════════════════════════════════════════════════════════════
 * Ploopy Adept Trackball - Physical Button Layout (top-down view)
 *
 *               A        B    C         D
 *              ┌───┐    ┌───┐  ┌───┐    ┌───┐
 *              │   │    │   │  │   │    │   │
 *              └───┘    └───┘  └───┘    └───┘
 *                      ╭──────────╮
 *                     │           │
 *              ┌───┐  │   BALL    │  ┌───┐
 *           E  │   │  │           │  │   │  F
 *              └───┘   ╰──────────╯  └───┘
 *

 */

enum layers {
    _BASE,
    _MOD,
};

enum custom_keycodes {
    KC_DH_GAME = SAFE_RANGE,  // DeskHop Gaming Mode
};

#define KC_DH_SW LCTL(KC_CAPS)  // DeskHop Switch outputs

static bool dh_game_active = false;

// Access drag scroll state from ploopyco.c
extern bool is_drag_scroll;

// Auto drag scroll after inactivity
#define DRAG_SCROLL_IDLE_MS 60000  // 60 seconds
static uint32_t last_mouse_activity = 0;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_DH_SW,    // Button A - DeskHop switch
        MO(_MOD),    // Button B - hold for layer 1
        DRAG_SCROLL, // Button C - toggle drag scroll
        MS_BTN2,      // Button D - right click
        LCTL(KC_UP),  // Button E - Mission Control (macOS)
        MS_BTN1       // Button F
    ),
    [_MOD] = LAYOUT(
        KC_DH_GAME,     // Button A - DeskHop gaming mode toggle
        _______,        // Button B
        DPI_CONFIG,     // Button C - cycle DPI
        LCTL(KC_RGHT),  // Button D - ctrl+right
        EE_CLR,         // Button E - clear EEPROM
        LCTL(KC_LEFT)   // Button F - ctrl+left
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Exit drag scroll mode on any button press (except DRAG_SCROLL itself and layer keys)
    if (record->event.pressed && is_drag_scroll) {
        if (keycode != DRAG_SCROLL && keycode != MO(_MOD) && keycode != DPI_CONFIG) {
            is_drag_scroll = false;
            last_mouse_activity = timer_read32();  // Reset timer so we don't immediately re-enter
        }
    }

    switch (keycode) {
        case KC_DH_GAME:
            // DeskHop needs all keys in the same HID report
            if (record->event.pressed) {
                dh_game_active = !dh_game_active;
                add_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_RSFT));
                add_key(KC_G);
                send_keyboard_report();
                wait_ms(50);
                del_key(KC_G);
                del_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_RSFT));
                send_keyboard_report();
            }
            return false;
    }
    return true;
}

// Track mouse movement to reset idle timer
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (mouse_report.x != 0 || mouse_report.y != 0) {
        last_mouse_activity = timer_read32();
    }
    return mouse_report;
}

// Check for idle timeout and auto-enter drag scroll mode
void housekeeping_task_user(void) {
    if (!is_drag_scroll && timer_elapsed32(last_mouse_activity) > DRAG_SCROLL_IDLE_MS) {
        is_drag_scroll = true;
    }
}
