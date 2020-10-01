#include QMK_KEYBOARD_H

#define ST_ALT OSM(MOD_LALT)
#define LAUNCH LCTL(KC_F7)

/* Layers */
#define _BASE 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

// layer switchers
#define LOWER  LT(_LOWER, KC_BSPC)
#define RAISE  LT(_RAISE, KC_SPC)
#define NAV_ESC LT(_ADJUST, KC_ESC)
#define SHIFT_f MT(MOD_LSFT, KC_F)
#define SHIFT_j MT(MOD_LSFT, KC_J)

#define CENTER MT(MOD_LCTL, KC_ENT)

enum my_keycodes {
   SLASHER=SAFE_RANGE
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define WIN_BACk LALT(LSFT(KC_ESC))
#define WIN_FWD LALT(KC_ESC)


// COMBOS 

const uint16_t PROGMEM caps_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM backslash_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {COMBO(caps_combo, KC_CAPS), COMBO(backslash_combo, KC_BSLS), COMBO(equals_combo, KC_EQL)};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
    * ,-----------------------------------------.  .-----------------------------------------.
    * |      |   Q  |   W  |   E  |   R  |   T  |  |  Y   |   U  |   I  |   O  |   P  |      |
    * |------+------+------+------+------+------|  |------+------+------+------+------+------|
    * |      |   A  |   S  |   D  |   F  |   G  |  |  H   |   J  |   K  |   L  |   ;  |      |
    * |------+------+------+------+------+------|  |------+------+------+------+------+------|
    * |      |   Z  |   X  |   C  |   V  |   B  |  |  N   |   M  |   ,  |   .  |   /  |      |
    * |------+------+------+------+------+------|  |------+------+------+------+------+------|
    * |      |      | GUI  | Alt  |BckLow|NavEsc|  |Enter |SpeRai| TAb  |      |      |      |
    * `-----------------------------------------.  .-----------------------------------------'
    */
    [_BASE] = LAYOUT_ortho_4x12(
        _______, KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,   SHIFT_f, KC_G,      KC_H,   SHIFT_j, KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,      KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, KC_LGUI, ST_ALT, LOWER,   NAV_ESC,   CENTER, RAISE,   KC_TAB,  _______, _______, _______
    ),

    /* Raise 
    * ,-----------------------------------------.  .----------------------------------------.
    * |      |  !   |   @  |   #  |   _  |   %  |  |     |   7  |   8  |  9   |  +   | BSPA |
    * |------+------+------+------+------+------|  |-----+------+------+------+------+------|
    * |      |  ?   |   `  |   "  |   '  |   ^  |  |  $  |   4  |   5  |  6   |  -   |Enter |
    * |------+------+------+------+------+------|  |-----+------+------+------+------+------|
    * |      |   |  |   [  |   {  |   (  |   &  |  |     |   1  |   2  |  3   |  *   |   =  |
    * |------+------+------+------+------+------|  |-----+------+------+------+------+------|
    * |      |  GUI | Ctrl |  Alt |      |      |  |     |Launch|   0  |   .  |   /  |      |
    * `-----------------------------------------.  .---------------------------------------'
    */
    [_LOWER] = LAYOUT_ortho_4x12(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KC_PERC,   _______, KC_7,   KC_8, KC_9,   KC_PLUS, _______,
        _______, KC_QUES, KC_GRV,  KC_DQUO, KC_QUOT, KC_CIRC,   KC_DLR,  KC_4,   KC_5, KC_6,   KC_MINS, _______,
        _______, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,   _______, KC_1,   KC_2, KC_3,   KC_ASTR, _______,
        _______, _______, KC_LCTL, ST_ALT,  _______, _______,   _______, LAUNCH, KC_0, KC_DOT, KC_SLSH, _______
    ),

    /* Lowerk
    * ,-----------------------------------------.  .-----------------------------------------.
    * | App1 |      |  F10  | F11 |  F12 |      |  |     |      |      |      |      | BSPA |
    * |------+------+------+------+------+------|  |-----+------+------+------+------+------|
    * | App2 |      |  F7  |  F8  |  F9  |      |  |     |      |      |      |      |Enter |
    * |------+------+------+------+------+------|  |-----+------+------+------+------+------|
    * | App3 |      |  F4  |  F5  |  F6  |      |  |     |   )  |   }  |   ]  |   ~  |      |
    * |------+------+------+------+------+------|  |-----+------+------+------+------+------|
    * | App4 |      |  F1  |  F2  |  F3  |      |  |     |   X  | RALT | RCTL |       |RESET|
    * `-----------------------------------------.  .----------------------------------------'
    */
    [_RAISE] = LAYOUT_ortho_4x12(
        _______, _______, KC_F10, KC_F11, KC_F12, _______,   _______, KC_BTN1, KC_BTN2, _______,  _______, _______,
        _______, _______, KC_F7,   KC_F8,  KC_F9, _______,   _______, KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R, _______,
        _______, _______, KC_F4,   KC_F5,  KC_F6, _______,   _______, KC_RPRN, KC_RCBR, KC_RBRC,  KC_TILD, _______,
        _______, _______, KC_F1,   KC_F2,  KC_F3, _______,   _______, _______, RESET,   KC_RCTL,  _______, _______
    ),


    /* Adjust , 
    * ,-----------------------------------------.  .-----------------------------------------.
    * |      | ^Q   | !+ESC| !ESC |  tab | focus|  |      | HOME | PGDN | PGUP | END  |DELETE|
    * |------+------+------+------+------+------|  |------+------+------+------+------+------|
    * |      | ^A   |  ^S  |  DEL | ^F   |Search|  |      | LEFT | DOWN | UP   | RIGHT|enter |
    * |------+------+------+------+------+------|  |------|------+------+------+------+------|
    * | shift| ^Z   | ^X   | ^C   | ^V   |      |  |      |  W1  |  W2  |  W3  |  W4  |shift |
    * |------+------+------+------+------+------|  |------+------+------+------+------+------|
    * | ctrl |  GUI | Ctrl |  Alt | Space| BACk |  |Forwrd|      |      |      |      |      |
    * `-----------------------------------------.  .----------------------------------------'
    */
    [_ADJUST] = LAYOUT_ortho_4x12(
        _______, LGUI(KC_Q), WIN_BACk,   WIN_FWD,       LCTL(KC_TAB), LALT(KC_F7),   _______,    KC_HOME,    KC_PGDOWN,  KC_PGUP,    KC_END,     KC_DELETE,
        _______, LCTL(KC_A), LCTL(KC_S), KC_DELETE,     LCTL(KC_F),   LCTL(KC_L),    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_ENT,
        KC_LSFT, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),    LCTL(KC_V),   _______,       _______,    LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), KC_RSFT,
        KC_LCTL, KC_LGUI,    KC_LCTL,    OSM(MOD_LALT), KC_SPC,       KC_BTN4,       KC_BTN5,    _______,    _______,    _______,    _______,    _______
    ), 

};


/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch(keycode) { */
/*         case SLASHER: */
/*             if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT))) { */
/*                 if (record->event.pressed) { */
/*                     // when keycode QMKBEST is pressed */
/*                     register_code(KC_PIPE); */
/*                     unregister_code(KC_PIPE); */
/*                 } */ 
/*                 break; */
/*             } else { */
/*                 if (record->event.pressed) { */
/*                     // when keycode QMKBEST is pressed */
/*                     register_code(KC_SLASH); */
/*                     unregister_code(KC_SLASH); */
/*                 } */ 
/*                 break; */
/*             } */
/*         break; */
/*     } */
/*     return true; */
/* } */
