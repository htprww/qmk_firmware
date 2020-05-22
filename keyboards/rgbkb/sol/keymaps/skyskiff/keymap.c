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
    _MAC = 0,
    _WIN,
    _GME,
    _NAV,
    _FN1,
    _FN2
};

// Keycode defines for layers
#define MAC DF(_MAC)
#define WIN DF(_WIN)
#define GME DF(_GME)

#define NAV MO(_NAV)
#define FN1 MO(_FN1)
#define FN2 MO(_FN2)

#define FN_SPC LT(_FN1, KC_SPC)

enum custom_keycodes { RGBRST = SAFE_RANGE, RGB_MENU, RGB_SAVE, CTRL_K, CTRL_O, POINTER, ARROW, FUNC, SETMWE};

#define FN_ESC LT(_FN1, KC_ESC)
#define FN_CAPS LT(_FN1, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT( \
    KC_ESC,   KC_1,     KC_2,   KC_3,    KC_4,    KC_5,   KC_GRV,  KC_BSLS, KC_6,     KC_7,   KC_8,    KC_9,    KC_0,    KC_DEL,  \
    KC_TAB,   KC_Q,     KC_W,   KC_E,    KC_R,    KC_T,   SETMWE,  FUNC,    KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL,  KC_A,     KC_S,   KC_D,    KC_F,    KC_G,   KC_MINS, KC_EQL,  KC_H,     KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,     KC_X,   KC_C,    KC_V,    KC_B,   KC_MUTE, RGB_TOG, KC_N,     KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),  \
    G(KC_TAB),G(KC_GRV),KC_LALT,KC_LGUI, FN1,     KC_SPC, KC_ENT,  KC_ENT,  KC_SPC,   FN2,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,\
                                                  KC_SPC, KC_ENT,  KC_ENT,  KC_SPC),

    [_WIN] = LAYOUT( \
    KC_GRV,   KC_1,     KC_2,   KC_3,    KC_4,    KC_5,   KC_MINS, KC_EQL,   KC_6,     KC_7,   KC_8,    KC_9,    KC_0,    KC_BSLS, \
    KC_ESC,   KC_Q,     KC_W,   KC_E,    KC_R,    KC_T,   POINTER, ARROW,    KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_TAB,   KC_A,     KC_S,   KC_D,    KC_F,    KC_G,   KC_DEL,  FUNC,     KC_H,     KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LCTL,  KC_Z,     KC_X,   KC_C,    KC_V,    KC_B,   KC_MUTE, RGB_TOG,  KC_N,     KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),  \
    G(KC_TAB),G(KC_GRV),KC_LALT,KC_LGUI, FN1,      KC_SPC, KC_LSPO, KC_RSPC,  KC_SPC,   FN2,     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,\
                                                  KC_SPC, KC_LSPO, KC_RSPC,  KC_SPC),

    [_GME] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_F1, KC_EQL,   KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSLS,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_F2, KC_RBRC,  KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,  \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_F3, KC_QUOT,  KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,   \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MUTE, RGB_TOG,  KC_N,    KC_M,   KC_COMM, KC_UP,  KC_SLSH, RSFT_T(KC_ENT),  \
    KC_LCTL, KC_GRV,  KC_LALT, KC_LALT, KC_LALT, KC_SPC, KC_DEL, KC_BSPC,  KC_SPC,   FN1,     KC_LEFT, KC_DOWN, KC_RIGHT,   KC_LCTL, \
                                                 KC_SPC, KC_DEL, KC_BSPC,  KC_SPC),

    [_NAV] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, _______, _______, CTRL_O,  KC_UP,   _______, \
    _______, KC_HOME, _______, KC_DEL, KC_RIGHT, _______, _______, _______, KC_BSPC, _______, CTRL_K,  _______, _______, _______, \
    _______, _______, _______, _______, _______, KC_LEFT, _______, _______, KC_DOWN, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______),

    [_FN1] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_CAPS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_TILD, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PIPE, KC_F12,  \
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_UNDS, POINTER, ARROW,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_COLN,  KC_DQT, \
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_ASTR, RESET,   RGBRST,  KC_PPLS, KC_AMPR, KC_LT,   KC_GT,   KC_QUES, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______),

    [_FN2] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_CAPS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_TILD, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PIPE, KC_F12,  \
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_UNDS, POINTER, ARROW,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_COLN,  KC_DQT, \
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_ASTR, RESET,   RGBRST,  KC_PPLS, KC_AMPR, KC_LT,   KC_GT,   KC_QUES, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                                                 _______, _______, _______, _______)
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

void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = biton32(layer_state);

    if (index == 2) { /* left encoder */
        if (layer == _FN1 || layer == _FN2) {
            if (clockwise) {
                uint8_t l = _MAC;
                tap_code(DF(l));
            } else {
                uint8_t l = _WIN;
                tap_code(DF(l));
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        }
    } else if (index == 5) { /* right encoder*/
        if (layer == _FN1 || layer == _FN2) {
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

        case CTRL_K:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DELETE));
            } else {
            }
            break;

        case CTRL_O:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER) SS_TAP(X_LEFT));
            }
            break;

        case POINTER:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;

        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;

        case FUNC:
            if (record->event.pressed) {
                SEND_STRING("function");
            }
            break;

        case SETMWE:
            if (record->event.pressed) {
                SEND_STRING("setmwe pwd");
            }
            break;
    }
    return true;
}
