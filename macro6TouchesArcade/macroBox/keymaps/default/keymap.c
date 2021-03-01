#include "kb.h"

enum layers {
    _BASE = 0,
    _BASE2,
    _BASE3

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = KEYMAP(RCS(KC_S), RCS(KC_B), LALT(KC_SPACE), LCTL(KC_C), LCTL(KC_V), DF(_BASE2)),
	[_BASE2] = KEYMAP(LCTL(KC_N), LCTL(KC_L), RCS(KC_1), LCTL(KC_X), LCTL(KC_V), DF(_BASE3)),
    [_BASE3] = KEYMAP(LCTL(KC_B), LCTL(KC_S), RCS(KC_T), LCTL(KC_G), LCTL(KC_H), DF(_BASE)),

};

