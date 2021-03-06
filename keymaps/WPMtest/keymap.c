/* Copyright 2018 Jack Humbert
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
#include <stdio.h>
#include "remote_kb.h"

#define _MA 0
#define _FN 1

enum custom_keycodes {
  KC_CUST = SAFE_RANGE,
};

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_0; }

void oled_task_user(void) {

    switch (get_highest_layer(layer_state)) {
        case _MA:
            oled_write_P(PSTR("_MA Layer\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("_FN Layer\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
	char wpm_str[5];
	sprintf(wpm_str, "WPM = %i\n", get_current_wpm());
	//oled_write_P(PSTR("\n"), false);
	oled_write(wpm_str, false);
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("[ C A P S   L O C K ]") : PSTR("[caps off]"), false);

}

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MA] = LAYOUT(
           KC_F16,    KC_F15, KC_KP_MINUS, \
  KC_KP_7, KC_KP_8,  KC_KP_9,        KC_KP_PLUS, \
  KC_KP_4, KC_KP_5,  KC_KP_6,        KC_NO, \
  KC_KP_1, KC_KP_2,  KC_KP_3,        TO(_FN), \
  KC_NO,   KC_KP_0,  KC_KP_DOT,      KC_NO \

    ),
    [_FN] = LAYOUT(
           KC_NO, RGB_TOG, KC_NO,
    KC_NO, KC_NO, RGB_MOD, KC_NO,
    KC_NO, KC_NO, RGB_HUI, KC_NO,
    KC_NO, KC_NO, RGB_SAI, KC_NO,
    KC_NO,  KC_NO, RGB_VAI, TO(_MA)

    ),
};
/*const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MA] = LAYOUT_ansi(
             KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    KC_MUTE, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
    KC_MPLY, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    _______, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
    _______, KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                    MO(_FN), KC_RALT, MO(_FN), KC_LEFT,          KC_DOWN, KC_RGHT
  ),
  [_FN] = LAYOUT_ansi(
               RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_HOME,  KC_INS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,                   _______,                   _______, _______, _______, _______,          _______, _______
  ),

};
*/
/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_record_remote_kb(keycode, record);
  switch(keycode) {
    case KC_CUST: //custom macro
      if (record->event.pressed) {
      }
    break;

    case RM_1: //remote macro 1
      if (record->event.pressed) {
      }
    break;

    case RM_2: //remote macro 2
      if (record->event.pressed) {
      }
    break;

    case RM_3: //remote macro 3
      if (record->event.pressed) {
      }
    break;

    case RM_4: //remote macro 4
      if (record->event.pressed) {
      }
    break;

  }
return true;
}*/

void matrix_init_user(void) {
  matrix_init_remote_kb();
}

void matrix_scan_user(void) {
  matrix_scan_remote_kb();
}
