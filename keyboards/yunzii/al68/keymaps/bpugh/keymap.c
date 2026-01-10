#include QMK_KEYBOARD_H

enum my_keycodes {
    KC_PDB = SAFE_RANGE,
    KC_MPL,
    KC_GRAV,  // Grave that ignores shift
};

#define KC_WINDOW_LEFT LCTL(KC_LEFT)
#define KC_WINDOW_RIGHT LCTL(KC_RIGHT)
#define KC_WINDOW_UP LCTL(KC_UP)

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] = { ENCODER_CCW_CW(KC_BRIU, KC_BRID) },
    [2] = { ENCODER_CCW_CW(RM_VALU, RM_VALD) },  // Backlight brightness
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default
     * ,----------------------------------------------------------------.
     * |GEs| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |Bksp |Mute|
     * |----------------------------------------------------------------|
     * |Tab  | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \  |Del |
     * |----------------------------------------------------------------|
     * |Fn    | A | S | D | F | G | H | J | K | L | ; | ' | Enter |PgUp|
     * |----------------------------------------------------------------|
     * |Shift   | Z | X | C | V | B | N | M | , | . | / |Shift| Up |PgDn|
     * |----------------------------------------------------------------|
     * |Ctrl|Gui |Alt |       Space        |Fn2 |Ctrl|   |Lft|Dwn|Rgt |
     * `----------------------------------------------------------------'
     */
    [0] = LAYOUT_65_ansi_blocker(
        QK_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        MO(1),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LGUI, KC_LALT,                   KC_SPC,                    MO(2),   KC_RCTL,                   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Layer 1: Function (held from caps lock position)
     * ,----------------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Del |    |
     * |----------------------------------------------------------------|
     * |     |Prv|Ply|Nxt|Rbt|Dbg|   |PgU| Up|PgD|PDB|   |   |     |Ins |
     * |----------------------------------------------------------------|
     * |      |   |VoD|VoU|Mut|   |Hom|Lft|Dwn|Rgt|Ins|Del| Enter |WinR|
     * |----------------------------------------------------------------|
     * |Caps    |   |BrD|BrU|   |Rst|End|MPL|   |   |   |     |WUp|WinL|
     * |----------------------------------------------------------------|
     * |    |    |    |                    |    |    |   |   |   |     |
     * `----------------------------------------------------------------'
     */
    [1] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, QK_RBT,  DB_TOGG, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_PDB,  _______, _______, _______, KC_INS,
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_DEL,           _______, KC_WINDOW_RIGHT,
        KC_CAPS, _______, KC_BRID, KC_BRIU, _______, QK_BOOT, KC_END,  KC_MPL,  _______, _______, _______, _______,          KC_WINDOW_UP, KC_WINDOW_LEFT,
        _______, _______, _______,                   _______,                   _______, _______,                   _______, _______, _______
    ),

    /* Layer 2: BLE & Backlight (held from right of space)
     * ,----------------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| EEC |    |
     * |----------------------------------------------------------------|
     * |     |BL1|BL2|BL3|24G|   |   |   |   |   |   |   |   |     |    |
     * |----------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |       |    |
     * |----------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |     |Br+|    |
     * |----------------------------------------------------------------|
     * |    |    |    |     Backlight      |    |    |   |   |Br-|    |
     * `----------------------------------------------------------------'
     */
    [2] = LAYOUT_65_ansi_blocker(
        KC_GRAV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  EE_CLR,  _______,
        _______, KC_BLE1, KC_BLE2, KC_BLE3, KC_24G,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RM_VALU, _______,
        _______, _______, _______,                   RM_TOGG,                   _______, _______,                   _______, RM_VALD, _______
    ),
};

bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(3, 255, 255, 255);  // Indicator LED, white
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PDB:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_TAP(X_ESC)
                    "o"
                    "breakpoint()"
                    SS_TAP(X_ESC)
                    ":w\n"
                );
            }
            return false;
        case KC_MPL:
            if (record->event.pressed) {
                SEND_STRING(
                    "import matplotlib.pyplot as plt\n"
                    "plt.imshow(); plt.show()"
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT)
                );
            }
            return false;
        case KC_GRAV:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_GRV);
                set_mods(mods);
            }
            return false;
    }

    return true;
}
