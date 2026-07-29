#include QMK_KEYBOARD_H
#include "keymap_us_international.h"


// custom key codes for e.g. macros
enum custom_keycodes {
  ARROW = SAFE_RANGE,
  COMMA_AND_SEMICOLON,  // , on tap, ; when shifted (german layout habit). ? lives on SYM
  DOT_AND_COLON,        // . on tap, : when shifted.                       ! lives on SYM
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
  WIN_CYCLE,     // next window of the current app: cmd-` on mac, alt-esc on PC
  TABS,          // Meh chord sent literally, bypassing the ctrl<->gui swap
  RGRID          // cmd+shift+space sent literally, bypassing the ctrl<->gui swap
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
#define HR_J SFT_T(KC_J)
#define HR_F SFT_T(KC_F)
// MAGIC on tap, GUI on hold. a mod-tap only accepts a basic keycode, so an otherwise unused
// F-key stands in for MAGIC and is intercepted in process_record_user - it never reaches the
// host. going through a real mod-tap keeps TAPPING_TERM, PERMISSIVE_HOLD and CHORDAL_HOLD
// behaving exactly like every other home row mod.
#define HR_MAGIC GUI_T(KC_F20)


const uint16_t PROGMEM reset_left_combo[] = {KC_Q, KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM reset_right_combo[] = {KC_Y, KC_P, KC_N, COMBO_END};
const uint16_t PROGMEM mac_esc_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {HR_F, HR_J, COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {HR_F, KC_G, COMBO_END};
const uint16_t PROGMEM switch_to_pc_combo[] = {KC_C, LT(SYM, KC_V), KC_B, COMBO_END};
const uint16_t PROGMEM switch_to_mac_combo[] = {KC_N, LT(SYM, KC_M), COMMA_AND_SEMICOLON, COMBO_END};
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
  // MAGIC and the semicolon key are swapped on purpose: MAGIC earns the right pinky home
  // position because it now carries a pile of rules, and ";" gives up that seat because
  // "s" + MAGIC types one anyway. the cost is that right GUI moves down a row.
  [DEFAULT] = LAYOUT_split_3x6_3(
    OSM(MOD_LSFT),  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                    KC_Y,       KC_U,             KC_I,                   KC_O,               KC_P,               OSM(MOD_RSFT),
    KC_BSPC,        GUI_T(KC_A),    ALT_T(KC_S),    CTL_T(KC_D),    HR_F,           KC_G,                    KC_H,       HR_J,             CTL_T(KC_K),            ALT_T(KC_L),        HR_MAGIC,           KC_ENTER,
    KC_TAB,         KC_Z,           KC_X,           KC_C,           LT(SYM, KC_V),  KC_B,                    KC_N,       LT(NUM, KC_M),    COMMA_AND_SEMICOLON,    DOT_AND_COLON,      GUI_T(KC_SCLN),     KC_DEL,
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
_______,  KC_TILD,            KC_UNDS,           KC_LCBR,         KC_RCBR,         KC_HASH,        ARROW,  KC_LT,          KC_GT,     KC_AT,     KC_COLN,        _______,
                                                _______,        _______,        MO(NUM),        _______, _______,       _______
),
//====================================================================================================================================================================================


// split by hand along "does this key still need a modifier?":
//   left  = keys that already carry their own mods (C(KC_C), MUTE, TABS, ...) or need none.
//           they sit next to the mods on purpose - nothing is ever chorded with them.
//   right = bare keys (arrows, page/home/end) that are chorded with the left home row mods,
//           so the chord is always cross-hand.
// the home row is plain mods, not mod-taps, so no hold on this layer can misfire a character.
// tab/bspc/del/enter are deliberately absent: DEFAULT carries them on the outer columns, where
// the opposite hand's home row mod already gives ctrl+bspc / alt+tab cross-hand. enter and del
// even shine through here, since the right outer column is transparent.
// DEL_WORD moved in from DEFAULT and kept its physical key, so it is now NAV + that key.
// WIN_CYCLE sits opposite the mods on purpose: left SFT + it cycles windows backwards.
// the remaining XXXXXXX on the right inner column is free real estate.
[NAV] = LAYOUT_split_3x6_3(
TABS,               SHOW_APPS,  TO(MOUSE_LAYER),  RGRID,       NAV_BACK,  NAV_FWD,          XXXXXXX,    KC_PGUP,  KC_UP,    KC_PGDN,    KC_PAUS,       _______,
MUTE,               KC_LGUI,    KC_LALT,          KC_LCTL,     KC_LSFT,   QK_REP,           WIN_CYCLE,  KC_LEFT,  KC_DOWN,  KC_RIGHT,   CONTEXT_MENU,  _______,
CLIPBOARD_HISTORY,  C(KC_Z),    C(KC_X),          C(KC_C),     C(KC_V),   C(KC_Y),          XXXXXXX,    KC_HOME,  KC_END,   KC_MY_ESC,  DEL_WORD,      _______,
                                                  _______,     _______,   _______,          MO(NUM),  _______,  _______
),

//====================================================================================================================================================================

[NUM] = LAYOUT_split_3x6_3(
KC_MPRV, KC_MNXT,       KC_7,        KC_8,        KC_9,        _______,        _______, KC_F7,         KC_F8,          KC_F9,          KC_F10,          KC_VOLU,
UG_HUEU, GUI_T(KC_0),   ALT_T(KC_4),    CTL_T(KC_5),    SFT_T(KC_6),    KC_DOT,        _______, SFT_T(KC_F4),  CTL_T(KC_F5),   ALT_T(KC_F6),   GUI_T(KC_F11),      KC_VOLD,
UG_TOGG, KC_MPLY,       KC_1,        KC_2,        KC_3,        KC_COMM,        _______, KC_F1,         KC_F2,          KC_F3,          KC_F12,          KC_MUTE,
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

// a backspace erased the character the newest entry stands for, so drop that entry and let
// the older ones slide back in - otherwise MAGIC would count on text that is no longer there
void undo_last_key(void) {
    last_keys[2] = last_keys[1];
    last_keys[1] = last_keys[0];
    last_keys[0] = KC_NO;
}

void push_last_key(uint16_t token) {
    last_keys[0] = last_keys[1];
    last_keys[1] = last_keys[2];
    last_keys[2] = token;
}

// what MAGIC remembers a key as, or KC_NO for keys it has no rules for.
// alphas and digits collapse to their basic keycode. the punctuation MAGIC cares about is
// normalised to one canonical keycode each, so it does not matter that - and [ happen to sit
// on home row mod-taps on SYM. the shift stays in the token, which is what keeps "(" from
// looking like "9".
static uint16_t magic_token_for(uint16_t keycode) {
    switch (keycode) {
        case KC_MINS:
        case CTL_T(KC_MINS): return KC_MINS;
        case KC_EQL:
        case SFT_T(KC_EQL):  return KC_EQL;
        case KC_DOT:         return KC_DOT;
        case KC_COMM:        return KC_COMM;
        case KC_LBRC:
        case CTL_T(KC_LBRC): return KC_LBRC;
        case KC_LPRN:        return KC_LPRN;
        case KC_LCBR:        return KC_LCBR;
        case KC_LT:          return KC_LT;
    }
    const uint16_t basic = QK_MODS_GET_BASIC_KEYCODE(keycode);
    if (basic >= KC_A && basic < KC_0) {
        return basic;
    }
    return KC_NO;
}

// MAGIC completes an opening bracket into its pair: "(" then MAGIC yields "()".
// takes a token from the history, returns KC_NO for anything that is not an opening bracket.
static uint16_t closing_bracket_for(uint16_t token) {
    switch (token) {
        case KC_LPRN: return KC_RPRN;
        case KC_LCBR: return KC_RCBR;
        case KC_LT:   return KC_GT;
        case KC_LBRC: return KC_RBRC;
    }
    return KC_NO;
}

// a single key MAGIC swaps for a punctuation mark. only consulted after the longer
// sequences, which is what keeps "and" from being swallowed by the "d" rule.
// the dot and comma entries make MAGIC an escalator: . becomes : and , becomes ; -
// and because the produced mark is recorded again, d MAGIC MAGIC walks d -> . -> :
static uint16_t magic_punctuation_for(uint16_t token) {
    switch (token) {
        case KC_F:    return KC_QUES;
        case KC_A:    return KC_EXLM;
        case KC_D:    return KC_DOT;
        case KC_C:    return KC_COMM;
        case KC_S:    return KC_SCLN;
        case KC_DOT:  return KC_COLN;
        case KC_COMM: return KC_SCLN;
    }
    return KC_NO;
}

// everything MAGIC can do, reachable from both the plain MAGIC key and the tap side of
// HR_MAGIC. longest match wins, so the branches run three keys, then two, then one. that
// ordering is load bearing: "and" and "d" both end in d, and "and" has to win.
// every branch clears the history afterwards, so a second MAGIC press cannot fire again on
// keys that are no longer on screen.
static void magic_activate(void) {
    const uint16_t closer = closing_bracket_for(last_keys[2]);
    const uint16_t punct  = magic_punctuation_for(last_keys[2]);

    // three keys
    if (last_three_keys_are(KC_A, KC_N, KC_D)) {
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
        SEND_STRING("&&");
        consume_last_keys();

    // two keys. "(-" and "(=" grow into a lambda with the caret parked in the block.
    // the string stays literal in each branch so SEND_STRING keeps working on an AVR
    // build too. for "{ }" style padding, pad the string and bump the KC_LEFT count.
    } else if (last_two_keys_are(KC_A, KC_T)) {
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
        SEND_STRING("@");
        consume_last_keys();
    } else if (last_two_keys_are(KC_LPRN, KC_MINS)) {
        tap_code(KC_BSPC);  // the "-" was only the trigger
        SEND_STRING(") -> {}");
        tap_code(KC_LEFT);
        consume_last_keys();
    } else if (last_two_keys_are(KC_LPRN, KC_EQL)) {
        tap_code(KC_BSPC);
        SEND_STRING(") => {}");
        tap_code(KC_LEFT);
        consume_last_keys();

    // one key. an opening bracket gains its partner, so no bspc there - the bracket
    // itself stays on screen. a letter is replaced by its punctuation mark.
    } else if (closer != KC_NO) {
        tap_code16(closer);
        consume_last_keys();
    } else if (punct != KC_NO) {
        tap_code(KC_BSPC);
        tap_code16(punct);
        // remember the mark now on screen instead of clearing outright, so MAGIC can
        // escalate its own output: d MAGIC MAGIC walks d -> . -> :
        consume_last_keys();
        push_last_key(punct);
    // a backspace escalates into a word deletion. this one re-arms itself instead of
    // clearing, so holding the thought and tapping MAGIC again eats the next word too.
    } else if (last_key_is(KC_BSPC)) {
        tap_code16(is_mac() ? A(KC_BSPC) : C(KC_BSPC));
        consume_last_keys();
        push_last_key(KC_BSPC);
    }
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
            } else if ((mods | oneshot_mods) & (MOD_MASK_CTRL | MOD_MASK_GUI)) {
                // ctrl or gui held? gui counts too so the same physical key
                // works in mac mode, where the ctrl<->gui swap turns the
                // ctrl mod-tap into gui
                del_mods(MOD_MASK_CTRL | MOD_MASK_GUI);
                del_oneshot_mods(MOD_MASK_CTRL | MOD_MASK_GUI);
                SEND_STRING("|>");
                set_mods(mods);
            } else {
                SEND_STRING("->");
            }
        }
        return false;
    // these two return false before the history code below, so they record themselves here.
    // the shifted marks are recorded too - they have no MAGIC rules, but an unrecorded key
    // would leave a stale older token in the buffer for MAGIC to mismatch on.
    case COMMA_AND_SEMICOLON:
        if (record->event.pressed) {
            const bool shifted = (mods | oneshot_mods) & MOD_MASK_SHIFT;
            send_key_or_another_if_shifted(KC_COMM, KC_SCLN);
            push_last_key(shifted ? KC_SCLN : KC_COMM);
        }
        return false;
    case DOT_AND_COLON:
        if (record->event.pressed) {
            const bool shifted = (mods | oneshot_mods) & MOD_MASK_SHIFT;
            send_key_or_another_if_shifted(KC_DOT, KC_COLN);
            push_last_key(shifted ? KC_COLN : KC_DOT);
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
            // a whole word is gone, so nothing in the buffer still describes the screen
            consume_last_keys();
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
    case HR_MAGIC:
        // QMK's tap-hold machinery already decided which one this is
        if (record->tap.count) {
            if (record->event.pressed) {
                magic_activate();
            }
            return false;  // the stand-in F-key must never reach the host
        }
        return true;       // hold: let QMK send GUI as usual
    case WIN_CYCLE:
        if (record->event.pressed) {
            // tap_code16 bypasses the ctrl<->gui swap, so the real mod is named here.
            // a held shift survives into the report, which makes shift+key cycle backwards.
            // on PC alt-esc is only a rough stand-in: it walks every window, not just this
            // app's, because windows has no same-app cycle.
            tap_code16(is_mac() ? G(KC_GRV) : A(KC_ESC));
        }
        return false;
    case TABS:
        if (record->event.pressed) {
            //tap_code16 bypasses the ctrl<->gui swap, so the OS-side hotkey always sees a real Meh chord
            tap_code16(MEH(KC_F13));
        }
        return false;
    case RGRID:
        if (record->event.pressed) {
            //same trick: always a real cmd+shift+space, regardless of OS mode
            tap_code16(G(S(KC_C)));
        }
        return false;
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
            magic_activate();
            return false; // consume MAGIC
        }

        // 2. Keep the buffer in step with the screen when text is deleted again.
        //    ctrl/alt/gui+bspc kills a whole word, a bare bspc a single character.
        //    KC_DEL is not in here on purpose: it eats what is *after* the cursor.
        if (keycode == KC_BSPC) {
            if ((mods | oneshot_mods) & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) {
                consume_last_keys();
            } else {
                // rewind past the character that just died, then remember the backspace
                // itself so a following MAGIC can escalate it into a word deletion
                undo_last_key();
                push_last_key(KC_BSPC);
            }
            return true;
        }

        // 3. A key pressed with ctrl/alt/gui was a shortcut, not typed text, so it must not
        //    enter the history. without this, ctrl-s followed by MAGIC would see an "s" that
        //    was never typed and eat a real character to put a ";" in its place.
        //    shift is fine: shift-a really does type an A.
        if ((mods | oneshot_mods) & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) {
            return true;
        }

        // 4. Update the history buffer; keys MAGIC has no rules for leave it alone
        const uint16_t token = magic_token_for(keycode);
        if (token != KC_NO) {
            push_last_key(token);
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
