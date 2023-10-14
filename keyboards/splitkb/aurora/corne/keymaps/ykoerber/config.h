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

// build with
// make splitkb/aurora/corne/rev1:ykoerber -e CONVERT_TO=promicro_rp2040

#pragma once

#ifdef RGBLIGHT_ENABLE
    // #define RGBLIGHT_EFFECT_BREATHING
#endif


#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
//#define SPLIT_USB_DETECT
//avoid the following: if entering " =" I'll get "  j" because I tap the space key twice, and the second hold is interpreted as holding space
#define TAPPING_FORCE_HOLD
//#define TAPPING_TERM 100
//#define PERMISSIVE_HOLD
//handedness via EEPROM
//#define EE_HANDS
#define COMBO_COUNT 2
//without: rolling on a layer with home row mods will use the mods and not output the individual key strokes
//see https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
//#define IGNORE_MOD_TAP_INTERRUPT



//rgb
#define RGBLIGHT_DEFAULT_HUE 169