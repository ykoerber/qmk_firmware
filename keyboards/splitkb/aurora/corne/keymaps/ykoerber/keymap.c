#include QMK_KEYBOARD_H
#include "keymap_us_international.h"


// custom key codes for e.g. macros
enum custom_keycodes {
  ARROW = SAFE_RANGE,
  COMMA_AND_QUEST_MARK,
  DOT_AND_EXCL_MARK,
  KC_MY_ESC
};

#define DEFAULT 0
#define MAC_DEFAULT 1
#define MOUSE_LAYER 2
#define MAC_MOUSE_LAYER 3
#define SCROLL_LAYER 4
#define SYM 5
#define MAC_SYM 6
#define NUM 7
#define MAC_NUM 8
#define NAV 9
#define MAC_NAV 10
#define UTIL_LAYER 11
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
#define SHOW_APPS C(A(KC_TAB))
#define MAC_SHOW_APPS G(A(KC_TAB))
#define MOUSECLICK KC_F19
#define MAC_ESC LT(MAC_SYM, KC_ESC)
#define PC_ESC LT(SYM, KC_ESC)
#define HR_J SFT_T(KC_J)
#define HR_F SFT_T(KC_F)
#define HR_K GUI_T(KC_K)
#define HR_L ALT_T(KC_L)
#define HR_SCLN CTL_T(KC_SCLN)

//enum combos {
//  RESET_LEFT,
//  RESET_RIGHT,
//  UI_ESC,
//  CMB_CAPSWORD
//};


