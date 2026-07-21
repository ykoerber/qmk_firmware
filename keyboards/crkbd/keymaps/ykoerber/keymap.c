#include QMK_KEYBOARD_H
#include "keymap_us_international.h"


// custom key codes for e.g. macros
enum custom_keycodes {
  ARROW = SAFE_RANGE,
  COMMA_AND_QUEST_MARK,
  DOT_AND_EXCL_MARK,
  KC_MY_ESC,
  MAGIC,
  // OS switching: sets the ctrl<->gui swap and persists it to EEPROM
  TO_PC,
  TO_MAC,
  // semantic keys whose PC/mac difference is more than the ctrl<->gui swap
  DEL_WORD,      // delete previous word: ctrl-bspc on PC, alt-bspc on mac
  NAV_BACK,      // browser back: KC_WBAK on PC, cmd-[ on mac
  NAV_FWD,       // browser forward: KC_WFWD on PC, cmd-] on mac
  CONTEXT_MENU,  // menu key on PC, hotkey chord on mac
  TABS           // Meh chord sent literally, bypassing the ctrl<->gui swap
};



#define DEFAULT 0
#define MOUSE_LAYER 1
#define SCROLL_LAYER 2
#define SYM 3
#define NAV 4
#define NUM 5
#define GAMING 6
#define GAMING_NUM 7


#define PTT KC_F16
#define MUTE A(S(KC_F18))
#define BOOKMARKS HYPR(KC_B)
//ctrl+gui chord: symmetric under the ctrl<->gui swap, so it works unchanged in both OS modes
#define CLIPBOARD_HISTORY C(G(KC_F13))
#define ACE_JUMP G(A(KC_F13))
#define ACE_SCROLL S(G(A(KC_F13)))
#define MY_SPACE LT(NAV, KC_SPC)
//the ctrl<->gui swap turns this into gui+alt+tab in mac mode
#define SHOW_APPS C(A(KC_TAB))
#define MOUSECLICK KC_F19
#define PC_ESC LT(SYM, KC_ESC)
#define HR_J SFT_T(KC_J)
#define HR_F SFT_T(KC_F)


