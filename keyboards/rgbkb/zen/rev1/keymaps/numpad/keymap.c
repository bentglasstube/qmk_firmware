#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _NUMPAD = 0,
    _LIGHTS,
};


enum custom_keycodes {
  NUMPAD = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Numpad  (This is reversed because I only have the right half
   *         .-----------------------------------------.
   *         |   7  |   8  |   9  |   (  |   )  | Bksp |
   *         |------+------+------+------+------+------|
   *         |   4  |   5  |   6  |   *  |   /  | Tab  |
   *         |------+------+------+------+------+------|
   *         |   1  |   2  |   3  |   -  | PgUp | Gui  |
   *         |------+------+------+------+------+------|
   *         |   0  |   .  |   ,  |  Up  | PgDn | Alt  |
   * .-------+------+------+------+------+------+------|
   * | Enter |   +  |  Esc | Left | Down | Rght | Ctrl |
   * '-------------------------------------------------'
   */

  [_NUMPAD] = LAYOUT( \
    KC_BSPC,             KC_RPRN, KC_LPRN, KC_P9,   KC_P8,    KC_P7,                      _______,  _______,  _______, _______, _______, _______, \
    KC_TAB,              KC_PSLS, KC_PAST, KC_P6,   KC_P5,    KC_P4,                      _______,  _______,  _______, _______, _______, _______, \
    LT(_LIGHTS,KC_NLCK), KC_PGUP, KC_MINS, KC_P3,   KC_P2,    KC_P1,                      _______,  _______,  _______, _______, _______, _______, \
    KC_RALT,             KC_PGDN, KC_UP,   KC_PCMM, KC_PDOT,  KC_P0,                      _______,  _______,  _______, _______, _______, _______, \
    KC_RCTL,             KC_RGHT, KC_DOWN, KC_LEFT, KC_ESC,   KC_PPLS, KC_PENT, _______,  _______,  _______,  _______, _______, _______, _______ \
  ),

  /* Lights  (This is reversed because I only have the right half
   *         .-----------------------------------------.
   *         |   7  |   8  |   9  |   (  |   )  | Bksp |
   *         |------+------+------+------+------+------|
   *         |   4  |   5  |   6  |   *  |   /  | Tab  |
   *         |------+------+------+------+------+------|
   *         |   1  |   2  |   3  |   -  | PgUp | Gui  |
   *         |------+------+------+------+------+------|
   *         |   0  |   .  |   ,  |  Up  | PgDn | Alt  |
   * .-------+------+------+------+------+------+------|
   * | Enter |   +  |  Esc | Left | Down | Rght | Ctrl |
   * '-------------------------------------------------'
   */

  [_LIGHTS] = LAYOUT( \
    _______, RGB_MOD, RGB_RMOD, RGB_M_P, RGB_M_B,  RGB_M_R,                    _______,  _______,  _______, _______, _______, _______, \
    _______, RGB_HUI, RGB_HUD,  RGB_M_K, RGB_M_X,  RGB_M_G,                    _______,  _______,  _______, _______, _______, _______, \
    _______, RGB_SAI, RGB_SAD,  _______, RGB_M_SW, RGB_M_SN,                   _______,  _______,  _______, _______, _______, _______, \
    _______, RGB_VAI, RGB_VAD,  _______, _______,  _______,                    _______,  _______,  _______, _______, _______, _______, \
    _______, RGB_SPI, RGB_SPD,  _______, _______,  _______,  RGB_TOG, _______, _______,  _______,  _______, _______, _______, _______ \
  ),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NUMPAD:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_NUMPAD);
      }
      return false;
      break;
  }
  return true;
}
