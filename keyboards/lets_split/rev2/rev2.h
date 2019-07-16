#pragma once

#include "lets_split.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);

#ifndef FLIP_HALF
// Standard Keymap
// (TRRS jack on the left half is to the right, TRRS jack on the right half is to the left)
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
    L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45, \
                L52, L53,                     R52, R53, \
                        L54, L55, R50, R51, \
                        \
                    L65, L63,           R62, R60, \
                    L64, L62,           R63, R61 \
    ) \
	{ \
		{ L00, L01, L02, L03, L04, L05 }, \
		{ L10, L11, L12, L13, L14, L15 }, \
		{ L20, L21, L22, L23, L24, L25 }, \
		{ L30, L31, L32, L33, L34, L35 }, \
		{ L40, L41, L42, L43, L44, L45 }, \
		{KC_NO, KC_NO,L52, L53, L54, L55 }, \
		{KC_NO, KC_NO,L62, L63, L64, L65 }, \
		{ R05, R04, R03, R02, R01, R00 }, \
		{ R15, R14, R13, R12, R11, R10 }, \
		{ R25, R24, R23, R22, R21, R20 }, \
		{ R35, R34, R33, R32, R31, R30 }, \
		{ R45, R44, R43, R42, R41, R40 }, \
		{KC_NO, KC_NO,R53, R52, R51, R50 }, \
		{KC_NO,KC_NO,R63, R62, R61, R60 } \
	}
#else
// Keymap with right side flipped
// (TRRS jack on both halves are to the right)
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, R30, R31, R32, R33, R34, R35, \
    L40, L41, L42, L43, L44, L45, R40, R41, R42, R43, R44, R45, \
                L52, L53,                     R52, R53, \
                        L54, L55, R50, R51, \
                        \
                    L65, L63,           R62, R60, \
                    L64, L62,           R63, R61 \
    ) \
	{ \
		{ L00, L01, L02, L03, L04, L05 }, \
		{ L10, L11, L12, L13, L14, L15 }, \
		{ L20, L21, L22, L23, L24, L25 }, \
		{ L30, L31, L32, L33, L34, L35 }, \
		{ L40, L41, L42, L43, L44, L45 }, \
		{KC_NO, KC_NO,L52, L53, L54, L55 }, \
		{KC_NO, KC_NO,L62, L63, L64, L65 }, \
		{ R00, R01, R02, R03, R04, R05 }, \
		{ R10, R11, R12, R13, R14, R15 }, \
		{ R20, R21, R22, R23, R24, R25 }, \
		{ R30, R31, R32, R33, R34, R35 }, \
		{ R40, R41, R42, R43, R44, R45 }, \
		{ R50, R51, R52, R53,KC_NO,KC_NO}, \
		{ R60, R61, R62, R63,KC_NO,KC_NO}, \
	}
#endif

#define LAYOUT_ortho_4x12 LAYOUT
