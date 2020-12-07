#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _M = 0,
    _W,
    _G,
    _N,
    _L,
    _R,
};

enum custom_keycodes { RGBRST = SAFE_RANGE, RGB_MENU, RGB_SAVE, NAV_K, NAV_O, NAV_U};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_M] = LAYOUT( \
    KC_ESC,       KC_1,     KC_2,   KC_3,    KC_4,    KC_5,   KC_F5,   KC_F8,   KC_6,     KC_7,   KC_8,     KC_9,   KC_0,    KC_DEL,     \
    KC_TAB,       KC_Q,     KC_W,   KC_E,    KC_R,    KC_T,   KC_F7,   KC_F10,  KC_Y,     KC_U,   KC_I,     KC_O,   KC_P,    KC_BSPC,    \
    CTL_T(KC_ESC),KC_A,     KC_S,   KC_D,    KC_F,    KC_G,   KC_F8,   KC_F11,  KC_H,     KC_J,   KC_K,     KC_L,   KC_SCLN, KC_QUOT,    \
    KC_LSFT,      KC_Z,     KC_X,   KC_C,    KC_V,    KC_B,   KC_MUTE, RGB_TOG, KC_N,     KC_M,   KC_COMM,  KC_DOT, KC_SLSH, SFT_T(KC_ENT),    \
    G(KC_TAB), G(KC_GRV), KC_LALT, KC_LGUI, MO(_L), KC_SPC, KC_ENT,  KC_ENT,  KC_SPC, MO(_R), RGUI_T(KC_LEFT),  KC_DOWN, KC_UP, KC_RIGHT,\
                                                      KC_SPC, KC_ENT,  KC_ENT,  KC_SPC),

    [_W] = LAYOUT( \
    _______,   _______,     _______,   _______,    _______,    _______,   KC_F5,   KC_F8,   _______,     _______,   _______,  _______,  _______, _______,     \
    _______,   _______,     _______,   _______,    _______,    _______,   KC_F10,  KC_F10,  _______,     _______,   _______,  _______,  _______, _______,    \
    LT(_N, KC_ESC), _______, _______, _______,   _______,    _______,   KC_F11,  KC_F11,  _______,     _______,   _______,  _______,  _______, _______,    \
    _______,   _______,     _______,   _______,    _______,    _______,   KC_MUTE, RGB_TOG, _______,     _______,   _______,  _______,  _______, _______,    \
    KC_LGUI,   A(KC_TAB), KC_LALT,KC_LCTL, MO(_L),KC_SPC, KC_ENT,  KC_ENT,  KC_SPC, MO(_R), _______, _______, _______, _______,\
                                                      KC_SPC, KC_ENT,  KC_ENT,  KC_SPC),

    [_G] = LAYOUT( \
    _______,   _______,    _______,    _______,    _______,    _______,   KC_F1,   KC_P7,    _______,     _______,   _______,    _______,    _______,     _______,  \
    _______,   _______,    _______,    _______,    _______,    _______,   KC_F2,   KC_P4,    _______,     _______,   _______,    _______,    _______,     _______,  \
    LT(_N, KC_ESC), _______,    _______,    _______,    _______,    _______,   KC_F3,   KC_P1,    _______,     _______,   _______,    _______,    _______,  _______,  \
    _______,  _______,    _______,    _______,    _______,    _______,   KC_MUTE, RGB_TOG,  _______,     _______,   _______, KC_UP,   _______,  _______,  \
    KC_LCTL,  KC_GRV,  KC_LBRC, KC_RBRC, KC_LALT, KC_SPC, KC_ENT,  KC_ENT,   KC_SPC, MO(_R), KC_LEFT, KC_DOWN, KC_RIGHT, KC_RGUI,  \
                                                  KC_SPC, KC_ENT,  KC_ENT,   KC_SPC),

    [_N] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, NAV_U,   _______, NAV_O,   KC_UP,   _______, \
    _______, KC_HOME, _______, KC_DEL, KC_RIGHT, _______, _______, _______, KC_BSPC, _______, NAV_K,   _______, _______, _______, \
    _______, _______, _______, C(KC_C), _______, KC_LEFT, _______, _______, KC_DOWN, _______, _______, _______, _______, _______, \
    _______,_______,_______,_______,_______,LGUI(KC_SPC), _______, _______, LGUI(KC_SPC),_______,_______,_______,_______,_______, \
                                            LGUI(KC_SPC), _______, _______, LGUI(KC_SPC)),


    [_L] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TILD,   XXXXXXX, XXXXXXX, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_DOT,  KC_DEL,  \
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   S(KC_F8),  XXXXXXX, XXXXXXX, KC_MINS, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_PIPE,  \
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_F11), RESET,   RGBRST,  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_SLSH, _______,\
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_SPC,    XXXXXXX, XXXXXXX, KC_SPC,  KC_0,    _______, XXXXXXX, XXXXXXX, XXXXXXX,  \
                                                 KC_SPC,    XXXXXXX, XXXXXXX, KC_SPC),

    [_R] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_TILD, XXXXXXX, XXXXXXX, KC_PLUS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_DEL,  \
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  XXXXXXX, XXXXXXX, KC_MINS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_PIPE,  \
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_UNDS, RESET,   RGBRST,  KC_EQL,  KC_AMPR, KC_ASTR, KC_RABK, KC_BSLS, _______,\
    XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_DEL,  KC_SPC,  XXXXXXX, XXXXXXX, KC_SPC,  _______, _______, DF(_M), DF(_W), DF(_G),  \
                                                 KC_SPC,  XXXXXXX, XXXXXXX, KC_SPC),


};

