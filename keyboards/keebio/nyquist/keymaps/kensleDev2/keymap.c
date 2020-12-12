#include QMK_KEYBOARD_H

enum layer_number {
    _WIN = 0,
    _MAC,
    _LOWER,
    _HIGHER,
    _FUNCT
};

/// ------------------------------------------------  variables
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LOWER LT(_LOWER, KC_BSPC)
#define HIGHER LT(_HIGHER, KC_SPC)
#define NAV LT(_NAV, KC_ESC)
#define FUNCT LT(_FUNCT, KC_F13)

#define SFT_Z LSFT_T(KC_Z)
#define SFT_SLH LSFT_T(KC_SLSH)

#define CTLETR MT(MOD_LCTL, KC_ENT)
#define CTLESC MT(MOD_LCTL, KC_ESC)
#define CMDETR MT(MOD_LGUI, KC_ENT)
#define WINESC MT(MOD_LGUI, KC_ESC)



// Window management
#define W_FD A(KC_K)
#define W_BK A(KC_J)
#define W_SM A(KC_H)
#define W_BG A(KC_L)
#define W_TLE A(KC_T)
#define W_X S(A(KC_C))
#define W_PRM A(KC_M)
#define W_SWP A(KC_ENTER)

#define WL_RST A(KC_N)
#define WL_FD A(KC_SPACE)
#define WL_BK S(A(KC_SPACE))
#define WL_MENU A(KC_P)

#define ALTTAB A(KC_TAB)



/// ------------------------------------------------  combos

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


// ------------------------------------------------ macros

enum custom_keycodes  {
    WIN_KEY = SAFE_RANGE,
    MAC_KEY
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case WIN_KEY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN);
            }
            return false;
        break;
   };
    return true;
}

/// ------------------------------------------------  keymaps

/// todo

// a - alt
// cheat sheet

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// <!-- keymap -->

[_WIN] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, SFT_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,   KC_N   , KC_M   , KC_COMM, KC_DOT , SFT_SLH, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, FUNCT  , LOWER  , CTLETR ,   WINESC , HIGHER , KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_LOWER] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, _______, _______, _______, _______, _______,   _______, KC_7   , KC_8   , KC_9   , KC_PLUS, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, _______, _______, _______, _______, KC_TAB ,   ALTTAB , KC_4   , KC_5   , KC_6   , KC_MINS, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, _______, _______, _______, _______, KC_DEL ,   KC_EQL , KC_1   , KC_2   , KC_3   , KC_ASTR, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,   _______, KC_0   , KC_EQL , XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_HIGHER] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, KC_EXLM, KC_AT  , KC_HASH, KC_UNDS, KC_PERC,   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, KC_QUES, KC_GRV , KC_DQUO, KC_QUOT, KC_CIRC,   KC_DLR , KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,   KC_BSLS, KC_RPRN, KC_RCBR, KC_RCBR, KC_TILD, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_BTN4, KC_BTN5,   _______, FUNCT  , RESET  , XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_FUNCT] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, _______, _______, _______, _______, _______,   _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, _______, _______, _______, _______, _______,   _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 , XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, _______, _______, _______, _______, _______,   _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,   _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),
// <!-- keymap end -->
};



/* [_MAC] = LAYOUT_ortho_4x12( \ */
/* //┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
/*     XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX, */
/* //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤ */
/*     XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, XXXXXXX, */
/* //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤ */
/*     XXXXXXX, SFT_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,   KC_N   , KC_M   , KC_COMM, KC_DOT , SFT_SLH, XXXXXXX, */
/* //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤ */
/*     XXXXXXX, XXXXXXX, XXXXXXX, FUNC   , LOWER  , CMDETR ,   CTLESC , HIGHER , KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX */
/* //└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘ */
/* ), */

        /* case MAC_KEY: */
        /*     if (record->event.pressed) { */
        /*         set_single_persistent_default_layer(_MAC); */
        /*     } */
        /*     return false; */
        /* break; */
 
