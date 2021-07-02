#include QMK_KEYBOARD_H

// #include "quantum/color.h"
// #include "drivers/issi/is31fl3736.h"
#include "wt_rgb_backlight_keycodes.h" // reuse these for now

enum {
	MAC = 0,
	WIN,
	GME,
	NAV,
	FN
};

enum custom_keycodes {
	NAV_K = SAFE_RANGE,
	NAV_U,
	NAV_O
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	// Mac layer
	[MAC] = LAYOUT_all(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    TO(WIN),
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_HOME, KC_END,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   MO(FN),
		KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_DEL,           KC_LEFT, KC_DOWN, KC_RGHT),

	// Win Layer
	[WIN] = LAYOUT_all(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   TO(GME),
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		MO(NAV), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
		KC_LGUI, KC_LALT, KC_LCTL,                            _______,                            KC_RCTL, _______,          _______, _______, _______),

	// Game Layer
	[GME] = LAYOUT_all(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   TO(MAC),
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		MO(NAV), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
		KC_LCTL, KC_LBRC, KC_LALT,                            _______,                            KC_RCTL, KC_RGUI,          _______, _______, _______),

	// nav Layer
	[NAV] = LAYOUT_all(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, KC_END,  _______, _______, _______, NAV_U,   _______, NAV_O,   KC_UP,   _______, _______, _______,          _______,
		_______, KC_HOME, _______, KC_DEL,  KC_RGHT, _______, KC_BSPC, _______, NAV_K,   _______, _______, _______, _______,                   _______,
		_______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, _______, _______, _______, _______, _______,                   _______, _______,
		_______, _______, _______,                            LGUI(KC_SPC),                       _______, _______,          _______, _______, _______),

	// fn Layer
	[FN] = LAYOUT_all(
		RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______,          BR_INC,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   BR_DEC,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_VOLU, _______,
		_______, _______, _______,                            _______,                            _______, _______,          KC_MUTE, KC_VOLD, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NAV_K:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_END))SS_TAP(X_DEL));
      }
    break;
    case NAV_O:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER)SS_TAP(X_LEFT));
      }
    break;
    case NAV_U:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_HOME))SS_TAP(X_BSPC));
      }
    break;
  }
  return true;
}