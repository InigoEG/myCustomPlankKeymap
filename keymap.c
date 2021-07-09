/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _MOVE,
  _ADJUST
};

enum planck_keycodes {
  TD_SHIFT_CAPS = SAFE_RANGE
};

#define LOW_BSPC LT(_LOWER, KC_BSPC)
#define RAI_ENT LT(_RAISE, KC_ENT)
#define MOVE MO(_MOVE)

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Shift, twice for Caps Lock
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(MOD_MASK_SHIFT, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
    * ,-------------------------------------------------------------------------------------.
    * | Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Del  |
    * |-------+------+------+------+------+------+------+------+------+------+------+-------|
    * | Ctrl* |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"   |
    * |-------+------+------+------+------+------+------+------+------+------+------+-------|
    * | Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  /?  | Shift |
    * |-------+------+------+------+------+------+------+------+------+------+------+-------|
    * | Move  |      | OS   | Alt  |Lower*|    Space    |Raise*| Alt  | Vol- | Vol+ | Mute  |
    * `-------------------------------------------------------------------------------------'
    *
    * - Ctrl when held, Esc when tapped
    * - Lower when held, Bksp when tapped
    * - Raise when held, Enter when tapped
    * - Del = Shift + Bksp
    * - Ctrl + Alt + Bksp = Ctrl + Alt + Del
    * - Shift + Shift = Caps On/Off
    */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        LCTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        TD(TD_SHIFT_CAPS),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(TD_SHIFT_CAPS),
        MOVE,             XXXXXXX, KC_LGUI, KC_LALT, LOW_BSPC,KC_SPC,  KC_SPC,  RAI_ENT, KC_RALT, KC_VOLD, KC_VOLU, KC_MUTE
    ),

    /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |  |   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      | Prev | Next |Py/Ps |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT_planck_grid(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY
    ),

    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_planck_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Move
    * ,-----------------------------------------------------------------------------------.
    * |      |      | PgUp |PgDown|      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      | Home | End  |Shift |      |      | Left | Down |  Up  |Right |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_MOVE] = LAYOUT_planck_grid(
        _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_HOME, KC_END , KC_LSFT, _______,_______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Adjust (Lower + Raise)
    * ,-----------------------------------------------------------------------------------.
    * |      |RESET |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |MS B1 |MS B2 |      |      | MS L | MS D | MS U | MS R |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT_planck_grid(
        _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/*
    When you want to override the behavior of an existing key, or define the behavior for a new 
    key, you should use the process_record_kb() and process_record_user() functions. These are 
    called by QMK during key processing before the actual key event is handled. If these functions 
    return true QMK will process the keycodes as usual. That can be handy for extending the 
    functionality of a key rather than replacing it. If these functions return false QMK will skip 
    the normal key handling, and it will be up to you to send any key up or down events that are 
    required. These function are called every time a key is pressed or released.
*/

// uint8_t mod_state;
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     mod_state = get_mods();
//     switch (keycode) {
//         case LOW_BSPC:
//         case KC_BSPC:
//         {
//             static bool del_registered;
//             // Key Pressed
//             if (record->event.pressed && mod_state) {
//                 /****************************** Shift + Bksp = Del ************************/
//                 if (MOD_MASK_SHIFT) {
//                     // First temporarily canceling both shifts so that shift isn't 
//                     // applied to the KC_DEL keycode
//                     del_mods(MOD_MASK_SHIFT);
//                     register_code(KC_DEL);
//                     // Update the boolean variable to reflect the status of KC_DEL
//                     del_registered = true;
//                     // Reapplying modifier state so that the held shift key(s) still 
//                     // work even after having tapped the Backspace/Delete key
//                     set_mods(mod_state);
//                 }
//                 /******************** Ctrl + Alt + Bksp = Ctrl + Alt + Del ****************/
//                 else if (MOD_MASK_CTRL & MOD_MASK_ALT) {
//                     register_code(KC_DEL);
//                     del_registered = true;
//                 }
//                 return false;
//             // Key Released
//             } else {
//                 if (del_registered) {
//                     unregister_code(KC_DEL);
//                     del_registered = false;
//                     return false;
//                 }
//             }
//             break;
//         }
//     }
//     return true;
// };