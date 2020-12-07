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
    _FN2,
    _M,
    _NAVR,
    _MOUR,
    _MEDR,
    _NSL,
    _NSSL,
    _FUNL
};

// Keycode defines for layers
#define MAC DF(_MAC)
#define WIN DF(_WIN)
#define GME DF(_GME)

#define NAV MO(_NAV)
#define FN1 MO(_FN1)
#define FN2 MO(_FN2)


enum custom_keycodes { RGBRST = SAFE_RANGE, RGB_MENU, RGB_SAVE, NAV_K, NAV_O, NAV_U};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT( \
    KC_ESC,   KC_1,     KC_2,   KC_3,    KC_4,   KC_5,   KC_F5,   KC_F8,   KC_6,     KC_7,   KC_8,    KC_9,    KC_0,    KC_DEL,     \
    KC_TAB,   KC_Q,     KC_W,   KC_E,    KC_R,   KC_T,   KC_F7,   KC_F10,  KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,    \
    KC_LCTL,  KC_A,     KC_S,   KC_D,    KC_F,   KC_G,   KC_F8,   KC_F11,  KC_H,     KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,    \
    KC_LSFT,  KC_Z,     KC_X,   KC_C,    KC_V,   KC_B,   KC_MUTE, RGB_TOG, KC_N,     KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,    \
    G(KC_TAB),G(KC_GRV),KC_LALT,KC_LGUI, FN1,    KC_SPC, KC_ENT,  KC_ENT,  KC_SPC,   FN2, RGUI_T(KC_LEFT), KC_DOWN, KC_UP, KC_RIGHT,\
                                                 KC_SPC, KC_ENT,  KC_ENT,  KC_SPC),

    [_WIN] = LAYOUT( \
    KC_GESC,  KC_1,     KC_2,   KC_3,    KC_4,   KC_5,   KC_F5,   KC_F8,   KC_6,     KC_7,   KC_8,    KC_9,    KC_0,    KC_DEL,     \
    KC_TAB,   KC_Q,     KC_W,   KC_E,    KC_R,   KC_T,   KC_F10,  KC_F10,  KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,    \
    NAV,      KC_A,     KC_S,   KC_D,    KC_F,   KC_G,   KC_F11,  KC_F11,  KC_H,     KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,    \
    KC_LSFT,  KC_Z,     KC_X,   KC_C,    KC_V,   KC_B,   KC_MUTE, RGB_TOG, KC_N,     KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,    \
    KC_LGUI, A(KC_TAB), KC_LALT,KC_LCTL, FN1,    KC_SPC, KC_ENT,  KC_ENT,  KC_SPC,   FN2, RCTL_T(KC_LEFT), KC_DOWN, KC_UP, KC_RIGHT,\
                                                 KC_SPC, KC_ENT,  KC_ENT,  KC_SPC),

    [_GME] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_F1,   KC_P7,    KC_6,    KC_7,  KC_8,    KC_9,    KC_0,     KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_F2,   KC_P4,    KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,     KC_BSPC,  \
    NAV,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_F3,   KC_P1,    KC_H,    KC_J,  KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MUTE, RGB_TOG,  KC_N,    KC_M,  KC_COMM, KC_UP,   KC_SLSH,  KC_RSFT,  \
    KC_LCTL, KC_GRV,  KC_LBRC, KC_RBRC, KC_LALT, KC_SPC, KC_ENT,  KC_ENT,   KC_SPC,  FN2,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_RGUI,  \
                                                 KC_SPC, KC_ENT,  KC_ENT,   KC_SPC),

    [_NAV] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_END,  _______, _______, _______, _______, _______, NAV_U,   _______, NAV_O,   KC_UP,   _______, \
    _______, KC_HOME, _______, KC_DEL, KC_RIGHT, _______, _______, _______, KC_BSPC, _______, NAV_K,   _______, _______, _______, \
    _______, _______, _______, C(KC_C), _______, KC_LEFT, _______, _______, KC_DOWN, _______, _______, _______, _______, _______, \
    _______,_______,_______,_______,_______,LGUI(KC_SPC), _______, _______, LGUI(KC_SPC),_______,_______,_______,_______,_______, \
                                            LGUI(KC_SPC), _______, _______, LGUI(KC_SPC)),

    [_FN1] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_CAPS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_TILD, _______, _______,   KC_PIPE, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_F12,  \
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV, S(KC_F11),S(KC_F11), KC_PLUS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_DQT,  \
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_UNDS, RESET,    RGBRST,   KC_MINS, KC_EQL,  KC_ASTR, KC_RABK, KC_BSLS, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, \
                                                 _______, _______, _______, _______),

    [_FN2] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_CAPS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_TILD, _______, _______,   KC_PIPE, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_F12,  \
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV, S(KC_F11),S(KC_F11), KC_PLUS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_DQT,  \
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_UNDS, RESET,    RGBRST,   KC_MINS, KC_EQL,  KC_ASTR, KC_RABK, KC_BSLS, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   MAC,     WIN,     GME,     DF(_M),  \
                                                 _______, _______, _______, _______),


    [_M] = LAYOUT( \
    XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX, \
    XXXXXXX, KC_Q,     KC_W,        KC_E,       KC_R,       KC_T,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,          XXXXXXX, \
    XXXXXXX,GUI_T(KC_A),ALT_T(KC_S),CTL_T(KC_D),SFT_T(KC_F),KC_G,    XXXXXXX, XXXXXXX, KC_H, SFT_T(KC_J), CTL_T(KC_K), ALT_T(KC_L), GUI_T(KC_SCLN),XXXXXXX, \
    XXXXXXX, KC_Z,    ALGR_T(KC_X), KC_C,       KC_V,       KC_B,    KC_MUTE, RGB_TOG, KC_N,    KC_M,       KC_COMM,   ALGR_T(KC_DOT), KC_SLSH,    XXXXXXX,  \
    KC_NO,KC_NO,KC_NO,LT(_MEDR,KC_ESC),LT(_NAVR,KC_SPC),LT(_MOUR,KC_TAB),KC_NO,KC_NO,LT(_NSSL,KC_ENT),LT(_NSL,KC_BSPC),LT(_FUNL,KC_DEL),KC_NO,KC_NO,KC_NO,\
                                                        LT(_MOUR,KC_TAB),KC_NO,KC_NO,LT(_NSSL,KC_ENT)),

    [_NAVR] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, RGB_TOG, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,   XXXXXXX, \
    KC_NO,   KC_NO,   KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   KC_NO,   KC_ENT,  KC_BSPC, KC_DEL,  KC_NO,   KC_NO,    KC_NO,   \
                                                 XXXXXXX, KC_NO,   KC_NO,   KC_ENT),

    [_MOUR] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, RGB_TOG, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, \
    KC_NO,   KC_NO,   KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   KC_NO,  KC_BTN1,  KC_BTN3, KC_BTN2, KC_NO,   KC_NO,   KC_NO,   \
                                                 XXXXXXX, KC_NO,   KC_NO,  KC_BTN1),

    [_MEDR] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_NO,   KC_NO,   KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   KC_NO,   KC_MSTP, KC_MPLY, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   \
                                                 XXXXXXX, KC_NO,   KC_NO,   KC_MSTP),
    
    [_NSL] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_MUTE, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_NO,   KC_NO,   KC_NO,   KC_DOT,  KC_0,    KC_MINS, KC_NO,   KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   KC_NO,   KC_NO,   \
                                                 KC_MINS, KC_NO,   KC_NO,   XXXXXXX),

    [_NSSL] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_MUTE, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_NO,   KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_UNDS, KC_NO,   KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   KC_NO,   KC_NO,   \
                                                 KC_UNDS, KC_NO,   KC_NO,   XXXXXXX),

    [_FUNL] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, RESET,   RGBRST,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_NO,   KC_NO,   KC_NO,   KC_APP,  KC_SPC,  KC_TAB,  KC_NO,   KC_NO,   XXXXXXX, XXXXXXX, XXXXXXX, KC_NO,   KC_NO,   MAC,     \
                                                 KC_TAB,  KC_NO,   KC_NO,   XXXXXXX),

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
        if (layer == _FN1 || layer == _FN2) {
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
