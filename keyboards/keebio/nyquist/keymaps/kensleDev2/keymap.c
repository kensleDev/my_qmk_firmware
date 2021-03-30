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

#define LOWER LT(_LOWER, KC_BSPC)
#define HIGHER LT(_HIGHER, KC_SPC)
#define NAV LT(_NAV, KC_ESC)
#define FUNCT LT(_FUNCT, KC_F13)

#define D_MAIN DF(_WIN)
#define D_MAC DF(_MAC)

// #define D_GAME DF(_GAME)
// #define D_STRM DF(_STREAM)

// #define GME_SFT LT(_GAME_SHIFT, KC_M)
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

// OBS
#define OB_M C(A(KC_Z))
#define OB_B S(A(KC_X))
#define OB_P S(C(KC_C))
#define OB_PB S(C(KC_B))
#define OB_PG S(C(KC_V))
#define OB_C_ON S(C(KC_N))
#define OB_C_OF S(C(KC_M))

// VOICE MEETER
#define VM_M_DN C(A(S(KC_3)))
#define VM_M_UP C(A(S(KC_4)))
#define VM_MU_ME C(A(S(KC_A)))
#define VM_MU_M C(A(S(KC_1)))
#define VM_MU_C C(A(S(KC_2)))
#define VM_MU_C C(A(S(KC_2)))

enum keycodes {
    RUST_E = SAFE_RANGE
};


/// ------------------------------------------------  combos

enum combos {
  CO_TAB,
  CO_GUI,
  CO_CAPS,
};

const uint16_t PROGMEM tab_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_Q, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CO_TAB] = COMBO(tab_combo, KC_TAB),
  [CO_GUI] = COMBO(gui_combo, KC_LGUI),
  [CO_CAPS] = COMBO(caps_combo, KC_CAPS),
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
        // case D_GAME:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_GAME);
        //     }
        //     return false;
        // break;
        // case D_STRM:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_STREAM);
        //     }
        //     return false;
        // break;

        // case RUST_E:
        //     if (record->event.pressed) {
        //         // when keycode QMKBEST is pressed
        //         register_code(KC_E);
        //     } else {
        //         unregister_code(KC_E);
        //         _delay_ms(150);
        //         register_code(KC_J);
        //         unregister_code(KC_J);
        //         _delay_ms(170);
        //         register_code(KC_BSPC);
        //         unregister_code(KC_BSPC);
        //         // when keycode QMKBEST is released
        //     }
        // break;
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
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, SFT_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,   KC_N   , KC_M   , KC_COMM, KC_DOT , SFT_SLH, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, FUNCT  , LOWER  , CTLETR ,   WINESC , HIGHER , KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_MAC] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, SFT_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,   KC_N   , KC_M   , KC_COMM, KC_DOT , SFT_SLH, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, FUNCT  , LOWER  , CMDETR ,   CTLESC , HIGHER , KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),


[_LOWER] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, D_MAIN , _______, _______, _______, _______,   _______, KC_7   , KC_8   , KC_9   , KC_PLUS, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, D_MAC  , _______, _______, _______, KC_TAB ,   ALTTAB , KC_4   , KC_5   , KC_6   , KC_MINS, XXXXXXX,
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

// <!-- keymap end --
};


/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     switch (get_highest_layer(state)) { */
/*     case _LOWER: */
/*         rgblight_setrgb (0x00,  0x00, 0xFF); */
/*         break; */
/*     case _HIGHER: */
/*         rgblight_setrgb (0xFF,  0x00, 0x00); */
/*         break; */
/*     case _FUNCT: */
/*         rgblight_setrgb (0x00,  0xFF, 0x00); */
/*         break; */
/*     case _GAME: */
/*         rgblight_setrgb (0x7A,  0x00, 0xFF); */
/*         break; */
/*     default: //  for any other layers, or the default layer */
/*         rgblight_setrgb (0x00,  0xFF, 0xFF); */
/*         break; */
/*     } */
/*   return state; */
/* } */


/*
[_GAME] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_TAB , KC_Q   , KC_W   , RUST_E , KC_R   , KC_T   ,   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , D_MAIN ,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, D_GAME ,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,   KC_N   , KC_M   , KC_COMM, KC_DOT , SFT_SLH, D_STRM,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LCTL, XXXXXXX, XXXXXXX, KC_N   , KC_SPC , GME_SFT,   CTLETR , HIGHER , KC_LALT, XXXXXXX, XXXXXXX, LOWER
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_GAME_SHIFT] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    KC_F2  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,   _______, _______, _______, _______, _______, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_F3  , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,   _______, OB_M   , OB_B   , OB_C_OF, OB_C_ON, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_F1  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT ,   _______, OB_P   , OB_PG  , OB_PG  , _______, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_F9  , XXXXXXX, XXXXXXX, _______, KC_ESC , _______,   _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
),

[_STREAM] = LAYOUT_ortho_4x12( \
//┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐
    XXXXXXX, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY,   _______, _______, _______, _______, _______, D_MAIN ,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, OB_M   , OB_B   , OB_C_OF, OB_C_ON, VM_M_UP,   _______, _______, _______, _______, _______, D_GAME ,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, OB_P   , OB_PG  , OB_PB  , _______, VM_M_DN,   _______, _______, _______, _______, _______, D_STRM ,
//├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, VM_MU_C, VM_MU_M,VM_MU_ME,   _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
//└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘
)
*/


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

/* [_GAME_SHIFT] = LAYOUT_ortho_4x12( \ */
/* //┌────────┬────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┬────────┐ */
 /*    XXXXXXX, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, XXXXXXX, */
/* //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤ */
 /*    XXXXXXX, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, XXXXXXX, */
/* //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤ */
 /*    XXXXXXX, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, XXXXXXX, */
/* //├────────┼────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┼────────┤ */
 /*    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,   _______, _______, _______, XjXXXXXX, XXXXXXX, XXXXXXX */
/* //└────────┴────────┴────────┴────────┴────────┴────────┘ └────────┴────────┴────────┴────────┴────────┴────────┘ */
/* ), */


