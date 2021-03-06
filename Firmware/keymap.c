/*
Copyright 2020 Marek Kaplan <kaplan.marek@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "led.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //0: FN1 layer
    {{KC_GRV,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,   KC_7,  KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC},
     {KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,   KC_U,  KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS},
     {KC_ESC,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,  KC_H,   KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT },
     {KC_LSFT, KC_NO,   KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_NO,   KC_RSFT},
     {KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_NO, KC_SPC, KC_NO, KC_NO, KC_NO,   KC_RALT, KC_FN0,  KC_FN1,  KC_RCTL}},
    //1: FN2 layer
    {{KC_GRV,  KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL},
     {KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,    KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS},
     {KC_ESC,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_SCLN, KC_QUOT, KC_NO,   KC_ENT },
     {KC_LSFT, KC_NO,   KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_BSLS, KC_NO,   KC_RSFT},
     {KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_NO, KC_SPC,  KC_NO,   KC_NO, KC_NO,   KC_RALT, KC_FN0,  KC_FN1,  KC_RCTL}}
};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
	[0] = ACTION_DEFAULT_LAYER_SET(0), //set FN1 layer
	[1] = ACTION_DEFAULT_LAYER_SET(1), //set FN2 layer
};

// Change led status when default layer is changed
void hook_default_layer_change(uint32_t default_layer_state)
{
    if (default_layer_state != 0x00000001)
    {
        led1_on();
        led2_off();
        return;
    }
    led2_on();
    led1_off();
}

// Turn on dafault layer indicator led2
// near the end of boot process
void hook_late_init(void)
{
    led2_on();
}

