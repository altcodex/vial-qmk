// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum my_keycodes {
  TG_LAYOUT = SAFE_RANGE
};

bool is_jis = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_hhkb(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
                          KC_LGUI, ALT_T(KC_LNG2),                   KC_SPC,                             CTL_T(KC_LNG1), KC_RGUI
    ),

    [1] = LAYOUT_60_hhkb(
        TG_LAYOUT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_RGHT,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_DOWN, _______, _______,
                          _______, _______,                   _______,                            _______, _______
    )
};

#include "twpair_on_jis.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TG_LAYOUT:
      if (record->event.pressed) {
        is_jis = !is_jis;
      }
      return false;
    default:
      if (is_jis && !twpair_on_jis(keycode, record))
        return false;

      return true;
  }
}
