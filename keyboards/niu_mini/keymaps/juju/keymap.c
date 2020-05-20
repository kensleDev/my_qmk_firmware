#include QMK_KEYBOARD_H


static bool bsdel_mods = false;

// ---------------------------------------------------------------- Macro Declarations
enum {
    COPY = 0,
    PASTE,
    CUT,
    UNDO,
    REDO,
    ALL,
    SAVE,
    WIN_P,
    WIN_N,
    M_BSDEL
};


// ---------------------------------------------------------------- Macro Definitions
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

    
    case M_BSDEL: {
      uint8_t kc = KC_BSPC;

      if (keyboard_report->mods) {
        kc = KC_DEL;
        bsdel_mods = true;
      } else {
        bsdel_mods = false;
      }

      if (record->event.pressed)
        register_code (kc);
      else
        unregister_code (kc);
    }


  }
  return MACRO_NONE;
};

// ----------------------------------------------------------------Tap Dance Declarations
enum {
  TD_COLON_SEMI = 0,
  TD_QUOUTE_DOUBLE,
  TD_SLASH_QUESTION,
  TD_DOT_EXCLAIM,
  TD_SLASH_PIPE
};

// ---------------------------------------------------------------- Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {

  [TD_COLON_SEMI]  = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SCOLON),
  [TD_QUOUTE_DOUBLE]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DOUBLE_QUOTE),
  [TD_SLASH_QUESTION]  = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_QUESTION),
  [TD_DOT_EXCLAIM]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_EXCLAIM),
  [TD_SLASH_PIPE]  = ACTION_TAP_DANCE_DOUBLE(KC_BSLASH, KC_PIPE),
};

// ----------------------------------------------------------------
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

// ----------------------------------------------------------------Layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |Shift(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   ?  |Shift)|
     * |------+------+------+------+------+------+------+------+------+------+------+------|  
     * |Ctrl[ |  GUI |  Alt |      |Layer1|    Space    |Layer2|  `   |Quote |   /  |Hyper]|
     * `-----------------------------------------------------------------------------------'
     */
    [0]   = LAYOUT_planck_mit(
        KC_TAB,                         KC_Q,    KC_W,    KC_E,       KC_R,  KC_T,   KC_Y,   KC_U,     KC_I,                 KC_O,                  KC_P,                  KC_BSPACE,
        LT(1, KC_ESCAPE),               KC_A,    KC_S,    KC_D,       KC_F,  KC_G,   KC_H,   KC_J,     KC_K,                 KC_L,     TD(TD_COLON_SEMI),                   KC_ENTER,
        KC_LSPO, 	                      KC_Z,    KC_X,    KC_C,       KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM,   TD(TD_DOT_EXCLAIM), TD(TD_SLASH_QUESTION),                    KC_RSPC,
        LCTL_T(KC_LEFT_CURLY_BRACE), KC_LGUI, KC_LALT,    _______,   TT(2),     KC_SPC,     TT(2), KC_GRAVE, TD(TD_QUOUTE_DOUBLE),     TD(TD_SLASH_PIPE), MEH_T(KC_RIGHT_CURLY_BRACE)
    ), 


    /* Layer 1
    * ,-----------------------------------------------------------------------------------.
    * |      | ENTER| !+ESC| !ESC |  ^L  |  ^W  |      | HOME | PGDN | PGUP | END  |DELETE|
    * |------+------+------+------+------+------+-------------+------+------+------+------|
    * |      | ^A   |  ^S  |  DEL | BKSP |      |      | LEFT | DOWN | UP   | RIGHT|      |
    * |------+------+------+------+------+------+------|------+------+------+------+------|
    * |      | ^Z   | ^X   | ^C   | ^V   |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | RESET| ^+Z  |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [1] = LAYOUT_planck_mit(
       _______, KC_ENTER, M(WIN_P),  M(WIN_N),   _______, _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP,   KC_END, KC_DELETE,
       _______,   M(ALL),  M(SAVE), KC_DELETE, KC_BSPACE, _______, _______, KC_LEFT,   KC_DOWN,   KC_UP, KC_RIGHT,   _______,
       _______,  M(UNDO),   M(CUT),   M(COPY),  M(PASTE), _______, _______, _______,   _______, _______,  _______,   _______,
         RESET,  M(REDO),  _______,   _______,   _______,      _______,      _______,  _______, _______,  _______,   _______ 
    ),

    /* Layer 2
    * ,-----------------------------------------------------------------------------------.
    * |      |  F10  | F11 |  F12 |      |   !  |   $  |      |   7  |   8  |  9   |   +  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |      |   "  |   %  |      |   4  |   5  |  6   |   -  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |  F4  |  F5  |  F6  |      |   #  |   ^  |      |   1  |   2  |  3   |   *  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |      |      |      |      |   0  |   .  |   =  |   /  |
    * `-----------------------------------------------------------------------------------'
    */
    [2] = LAYOUT_planck_mit(
       _______, KC_F10, KC_F11, KC_F12, _______,    KC_EXCLAIM,     KC_DOLLAR, _______, KC_7,   KC_8,         KC_9,     KC_KP_PLUS,
       _______, KC_F7,   KC_F8,  KC_F9, _______,      KC_QUOTE,    KC_PERCENT, _______, KC_4,   KC_5,         KC_6,    KC_KP_MINUS,
       _______, KC_F4,   KC_F5,  KC_F6, _______, KC_NONUS_HASH, KC_CIRCUMFLEX, _______, KC_1,   KC_2,         KC_3, KC_KP_ASTERISK,
       _______, KC_F1,   KC_F2,  KC_F3, _______,            _______,           _______, KC_0, KC_DOT,  KC_KP_EQUAL,    KC_KP_SLASH
    )    

};


