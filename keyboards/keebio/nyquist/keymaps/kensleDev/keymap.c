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
#define CTLETR MT(MOD_LCTL, KC_ENT)
#define _______ KC_TRNS
#define XXXXXXX KC_NO
 
#define DTOP1 LGUI(KC_1)
#define DTOP2 LGUI(KC_2)
#define DTOP3 LGUI(KC_3)
#define DTOP4 LGUI(KC_4)

#define LAUNCH LCTL(KC_F7)

#define WIN_N LALT(KC_ESC)
#define WIN_P LSFT(LALT(KC_ESC))
#define WIN_C LGUI(KC_Q)

#define SFT_Z LSFT_T(KC_Z)
#define SFT_SLH LSFT_T(KC_SLSH)

// combos
enum combos {
  CO_TAB,
  CO_GUI,
  CO_CAPS
};
const uint16_t PROGMEM tab_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_Q, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CO_TAB] = COMBO(tab_combo, KC_TAB),
  [CO_GUI] = COMBO(gui_combo, KC_LGUI),
  [CO_CAPS] = COMBO(caps_combo, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, SFT_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,   KC_N   , KC_M   , KC_COMM, KC_DOT , SFT_SLH, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, LOWER  , CTLETR ,   NAV    , RAISE  , KC_LEAD, XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),


[_LOWER] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, KC_EXLM, KC_AT  , KC_HASH, KC_UNDS, KC_PERC,   KC_CIRC, KC_7   , KC_8   , KC_9   , KC_PLUS, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, KC_QUES, KC_GRV , KC_DQUO, KC_QUOT, KC_CIRC,   KC_DLR , KC_4   , KC_5   , KC_6   , KC_MINS, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,   KC_EQL , KC_1   , KC_2   , KC_3   , KC_ASTR, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,   _______, _______, KC_0,    XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),


[_RAISE] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, RESET  , _______, KC_F10 , KC_F11 , KC_F12 ,   _______, KC_BTN1, KC_BTN2, _______, _______, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, _______, _______, KC_F7  , KC_F8  , KC_F9  ,   _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, _______, _______, KC_F4  , KC_F5  , KC_F6  ,   _______, KC_RPRN, KC_RCBR, KC_RCBR, KC_TILD, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, KC_F1  , KC_F2  , KC_F3  ,   _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX 
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_NAV] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, _______, _______, _______, _______, _______,   WIN_P  , KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, _______, _______, _______, _______, _______,   WIN_N  , KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, _______, _______, _______, _______, KC_DEL ,   WIN_C  , DTOP1,   DTOP2,   DTOP3,   DTOP4,   XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,   KC_BTN4, KC_BTN5, LAUNCH , XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
), 

}; 


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    
  }
  return true;
}


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_SLSH) {
      // Anything you can do in a macro.
      SEND_STRING("\\");

    }
    // SEQ_TWO_KEYS(KC_D, KC_D) {
    //   SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    // }
    // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
    //   SEND_STRING("https://start.duckduckgo.com\n");
    // }
    // SEQ_TWO_KEYS(KC_A, KC_S) {
    //   register_code(KC_LGUI);
    //   register_code(KC_S);
    //   unregister_code(KC_S);
    //   unregister_code(KC_LGUI);
    // }
  }
}
