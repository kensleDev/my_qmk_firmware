#include QMK_KEYBOARD_H

#define ST_ALT OSM(MOD_LALT)
#define LAUNCH LCTL(KC_F7)

/* Layers */
#define _BASE 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

// layer switchers
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NAV_ESC MO(_ADJUST)


// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
    * ,-----------------------------------------.  .----------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |  |  Y   |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------|  |------+------+------+------+------+------|
    * | Func |   A  |   S  |   D  |   F  |   G  |  |  H   |   J  |   K  |   L  |   ;  | Enter|
    * |------+------+------+------+------+------|  |------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |  |  N   |   M  |   ,  |   .  |   /  |  '   |
    * |------+------+------+------+------+------|  |------+------+------+------+------+------|
    * | Ctrl |  `   | GUI  | Alt  |Lower |Back  |  |Space |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------.  .----------------------------------------'
    */
    [_BASE] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_ESC,
        NAV_ESC, KC_A,    KC_S,    KC_D,   KC_F,  KC_G,    KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LCTL, ST_ALT, LOWER, KC_BSPC, KC_SPC, RAISE, KC_RALT, KC_RCTL, KC_BSLS, KC_RCTL
    ),

    /* Adjust , 
    * ,-----------------------------------------------------------------------------------.
    * |      | ^Q   | !+ESC| !ESC |  F11  |     | BACk | HOME | PGDN | PGUP | END  |DELETE|
    * |------+------+------+------+------+------+-------------+------+------+------+------|
    * |      | ^A   |  ^S  |  DEL | ^F   |  ^L  |Forwar| LEFT | DOWN | UP   | RIGHT|enter |
    * |------+------+------+------+------+------+------|------+------+------+------+------|
    * |      | ^Z   | ^X   | ^C   | ^V   |      |      |  W1  |  W2  |  W3  |  W4  |shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  GUI | Ctrl |  Alt |      |      |      |DelWrd|      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT_ortho_4x12(
        _______, LGUI(KC_Q), LALT(LSFT(KC_ESC)), LALT(KC_ESC),  LCTL(KC_L), _______,    KC_WBAK,       KC_HOME,         KC_PGDOWN,  KC_PGUP,    KC_END,     KC_DELETE,
        _______, LCTL(KC_A), LCTL(KC_S),         KC_DELETE,     LCTL(KC_F), LCTL(KC_L), KC_WFWD,       KC_LEFT,         KC_DOWN,    KC_UP,      KC_RGHT,    KC_ENT,
        _______, LCTL(KC_Z), LCTL(KC_X),         LCTL(KC_C),    LCTL(KC_V), _______,    _______,       LGUI(KC_1),      LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), KC_RSFT,
        KC_LCTL, KC_LGUI,    KC_LCTL,            OSM(MOD_LALT), _______,    _______,    LALT(KC_PGUP), LCTL(KC_BSPACE), _______,    _______,    _______,    _______
    ),


    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |      |  !   |   @  |   #  |   _  |   %  |      |   7  |   8  |  9   |  +   | BSPA |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |  ?   |   `  |   "  |   '  |   ^  |   $  |   4  |   5  |  6   |  -   |Enter |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |   |  |   [  |   {  |   (  |   &  |      |   1  |   2  |  3   |  *   |   =  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  GUI | Ctrl |  Alt |      |      |      |Launch|   0  |   .  |   /  |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT_ortho_4x12(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, KC_PERC, _______, KC_7,   KC_8, KC_9,   KC_PLUS, KC_BSPC,
        _______, KC_QUES, KC_GRV,  KC_DQUO, KC_QUOT, KC_CIRC, KC_DLR,  KC_4,   KC_5, KC_6,   KC_MINS, KC_ENT,
        _______, KC_PIPE, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, _______, KC_1,   KC_2, KC_3,   KC_ASTR, KC_EQL,
        KC_LCTL, KC_LGUI, KC_LCTL, ST_ALT,  _______, _______, _______, LAUNCH, KC_0, KC_DOT, KC_SLSH, _______
    ),

    /* Lowerk
    * ,-----------------------------------------------------------------------------------.
    * | App1 |      |  F10  | F11 |  F12 |      |      |      |      |      |      | BSPA |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | App2 |      |  F7  |  F8  |  F9  |      |      |      |      |      |      |Enter |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | App3 |      |  F4  |  F5  |  F6  |      |      |   )  |   }  |   ]  |   ~  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | App4 |      |  F1  |  F2  |  F3  |      |      |   X  | RALT | RCTL |       |RESET|
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_ortho_4x12(
        LGUI(KC_1), _______, KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, _______,  _______, KC_BSPC,
        LGUI(KC_2), _______, KC_F7,   KC_F8,  KC_F9, _______, _______, _______, _______, _______,  _______,  KC_ENT,
        LGUI(KC_3), _______, KC_F4,   KC_F5,  KC_F6, _______, _______, KC_RPRN, KC_RCBR, KC_RBRC,  KC_TILD, _______,
        LGUI(KC_4), _______, KC_F1,   KC_F2,  KC_F3, _______, _______, _______, KC_RALT, KC_RCTL,  _______,   RESET
    )


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  }
  return true;
}
