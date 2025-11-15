// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum my_keycodes {
  JS_ARROW = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_40_hhkb(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        LCTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_MINS, KC_RSFT, MO(1),
        KC_LGUI, ALT_T(KC_LNG2), LT(2,KC_SPC),  LT(2,KC_SPC),  RCTL_T(KC_LNG1), KC_RGUI
    ),
    [1] = LAYOUT_40_hhkb(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, KC_HOME,  KC_UP,   KC_END,  KC_DEL,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_PGUP, KC_LEFT, KC_RIGHT, _______,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PGDN, KC_DOWN,  _______, _______,
        _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT_40_hhkb(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    JS_ARROW, _______, KC_LBRC,  KC_RBRC, KC_BSLS, _______,
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,   KC_GRAVE, KC_SCLN, KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, KC_COMM,  KC_DOT,  KC_SLSH, _______, _______,
        _______, _______, KC_LSFT, KC_RSFT,  _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case JS_ARROW:
      if (record->event.pressed) {
        // when keycode pressed
        SEND_STRING("=>");
      } else {
        // when keycode released
      }
      return false;
    default:
      return true;
  }
}
