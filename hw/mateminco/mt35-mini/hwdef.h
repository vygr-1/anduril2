/// mateminco/mt35-mini/hwdef.h  
/// Mateminco MT35-Mini has its own hwdef.h  


// Mateminco MT35-Mini / Astrolux FT03
// Copyright (C) 2022-2023 (original author TBD), Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later


#pragma once


///   ///   ///   ///   ///   ///   ///   ///   ///   ///


/* /// Driver layout
 *
 *           ----
 *   Reset -|1  8|- VCC
 * eswitch -|2  7|- Aux LED
 *  1x7135 -|3  6|- NC
 *     GND -|4  5|- FET
 *           ----
 */


/*  /// MT35 Mini hwdef.c 
/// OG  : #define HWDEF_C  hank/emisar-d4/hwdef.c 

/// Mod : #define HWDEF_C  mateminco--mt35-mini/hwdef.c
 */
#define HWDEF_C  mateminco/mt35-mini/hwdef.c


/*  /// MT35 Mini, "fsm/chan-aux.h" 
/// copied from "sofirn/sc31-pro-t1616/hwdef.h" : 
// allow using aux LEDs as extra channel modes
#include "fsm/chan-aux.h"

 */
#include "fsm/chan-aux.h"


///   ///   ///   ///   ///   ///   ///   ///   ///   ///


/*  /// channel modes

/// OG:
// channel modes
// * 0. FET+7135 stacked
#define NUM_CHANNEL_MODES  1
enum CHANNEL_MODES {
    CM_MAIN = 0,
};



/// Mod. copied from "sofirn/sc31-pro-t1616/hwdef.h" : 
// channel modes:
// * 0. FET+7135 stacked
// * 1. aux LEDs

#define NUM_CHANNEL_MODES  2

enum CHANNEL_MODES {
    CM_MAIN = 0,
    CM_AUX
};

 */

#define NUM_CHANNEL_MODES  2

enum CHANNEL_MODES {
    CM_MAIN = 0,
    CM_AUX
};


#define DEFAULT_CHANNEL_MODE  CM_MAIN


// right-most bit first, modes are in fedcba9876543210 order
#define CHANNEL_MODES_ENABLED 0b00000001


#define PWM_CHANNELS 2  // old, remove this


#define PWM_BITS      8       // attiny85 only supports up to 8 bits

#define PWM_GET       PWM_GET8

#define PWM_DATATYPE  uint8_t

#define PWM_DATATYPE2 uint16_t

#define PWM1_DATATYPE uint8_t   // little FET ramp

#define PWM2_DATATYPE uint8_t   // big FET ramp


#define PWM_TOP_INIT  255    // highest value used in top half of ramp


// 1x7135 channel
#define CH1_PIN  PB4        // pin 3, 1x7135 PWM
#define CH1_PWM  OCR1B      // OCR1B is the output compare register for PB4


// DD FET channel
#define CH2_PIN  PB0        // pin 5, FET PWM
#define CH2_PWM  OCR0A      // OCR0A is the output compare register for PB0


// lighted button
#define AUXLED_PIN   PB2    // pin 7


// e-switch
#ifndef SWITCH_PIN
#define SWITCH_PIN   PB3    // pin 2
#define SWITCH_PCINT PCINT3 // pin 2 pin change interrupt
#endif


#define ADC_PRSCL   0x07    // clk/128


// average drop across diode on this hardware
#ifndef VOLTAGE_FUDGE_FACTOR
#define VOLTAGE_FUDGE_FACTOR 7  // add 0.35V
#endif


#define FAST 0xA3           // fast PWM both channels
#define PHASE 0xA1          // phase-correct PWM both channels


inline void hwdef_setup() {
    // configure PWM channels
    DDRB = (1 << CH1_PIN)
         | (1 << CH2_PIN);

    // configure PWM channels
    TCCR0B = 0x01; // pre-scaler for timer (1 => 1, 2 => 8, 3 => 64...)
    TCCR0A = PHASE;

    // Second PWM counter is ... weird
    TCCR1 = _BV (CS10);
    GTCCR = _BV (COM1B1) | _BV (PWM1B);
    OCR1C = PWM_TOP_INIT;  // Set ceiling value to maximum

    // configure e-switch
    PORTB = (1 << SWITCH_PIN);  // e-switch is the only input
    PCMSK = (1 << SWITCH_PIN);  // pin change interrupt uses this pin
}



#define LAYOUT_DEFINED



///   ///   ///   ///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///   ///   ///   ///



/*  /// BLANK   

 */

/*  /// MT35 Mini BLANK   

 */



/// mateminco--mt35-mini/hwdef.h 



///   END   