const uint16_t PROGMEM reset_left_combo[] = {KC_Q, KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM reset_right_combo[] = {KC_Y, KC_P, KC_N, COMBO_END};
const uint16_t PROGMEM mac_esc_combo[] = {LT(MAC_UTIL_LAYER, KC_U), KC_I, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {HR_F, HR_J, COMBO_END};

combo_t key_combos[] = {
    COMBO(reset_left_combo, QK_BOOT),
    COMBO(reset_right_combo, QK_BOOT),
    COMBO(mac_esc_combo, KC_MY_ESC),
    COMBO(fj_combo, CW_TOGG)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //====================================================================================================================================================================================
  [DEFAULT] = LAYOUT_split_3x6_3(
    OSM(MOD_LSFT),  KC_Q,           KC_W,           KC_E,           LT(UTIL_LAYER, KC_R),   KC_T,                               KC_Y,       LT(UTIL_LAYER, KC_U),   KC_I,                   KC_O,               KC_P,           OSM(MOD_RSFT),
    KC_BSPC,        GUI_T(KC_A),    ALT_T(KC_S),    CTL_T(KC_D),    HR_F,            KC_G,                               KC_H,       HR_J,                   CTL_T(KC_K),            ALT_T(KC_L),        GUI_T(KC_SCLN), KC_ENTER,
    KC_TAB,         KC_Z,           KC_X,           KC_C,           KC_V,                   KC_B,                               KC_N,       KC_M,                   COMMA_AND_QUEST_MARK,   DOT_AND_EXCL_MARK,  A(KC_BSPC),         KC_DEL,
                                    PTT,            MY_SPACE,       MO(NAV),                                                    OSL(NUM),   PC_ESC,                 MOUSECLICK
  ),

    [MAC_DEFAULT] = LAYOUT_split_3x6_3(
    _______, _______, _______, _______, LT(MAC_UTIL_LAYER,KC_R), _______,                   _______, LT(MAC_UTIL_LAYER, KC_U), _______, _______, _______, _______,
    _______, CTL_T(KC_A),  _______, GUI_T(KC_D), _______, _______,                          _______,    HR_J,  HR_K,  HR_L, HR_SCLN, _______,
    _______, _______, _______, _______, _______, _______,                                   _______, _______, _______, _______, _______, _______,
                                _______, MAC_MY_SPACE,  MO(MAC_NAV),                                OSL(MAC_NUM), OSL(MAC_SYM), _______
  ),


   //====================================================================================================================================================================================

  [MOUSE_LAYER] = LAYOUT_split_3x6_3(
      _______, KC_WBAK, KC_WFWD, MS_ACL2, MO(SCROLL_LAYER), XXXXXXX,                      XXXXXXX, MS_WHLU, MS_UP, MS_WHLD, XXXXXXX, _______,
      _______,KC_LCTL, KC_LSFT, MS_ACL1, MS_BTN1, MS_BTN2,                     XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, _______,
      _______,XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN3, XXXXXXX,                      XXXXXXX, MS_WHLL, MS_DOWN, MS_WHLR, XXXXXXX, _______,
                          _______,   TO(DEFAULT),   MO(NAV),            MO(NUM),   TO(DEFAULT), XXXXXXX
  ),
  [MAC_MOUSE_LAYER] = LAYOUT_split_3x6_3(
     _______, G(KC_LBRC), G(KC_RBRC), MS_ACL2, MO(SCROLL_LAYER), XXXXXXX,                      XXXXXXX, MS_WHLU, MS_UP, MS_WHLD, XXXXXXX, _______,
      _______,KC_LGUI, KC_LSFT, MS_ACL1, MS_BTN1, MS_BTN2,                     XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, _______,
      _______,XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN3, XXXXXXX,                      XXXXXXX, MS_WHLR, MS_DOWN, MS_WHLL, XXXXXXX, _______,
                                   _______, TO(MAC_DEFAULT) , MO(MAC_NAV),     MO(MAC_NUM),   TO(MAC_DEFAULT), XXXXXXX
    ),
  [SCROLL_LAYER] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______,                      _______, _______, MS_WHLU, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                      _______, MS_WHLR, MS_WHLD, MS_WHLL, _______, _______,
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                   _______, _______,   _______,                  _______, _______, _______
    ),
//====================================================================================================================================================================================




  [SYM] = LAYOUT_split_3x6_3(
      _______, KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR,                                     _______, KC_PERC, KC_PPLS, KC_ASTR, KC_CIRC, _______,
      _______, GUI_T(KC_QUOT), ALT_T(KC_SLSH), CTL_T(KC_LBRC), SFT_T(KC_RBRC), KC_DQUO,         _______, SFT_T(KC_EQL), CTL_T(KC_MINS), ALT_T(KC_BSLS), GUI_T(KC_GRV), _______,
      _______, KC_TILD, KC_UNDS, KC_LCBR, KC_RCBR, KC_HASH,                                     _______, KC_AT, KC_LT, KC_GT, KC_COLN, _______,
                                   _______, _______, _______,                        _______,   _______, _______
  ),
    [MAC_SYM] = LAYOUT_split_3x6_3(
      _______, KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN, KC_DLR,                                     _______, KC_PERC, KC_PPLS, KC_ASTR, KC_CIRC, _______,
      _______, CTL_T(KC_QUOT), ALT_T(KC_SLSH), GUI_T(KC_LBRC), SFT_T(KC_RBRC), KC_DQUO  ,        _______, SFT_T(KC_EQL), GUI_T(KC_MINS), ALT_T(KC_BSLS), CTL_T(KC_GRV), _______,
      _______, KC_TILD, KC_UNDS, KC_LCBR, KC_RCBR, KC_HASH,                                     _______, KC_AT, KC_LT, KC_GT, KC_COLN, _______,
                                   _______, _______, _______,                        _______,   _______, _______
    ),
//====================================================================================================================================================================================




// number + FN =======================================================================================================================================================================
  [NUM] = LAYOUT_split_3x6_3(
      _______, KC_ASTR, KC_7,   KC_8,       KC_9,  KC_PPLS,                         _______, KC_F7, KC_F8, KC_F9, KC_F10, _______,
      _______, GUI_T(KC_0), ALT_T(KC_4),   CTL_T(KC_5), SFT_T(KC_6),  KC_DOT,       _______, SFT_T(KC_F4), CTL_T(KC_F5), ALT_T(KC_F6), GUI_T(KC_F11), _______,
      _______, KC_SLSH, KC_1,   KC_2,       KC_3, KC_MINS,                          _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
                                          _______, _______, _______,                _______, _______, _______
  ),
   [MAC_NUM] = LAYOUT_split_3x6_3(
      _______, KC_ASTR, KC_7,   KC_8,       KC_9,  KC_PPLS,                         _______, KC_F7, KC_F8, KC_F9, KC_F10, _______,
       _______, CTL_T(KC_0), ALT_T(KC_4),   GUI_T(KC_5), SFT_T(KC_6),  KC_DOT,      _______, SFT_T(KC_F4), GUI_T(KC_F5), ALT_T(KC_F6), CTL_T(KC_F11), _______,
      _______, KC_SLSH, KC_1,   KC_2,       KC_3, KC_MINS,                          _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
                                          _______, _______, _______,                            _______, _______, _______
   ),

//====================================================================================================================================================================================


    [NAV] = LAYOUT_split_3x6_3( //NAV
        _______, TO(MOUSE_LAYER),KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,                     C(KC_Y), KC_PGUP,  KC_UP,  KC_PGDN, KC_PAUS, _______,
        _______, KC_LGUI,        KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      UG_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_APP, _______,
        _______, C(KC_Z),        C(KC_X), C(KC_C), C(KC_V), KC_VOLD,                      UG_HUEU, KC_HOME, KC_END, SHOW_APPS, MUTE,    _______,
                                        _______, _______,  _______,                     _______, _______, _______
  ),
      [MAC_NAV] = LAYOUT_split_3x6_3(
        _______, TO(MAC_MOUSE_LAYER),KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,                       G(KC_Y),  KC_PGUP,  KC_UP,  KC_PGDN, KC_PAUS, _______,
        _______, KC_LCTL,            KC_LALT, KC_LGUI, KC_LSFT,  KC_VOLU,                       UG_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, MAC_CONTEXT_MENU, _______,
        _______, G(KC_Z),        G(KC_X), G(KC_C), G(KC_V), KC_VOLD,                      UG_HUEU, KC_HOME, KC_END, MAC_SHOW_APPS, MUTE,    _______,
                                          _______, _______,  _______,                     _______, _______, _______
    ),

//====================================================================================================================================================================

    [UTIL_LAYER] = LAYOUT_split_3x6_3(
     _______, KC_WBAK, KC_WFWD, XXXXXXX, CW_TOGG, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX , PDF(MAC_DEFAULT),
      _______,XXXXXXX, XXXXXXX, XXXXXXX, ACE_JUMP, XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                 _______,   _______,  _______,     _______,   _______, _______
  ),
    [MAC_UTIL_LAYER] = LAYOUT_split_3x6_3(
     _______, G(KC_LBRC), G(KC_RBRC), G(S(KC_LBRC)), G(S(KC_RBRC)), TABS,                      XXXXXXX, G(KC_TILD), G(KC_GRV), XXXXXXX, XXXXXXX,  PDF(DEFAULT),
      _______,KC_LCTL, KC_LALT, GUI_T(KC_TAB), SFT_T(KC_ENTER), ACE_JUMP,                 MAC_CLIPBOARD_HISTORY, SFT_T(KC_BSPC), GUI_T(KC_DEL), KC_LALT, KC_LCTL, _______,
      _______, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17,                      KC_F18, KC_F19, KC_F20, KC_F21, KC_F21, _______,
                                 _______,   _______,  _______,     _______,   _______, _______
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
    case PC_ESC:
        if (record->tap.count == 0) {
            //key is being held => use normal LT behavior
            return true;
        } else if(record->event.pressed && is_caps_word_on()) {
            caps_word_off();
            return false;
        } else if(record->event.pressed) {
            tap_code(KC_ESC);
            return false;
        } else {
            return false;
        }
    case MAC_ESC:
        if (record->tap.count == 0) {
            //key is being held => use normal LT behavior
            return true;
        } else if(record->event.pressed && is_caps_word_on()) {
            caps_word_off();
            return false;
        } else if(record->event.pressed) {
            tap_code(KC_ESC);
            return false;
        } else {
            return false;
        }
    case KC_MY_ESC:
        if(record->event.pressed && is_caps_word_on()) {
            caps_word_off();
            return false;
        } else if(record->event.pressed) {
            tap_code(KC_ESC);
            return false;
        }
    }

    return true;
}



#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
//   rgblight_enable_noeeprom(); // enables RGB, without saving settings
//   rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
//   rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}
#endif


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );
