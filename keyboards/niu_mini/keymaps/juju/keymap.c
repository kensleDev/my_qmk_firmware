#include QMK_KEYBOARD_H

// const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
//     UCIS_SYM("poop", 0x1F4A9),                // 💩
//     UCIS_SYM("rofl", 0x1F923)               // 🤣
// );

// enum custom_keycodes {
//     EMOJI = SAFE_RANGE
// };


// ----------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // switch (keycode) {
    //     case EMOJI:
    //         if (record->event.pressed) {
    //             qk_ucis_start();
    //         }
    //     break;
    // }
    return true;
}

void led_set_user(uint8_t usb_led) {

    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_COMPOSE)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_KANA)) {

    } else {

    }

}

// ----------------------------------------------------------------Layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base
     * ,-----------------------------------------------------------------------------------.
     * |TB-CTL|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |LT-ESC|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  GUI | Ctrl |  Alt |Up-L  |    Space    |Low-b | RALT | RCTL |   \  |      |
     * `-----------------------------------------------------------------------------------'
     */
    [0] = LAYOUT_planck_mit(
      KC_TAB,              KC_Q,    KC_W,          KC_E,  KC_R,  KC_T,   KC_Y,             KC_U,    KC_I,    KC_O,     KC_P, KC_BSPC,
      LT(1, KC_ESCAPE),    KC_A,    KC_S,          KC_D,  KC_F,  KC_G,   KC_H,             KC_J,    KC_K,    KC_L,  KC_SCLN,  KC_ENT,
      KC_LSFT, 	           KC_Z,    KC_X,          KC_C,  KC_V,  KC_B,   KC_N,             KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
      KC_LCTL,          KC_LGUI, KC_LCTL, OSM(MOD_LALT), MO(2),     KC_SPC,    LT(3, KC_BSPACE), KC_RALT, KC_RCTL,  KC_BSLS, KC_RCTL
    ),

    /* Transport , LCTL(KC_F7)
    * ,-----------------------------------------------------------------------------------.
    * |      | ^Q   | !+ESC| !ESC |  F11  |     |      | HOME | PGDN | PGUP | END  |DELETE|
    * |------+------+------+------+------+------+-------------+------+------+------+------|
    * |      | ^A   |  ^S  |  DEL | ^F   |  ^L  |      | LEFT | DOWN | UP   | RIGHT|enter |
    * |------+------+------+------+------+------+------|------+------+------+------+------|
    * |      | ^Z   | ^X   | ^C   | ^V   |      |      |  W1  |  W2  |  W3  |  W4  |shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  GUI | Ctrl |  Alt |      |             |DelWrd|      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [1] = LAYOUT_planck_mit(
      _______,       LGUI(KC_Q), LALT(LSFT(KC_ESC)),  LALT(KC_ESC),  LCTL(KC_L),    _______, _______,         KC_HOME,  KC_PGDOWN,    KC_PGUP,     KC_END, KC_DELETE,
      _______,       LCTL(KC_A),         LCTL(KC_S),     KC_DELETE,  LCTL(KC_F), LCTL(KC_L), _______,         KC_LEFT,    KC_DOWN,      KC_UP,    KC_RGHT,    KC_ENT,
      _______,       LCTL(KC_Z),         LCTL(KC_X),    LCTL(KC_C),  LCTL(KC_V),    _______, _______,      LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4),   KC_RSFT,
      KC_LCTL,          KC_LGUI,            KC_LCTL, OSM(MOD_LALT),     _______,      LALT(KC_PGUP),  LCTL(KC_BSPACE),    _______,    _______,    _______,   _______
    ),

    /* Upperz
    * ,-----------------------------------------------------------------------------------.
    * |      |  !   |   @  |   #  |   _  |   %  |      |   7  |   8  |  9   |  +   | BSPA |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |  ?   |   `  |   "  |   '  |   ^  |   $  |   4  |   5  |  6   |  -   |Enter |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |   |  |   [  |   {  |   (  |   &  |      |   1  |   2  |  3   |  *   |   =  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  GUI | Ctrl |  Alt |      |             |Launch|   0  |   .  |   /  |      |
    * `-----------------------------------------------------------------------------------'
    */
    [2] = LAYOUT_planck_mit(
      _______, KC_EXLM,   KC_AT,       KC_NUHS, KC_UNDS, KC_PERC, _______,        KC_7, KC_8,   KC_9, KC_PLUS, KC_BSPC,
      _______, KC_QUES,  KC_GRV,       KC_DQUO, KC_QUOT, KC_CIRC,  KC_DLR,        KC_4, KC_5,   KC_6, KC_MINS,  KC_ENT,
      _______, KC_PIPE, KC_LBRC,       KC_LCBR, KC_LPRN, KC_AMPR, _______,        KC_1, KC_2,   KC_3, KC_ASTR,  KC_EQL,
      KC_LCTL, KC_LGUI, KC_LCTL, OSM(MOD_LALT), _______,      _______,     LCTL(KC_F7), KC_0, KC_DOT, KC_SLSH, _______
    ),

    /* Lower
    * ,-----------------------------------------------------------------------------------.
    * | App1 |  F10  | F11 |  F12 |      |      |      |      |      |      |      | BSPA |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | App2 |  F7  |  F8  |  F9  |      |      |      |      |      |      |      |Enter |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | App3 |  F4  |  F5  |  F6  |      |      |      |   )  |   }  |   ]  |   ~  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | App4 |  F1  |  F2  |  F3  |      |             |   X  | RALT | RCTL |      |RESET |
    * `-----------------------------------------------------------------------------------'
    */
    [3] = LAYOUT_planck_mit(
      LGUI(KC_1), KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______,  _______, KC_BSPC,
      LGUI(KC_2), KC_F7,   KC_F8,  KC_F9, _______, _______, _______, _______, _______, _______,  _______,  KC_ENT,
      LGUI(KC_3), KC_F4,   KC_F5,  KC_F6, _______, _______, _______, KC_RPRN, KC_RCBR, KC_RBRC,  KC_TILD, _______,
      LGUI(KC_4), KC_F1,   KC_F2,  KC_F3, _______,     _______,      _______, KC_RALT, KC_RCTL,  _______,   RESET
    )

};

