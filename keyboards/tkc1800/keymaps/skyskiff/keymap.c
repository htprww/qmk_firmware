/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "LUFA/Drivers/Peripheral/TWI.h"
#include "i2c.h"
#include "ssd1306.h"

//Layers

enum {
  MAC = 0,
  WIN,
  GME,
  NON,
  NAV,
  FN
};

enum custom_keycodes {
  NAV_K = SAFE_RANGE,
  NAV_U,
  NAV_O,
  NAV_C
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap BASE: (Base Layer) Default Layer
   * ,-------------------------------------------------------.     ,-------------------.
   * |Esc| F1| F2| F3| F4| | F5| F6| F7| F8| | F9|F10|F11|F12|     |Ins |Home|PgUp|PrSc|
   * `-------------------------------------------------------'     |-------------------|
   *                                                               |Del |End |PgDn|ScrL|
   * ,-----------------------------------------------------------. |-------------------|
   * | ~ | 1 |  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|\ | Del| | |NumL| /  | *  |Paus|
   * |-----------------------------------------------------------| |-------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| BKSP| | 7  | 8  | 9  | -  |
   * |-----------------------------------------------------------| |-------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | | 4  | 5  | 6  | +  |
   * |-----------------------------------------------------------' |-------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift  | Up | 1  | 2  | 3  | Ent|
   * |--------------------------------------------------------'----`--------------|    |
   * |Ctrl|Gui |Alt |      Space           |Alt |Fn |Ctr|Left |Down|Rght| 0  | .  |    |
   * `---------------------------------------------------------------------------------'
   */
  [MAC] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    DF(WIN), KC_MUTE, KC_VOLD, KC_VOLU, \
                                                                                                                                           KC_F5,  S(KC_F8), KC_HOME, KC_PGUP, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_F7,   KC_F8,   KC_END,  KC_PGDN, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_P7,   KC_P8,   KC_P9,   XXXXXXX, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,           KC_P4,   KC_P5,   KC_P6,   G(KC_C), \
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,       KC_P1,   KC_P2,   KC_P3,   XXXXXXX, \
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                        KC_RGUI, MO(FN), KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT,       KC_P0,   KC_PDOT, KC_PENT  \
  ),
  [WIN] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    DF(GME),  KC_MUTE, KC_VOLD, KC_VOLU, \
                                                                                                                                           KC_F5,  S(KC_F11), KC_HOME, KC_PGUP, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_F10,  KC_F11,   KC_END,  KC_PGDN, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_P7,   KC_P8,    KC_P9,   XXXXXXX, \
    MO(NAV), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,           KC_P4,   KC_P5,    KC_P6,   C(KC_C), \
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,       KC_P1,   KC_P2,    KC_P3,   XXXXXXX, \
    KC_LALT, KC_LGUI, KC_LCTL,                   KC_SPC,                        KC_RCTL, MO(FN), KC_RGUI,          KC_LEFT, KC_DOWN, KC_RGHT,       KC_P0,    KC_PDOT, KC_PENT  \
  ),
  [GME] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    DF(NON),  KC_MUTE, KC_VOLD, KC_VOLU, \
                                                                                                                                           KC_F5,   S(KC_F11),  KC_HOME, KC_PGUP, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_F10,  KC_F11,  KC_END,  KC_PGDN, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_P7,   KC_P8,   KC_P9,   XXXXXXX, \
    MO(NAV), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,           KC_P4,   KC_P5,   KC_P6,   C(KC_C), \
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,       KC_P1,   KC_P2,   KC_P3,   XXXXXXX, \
    KC_LCTL, KC_RBRC, KC_LALT,                   KC_SPC,                        KC_RCTL, MO(FN), KC_RGUI,          KC_LEFT, KC_DOWN, KC_RGHT,       KC_P0,   KC_PDOT, KC_PENT  \
  ),
  /* non layer */
  [NON] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    DF(MAC), XXXXXXX, XXXXXXX, XXXXXXX, \
                                                                                                                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                        XXXXXXX, MO(FN), XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
  /* windows navigation layer */
  [NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, \
                                                                                                                                           _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,  KC_END, _______, _______, _______,   NAV_U, _______,   NAV_O,   KC_UP, _______, _______, _______,          _______, _______, _______, XXXXXXX, \
    _______, KC_HOME, _______,  KC_DEL, KC_RGHT, _______, KC_BSPC, _______,   NAV_K, _______, _______, _______, XXXXXXX, _______,          _______, _______, _______, _______, \
    _______, XXXXXXX, _______, _______, C(KC_C), _______, KC_LEFT, KC_DOWN, _______, _______, _______, _______, _______,    _______,       _______, _______, _______, XXXXXXX, \
    _______, _______, _______,                   LGUI(KC_SPC),                    _______, _______, _______,      _______, _______, _______,        _______, _______, _______  \
  ),
  /* Keymap FUNCTION: (Function Layer)
   * ,-------------------------------------------------------.     ,-------------------.
   * | RESET |  |  |  |  | |   |   |   |   | |   |   |   |   |     |    |    |    |    |
   * `-------------------------------------------------------'     |-------------------|
   *                                                               |    |    |    |    |
   * ,-----------------------------------------------------------. |-------------------|
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |       |   |   |   |   |   |   |   |   |   |   |   |       | |    |    |    |    |
   * |-----------------------------------------------------------' |-------------------|
   * |        |Tog|Mod|Hu+|Hu-|Sa+|Sa-|Va+|Va-|Stp|   |       |    |    |    |    |    |
   * |--------------------------------------------------------'----`--------------|    |
   * |    |    |    |                      |    |   |   |     |    |    |    | .  |    |
   * `---------------------------------------------------------------------------------'
   */
  [FN] = LAYOUT(
    RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, \
                                                                                                                                           _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, XXXXXXX, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,          _______, _______, _______, _______, \
    _______, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_STEP, _______, _______,      KC_BRIU,     _______, _______, _______, XXXXXXX, \
    _______, _______, _______,                   _______,                            _______, _______, _______,      KC_WBAK, KC_BRID, KC_WFWD,     _______, _______, _______  \
  )
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

layer_state_t default_layer_state_set_user(layer_state_t state)	{
  int layer = biton32(state);
  if (layer == NON) {
    PORTD &= ~(1<<2);
    PORTD &= ~(1<<3);
    PORTD &= ~(1<<4);
  }
  if (layer == MAC) {
    PORTD |= (1<<2);
  } else {
    PORTD &= ~(1<<2);
  }
  if (layer == WIN) {
    PORTD |= (1<<3);
  } else {
    PORTD &= ~(1<<3);
  }
  if (layer == GME) {
    PORTD |= (1<<4);
  } else {
    PORTD &= ~(1<<4);
  }
  return state;
}

// force nunlock on
void led_set_user(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }
}
