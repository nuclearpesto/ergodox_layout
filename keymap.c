#include  QMK_KEYBOARD_H
#include  "keymap_swedish.h"
#define ___ KC_TRNS
//#define D(STUFF) SS_DOWN(STUFF)
//#define U(STUFF) SS_UP(STUFF)
//#define T(STUFF) SS_TAP(X_STUFF)

enum layers {
    BASE, // default layer(qwerty)
    SYMB, // symbols
    MDIA, // media keys
    GAME  // game layer
};


//#undef TAPPING_TERM
//#define TAPPING_TERM 300

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap 0: Basic layer
   *
   * ,------------------------------------------------------.           ,----------------------------------------------------.
   * |  Grv   |    1   |    2   |   3  |   4  |   5  | Mute |           |  ´   |   6  |   7  |   8  |   9  |   0    |   +    |
   * |--------+--------+--------+------+------+-------------|           |------+------+------+------+------+--------+--------|
   * |  Tab   |    Q   |    W   |   E  |   R  |   T  |      |           | ~GAME|   Y  |   U  |   I  |   O  |   P    |   Å    |
   * |--------+--------+--------+------+------+------|  :   |           |      |------+------+------+------+--------+--------|
   * |!SYMB   |   A    |S/~SYMB |   D  |   F  |  G   |------|           |------|   H  |   J  |   K  |   L  |Ö/~MEDIA|   Ä    |
   * |--------+--------+--------+------+------+------| LSHFT|           | RSHFT|------+------+------+------+--------+--------|
   * |!SYMB   |   Z    |    X   |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -    | '      |
   * `--------+--------+--------+------+------+-------------'           `-------------+------+------+------+--------+--------'
   *   |APP   |  <|>   | Lgui   | Left | Right|                                       |  Up  | Down | RGUI |   ¨    | ~SYMB|
   *   `--------------------------------------'                                       `------------------------------------'
   *                                        ,-------------.       ,--------------.
   *                                        | lALT | Home |       | PgUp |  rALT  |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Del  |       | PgDn |        |      |
   *                                 | Space|Backsp|------|       |------|ESC/rctl|Enter |
   *                                 |      |ace   |esc/c |       | LGui |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [BASE] = LAYOUT_ergodox(  // layer 0 : default
                  // left hand
                  SE_GRV,          SE_1,           SE_2,           SE_3,    SE_4,    SE_5,  KC_MUTE,
                  KC_TAB,          SE_Q,           SE_W,           SE_E,    SE_R,    SE_T,  SE_COLN,
                  TG(SYMB),        SE_A,           LT(SYMB, SE_S), SE_D,    SE_F,    SE_G,
                  TG(SYMB),        SE_Z,           SE_X,           SE_C,    SE_V,    SE_B,  KC_LSFT,
                  KC_APP,          SE_LABK,        KC_LGUI,        KC_LEFT, KC_RGHT,

                                                                                    KC_LALT, KC_HOME,
                                                                                              KC_DEL,
                                                                     KC_SPC, KC_BSPC, LCTL_T(KC_ESC),



		  // right hand
                  SE_ACUT,      SE_6,    SE_7,    SE_8,    SE_9,    SE_0,              SE_PLUS,
                  DF(GAME),     SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,              SE_ARNG,
                                SE_H,    SE_J,    SE_K,    SE_L,    LT(MDIA, SE_ODIA), SE_ADIA,
                  KC_RSFT,      SE_N,    SE_M,    SE_COMM, SE_DOT,  SE_MINS,           SE_QUOT,
                                         KC_UP,   KC_DOWN, KC_RGUI, SE_COLN,           MO(SYMB),

                  KC_PGUP, KC_RALT,
                  KC_PGDN,
                  KC_LGUI, RCTL_T(KC_ESC), KC_ENT
                    ),


  /* Keymap 1: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  | CAPSLCK|
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   =  |   ~  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // SYMBOLS
  [SYMB] = LAYOUT_ergodox(
                  // left hand
                  ___, KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,         ___,
                  ___, SE_EXLM, SE_AT,      SE_LCBR,    SE_RCBR, SE_ASTR, ___,
                  ___, SE_HASH, SE_DLR,     SE_LPRN,    SE_RPRN, SE_GRV,
                  ___, SE_PERC, SE_CIRC,    SE_LBRC,    SE_RBRC, SE_TILD,       ___,
                  ___, ___,     ___,        ___,        ___,

		                                                                      ___, ___,
                                                                                   ___,
                                                                         ___, ___, ___,


		  // right hand
                  ___, KC_F6,      KC_F7,   KC_F8,  KC_F9,  KC_F10,   KC_F11,
                  ___, KC_UP,      KC_7,    KC_8,   KC_9,   KC_PAST,  KC_F12,
                       KC_DOWN,    KC_4,    KC_5,   KC_6,   KC_PPLS,  ___,
                  ___, SE_COLN,    KC_1,    KC_2,   KC_3,   SE_BSLS,  KC_CAPS_LOCK,
                                   KC_0,    KC_0,   KC_DOT, KC_EQL,   SE_TILD,

                  ___, ___,
                  ___,
                  ___, ___, ___
                  ),
  /* Keymap 2: Media and mouse keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | PRNTSC |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      | Lclk | MsUp | Rclk |ScrlUp|      |           |      |      | Play |VolUp |      |      |  F12   |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        | Mclk |MsLeft|MsDown|MsRght|ScrlDn|------|           |------|      | Prev |VolDn | Next |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      | Mute |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |Brwser|
   *                                 |      |      |------|       |------|      |Back  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // MEDIA AND MOUSE
  [MDIA] = LAYOUT_ergodox(
                  KC_PSCR, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ___,
                  ___,     ___,     KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, ___,
                  ___,     KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
                  ___,     ___,     ___,     ___,     ___,     ___,     ___,
                  ___,     ___,     ___,     ___,     ___,

		                                                   ___, ___,
                                                                        ___,
                                                              ___, ___, ___,


		  // right hand
          ___, KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
          ___,   ___, KC_MPLY, KC_VOLU, ___,     ___,    KC_F12,
                 ___, KC_MPRV, KC_VOLD, KC_MNXT, ___,     ___,
          ___,   ___, ___,     KC_MUTE, ___,     ___,     ___,
                      ___,     ___,     ___,     ___,     ___,

		          ___, ___,
                  ___,
                  ___, ___, KC_WBAK
                  ),

  /* Keymap 4: Gaming specific base layer, currently not doing much.
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   A  |   S  |      |      |      |------|           |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |        |
   *   `----------------------------------'                                       `------------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  [GAME] = LAYOUT_ergodox(
                  ___,      ___,  ___,  ___, ___, ___, ___,
                  ___,      ___,  ___,  ___, ___, ___, ___,
                  KC_ESC,      KC_A, KC_S, ___, ___, KC_G,
                  KC_LSFT,  ___,  ___,  ___, ___, ___, ___,
                  KC_LCTL, ___,  ___,  ___, ___,

		                             ___, ___,
                                                  ___,
                                        ___, ___, ___,


		  // right hand
                  ___,      ___, ___, ___, ___, ___, ___,
                  DF(BASE), ___, ___, ___, ___, ___, ___,
                  ___,      ___, ___, ___, ___, ___,
                  ___,      ___, ___, ___, ___, ___, ___,
                  ___,      ___, ___, ___, ___,

		  ___, ___,
                  ___,
                  ___, ___, ___
                  )
};


// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Make ralt behave like lalt when you tap tab
    switch (keycode) {
        case KC_RALT:
            if(get_mods() & (MOD_BIT(KC_LALT))){
                if(!record->event.pressed){
                    unregister_code(KC_LALT);
                }
            }
            return true;

        case KC_TAB:
            // Detect the activation of rightalt
            if (get_mods() & MOD_BIT(KC_RALT) ) {
                if (record->event.pressed) {
                    // No need to register KC_LALT because it's already active.
                    // The Alt modifier will apply on this KC_TAB.
                    register_code(KC_LALT);
                    register_code(KC_TAB);
                } else {
                    unregister_code(KC_TAB);
                }
                // Do not let QMK process the keycode further
                return false;
            }
            // Else, let QMK process the KC_ESC keycode as usual
            return true;
    }

    //return true in all other cases
    return true;

};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
