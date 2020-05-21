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
  GNU,
  WIN,
  CMD,
  NAV,
  FN
};

enum custom_keycodes {
  NAV_K = SAFE_RANGE,
  NAV_U,
  NAV_O,
  CMD_A,
  CMD_S,
  CMD_W,
  CMD_T,
  CMD_O,
  CMD_N
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
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    DF(GNU), KC_NLCK, KC_CAPS, KC_SLCK, \
                                                                                                                                           KC_0,    KC_FIND,  KC_HOME, KC_PGUP, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_COPY, KC_PASTE, KC_END,  KC_PGDN, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_P7,   KC_P8,    KC_P9,   XXXXXXX, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,           KC_P4,   KC_P5,    KC_P6,   KC_PPLS, \
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,       KC_P1,   KC_P2,    KC_P3,   XXXXXXX, \
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                        KC_RGUI, MO(FN), KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT,       KC_P0,   KC_PDOT,  KC_PENT  \
  ),
  [GNU] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    DF(WIN),  KC_HOME, KC_PGUP, KC_PSCR, \
                                                                                                                                           KC_1,  KC_END,  KC_PGDN, KC_PAUS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_NLCK, KC_CAPS, KC_SLCK, KC_PMNS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_P7,   KC_P8,   KC_P9,   XXXXXXX, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,           KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,       KC_P1,   KC_P2,   KC_P3,   XXXXXXX, \
    KC_LCTL, KC_LALT, MO(CMD),                   KC_SPC,                        MO(CMD), MO(FN), KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT,       KC_P0,   KC_PDOT, KC_PENT  \
  ),
  [WIN] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    DF(MAC),  KC_HOME, KC_PGUP, KC_PSCR, \
                                                                                                                                           KC_DEL,  KC_END,  KC_PGDN, KC_PAUS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_P7,   KC_P8,   KC_P9,   XXXXXXX, \
    MO(NAV), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,           KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,       KC_P1,   KC_P2,   KC_P3,   XXXXXXX, \
    KC_LGUI, KC_LALT, KC_LCTL,                   KC_SPC,                        KC_RCTL, MO(FN), KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT,       KC_P0,   KC_PDOT, KC_PENT  \
  ),
  /* linux command layer */
  [CMD] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, \
                                                                                                                                           _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______,   CMD_W, _______, _______,   CMD_T, _______, _______, _______, CMD_O,   _______, _______, _______, _______,          _______, _______, _______, XXXXXXX, \
    _______, CMD_A,     CMD_S, _______, KC_FIND, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,          _______, _______, _______, _______, \
    _______, XXXXXXX, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, _______,  CMD_N, _______, _______, _______, _______, _______,    _______,       _______, _______, _______, XXXXXXX, \
    _______, _______, _______,                   _______,                        _______, _______, _______,        _______, _______, _______,       _______, _______, _______  \
  ),
  /* windows navigation layer */
  [NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, \
                                                                                                                                           _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,  KC_END, _______, _______, _______,   NAV_U, _______,   NAV_O,   KC_UP, _______, _______, _______,          _______, _______, _______, XXXXXXX, \
    _______, KC_HOME, _______,  KC_DEL, KC_RGHT, _______, KC_BSPC, _______,   NAV_K, _______, _______, _______, XXXXXXX, _______,          _______, _______, _______, _______, \
    _______, XXXXXXX, _______, _______, _______, _______, KC_LEFT, KC_DOWN, _______, _______, _______, _______, _______,    _______,       _______, _______, _______, XXXXXXX, \
    _______, _______, _______,                   LGUI(KC_SPC),                        _______, _______, _______,        _______, _______, _______,       _______, _______, _______  \
  ),
  /* Keymap FUNCTION: (Function Layer)
   * ,-------------------------------------------------------.     ,-------------------.
   * |   |   |   |   |   | |   |   |   |   | |   |   |   |   |     |    |    |    |    |
   * `-------------------------------------------------------'     |-------------------|
   *                                                               |    |    |    |    |
   * ,-----------------------------------------------------------. |-------------------|
   * |   |   |   |   |   |   |   |   |   |   |   |   |   | RESET | |    |    |    |    |
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
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, \
                                                                                                                                           _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______, _______, _______, XXXXXXX, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,          _______, _______, _______, _______, \
    _______, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, BL_STEP, _______, _______,      _______,     _______, _______, _______, XXXXXXX, \
    _______, _______, _______,                   _______,                            _______, _______, _______,      _______, _______, _______,     _______, _______, _______  \
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
  if (layer == MAC) {
    PORTD |= (1<<2);
  } else {
    PORTD &= ~(1<<2);
  }
  if (layer == GNU) {
    PORTD |= (1<<3);
  } else {
    PORTD &= ~(1<<3);
  }
  if (layer == WIN) {
    PORTD |= (1<<4);
  } else {
    PORTD &= ~(1<<4);
  }
  return state;
}