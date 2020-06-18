#include QMK_KEYBOARD_H

// ----------------------------------------------------------------Layer Declarations
enum layers {
  _MAIN_WIN,
  _MAIN_MAC,
  _NAV_WIN,
  _NAV_MAC,
  _NUM_PADS,
  _SYM
};

enum keycodes {
  WIN = SAFE_RANGE,
  MAC
};

// ----------------------------------------------------------------Tap Dance Funcs
// void quoter (qk_tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//       tap_code(KC_QUOTE);
//     } else if (state->count == 2) {
//       tap_code(KC_DOUBLE_QUOTE);
//     } else if (state->count == 3) {
//       tap_code(KC_GRAVE);
//     } else {
//       reset_tap_dance (state);
//     }
// }

// ----------------------------------------------------------------Tap Dance Declarations
enum {
  TD_COLON_SEMI = 0,
  TD_QUOTER,
  TD_SLASH_QUESTION,
  TD_DOT_EXCLAIM,
  TD_SLASH_PIPE,
  TD_MINUS_UNDER,
  TD_AT_GRAVE,
  TD_PERC_DOLLA,
  TD_HASH_CARROT
};

// ---------------------------------------------------------------- Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_COLON_SEMI] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SCOLON),
  [TD_QUOTER] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DOUBLE_QUOTE), 
  [TD_SLASH_QUESTION] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_QUESTION),
  [TD_DOT_EXCLAIM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_EXCLAIM),
  [TD_SLASH_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BSLASH, KC_PIPE),
  [TD_MINUS_UNDER] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_UNDERSCORE),
  [TD_AT_GRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_AT, KC_GRAVE),
  [TD_PERC_DOLLA] = ACTION_TAP_DANCE_DOUBLE(KC_PERC, KC_DOLLAR),
  [TD_HASH_CARROT] = ACTION_TAP_DANCE_DOUBLE(KC_HASH, KC_CIRC),
};

