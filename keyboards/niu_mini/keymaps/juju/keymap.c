#include QMK_KEYBOARD_H

enum layer_number {
    _WIN = 0,
    _MAC,
    _LOWER,
    _HIGHER,
    _FUNCT,
    _GAME,
    _GAME_SHIFT,
    _STREAM

};

/// ------------------------------------------------  variables
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define DELWORD A(KC_BSPC)

#define LOWER LT(_LOWER, KC_BSPC)
#define HIGHER LT(_HIGHER, KC_SPC)
#define FUNCESC LT(_FUNCT, KC_ESC)

#define D_MAIN DF(_WIN)
#define D_MAC DF(_MAC)

// #define GME_SFT LT(_GAME_SHIFT, KC_M)
#define SFT_Z LSFT_T(KC_Z)
#define SFT_SLH LSFT_T(KC_SLSH)

#define CTLETR MT(MOD_LCTL, KC_ENT)
#define CTLESC MT(MOD_LCTL, KC_ESC)
#define CTLBKWD MT(MOD_LCTL, DELWORD)

#define CMDETR MT(MOD_LGUI, KC_ENT)
#define CMDETRK G(KC_ENT)

#define ALTTAB A(KC_TAB)
#define ALTESC MT(MOD_LALT, KC_ESC)

#define WINCLIP MT(MOD_LGUI, G(KC_V))


#define P1 C(A(S(KC_1)))
#define P2 C(A(S(KC_2)))
#define P3 C(A(S(KC_3)))
#define P4 C(A(S(KC_4)))
#define P5 C(A(S(KC_5)))
#define P6 C(A(S(KC_6)))
#define P7 C(A(S(KC_7)))
#define P8 C(A(S(KC_8)))
#define P9 C(A(S(KC_9)))

/// ------------------------------------------------  combos

enum combos {
  CO_TAB,
  CO_GUI,
  CO_CAPS,
  CO_DELW,
  CO_ESC
};

const uint16_t PROGMEM tab_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM backword_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_F, KC_Q, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [CO_TAB] = COMBO(tab_combo, KC_TAB),
  [CO_GUI] = COMBO(gui_combo, KC_LGUI),
  [CO_CAPS] = COMBO(caps_combo, KC_CAPS),
  [CO_DELW] = COMBO(backword_combo, DELWORD),
  [CO_ESC] = COMBO(esc_combo, KC_ESC),
};
 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WIN] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, SFT_Z  , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , SFT_SLH, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────-────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX,KC_LCTRL, FUNCESC, LOWER  ,      CTLETR,      HIGHER , ALTESC , WINCLIP, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴────────-────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_MAC] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────├────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, SFT_Z  , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , SFT_SLH, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────-────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, DELWORD, FUNCESC, LOWER  ,      CMDETR,      HIGHER , ALTESC , CTLBKWD, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴────────-────────┴────────┴────────┴────────┴────────┴────────┘
  ),


  [_LOWER] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, D_MAIN ,   P1   ,   P2   ,   P3   , CMDETRK, _______, KC_7   , KC_8   , KC_9   , KC_PLUS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, D_MAC  ,   P4   ,   P5   ,   P6   , KC_TAB , ALTTAB , KC_4   , KC_5   , KC_6   , KC_MINS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, _______,   P7   ,   P8   ,   P9   , KC_DEL , KC_EQL , KC_1   , KC_2   , KC_3   , KC_ASTR, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼─────────────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     _______,      KC_0   , KC_EQL , XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴────────-────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_HIGHER] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┐────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, KC_EXLM, KC_AT  , KC_HASH, KC_UNDS, KC_PERC, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_QUES, KC_GRV , KC_DQUO, KC_QUOT, KC_CIRC, KC_DLR , KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, KC_BSLS, KC_RPRN, KC_RCBR, KC_RCBR, KC_TILD, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼─────────────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_BTN4,     KC_BTN5,      _______, RESET  , XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_FUNCT] = LAYOUT_planck_mit( \
  //┌────────┬────────┬────────┬────────┬────────┬────────┐────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX, _______, _______, _______, _______, _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, _______, _______, _______, _______, _______, _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 , XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, _______, _______, _______, _______, _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼─────────────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     _______,      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┴────────┘
  ),

};


// ------------------------------------------------ macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case D_MAIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN);
            }
            return false;
        break;
        case D_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            return false;
        break;
   };
   return true;
}
