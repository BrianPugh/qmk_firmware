#include QMK_KEYBOARD_H


enum my_keycodes {
  KC_PDB = SAFE_RANGE,
  KC_MPL,
};

# define KC_WINDOW_LEFT LCTL(KC_LEFT)
# define KC_WINDOW_RIGHT LCTL(KC_RIGHT)
# define KC_WINDOW_UP LCTL(KC_UP)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY: Default Layer
    * ,--------------------------------------------------------------.
    * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backs|  `~| 15
    * |---------------------------------------------------------------|
    * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|Del| 15
    * |---------------------------------------------------------------|
    * |Fn/CL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|   Enter|PgU| 14
    * |---------------------------------------------------------------|
    * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD| 14
    * |---------------------------------------------------------------|
    * |Ctrl|Gui |Alt |         Space    |Gui |Alt |       |Lef|Dow|Rig| 10
    * `---------------------------------------------------------------'
    */

[0] = LAYOUT(
       KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,     KC_0,  KC_MINS,   KC_EQL,  KC_BSPC,          KC_GRV,
       KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,  KC_LBRC,  KC_RBRC,  KC_BSLS,    KC_WINDOW_UP,
        MO(1),     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,  KC_SCLN,  KC_QUOT,   KC_ENT,           KC_WINDOW_RIGHT,
      KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     KC_M, KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,    KC_UP,            KC_WINDOW_LEFT,
      KC_LCTL,  KC_LGUI, KC_LALT,                    KC_SPC,                    KC_RGUI,   MO(2),            KC_LEFT,  KC_DOWN,                   KC_RGHT
  ),
[1] = LAYOUT(
       KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,         _______,
      _______,  KC_MPRV, KC_MPLY, KC_MNXT, QK_BOOT, DB_TOGG, _______,  KC_PGUP,   KC_UP, KC_PGDN,   KC_PDB,  _______,  _______,  _______,         _______,
      _______,  _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_HOME,  KC_LEFT, KC_DOWN, KC_RGHT,   KC_INS,   KC_DEL,  _______,                   _______,
      _______,  _______, KC_BRID, KC_BRIU, _______, _______,  KC_END,   KC_MPL, _______, _______,  _______,  _______,  _______,                   _______,
      _______,  _______, _______,                   _______,                    _______,  _______,           _______,  _______,                   _______
  ),
[2] = LAYOUT(
       KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,         _______,
      _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______,  _______,         _______,
      _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______,                   _______,
      _______,  RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______, _______,  _______, _______, _______,  _______,  _______,  RGB_VAI,                   _______,
      _______,  _______, _______,            RGB_MODE_PLAIN,                    _______,  _______,           RGB_RMOD, RGB_VAD,                   RGB_MOD
    ),
[3] = LAYOUT(
      _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______,  _______,         _______,
      _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______,  _______,         _______,
      _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______,                   _______,
      _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______,  _______,  _______,                   _______,
      _______,  _______, _______,                   _______,                    _______,  _______,           _______,  _______,                   _______
    )
};


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
    }

    return true;
}
