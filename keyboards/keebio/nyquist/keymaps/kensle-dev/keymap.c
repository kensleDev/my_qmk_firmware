#include QMK_KEYBOARD_H

#define ST_ALT OSM(MOD_LALT)
#define LAUNCH LCTL(KC_F7)

/* Layers */
#define _BASE 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

// layer switchers
#define LOW_BCK  LT(_LOWER, KC_BSPC)
#define RSE_SPE  LT(_RAISE, KC_SPC)
#define ADJ_ESC LT(_ADJUST, KC_ESC)
#define SHIFT_z MT(MOD_LSFT, KC_Z)
#define SHIFT_sl MT(MOD_LSFT, KC_SLSH)
#define CTL_TAB MT(MOD_LCTL, KC_TAB)
#define ALT_BSLA MT(MOD_LALT, KC_BSLS)


// utils
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define WIN_BACk LALT(LSFT(KC_ESC))
#define WIN_FWD LALT(KC_ESC)

// COMBOS 

const uint16_t PROGMEM caps_combo[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM backslash_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(caps_combo, KC_CAPS), 
    COMBO(backslash_combo, KC_BSLS), 
    COMBO(gui_combo, KC_LGUI), 
    COMBO(enter_combo, KC_ENTER)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_4x12(
        _______, KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    /**/ KC_Y,     KC_U,    KC_I,     KC_O,    KC_P,     _______,
        _______, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    /**/ KC_H,     KC_J,    KC_K,     KC_L,    KC_SCLN,  _______,
        _______, SHIFT_z, KC_X,    KC_C,   KC_V,    KC_B,    /**/ KC_N,     KC_M,    KC_COMM,  KC_DOT,  SHIFT_sl, _______,
        _______, _______, _______, ST_ALT, LOW_BCK, ADJ_ESC, /**/ CTL_TAB,  RSE_SPE, ALT_BSLA, _______, _______,  _______
    ),

    [_LOWER] = LAYOUT_ortho_4x12(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KC_PERC,  /**/ _______, KC_7,   KC_8, KC_9,    KC_PLUS, _______,
        _______, KC_QUES, KC_GRV,  KC_DQUO, KC_QUOT, KC_CIRC,  /**/ KC_EQL,  KC_4,   KC_5, KC_6,    KC_MINS, _______,
        _______, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,  /**/ _______, KC_1,   KC_2, KC_3,    KC_ASTR, _______,
        _______, _______, _______, ST_ALT,  LOW_BCK, MOD_LCTL, /**/ CTL_TAB, LAUNCH, KC_0, _______, _______, _______
    ),

    [_RAISE] = LAYOUT_ortho_4x12(
        _______, _______, _______,  KC_F10, KC_F11, KC_F12, /**/ _______, KC_BTN1,  KC_BTN2, _______,  RESET,    _______,
        _______, _______, KC_ENTER, KC_F7,  KC_F8,  KC_F9,  /**/ _______, KC_MS_L,  KC_MS_D, KC_MS_U,  KC_MS_R,  _______,
        _______, _______, ST_ALT,   KC_F4,  KC_F5,  KC_F6,  /**/ _______, KC_RPRN,  KC_RCBR, KC_RBRC,  KC_TILD,  _______,
        _______, _______, _______,  KC_F1,  KC_F2,  KC_F3,  /**/ CTL_TAB, RSE_SPE,  _______, _______,  _______,  _______
    ),

    [_ADJUST] = LAYOUT_ortho_4x12(
        _______, LGUI(KC_Q), WIN_BACk,   WIN_FWD,       LCTL(KC_TAB), LALT(KC_F7), /**/  _______, KC_HOME,    KC_PGDOWN,  KC_PGUP,    KC_END,     _______,
        _______, LCTL(KC_A), LCTL(KC_S), KC_DELETE,     LCTL(KC_F),   LCTL(KC_L),  /**/  _______, KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,
        _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),    LCTL(KC_V),   _______,     /**/  _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), _______,
        _______, _______,    _______,    OSM(MOD_LALT), KC_SPC,       ADJ_ESC,     /**/  KC_BTN4, KC_BTN5,    CTL_TAB,    _______,    _______,    _______
    ), 

};


/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch(keycode) { */
/*     return true; */
/* } */

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
