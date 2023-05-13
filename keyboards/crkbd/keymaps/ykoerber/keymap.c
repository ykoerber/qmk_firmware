/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

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
qk_tap_dance_action_t tap_dance_actions[] = {
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
  [0] = LAYOUT_split_3x6_3( //
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   OSM(MOD_LSFT), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  OSM(MOD_RSFT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC, GUI_T(KC_A),  ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,            KC_H,    SFT_T(KC_J),  CTL_T(KC_K),  ALT_T(KC_L), GUI_T(KC_SCLN), KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, OSL(UTIL_LAYER),  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 PTT,   KC_SPC,  LT(NAV, KC_ESC),            OSL(NUM),   OSL(SYM_L), OSL(INTJ)
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3( //SYMBOL LEFT
  //,-----------------------------------------------------.                                 ,-----------------------------------------------------.
      KC_TRNS,  KC_AT,  KC_DLR, KC_LPRN, KC_RPRN,  KC_PERC,                                     KC_EXLM, KC_QUES, KC_PPLS, KC_ASTR, KC_CIRC, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, GUI_T(KC_QUOT), ALT_T(KC_SLSH), CTL_T(KC_LBRC), SFT_T(KC_RBRC), KC_DQUO,         KC_AMPR, SFT_T(KC_EQL), CTL_T(KC_MINS), ALT_T(KC_BSLS), GUI_T(KC_GRV), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TILD, KC_UNDS, KC_LCBR, KC_RCBR, KC_HASH,                                     KC_PIPE, ARROW, KC_LT, KC_GT, KC_COLN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS, LT(CHAR_MODS, KC_SPC),KC_TRNS,                        KC_TRNS,   KC_TRNS, KC_TRNS
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
      KC_TRNS, XXXXXXX, KC_7,   KC_8,       KC_9,  XXXXXXX,                         XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, GUI_T(KC_0), ALT_T(KC_4),   CTL_T(KC_5), SFT_T(KC_6), XXXXXXX,     XXXXXXX, SFT_T(KC_F4), CTL_T(KC_F5), ALT_T(KC_F6), GUI_T(KC_F11), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, KC_1,   KC_2,       KC_3, XXXXXXX,                          XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS,
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





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Get current mod and one-shot mod states.
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
    case ARROW:  // Arrow macro, types -> or =>.
        //source: https://getreuer.info/posts/keyboards/macros/index.html#macros-that-respond-to-mods
        if (record->event.pressed) {
            if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {  // Is shift held?
                del_mods(MOD_MASK_SHIFT);  // Temporarily delete shift.
                del_oneshot_mods(MOD_MASK_SHIFT);
                SEND_STRING("=>");
                set_mods(mods);            // Restore mods.
            } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {  // Is ctrl held?
                del_mods(MOD_MASK_CTRL);  
                del_oneshot_mods(MOD_MASK_CTRL);
                SEND_STRING("|>");
                set_mods(mods);           
            } else {
                SEND_STRING("->");
            }
        }
        return false;
    }
    return true;
}




#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
