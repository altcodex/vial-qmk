// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
        KC_ESC,           KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,           KC_U,    KC_I,    KC_O,    KC_P,            KC_MINS,
        KC_LBRC,          KC_A,         KC_S,    KC_D,    KC_F,    KC_G,               KC_H,           KC_J,    KC_K,    KC_L,    KC_SCLN,         KC_QUOT,
        LGUI_T(KC_EQL),   LALT_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,               LT(2, KC_N),    KC_M,    KC_COMM, KC_DOT,  RALT_T(KC_SLSH), RGUI_T(KC_BSLS),
        LCTL_T(KC_LNG2), LT(1, KC_SPC), LSFT_T(KC_BSPC),                              LSFT_T(KC_TAB), LT(1, KC_ENT),  LCTL_T(KC_LNG1)
    ),

    [1] = LAYOUT_split_3x6_3(
        KC_RCBR,         KC_EXLM,       KC_AT,   KC_HASH, KC_DLR,  KC_PERC,            KC_CIRC,        KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,        KC_TILD,
        KC_RBRC,         KC_1,          KC_2,    KC_3,    KC_4,    KC_5,               KC_6,           KC_7,    KC_8,    KC_9,    KC_0,           KC_GRV,
        LGUI_T(KC_F11),  LALT_T(KC_F1), KC_F2,   KC_F3,   KC_F4,   KC_F5,              LT(2, KC_F6),   KC_F7,   KC_F8,   KC_F9,   RALT_T(KC_F10), RGUI_T(KC_F12),
        _______, _______, LSFT_T(KC_DEL),                                              _______, _______, _______
    ),

    [2] = LAYOUT_split_3x6_3(
        _______,         _______,       _______,   _______, _______,  _______,          KC_PGUP, KC_HOME, KC_UP,   KC_END,   _______, _______,
        _______,         _______,       _______,   _______, _______,  _______,          KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
        _______,         _______,       _______,   _______, _______,  _______,          _______, _______, _______, _______,  _______, _______,
        _______,         _______,       _______,                                        _______, _______, _______
    )
};
