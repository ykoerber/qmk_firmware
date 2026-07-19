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

//only for elite-pi
//#define SERIAL_PIO_USE_PIO1

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define COMBO_COUNT 2

//mitigate switch chatter (one press registering as press-release-press),
//which combined with QUICK_TAP_TERM 0 turns a held home row mod tap into "letter + mod hold"
#define DEBOUNCE 10



#define TAPPING_TERM 200
//faster mod-hold activation if a key is tapped while dual-mod-key is hold for less than the tapping term
#define PERMISSIVE_HOLD

//disable key repeat:
//avoid the following: if entering " =" I'll get "  j" because I tap the space key twice, and the second hold is interpreted as holding space
#define QUICK_TAP_TERM 0

//handedness via EEPROM
#define EE_HANDS


// achordion :D
#define CHORDAL_HOLD


// mouse stuff
//constant cursor speed
#define MK_3_SPEED
// holding keys for changing speed
#define MK_MOMENTARY_ACCEL
//set speed settings
#define MOUSEKEY_INTERVAL_UNMOD 11
#define MK_C_OFFSET_UNMOD 24
#define MK_C_OFFSET_2 60

#define MOUSEKEY_INTERVAL_1 11
//#define MK_C_OFFSET_UNMOD 24
