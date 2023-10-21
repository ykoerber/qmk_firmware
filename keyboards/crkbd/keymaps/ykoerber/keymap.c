#include QMK_KEYBOARD_H

#define DEFAULT 0
#define SYM_L 1
#define NUM 2
#define NAV 3
#define FN 4
#define MOUSE_LAYER 5
#define UTIL_LAYER 6


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
  COMMA_AND_QUEST_MARK,
  DOT_AND_EXCL_MARK,
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
      KC_BSPC, GUI_T(KC_A),  ALT_T(KC_S), CTL_T(KC_D), SFT_T(KC_F), KC_G,           KC_H,    SFT_T(KC_J),  CTL_T(KC_K),  ALT_T(KC_L), GUI_T(KC_SCLN), KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, COMMA_AND_QUEST_MARK,  DOT_AND_EXCL_MARK, OSL(UTIL_LAYER),  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                         PTT,   KC_SPC,  LT(NAV, KC_ESC),                        OSL(NUM),   OSL(SYM_L), OSM(MOD_LCTL | MOD_LALT)
                              //`--------------------------'                   `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3( //SYMBOL 
  //,-----------------------------------------------------.                                 ,-----------------------------------------------------.
      KC_TRNS,  KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN,  KC_PERC,                                     KC_EXLM, KC_QUES, KC_PPLS, KC_ASTR, KC_CIRC, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, GUI_T(KC_QUOT), ALT_T(KC_SLSH), CTL_T(KC_LBRC), SFT_T(KC_RBRC), KC_DQUO,         KC_AMPR, SFT_T(KC_EQL), CTL_T(KC_MINS), ALT_T(KC_BSLS), GUI_T(KC_GRV), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                                     |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TILD, KC_UNDS, KC_LCBR, KC_RCBR, KC_HASH,                                     KC_PIPE, ARROW, KC_LT, KC_GT, KC_COLN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS,   KC_TRNS, KC_TRNS
                                      //`--------------------------'                `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3( //Symbol and number
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_AT, KC_7,   KC_8,       KC_9,  KC_COLN,                         XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, GUI_T(KC_0), ALT_T(KC_4),   CTL_T(KC_5), SFT_T(KC_6), KC_AMPR,     XXXXXXX, SFT_T(KC_F4), CTL_T(KC_F5), ALT_T(KC_F6), GUI_T(KC_F11), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_DLR, KC_1,   KC_2,       KC_3, KC_PIPE,                          XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3( //NAV
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, TO(MOUSE_LAYER), KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,                     C(KC_Y), KC_PGUP, KC_UP, KC_PGDN, KC_PAUS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      RGB_TOG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_APP, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_VOLD,                      RGB_HUI, KC_HOME, KC_END, XXXXXXX, MUTE, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3( //FN
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


  [5] = LAYOUT_split_3x6_3( //mouse layer
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

    [6] = LAYOUT_split_3x6_3( //util layer
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     QK_BOOT, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      XXXXXXX, RALT(KC_Y), XXXXXXX, RALT(KC_P), XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,RALT(KC_Q), RALT(KC_S), XXXXXXX, XXXXXXX, XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS, KC_TRNS
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
