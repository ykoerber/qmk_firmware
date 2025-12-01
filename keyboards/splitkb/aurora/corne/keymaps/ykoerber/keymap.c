#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "keymap_us_international.h"


// custom key codes for e.g. macros
enum custom_keycodes {
  ARROW = SAFE_RANGE,
  COMMA_AND_QUEST_MARK,
  DOT_AND_EXCL_MARK,
  KC_MY_ESC,
};

#define DEFAULT 0
#define SYM 1
#define NUM 2
#define NAV 3
#define MOUSE_LAYER 4
#define UTIL_LAYER 5
#define UMLAUT 6
#define MAC_DEFAULT 7
#define MAC_SYM 8
#define MAC_NUM 9
#define MAC_NAV 10
#define MAC_MOUSE_LAYER 11
#define MAC_UTIL_LAYER 12


#define PTT MEH(KC_F16)
#define MUTE MEH(KC_F17)
#define BOOKMARKS HYPR(KC_B)
#define TABS MEH(KC_F13)
#define MAC_CONTEXT_MENU HYPR(KC_F12)
#define MAC_CLIPBOARD_HISTORY C(G(KC_F13))
#define ACE_JUMP G(A(KC_F13))
#define ACE_SCROLL S(G(A(KC_F13)))
#define MY_SPACE LT(UTIL_LAYER, KC_SPC)
#define MAC_MY_SPACE LT(MAC_UTIL_LAYER, KC_SPC)
#define MY_ESC LT(SYM, KC_MY_ESC)
#define MAC_MY_ESC LT(MAC_SYM, KC_MY_ESC) //KC_ESC geht, KC_MY_ESC nicht
#define SHOW_APPS C(A(KC_TAB))
#define MOUSECLICK KC_F19



// combos
enum combos {
  RESET_LEFT,
  RESET_RIGHT,
  SWITCH_MAC_WIN
};

