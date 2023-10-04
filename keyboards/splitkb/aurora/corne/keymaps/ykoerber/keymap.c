/* Copyright 2022 splitkb.com <support@splitkb.com>
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

#define DEFAULT 0
#define SYM_L 1
#define SYM_R 2
#define NUM 3
#define NAV 4
#define FN 5
#define SETTINGS 6
#define INTJ 7
#define CHAR_MODS 8
#define MOUSE_LAYER 9
#define UTIL_LAYER 10


#define PTT HYPR(KC_G)
#define MUTE HYPR(KC_M)
#define BOOKMARKS S(KC_F11)
#define IJ_ACTION C(S(KC_A))
#define IJ_CLASSES C(S(KC_K))
#define IJ_FILES C(S(KC_N))
#define IJ_DEBUG S(A(KC_F9))
#define IJ_RUN S(A(KC_F10))
#define IJ_STOP C(KC_F2)
#define ACE_JUMP C(KC_SCLN)

// Tap Dance declarations
enum {
    TD_INTJ_DEBUG,
    TD_INTJ_FILES
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_INTJ_DEBUG] = ACTION_TAP_DANCE_DOUBLE(S(A(KC_F9)), C(KC_F2)),
    [TD_INTJ_FILES] = ACTION_TAP_DANCE_DOUBLE(S(C(KC_K)), C(S(KC_N))),
};

// custom key codes for e.g. macros
enum custom_keycodes {
  ARROW = SAFE_RANGE,
};

// combos
enum combos {
  RESET_LEFT,
  RESET_RIGHT
};

const uint16_t PROGMEM reset_left_combo[] = {KC_Q, KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM reset_right_combo[] = {KC_Y, KC_P, KC_N, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [RESET_LEFT] = COMBO(reset_left_combo, QK_BOOT),
  [RESET_RIGHT] = COMBO(reset_right_combo, QK_BOOT),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   OSM(MOD_LSFT), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  OSM(MOD_RSFT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC, GUI_T(KC_A),  ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,            KC_H,    SFT_T(KC_J),  CTL_T(KC_K),  ALT_T(KC_L), GUI_T(KC_SCLN), KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, OSL(UTIL_LAYER),  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 PTT,   KC_SPC,  LT(NAV, KC_ESC),            OSL(NUM),   OSL(SYM_L), OSM(MOD_LCTL | MOD_LALT)
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3( //SYMBOL LEFT
  //,-----------------------------------------------------.                                 ,-----------------------------------------------------.
      KC_TRNS,  KC_LT, KC_GT, KC_LPRN, KC_RPRN,  KC_PERC,                                     KC_EXLM, KC_QUES, KC_PPLS, KC_ASTR, KC_CIRC, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, GUI_T(KC_QUOT), ALT_T(KC_SLSH), CTL_T(KC_LBRC), SFT_T(KC_RBRC), KC_DQUO,         KC_AMPR, SFT_T(KC_EQL), CTL_T(KC_MINS), ALT_T(KC_BSLS), GUI_T(KC_GRV), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TILD, KC_UNDS, KC_LCBR, KC_RCBR, KC_HASH,                                     KC_PIPE, ARROW, KC_LT, KC_GT, KC_COLN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS, KC_EXLM, KC_TRNS,                        KC_TRNS,   KC_TRNS, KC_TRNS
                                      //`--------------------------'                `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3( //SYMBOL RIGHT
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,TO(MOUSE_LAYER),XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,              KC_EXLM, KC_QUES, KC_PPLS, KC_ASTR, KC_CIRC, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_AMPR,  KC_EQL, KC_MINS, KC_BSLS, KC_GRV,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, PTT, MUTE,                            KC_PIPE, ARROW, KC_LT, KC_GT, KC_COLN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS, LT(CHAR_MODS, KC_ESC), KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3( //NUMBER
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_AT, KC_7,   KC_8,       KC_9,  KC_COLN,                         XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, GUI_T(KC_0), ALT_T(KC_4),   CTL_T(KC_5), SFT_T(KC_6), KC_AMPR,     XXXXXXX, SFT_T(KC_F4), CTL_T(KC_F5), ALT_T(KC_F6), GUI_T(KC_F11), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_DLR, KC_1,   KC_2,       KC_3, KC_PIPE,                          XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, MO(SETTINGS),     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3( //NAV
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, TO(MOUSE_LAYER), KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,                     C(KC_Y), KC_PGUP, KC_UP, KC_PGDN, KC_PAUS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_APP, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_VOLD,                      XXXXXXX, KC_HOME, KC_END, XXXXXXX, MUTE, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,  KC_TRNS,     MO(SETTINGS), KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [5] = LAYOUT_split_3x6_3( //FN
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [6] = LAYOUT_split_3x6_3( //SETTINGS
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [7] = LAYOUT_split_3x6_3( //IntelliJ
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      IJ_ACTION, C(KC_Q), XXXXXXX, C(KC_F1), MEH(KC_T), MEH(KC_F11),               XXXXXXX, C(A(KC_F7)), XXXXXXX, A(KC_5), A(KC_1), IJ_RUN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      IJ_CLASSES, C(S(KC_S)), MEH(KC_2), TD(TD_INTJ_DEBUG), C(A(KC_L)), MEH(KC_G),            C(KC_P), XXXXXXX, XXXXXXX, C(S(KC_E)), XXXXXXX, IJ_DEBUG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      IJ_FILES, MEH(KC_1), C(S(KC_R)), MEH(KC_3), MEH(KC_F3), BOOKMARKS,          C(S(KC_A)), TD(TD_INTJ_FILES), S(KC_F2), KC_F2, XXXXXXX, IJ_STOP,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [8] = LAYOUT_split_3x6_3( //CHAR MODS, default layer with home row mods
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,GUI_T(KC_A), ALT_T(KC_S),CTL_T(KC_D),SFT_T(KC_F), KC_G,           KC_H,   SFT_T(KC_J),  CTL_T(KC_K),  ALT_T(KC_L), GUI_T(KC_SCLN), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,KC_Z, RALT_T(KC_X),    KC_C,    KC_V,    KC_B,              KC_N,    KC_M, KC_COMM,  RALT_T(KC_DOT), C(KC_SCLN),  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [9] = LAYOUT_split_3x6_3( //mouse layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     QK_BOOT, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,GUI_T(KC_A), KC_MS_L, KC_MS_D, KC_MS_R, KC_G,                     XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS,   TO(DEFAULT),  KC_TRNS,     KC_BTN2,   KC_BTN1, KC_BTN3
                                      //`--------------------------'  `--------------------------'

  ),


  [10] = LAYOUT_split_3x6_3( //util layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     QK_BOOT, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      XXXXXXX, RALT(KC_Y), XXXXXXX, RALT(KC_P), XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,RALT(KC_Q), RALT(KC_S), XXXXXXX, XXXXXXX, XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS,   ACE_JUMP,  XXXXXXX,     XXXXXXX,   XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'

  )
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}
#endif