const uint16_t PROGMEM reset_left_combo[] = {KC_Q, KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM reset_right_combo[] = {KC_Y, KC_P, KC_N, COMBO_END};
const uint16_t PROGMEM mac_esc_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {HR_F, HR_J, COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {HR_F, KC_G, COMBO_END};
const uint16_t PROGMEM switch_to_pc_combo[] = {KC_C, LT(SYM, KC_V), KC_B, COMBO_END};
const uint16_t PROGMEM switch_to_mac_combo[] = {KC_N, LT(SYM, KC_M), COMMA_AND_QUEST_MARK, COMBO_END};
const uint16_t PROGMEM gaming_combo[] = {KC_T, KC_G, KC_B, COMBO_END};


combo_t key_combos[] = {
    COMBO(reset_left_combo, QK_BOOT),
    COMBO(reset_right_combo, QK_BOOT),
    COMBO(mac_esc_combo, KC_MY_ESC),
    COMBO(fj_combo, CW_TOGG),
    COMBO(mouse_combo, TO(MOUSE_LAYER)),
    COMBO(switch_to_pc_combo, TO_PC),
    COMBO(switch_to_mac_combo, TO_MAC),
    COMBO(gaming_combo, PDF(GAMING))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //====================================================================================================================================================================================
  [DEFAULT] = LAYOUT_split_3x6_3(
    OSM(MOD_LSFT),  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                    KC_Y,       KC_U,             KC_I,                   KC_O,               KC_P,               OSM(MOD_RSFT),
    KC_BSPC,        GUI_T(KC_A),    ALT_T(KC_S),    CTL_T(KC_D),    HR_F,           KC_G,                    KC_H,       HR_J,             CTL_T(KC_K),            ALT_T(KC_L),        GUI_T(KC_SCLN),     KC_ENTER,
    KC_TAB,         KC_Z,           KC_X,           KC_C,           LT(SYM, KC_V),  KC_B,                    KC_N,       LT(SYM, KC_M),    COMMA_AND_QUEST_MARK,   DOT_AND_EXCL_MARK,  DEL_WORD,           KC_DEL,
                                    MUTE,            PTT,           MY_SPACE,                               OSL(SYM),    OSL(NUM),    MAGIC
  ),

   //====================================================================================================================================================================================

  [MOUSE_LAYER] = LAYOUT_split_3x6_3(
      _______, NAV_BACK, NAV_FWD, MS_ACL2, MO(SCROLL_LAYER), XXXXXXX,           XXXXXXX, XXXXXXX, MS_UP, XXXXXXX, XXXXXXX, _______,
      _______,KC_LCTL, KC_LSFT, MS_ACL1, MS_BTN1, MS_BTN2,                      XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, _______,
      _______,XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                          _______,   TO(DEFAULT),   TO(DEFAULT),            TO(DEFAULT),   TO(DEFAULT), XXXXXXX
  ),
  [SCROLL_LAYER] = LAYOUT_split_3x6_3(
      _______, _______, _______, _______, _______, _______,                      _______, _______, MS_WHLU, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                      _______, MS_WHLL, MS_WHLD, MS_WHLR, _______, _______,
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                   _______, _______,   _______,                  _______, _______, _______
    ),
//====================================================================================================================================================================================




[SYM] = LAYOUT_split_3x6_3(
_______,  KC_PIPE,            KC_AMPR,           KC_LPRN,         KC_RPRN,         KC_DLR,         KC_EXLM, KC_PERC,       KC_PPLS,        KC_ASTR,        KC_CIRC,        _______,
_______,  GUI_T(KC_QUOT),      ALT_T(KC_SLSH),    CTL_T(KC_LBRC),  SFT_T(KC_RBRC),  KC_DQUO,        KC_QUES, SFT_T(KC_EQL), CTL_T(KC_MINS), ALT_T(KC_BSLS), GUI_T(KC_GRV),  _______,
_______,  KC_TILD,            KC_UNDS,           KC_LCBR,         KC_RCBR,         KC_HASH,        ARROW, KC_AT,         KC_LT,          KC_GT,          KC_COLN,        _______,
                                                _______,        _______,        MO(NUM),        _______, _______,       _______
),
//====================================================================================================================================================================================


[NAV] = LAYOUT_split_3x6_3(
_______, _______,           _______,        _______,        TO(MOUSE_LAYER),    QK_REP,                 C(KC_Y),            KC_PGUP,  KC_UP,  KC_PGDN, KC_PAUS,       _______,
_______, GUI_T(KC_DEL),     ALT_T(KC_TAB),  CTL_T(KC_BSPC), SFT_T(KC_ENTER),    MOUSECLICK,             CLIPBOARD_HISTORY,  KC_LEFT, KC_DOWN, KC_RIGHT, CONTEXT_MENU, _______,
_______, C(KC_Z),           C(KC_X),        C(KC_C),        C(KC_V),            SHOW_APPS,              TABS,               KC_HOME, KC_END, KC_MY_ESC, MUTE,         _______,
                                            _______,        _______,            _______,                MO(NUM),            _______, _______
),

//====================================================================================================================================================================

[NUM] = LAYOUT_split_3x6_3(
KC_MPRV, KC_MNXT,       KC_7,        KC_8,        KC_9,        _______,        _______, KC_F7,         KC_F8,          KC_F9,          KC_F10,         KC_MUTE,
UG_HUEU, GUI_T(KC_0),   ALT_T(KC_4),    CTL_T(KC_5),    SFT_T(KC_6),    KC_DOT,        _______, SFT_T(KC_F4),  CTL_T(KC_F5),   ALT_T(KC_F6),   GUI_T(KC_F11),         KC_VOLU,
UG_TOGG, KC_MPLY,       KC_1,        KC_2,        KC_3,        KC_COMM,        _______, KC_F1,         KC_F2,          KC_F3,          KC_F12,         KC_VOLD,
                                        _______,        _______,        _______,        _______, _______,       _______
),

//====================================================================================================================================================================================

[GAMING] = LAYOUT_split_3x6_3(
  KC_TAB, KC_Q, KC_W, KC_E,    KC_R,   KC_T,                              KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_LCTL, KC_A, KC_S, KC_D,    KC_F,   KC_G,                              KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_ENT,
  KC_LSFT,  KC_Z, KC_X, KC_C,    KC_V,   KC_B,                              KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
                       KC_LALT, KC_SPC, OSL(GAMING_NUM),                   KC_QUOT,  _______, PDF(DEFAULT)
),

[GAMING_NUM] = LAYOUT_split_3x6_3(
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       _______, _______, _______, _______, _______, _______,
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,                    _______, _______, _______
)

  //====================================================================================================================================================================================
};

void send_key_or_another_if_shifted(int16_t keycode, int16_t keycode_shifted) {
    const uint8_t mods = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
    if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        del_oneshot_mods(MOD_MASK_SHIFT);
        tap_code16(keycode_shifted);
        set_mods(mods);
    } else {
        tap_code16(keycode);
    }
}


// OS mode: the persisted ctrl<->gui swap doubles as the "we are on mac" flag
static bool is_mac(void) {
    return keymap_config.swap_lctl_lgui;
}


uint16_t last_keys[3] = {KC_NO, KC_NO, KC_NO};

bool last_key_is(uint16_t keycode) {
    return last_keys[2] == keycode;
}

bool last_two_keys_are(uint16_t keycode1, uint16_t keycode2) {
    return last_keys[1] == keycode1 && last_keys[2] == keycode2;
}

bool last_three_keys_are(uint16_t keycode1, uint16_t keycode2, uint16_t keycode3) {
    return last_keys[0] == keycode1 && last_keys[1] == keycode2 && last_keys[2] == keycode3;
}

void consume_last_keys(void) {
    last_keys[0] = KC_NO;
    last_keys[1] = KC_NO;
    last_keys[2] = KC_NO;
}

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
    case TO_PC:
    case TO_MAC:
        if (record->event.pressed) {
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = (keycode == TO_MAC);
            eeconfig_update_keymap(&keymap_config);
            set_single_persistent_default_layer(DEFAULT);
        }
        return false;
    case DEL_WORD:
        if (record->event.pressed) {
            tap_code16(is_mac() ? A(KC_BSPC) : C(KC_BSPC));
        }
        return false;
    case NAV_BACK:
        if (record->event.pressed) {
            tap_code16(is_mac() ? G(KC_LBRC) : KC_WBAK);
        }
        return false;
    case NAV_FWD:
        if (record->event.pressed) {
            tap_code16(is_mac() ? G(KC_RBRC) : KC_WFWD);
        }
        return false;
    case CONTEXT_MENU:
        if (record->event.pressed) {
            tap_code16(is_mac() ? HYPR(KC_F12) : KC_APP);
        }
        return false;
    case TABS:
        if (record->event.pressed) {
            //tap_code16 bypasses the ctrl<->gui swap, so the OS-side hotkey always sees a real Meh chord
            tap_code16(MEH(KC_F13));
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
    case KC_MY_ESC:
        if(record->event.pressed && is_caps_word_on()) {
            caps_word_off();
            return false;
        } else if(record->event.pressed) {
            tap_code(KC_ESC);
            return false;
        }
    }

    if (record->event.pressed) {
        // 1. Check if our special macro key was pressed
        if (keycode == MAGIC) {
            // Check if the history matches A then T
            if (last_two_keys_are(KC_A, KC_T)) {
                tap_code(KC_BSPC);
                tap_code(KC_BSPC);
                SEND_STRING("@");
                // clear history so a second MAGIC press doesn't fire again on stale keys
                consume_last_keys();
            } else if (last_three_keys_are(KC_A, KC_N, KC_D)) {
               tap_code(KC_BSPC);
               tap_code(KC_BSPC);
               tap_code(KC_BSPC);
               SEND_STRING("@");
               consume_last_keys();
            }
            return false; // consume MAGIC
        }


        // 2. Update the history buffer for all other keys if they are alphas
        uint16_t base_keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
        if (base_keycode >= KC_A && base_keycode < KC_0) {
            last_keys[0] = last_keys[1];
            last_keys[1] = last_keys[2];
            last_keys[2] = base_keycode;
        }
    }

    return true;
}



