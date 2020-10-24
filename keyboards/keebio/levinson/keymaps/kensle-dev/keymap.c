#include QMK_KEYBOARD_H


enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _NAV
};

// Fillers to make layering more clear
#define LOWER LT(_LOWER, KC_BSPC)          
#define RAISE LT(_RAISE, KC_SPC)
#define NAV LT(_NAV, KC_ESC)
#define CTLENR MT(MOD_LCTL, KC_ENT)
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define DTOP1 LGUI(KC_1)
#define DTOP2 LGUI(KC_2)
#define DTOP3 LGUI(KC_3)
#define DTOP4 LGUI(KC_4)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_ortho_4x12( \
  XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,  KC_T, /**/  KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    XXXXXXX, \
  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,  KC_G, /**/  KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, XXXXXXX, \
  XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B, /**/  KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, LOWER, NAV,  /**/  CTLENR, RAISE, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX \
),

[_LOWER] = LAYOUT_ortho_4x12( \
  XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KC_PERC, /**/ KC_CIRC, KC_7,    KC_8, KC_9,    KC_PLUS, XXXXXXX, \
  XXXXXXX, KC_QUES, KC_GRV,  KC_DQUO, KC_QUOTE,KC_CIRC, /**/ KC_DLR,  KC_4,    KC_5, KC_6,    KC_MINS, XXXXXXX, \
  XXXXXXX, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, /**/ KC_EQL,  KC_1,    KC_2, KC_3,    KC_ASTR, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, /**/ KC_BTN4, KC_BTN5, KC_0, XXXXXXX, XXXXXXX, XXXXXXX \
),


[_RAISE] = LAYOUT_ortho_4x12( \
  XXXXXXX, RESET,   _______, KC_F10,  KC_F11,  KC_F12, /**/ _______, KC_BTN1, KC_BTN2, _______, _______, XXXXXXX, \
  XXXXXXX, _______, _______, KC_F7,   KC_F8,   KC_F9,  /**/ _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, \
  XXXXXXX, _______, _______, KC_F4,   KC_F5,   KC_F6,  /**/ _______, KC_RPRN, KC_RCBR, KC_RCBR, KC_TILD, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,  /**/ _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX \
),


[_NAV] =  LAYOUT_ortho_4x12( \
  XXXXXXX, RESET,   _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   XXXXXXX, \
  XXXXXXX, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, \
  XXXXXXX, _______, _______, _______, _______, _______, _______, DTOP1,   DTOP2,   DTOP3,   DTOP4,    XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX,  XXXXXXX \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
