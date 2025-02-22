// aux-leds.h: Aux LED functions for Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#if defined(USE_INDICATOR_LED) && defined(TICK_DURING_STANDBY)
void indicator_led_update(uint8_t mode, uint8_t tick);
#endif
#if defined(USE_AUX_RGB_LEDS) && defined(TICK_DURING_STANDBY)
uint8_t setting_rgb_mode_now = 0;
void rgb_led_update(uint8_t mode, uint16_t arg);
void rgb_led_voltage_readout(uint8_t bright);
/*
 * 0: R
 * 1: RG
 * 2:  G
 * 3:  GB
 * 4:   B
 * 5: R B
 * 6: RGB
 * 7: rainbow
 * 8: voltage
 */
const PROGMEM uint8_t rgb_led_colors[] = {
    0b00000000,  // 0: black
    0b00000001,  // 1: red
    0b00000101,  // 2: yellow
    0b00000100,  // 3: green
    0b00010100,  // 4: cyan
    0b00010000,  // 5: blue
    0b00010001,  // 6: purple
    0b00010101,  // 7: white
};
// intentionally 1 higher than total modes, to make "voltage" easier to reach
// (at Hank's request)
const uint8_t RGB_LED_NUM_COLORS = 11
    #ifdef USE_BUTTON_LED
    +1
    #endif
    ;
#define RGB_LED_NUM_PATTERNS 6
#ifndef RGB_LED_OFF_DEFAULT
#define RGB_LED_OFF_DEFAULT 0x19  // low, voltage
//#define RGB_LED_OFF_DEFAULT 0x18  // low, rainbow
#endif
#ifndef RGB_LED_LOCKOUT_DEFAULT
#define RGB_LED_LOCKOUT_DEFAULT 0x39  // blinking, voltage
//#define RGB_LED_LOCKOUT_DEFAULT 0x37  // blinking, disco
#endif
#ifndef RGB_RAINBOW_SPEED
#define RGB_RAINBOW_SPEED 0x0f  // change color every 16 frames
#endif
#endif

#ifdef USE_EXTENDED_INDICATOR_PATTERNS
    #define INDICATOR_LED_NUM_PATTERNS 6
    #define INDICATOR_LED_CFG_MASK 0x0F
    #define INDICATOR_LED_CFG_OFFSET 4
#else
    #define INDICATOR_LED_NUM_PATTERNS 4
    #define INDICATOR_LED_CFG_MASK 0x03
    #define INDICATOR_LED_CFG_OFFSET 2
#endif

#ifdef USE_INDICATOR_LED
    #ifndef TICK_DURING_STANDBY
        #error "USE_INDICATOR_LED requires TICK_DURING_STANDBY"
    #endif
    // low nibble:  off state
    // high nibble: lockout state
    // modes are:
    //   0=off
    //   1=low
    //   2=high
    //   3=fancy blinking
    //   4=low blinking
    //   5=high blinking
    #ifndef INDICATOR_LED_DEFAULT_MODE
        #ifdef USE_INDICATOR_LED_WHILE_RAMPING
            #define INDICATOR_LED_DEFAULT_MODE ((2<<INDICATOR_LED_CFG_OFFSET) + 1)
        #else
            #define INDICATOR_LED_DEFAULT_MODE ((3<<INDICATOR_LED_CFG_OFFSET) + 1)
        #endif
    #endif
#endif
