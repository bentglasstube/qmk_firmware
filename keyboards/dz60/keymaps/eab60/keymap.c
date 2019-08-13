#include QMK_KEYBOARD_H

enum layers {
	_BASE,
	_FN,
	_NUM,
	_BL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT_60_ansi(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
		KC_LCTL, MO(_FN), KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_APP, KC_RCTL),

	[_FN] = LAYOUT_60_ansi(
		KC_SLEP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
		TT(_NUM),KC_HOME, KC_UP, KC_END, KC_PGUP, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PSCR, KC_VOLD, KC_VOLU, KC_MUTE,
		KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PAUS, KC_GRV, _______,
		_______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, RGB_TOG, KC_INS, _______, RGB_VAD, RGB_VAI, _______, _______,
		_______, _______, _______, _______, _______, RESET, TT(_BL), _______),

 [_NUM] = LAYOUT_60_ansi(
		TG(_NUM),KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_PMNS, KC_PPLS, _______,
		_______, KC_HOME, KC_UP, KC_END, KC_PGUP, XXXXXXX, XXXXXXX, KC_P4, KC_P5, KC_P6, KC_DLR, XXXXXXX, XXXXXXX, KC_NLCK,
		_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, XXXXXXX, KC_P1, KC_P2, KC_P3, KC_PAST, XXXXXXX, KC_PENT,
		_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0, KC_PCMM, KC_PDOT, KC_PSLS, _______,
		_______, _______, _______, _______, _______, _______, _______, _______),

	[_BL] = LAYOUT_60_ansi(
		TG(_BL), RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, XXXXXXX, RGB_RMOD,RGB_MOD, RGB_TOG,
		XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

	/* Template for new layers
	 
 	[] = LAYOUT_60_ansi(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______),
	*/

};