// ----------------------------------------------------------------Layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* -------------------- WIN ------------------- */

    /* 
    * ,-----------------------------------------------------------------------------------.
    * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |bspace|
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |L1 ESC|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |Shift(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift)|
    * |------+------+------+------+------+------+------+------+------+------+------+------|  
    * |Ctrl  |      |  GUI |  Alt |Layer2|    Space    |numpds|      |      |   \  |CTRL  |
    * `-----------------------------------------------------------------------------------'
    */ 
    [_MAIN_WIN] = LAYOUT_planck_mit(
      KC_TAB,                         KC_Q,    KC_W,          KC_E,         KC_R,   KC_T,     KC_Y,          KC_U,     KC_I,    KC_O,              KC_P, KC_BSPACE,
      LT(_NAV_WIN, KC_ESCAPE),        KC_A,    KC_S,          KC_D,         KC_F,   KC_G,     KC_H,          KC_J,     KC_K,    KC_L, TD(TD_COLON_SEMI),  KC_ENTER,
      KC_LSPO, 	                      KC_Z,    KC_X,          KC_C,         KC_V,   KC_B,     KC_N,         KC_M,  KC_COMM,  KC_DOT,           KC_SLASH,   KC_RSPC,
      KC_LCTL,                     _______, KC_LGUI, OSM(MOD_LALT),    OSL(_SYM),       KC_SPC,     TT(_NUM_PADS),  _______, _______, TD(TD_SLASH_PIPE),   KC_RCTL
    ), 
    /* 
    * ,-----------------------------------------------------------------------------------.
    * |      | ENTER| !+ESC| !ESC |  ^L  |  ^W  |      | HOME | PGDN | PGUP | END  |DELETE|
    * |------+------+------+------+------+------+-------------+------+------+------+------| 
    * |      | ^A   |  ^S  |  DEL | BKSP |  ^F  |      | LEFT | DOWN | UP   | RIGHT|  RUN |
    * |------+------+------+------+------+------+------|------+------+------+------+------|
    * |      | ^Z   | ^X   | ^C   | ^V   | ^+P  |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | ^+Z  |      |      |      |     ^P      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_NAV_WIN] = LAYOUT_planck_mit(
      _______,         KC_ENTER, LALT(LSFT(KC_ESC)), LALT(KC_ESC),  LCTL(KC_L),       LCTL(KC_W),     _______, KC_HOME, KC_PGDOWN, KC_PGUP,   KC_END,      KC_DELETE,
      _______,       LCTL(KC_A),         LCTL(KC_S),    KC_DELETE,   KC_BSPACE,       LCTL(KC_F),     _______, KC_LEFT,   KC_DOWN,   KC_UP, KC_RIGHT, LGUI(KC_SPACE),
      _______,       LCTL(KC_Z),         LCTL(KC_X),   LCTL(KC_C),  LCTL(KC_V), LCTL(LSFT(KC_P)),     _______, LGUI(1),   LGUI(2), LGUI(3),  LGUI(4),        LGUI(5),
      _______, LCTL(LSFT(KC_Z)),            _______,      _______,     _______,                 LCTL(KC_P),    _______,   _______, _______,    RESET,         _______ 
    ),   

    /* -------------------- MAC ------------------- */

    /* Layer 0
    * ,-----------------------------------------------------------------------------------.
    * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |bspace|
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |L1 ESC|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |Shift(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift)|
    * |------+------+------+------+------+------+------+------+------+------+------+------|  
    * |CTRL  |      |  GUI |  Alt |Layer2|    Space    |numpds|      |      |   \  |CTRL  |
    * `-----------------------------------------------------------------------------------'
    */  
    [_MAIN_MAC] = LAYOUT_planck_mit(
      KC_TAB,                    KC_Q,          KC_W,    KC_E,      KC_R,   KC_T,   KC_Y,          KC_U,    KC_I,    KC_O,              KC_P, KC_BSPACE,
      LT(_NAV_MAC, KC_ESCAPE),   KC_A,          KC_S,    KC_D,      KC_F,   KC_G,   KC_H,          KC_J,    KC_K,    KC_L, TD(TD_COLON_SEMI),  KC_ENTER,
      KC_LSPO, 	                 KC_Z,          KC_X,    KC_C,      KC_V,   KC_B,   KC_N,          KC_M, KC_COMM,  KC_DOT,          KC_SLASH,   KC_RSPC,
      KC_LCTL,                _______, OSM(MOD_LALT), KC_LGUI, OSL(_SYM),     KC_SPC,    OSL(_NUM_PADS), _______, _______, TD(TD_SLASH_PIPE),   KC_LCTL
    ), 

    /* 
    * ,-----------------------------------------------------------------------------------.
    * |      | ENTER| !+ESC| !ESC |  ^L  |  ^W  |      | HOME | PGDN | PGUP | END  |DELETE|
    * |------+------+------+------+------+------+-------------+------+------+------+------| 
    * |      | ^A   |  ^S  |  DEL | BKSP |  ^F  |      | LEFT | DOWN | UP   | RIGHT|  RUN |
    * |------+------+------+------+------+------+------|------+------+------+------+------|
    * |      | ^Z   | ^X   |  ^C  | ^V   | ^+P  |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | RESET| ^+Z  |      |      |      |     ^P      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_NAV_MAC] = LAYOUT_planck_mit(
      _______,         KC_ENTER, LGUI(LSFT(KC_TAB)), LGUI(KC_TAB),  LGUI(KC_L),       LGUI(KC_W),      _______, KC_HOME, KC_PGDOWN, KC_PGUP,   KC_END,      KC_DELETE,
      _______,       LGUI(KC_A),         LGUI(KC_S),    KC_DELETE,   KC_BSPACE,       LGUI(KC_F),      _______, KC_LEFT,   KC_DOWN,   KC_UP, KC_RIGHT, LALT(KC_SPACE),
      _______,       LGUI(KC_Z),         LGUI(KC_X),   LGUI(KC_C),  LGUI(KC_V), LGUI(LSFT(KC_P)),      _______, LGUI(1),   LGUI(2), LGUI(3),  LGUI(4),        LGUI(5),
      _______, LCTL(LSFT(KC_Z)),            _______,      _______,     _______,              LGUI(KC_P),        _______,   _______, _______,    RESET,        _______ 
    ),

    /* -------------------- SYM ------------------- */

    /*
    * ,-----------------------------------------------------------------------------------.
    * |      |  F10  | F11 |  F12 |      |   [  |   ]  |  7   |   8  |   9  |  +   | BSPA |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |      |   (  |   )  |  4   |   5  |   6  |  -   |Enter |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |  F4  |  F5  |  F6  |      |   {  |   }  |  1   |   2  |   3  |  *   |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |      |  backspace  |      |   0  |   .  |  /   |  =   |
    * `-----------------------------------------------------------------------------------' 
    */
    [_NUM_PADS] = LAYOUT_planck_mit(
      _______, KC_F10, KC_F11, KC_F12, _______, KC_LBRC, KC_RBRC,    KC_7,  KC_8,   KC_9, KC_PPLS, KC_BSPACE, 
      _______, KC_F7,   KC_F8,  KC_F9, _______, KC_LPRN, KC_RPRN,    KC_4,  KC_5,   KC_6, KC_PMNS,  KC_ENTER,
      _______, KC_F4,   KC_F5,  KC_F6, _______, KC_LCBR, KC_RCBR,    KC_1,  KC_2,   KC_3, KC_PAST,   _______, 
      _______, KC_F1,   KC_F2,  KC_F3, _______,     KC_BSPACE,    _______,  KC_0, KC_DOT, KC_PSLS,    KC_PEQL
    ),

    /* -------------------- SYM ------------------- */

    /*
    * ,-----------------------------------------------------------------------------------.
    * |  WIN |   !   |   @  |  #  |      |   %  |      |      |      |      |      | BSPA |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |  MAC |   ?  |   `  |   "  |  '   |   ^  |   $  |   -  |  _   |   =  |   ~  |Enter |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |   |  |   /  |   &  |   £  |   \  |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | RESET|      |      |      |      |  backspace  |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------' 
    */
    [_SYM] = LAYOUT_planck_mit(
          WIN, KC_EXLM,    KC_AT,  KC_HASH,  _______, KC_PERC,  _______,  _______, _______,     _______, _______, KC_BSPC, 
          MAC, KC_QUES, KC_GRAVE,  KC_DQUO,  KC_QUOT, KC_CIRC,   KC_DLR, KC_MINUS, KC_UNDS,    KC_EQUAL, KC_TILD, KC_ENT,
      _______, _______,  _______,  KC_PIPE,  KC_PSLS, KC_AMPR,    KC_AT,  KC_NUBS, _______,     _______, _______, _______, 
        RESET, _______,  _______,  _______,  _______,     KC_BSPACE,      _______, _______,     _______, _______, _______
    )

};