void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
//   rgblight_enable_noeeprom(); // enables RGB, without saving settings
//   rgblight_sethsv_noeeprom(HSV_RED); // sets the color to red without saving
//   rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
#endif

    // heal a stale persisted default layer from EEPROM (layer numbers may
    // change between flashes; only DEFAULT and GAMING are valid defaults)
    uint8_t default_layer = get_highest_layer(default_layer_state);
    if (default_layer != DEFAULT && default_layer != GAMING) {
        set_single_persistent_default_layer(DEFAULT);
    }
}


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x6_3(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );


// holding both thumb keys (nav + sym) activates the num layer.
// hand-rolled instead of update_tri_layer_state(), because that force-clears
// NUM on every layer change and thereby breaks direct activation via
// OSL(NUM) and MO(NUM)
layer_state_t layer_state_set_user(layer_state_t state) {
    static bool num_activated_by_tri = false;
    const layer_state_t sym_and_nav = ((layer_state_t)1 << SYM) | ((layer_state_t)1 << NAV);
    if ((state & sym_and_nav) == sym_and_nav) {
        if (!(state & ((layer_state_t)1 << NUM))) {
            num_activated_by_tri = true;
        }
        state |= (layer_state_t)1 << NUM;
    } else if (num_activated_by_tri) {
        state &= ~((layer_state_t)1 << NUM);
        num_activated_by_tri = false;
    }
    return state;
}


bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (get_highest_layer(default_layer_state) == GAMING) {
        return false;
    }
    return true;
}


bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    // I have a dedicated underscore key, so no need to shift KC_MINS.
    case KC_MINS:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