void rgb_matrix_step_noeeprom(void) {
    led_flags_t current = rgb_matrix_get_flags();
    if (current == LED_FLAG_NONE) {
        return;
    }
    rgb_matrix_config.mode++;
    if (rgb_matrix_config.mode >= RGB_MATRIX_EFFECT_MAX) rgb_matrix_config.mode = 1;
}

void rgb_matrix_step_reverse_noeeprom(void) {
    led_flags_t current = rgb_matrix_get_flags();
    if (current == LED_FLAG_NONE) {
        return;
    }
    rgb_matrix_config.mode--;
    if (rgb_matrix_config.mode < 1) rgb_matrix_config.mode = RGB_MATRIX_EFFECT_MAX - 1;
}

void rgb_matrix_toggle_noeeprom(void) {
    static led_flags_t previous = LED_FLAG_ALL;
    led_flags_t current = rgb_matrix_get_flags();
    if (current == LED_FLAG_NONE) {
        rgb_matrix_set_flags(previous);
        rgb_matrix_enable_noeeprom();
    } else {
        previous = current;
        rgb_matrix_set_flags(LED_FLAG_NONE);
        rgb_matrix_disable_noeeprom();
    }
}

// For RGBRST Keycode
void rgb_matrix_increase_flags(void) {
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
        } break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
        } break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
        } break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
        } break;
    }
}

void rgb_matrix_decrease_flags(void) {
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
        } break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_set_color_all(0, 0, 0);
        } break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
        } break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_enable_noeeprom();
        } break;
    }
}

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = biton32(layer_state);

    if (index == 2) { /* left encoder */
        if (layer == _L || layer == _R) {
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        }
    } else if (index == 5) { /* right encoder*/
        if (layer == _L || layer == _R) {
            if (clockwise) {  // flipped
                rgb_matrix_decrease_flags();
            } else {
                rgb_matrix_increase_flags();
            }
        } else {
            if (clockwise) {  // flipped
                rgb_matrix_step_reverse_noeeprom();
            } else {
                rgb_matrix_step_noeeprom();
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint16_t reset_timer;
    switch (keycode) {
        case RGBRST:
            if (record->event.pressed) {
                eeconfig_update_rgb_matrix_default();
            }
            return false;
        // case RESET:
        //     if (record->event.pressed) {
        //         reset_timer = timer_read();
        //     } else {
        //         if (timer_elapsed(reset_timer) >= 500) {
        //             reset_keyboard();
        //         }
        //     }
        //     return false;

        case RGB_TOG:
            if (record->event.pressed) {
                rgb_matrix_toggle_noeeprom();
            }
            return false;

        case RGB_SAVE:
            if (record->event.pressed) {
                // eeconfig_update_rgb_matrix();
            }
            return false;

        case NAV_K:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DEL));
            }
            break;
        case NAV_O:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER) SS_TAP(X_LEFT));
            }
            break;
        case NAV_U:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_BSPC));
            }
            break;
    }
    return true;
}