// ----------------------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case (WIN):
        if (record->event.pressed) {
          print("mode just switched to windows\n");
          set_single_persistent_default_layer(_MAIN_WIN);
        }
        return false;
        break;
      case MAC:
        if (record->event.pressed) {
          print("mode just switched to mac\n");
          set_single_persistent_default_layer(_MAIN_MAC);
        }
        return false;
        break;

    }
      return true;

}

void led_set_user(uint8_t usb_led) {

    // if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {

    // } else {

    // }

    // if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {

    // } else {

    // }

    // if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {

    // } else {

    // }

    // if (IS_LED_ON(usb_led, USB_LED_COMPOSE)) {

    // } else {

    // }

    // if (IS_LED_ON(usb_led, USB_LED_KANA)) {

    // } else {

    // }

}















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

// 
// static bool bsdel_mods = false;


// // ---------------------------------------------------------------- Macro Declarations
// enum {
//     COPY = 0,
//     REDO,
//     M_BSDEL
// };


// // ---------------------------------------------------------------- Macro Definitions
// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
// {
//   switch(id) {

//     case REDO: {
//       if (record->event.pressed) {
//         return MACRO(D(LCTRL), D(LSHIFT), T(Z), U(LSHIFT), U(LCTRL), END);
//       }
//     }

    
//     case M_BSDEL: {
//       uint8_t kc = KC_BSPC;

//       if (keyboard_report->mods) {
//         kc = KC_DEL;
//         bsdel_mods = true;
//       } else {
//         bsdel_mods = false;
//       }

//       if (record->event.pressed)
//         register_code (kc);
//       else
//         unregister_code (kc);
//     }


//   }
//   return MACRO_NONE;
// };