// /*----------------------------------------------------------------Leader Layer ()
//     * ,-----------------------------------------------------------------------------------.
//     * |      |      |      |      |      |      |      |      |      |      |      | RESET|
//     * |------+------+------+------+------+-------------+------+------+------+------+------|
//     * |      | ^A   |  ^S  |  DEL |      |      |      |      |      |      |      |      |
//     * |------+------+------+------+------+------|------+------+------+------+------+------|
//     * |      | ^Z   | ^X   | ^C   | ^V   |      |      |      |      |      |      |      |
//     * |------+------+------+------+------+------+------+------+------+------+------+------|
//     * |      | ^+Z  |      |      |      |      |      |      |      |      |      |      |
//     * `-----------------------------------------------------------------------------------'
//     */

// LEADER_EXTERNS();
// void matrix_scan_user(void) {
//   LEADER_DICTIONARY() {
//     leading = false;
//     leader_end();

//     SEQ_ONE_KEY(KC_A) {
//       SEND_STRING(SS_LCTRL("a"));
//     }

//     SEQ_ONE_KEY(KC_S) {
//       SEND_STRING(SS_LCTRL("s"));
//     }

//     SEQ_ONE_KEY(KC_C) {
//       SEND_STRING(SS_LCTRL("c"));
//     }

//     SEQ_ONE_KEY(KC_V) {
//       SEND_STRING(SS_LCTRL("v"));
//     }

//     SEQ_ONE_KEY(KC_X) {
//       SEND_STRING(SS_LCTRL("x"));
//     }

//    SEQ_ONE_KEY(KC_Z) {
//       SEND_STRING(SS_LCTRL("z"));
//    }
   

   
//   }
// }


// /* 
//     /* Layer 2
//     * ,-----------------------------------------------------------------------------------.
//     * |      |  !   |   "  |   #  |   9  |   {  |   }  |  0   |   $  |   %  |  ^   |      |
//     * |------+------+------+------+------+-------------+------+------+------+------+------|
//     * |      | 5    |  6   |   7  |   8  |   (  |   )  |  1   |  2   |   3  |   4  |      |
//     * |------+------+------+------+------+------|------+------+------+------+------+------|
//     * |      |      |      |  /   |  *   |   [  |   ]  |   +  |   -  |   .  |   &  |      |
//     * |------+------+------+------+------+------+------+------+------+------+------+------|
//     * |      |      |      |      |      |      |      |      |      |      |      |  `   |
//     * `-----------------------------------------------------------------------------------'
//     */
//     [2] = LAYOUT_planck_mit(
//        _______, KC_EXCLAIM, KC_QUOTE, KC_NONUS_HASH,           KC_9, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,       KC_0, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, _______,
//        _______,       KC_5,     KC_6,          KC_7,           KC_8,       KC_LEFT_PAREN,       KC_RIGHT_PAREN,       KC_1,     KC_2,        KC_3,          KC_4, _______,
//        _______,    _______,  _______,   KC_KP_SLASH, KC_KP_ASTERISK,         KC_LBRACKET,          KC_RBRACKET, KC_KP_PLUS, KC_MINUS,   KC_KP_DOT,       _______, _______,
//        _______,    _______,  _______,       _______,        _______,                  _______,         _______,    _______,  _______,     _______,       KC_GRV
//     )   */