const uint16_t PROGMEM reset_left_combo[] = {KC_Q, KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM reset_right_combo[] = {KC_Y, KC_P, KC_N, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [RESET_LEFT] = COMBO(reset_left_combo, QK_BOOT),
  [RESET_RIGHT] = COMBO(reset_right_combo, QK_BOOT)
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   OSM(MOD_LSFT), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  OSM(MOD_RSFT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC, GUI_T(KC_A),  ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,           KC_H,    SFT_T(KC_J),  CTL_T(KC_K),  ALT_T(KC_L), GUI_T(KC_SCLN), KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, COMMA_AND_QUEST_MARK,  DOT_AND_EXCL_MARK, KC_MY_ESC,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                PTT, MY_SPACE,  MO(NAV),                      OSL(NUM), LT(SYM, KC_ESC), MOUSECLICK
                              //`--------------------------'                   `--------------------------'

  ),

  [SYM] = LAYOUT_split_3x6_3( //SYMBOL
  //,-----------------------------------------------------.                                 ,-----------------------------------------------------.
      KC_TRNS,  KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR,                                     XXXXXXX, KC_PERC, KC_PPLS, KC_ASTR, KC_CIRC, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, GUI_T(KC_QUOT), ALT_T(KC_SLSH), CTL_T(KC_LBRC), SFT_T(KC_RBRC), KC_DQUO,         XXXXXXX, SFT_T(KC_EQL), CTL_T(KC_MINS), ALT_T(KC_BSLS), GUI_T(KC_GRV), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TILD, KC_UNDS, KC_LCBR, KC_RCBR, KC_HASH,                                     XXXXXXX, KC_AT, KC_LT, KC_GT, KC_COLN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS,   KC_TRNS, KC_TRNS
                                      //`--------------------------'                `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3( // number + FN
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_ASTR, KC_7,   KC_8,       KC_9,  KC_PPLS,                         XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, GUI_T(KC_0), ALT_T(KC_4),   CTL_T(KC_5), SFT_T(KC_6),  KC_DOT,     XXXXXXX, SFT_T(KC_F4), CTL_T(KC_F5), ALT_T(KC_F6), GUI_T(KC_F11), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_SLSH, KC_1,   KC_2,       KC_3, KC_MINS,                          XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [NAV] = LAYOUT_split_3x6_3( //NAV
  //,-------------------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, TO(MOUSE_LAYER),KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,                     C(KC_Y), KC_PGUP,  KC_UP,  KC_PGDN, KC_PAUS, KC_TRNS,
  //|--------+----------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LGUI,        KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      UG_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_APP, KC_TRNS,
  //|--------+----------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, C(KC_Z),        C(KC_X), C(KC_C), C(KC_V), KC_VOLD,                      UG_HUEU, KC_HOME, KC_END, SHOW_APPS, MUTE,    KC_TRNS,
  //|--------+----------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS,  KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'                   `--------------------------'
  ),


  [MOUSE_LAYER] = LAYOUT_split_3x6_3( //mouse layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     QK_BOOT, XXXXXXX, XXXXXXX, MS_UP, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,GUI_T(KC_A), MS_LEFT, MS_DOWN, MS_RGHT, KC_G,                     XXXXXXX, MS_ACL2, MS_ACL1, MS_ACL0, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS,   TO(DEFAULT),  KC_TRNS,     MS_BTN2,   MS_BTN1, MS_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

    [UTIL_LAYER] = LAYOUT_split_3x6_3( //util layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TRNS, KC_WBAK, KC_WFWD, XXXXXXX, CW_TOGG, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(MAC_DEFAULT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,XXXXXXX, XXXXXXX, XXXXXXX, ACE_JUMP, XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'

  ),
    [UMLAUT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, US_UDIA, XXXXXXX, US_ODIA, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,US_ADIA, US_SS, XXXXXXX, XXXXXXX, XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [MAC_DEFAULT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
   OSM(MOD_LSFT), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  OSM(MOD_RSFT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BSPC, CTL_T(KC_A),  ALT_T(KC_S), GUI_T(KC_D), SFT_T(KC_F), KC_G,           KC_H,    SFT_T(KC_J),  GUI_T(KC_K),  ALT_T(KC_L), CTL_T(KC_SCLN), KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, COMMA_AND_QUEST_MARK,  DOT_AND_EXCL_MARK, KC_MY_ESC,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                PTT, MAC_MY_SPACE,  MO(MAC_NAV),                      OSL(MAC_NUM), LT(SYM, KC_ESC), MOUSECLICK
                              //`--------------------------'                   `--------------------------'

  ),

  [MAC_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                 ,-----------------------------------------------------.
      KC_TRNS,  KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR,                                     XXXXXXX, KC_PERC, KC_PPLS, KC_ASTR, KC_CIRC, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, CTL_T(KC_QUOT), ALT_T(KC_SLSH), GUI_T(KC_LBRC), SFT_T(KC_RBRC), KC_DQUO,         XXXXXXX, SFT_T(KC_EQL), GUI_T(KC_MINS), ALT_T(KC_BSLS), CTL_T(KC_GRV), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TILD, KC_UNDS, KC_LCBR, KC_RCBR, KC_HASH,                                     XXXXXXX, KC_AT, KC_LT, KC_GT, KC_COLN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS,   KC_TRNS, KC_TRNS
                                      //`--------------------------'                `--------------------------'
  ),

  [MAC_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_ASTR, KC_7,   KC_8,       KC_9,  KC_PPLS,                         XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, CTL_T(KC_0), ALT_T(KC_4),   GUI_T(KC_5), SFT_T(KC_6),  KC_DOT,     XXXXXXX, SFT_T(KC_F4), GUI_T(KC_F5), ALT_T(KC_F6), CTL_T(KC_F11), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_SLSH, KC_1,   KC_2,       KC_3, KC_MINS,                          XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [MAC_NAV] = LAYOUT_split_3x6_3(
  //,-------------------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, TO(MAC_MOUSE_LAYER),KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,                     G(KC_Y), KC_PGUP,  KC_UP,  KC_PGDN, KC_PAUS, KC_TRNS,
  //|--------+----------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LCTL,     KC_LALT, KC_LGUI, KC_LSFT, KC_VOLU,                      UG_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, MAC_CONTEXT_MENU, KC_TRNS,
  //|--------+----------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, G(KC_Z),        G(KC_X), G(KC_C), G(KC_V), KC_VOLD,                      UG_HUEU, KC_HOME, KC_END, SHOW_APPS, MUTE,    KC_TRNS,
  //|--------+----------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, KC_TRNS,  KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'                   `--------------------------'
  ),


[MAC_MOUSE_LAYER] = LAYOUT_split_3x6_3( //mouse layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     QK_BOOT, MS_WHLL, MS_WHLU, MS_UP, MS_WHLD, MS_WHLR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,GUI_T(KC_A), MS_LEFT, MS_DOWN, MS_RGHT, KC_G,                     XXXXXXX, MS_ACL0, MS_ACL1, MS_ACL2, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_A,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(MAC_DEFAULT), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS,   TO(MAC_DEFAULT),  MO(MAC_NAV),     MS_BTN2,   MS_BTN1, MS_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

    [MAC_UTIL_LAYER] = LAYOUT_split_3x6_3( //KC_F19 ACE_JUMP   SFT_T(KC_EQL), GUI_T(KC_MINS), ALT_T(KC_BSLS), CTL_T(KC_GRV), BOOKMARKS
  //,-----------------------------------------------------.                    ,-----------------------------------------------------|
     KC_TRNS, G(KC_LBRC), G(KC_RBRC), G(S(KC_LBRC)), G(S(KC_RBRC)), TABS,                      XXXXXXX, G(KC_TILD), G(KC_GRV), XXXXXXX, XXXXXXX, TO(DEFAULT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,KC_LCTL, KC_LALT, GUI_T(KC_TAB), SFT_T(KC_ENTER), ACE_JUMP,                 MAC_CLIPBOARD_HISTORY, SFT_T(KC_BSPC), GUI_T(KC_DEL), KC_LALT, KC_LCTL, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17,                      KC_F18, KC_F19, KC_F20, KC_F21, KC_F21, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'

  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

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
    case COMMA_AND_QUEST_MARK:
        if (record->event.pressed) {
            if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);
                SEND_STRING("?");
                set_mods(mods);
            } else {
                SEND_STRING(",");
            }
        }
        return false;
    case DOT_AND_EXCL_MARK:
        if (record->event.pressed) {
            if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);
                SEND_STRING("!");
                set_mods(mods);
            } else {
                SEND_STRING(".");
            }
        }
        return false;
    case KC_MY_ESC:
        if(record -> event.pressed) {
            if(is_caps_word_on()) {
                //turn caps_word off on escape and consume escape
                caps_word_off();
            } else {
                tap_code16(KC_ESC);
            }
        }
        return false;
    }

    return true;
}


void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // allow same-hand holds for the space key. This is necessary because the space key is a LT key
  switch (tap_hold_keycode) {
    case MY_SPACE:
    case MAC_MY_SPACE:
//    case MY_ESC:
//    case MAC_MY_ESC:
      return true;
  }

  // opposite hands rule as default
  return achordion_opposite_hands(tap_hold_record, other_record);
}


#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
//   rgblight_enable_noeeprom(); // enables RGB, without saving settings
//   rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
//   rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}
#endif
