#include QMK_KEYBOARD_H
enum layer_number {
    _WIN = 0,
    _MAC,
    _NUM,
    _NAV,
    _PUNC,
    _FUNCT,
    _GAME,
    _GAME_SHIFT,
    _STREAM
};

/// ------------------------------------------------  variables
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define FINGER KC_TRNS
#define I_ DF(KC_TRNS)
#define _I DF(KC_TRNS)


#define PUNC LT(_PUNC, KC_SPC)
#define NAV LT(_NAV, KC_BSPC)
#define H_FUNC LT(_FUNCT, KC_H)
#define G_NUM LT(_NUM, KC_G)

#define D_MAIN DF(_WIN)
#define D_MAC DF(_MAC)

#define LAUNCH G(KC_SLSH)

// PROGRAMS 
#define P1 C(A(S(KC_1)))
#define P2 C(A(S(KC_2)))
#define P3 C(A(S(KC_3)))
#define P4 C(A(S(KC_4)))
#define P5 C(A(S(KC_5)))
#define P6 C(A(S(KC_6)))
#define P7 C(A(S(KC_7)))
#define P8 C(A(S(KC_8)))
#define P9 C(A(S(KC_9)))

// Left-hand home row mods
#define W_A LGUI_T(KC_A)
#define W_S LALT_T(KC_S)
#define W_D LSFT_T(KC_D)
#define W_F LCTL_T(KC_F)

// Right-hand home row mods
#define W_J RCTL_T(KC_J)
#define W_K LSFT_T(KC_K)
#define W_L LALT_T(KC_L)
#define W_SC RGUI_T(KC_SCLN)


// Left-hand home row mods
#define M_A LCTL_T(KC_A)
#define M_S LALT_T(KC_S)
#define M_D LSFT_T(KC_D)
#define M_F LGUI_T(KC_F)

// Right-hand home row mods
#define M_J RGUI_T(KC_J)
#define M_K LSFT_T(KC_K)
#define M_L LALT_T(KC_L)
#define M_SC RCTL_T(KC_SCLN)
/// ------------------------------------------------  combos

enum combos {
  CO_CAPS
};

const uint16_t PROGMEM caps_combo[] = {KC_Q, KC_P, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [CO_CAPS] = COMBO(caps_combo, KC_CAPS),
};

enum keycodes {
    CLEAR
};


// ------ ------------------------------------------ macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case CLEAR:
        if (record->event.pressed) {
            layer_clear();

        }
        break;

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


/// ------------------------------------------------  keymaps

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_WIN] = LAYOUT( \
//┌────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┐
I_, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, W_A    , W_S    , W_D    , W_F    , G_NUM  ,   H_FUNC , W_J    , W_K    , W_L    , W_SC   ,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,_I,
//└─-──────┴─-──────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┴────────┘
 	                  KC_DEL , NAV    , KC_ENT ,   KC_ESC , PUNC   , LAUNCH 
//		            └────────┴────────┴────────┘ └────────┴────────┴────────┘
),

[_MAC] = LAYOUT( \
//┌────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┐
I_, KC_EXLM, KC_AT  , KC_HASH, KC_UNDS, KC_PERC,   KC_CIRC, KC_7   , KC_8   , KC_9   , KC_PLUS,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, KC_QUES, KC_GRV , KC_DQUO, KC_QUOT, KC_CIRC,   KC_DLR , KC_4   , KC_5   , KC_6   , KC_MINS,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,   KC_EQL , KC_1   , KC_2   , KC_3   , KC_ASTR,_I,
//└────────┴────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┴───-────┘
                      KC_DEL , NAV    , KC_ENT ,   KC_ESC , PUNC   , LAUNCH 
//	                └────────┴────────┴────────┘ └────────┴────────┴────────┘
//
),

[_NUM] = LAYOUT( \
//┌────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┐
I_, KC_EXLM, KC_AT  , KC_HASH, KC_UNDS, KC_PERC,   KC_CIRC, KC_7   , KC_8   , KC_9   , KC_PLUS,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, KC_QUES, KC_GRV , KC_DQUO, KC_QUOT, KC_CIRC,   KC_DLR , KC_4   , KC_5   , KC_6   , KC_MINS,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,   KC_EQL , KC_1   , KC_2   , KC_3   , KC_ASTR,_I,
//└────────┴────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┴────────┘
                      KC_DEL , NAV    , KC_ENT ,   KC_ESC , PUNC   , LAUNCH 
//	                └────────┴────────┴────────┘ └────────┴────────┴────────┘
//
),


[_NAV] = LAYOUT( \
//┌────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┐
I_, _______, _______, _______, _______, _______,   P1     , KC_HOME, KC_PGDN, KC_PGUP, KC_END ,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, _______, _______, _______, _______, _______,   P2     , KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, _______, _______, _______, _______, _______,   P3     , P4     , P5     , P6     , P7     ,_I,
//└────────┴────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┴────────┘
                      _______, FINGER , _______,   _______, _______, XXXXXXX
//	                └────────┴────────┴────────┘ └────────┴────────┴────────┘
//
),

[_PUNC] = LAYOUT( \
//┌────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┐
I_, KC_EXLM, KC_AT  , KC_HASH, KC_UNDS, KC_PERC,   _______, _______, _______, _______, _______,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, KC_QUES, KC_GRV , KC_DQUO, KC_QUOT, KC_CIRC,   KC_DLR , _______, _______, _______, _______,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,   KC_BSLS, KC_RPRN, KC_RCBR, KC_RBRC, KC_TILD,_I,
//└────────┴────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┴────────┘
                      _______, _______, KC_BTN4,   RESET  , FINGER , _______
//	                └────────┴────────┴────────┘ └────────┴────────┴────────┘
//
),

[_FUNCT] = LAYOUT( \
//┌────────┬────────┬────────┬────────┬────────┐ ┌────────┬────────┬────────┬────────┬────────┐
I_, KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,   _______, _______, _______, _______, _______,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______,   FINGER , _______, _______, _______, _______,_I,
//├────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┤
I_, KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______,   _______, _______, _______, _______, _______,_I,
//└────────┴────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┴────────┘
                      _______, _______, _______,   _______, _______, _______
//	                └────────┴────────┴────────┘ └────────┴────────┴────────┘
//
)

};


// // Leader - Anything you can do in a macro.
// LEADER_EXTERNS();

// void matrix_scan_user(void) {
//   LEADER_DICTIONARY() {
//     leading = false;
//     leader_end();

//     SEQ_ONE_KEY(KC_SLSH) {
//       // Anything you can do in a macro.
//       SEND_STRING("\\");

//     }
//     // SEQ_TWO_KEYS(KC_D, KC_D) {
//     //   SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
//     // }
//     // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
//     //   SEND_STRING("https://start.duckduckgo.com\n");
//     // }
//     // SEQ_TWO_KEYS(KC_A, KC_S) {
//     //   register_code(KC_LGUI);
//     //   register_code(KC_S);
//     //   unregister_code(KC_S);
//     //   unregister_code(KC_LGUI);
//     // }
//   }
// }
