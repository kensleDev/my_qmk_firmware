#include QMK_KEYBOARD_H

// Macro Declarations
enum {
    COPY = 0,
    PASTE,
    CUT,
    UNDO,
    REDO,
    ALL,
    SAVE,
    WIN_P,
    WIN_N
};


// Macro Definitions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

    // for more complex macros (want to add modifiers, etc.)
    case COPY: {
      if (record->event.pressed) {
         return MACRO(D(LCTRL), T(C), U(LCTRL), END);
      }
    }

    case PASTE: {
      if (record->event.pressed) {
        return MACRO(D(LCTRL), T(V), U(LCTRL), END);
      }
    }

    case CUT: {
      if (record->event.pressed) {
        return MACRO(D(LCTRL), T(X), U(LCTRL), END);
      }
    }

    case UNDO: {
      if (record->event.pressed) {
        return MACRO(D(LCTRL), T(Z), U(LCTRL), END);
      }
    }

    case REDO: {
      if (record->event.pressed) {
        return MACRO(D(LCTRL), D(LSHIFT), T(Z), U(LSHIFT), U(LCTRL), END);
      }
    }

    case ALL: {
      if (record->event.pressed) {
        return MACRO(D(LCTRL), T(A), U(LCTRL), END);
      }
    }

    case SAVE: {
      if (record->event.pressed) {
        return MACRO(D(LCTRL), T(S), U(LCTRL), END);
      }
    }

    case WIN_N: {
      if (record->event.pressed) {
        return MACRO(D(LALT), T(ESC), U(LALT), END);
      }
    }

    case WIN_P: {
      if (record->event.pressed) {
        return MACRO(D(LALT), D(LSHIFT), T(ESC), U(LSHIFT), U(LALT), END);
      }
    }

  }
  return MACRO_NONE;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ?  |Right |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  GUI |  Alt |      |Layer1|    Space    |Layer2|   `  |   @  |   /  |Quote |
     * `-----------------------------------------------------------------------------------'
     */
    [0] = LAYOUT_planck_mit(
        KC_TAB,  	KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    	 KC_BSPC,
        KC_ESCAPE,      KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, 	 KC_ENT,
        KC_LSFT, 	KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_QUESTION,  KC_RSFT,
        KC_LCTL, 	KC_LGUI, KC_LALT, KC_LALT, TT(2),     KC_SPC,     TT(1), KC_GRV, KC_AT,   KC_SLSH, 	 KC_QUOT
    ),

    /* Layer 1
     * ,-----------------------------------------------------------------------------------.
     * |      | F10  | F11  | F12  |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F4  |  F5  |  F6  |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Reset|  F1  |  F2  |  F3  |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [1] = LAYOUT_planck_mit(
        _______, KC_F10,  KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F7,   KC_F8,  KC_F9,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F4,   KC_F5,  KC_F6,  _______, _______, _______, _______, _______, _______, _______, _______,
        RESET,   KC_F1,   KC_F2,  KC_F3,  _______,     _______,      _______, _______, _______, _______, _______
    ),

    /* Layer 2 (r_ Indicates RGB Controls)
    * ,-----------------------------------------------------------------------------------.
    * |      | ENTER| !+ESC| !ESC |      |      |      | HOME | PGDN | PGUP | END  |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      | ^A   |  ^S  | BKSP | DEL  |      |      | LEFT | DOWN |  UP  | RIGHT|      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      | ^Z   | ^X   | ^C   | ^V   |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | ^+Z  |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [2] = LAYOUT_planck_mit(
       _______, KC_ENTER, M(WIN_P),  M(WIN_N),   _______, _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP,   KC_END, _______,
       _______,   M(ALL),  M(SAVE), KC_BSPACE, KC_DELETE, _______, _______, KC_LEFT,   KC_DOWN,   KC_UP, KC_RIGHT, _______,
       _______,  M(UNDO),   M(CUT),   M(COPY),  M(PASTE), _______, _______, _______,   _______, _______, _______,  _______,
       _______,  M(REDO),  _______,   _______,   _______,     _______,      _______,   _______, _______, _______,  _______
    )

  
};



void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
