/// sofirn/sp36-t1616/anduril.h

// Sofirn SP36 (small Q8) config options for Anduril using the Attiny1616
// Copyright (C) 2021-2023 (FIXME)
// SPDX-License-Identifier: GPL-3.0-or-later


#pragma once


#include "sofirn/sp36-t1616/hwdef.h"


#include "sofirn/anduril.h"


/*   /// BLANK   

 */



// copied from Wurkkos TS25 ramp



#define RAMP_SIZE 150



// 7135 at 75/150
// level_calc.py 5.7895 2 150 7135 1 0.1 130 FET 1 10 3000 --pwm dyn:74:4096:255:3
// (with some manual tweaks)

#define PWM1_LEVELS  1,1,2,3,3,4,5,6,7,8,9,11,12,13,15,16,18,19,21,23,26,27,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,71,74,76,78,80,82,85,87,90,93,96,100,103,107,112,116,122,127,133,140,147,154,163,171,182,192,203,215,228,241,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0



// non-zero part of FET channel calculated with:
//   level_calc.py 3 1 75 7135 1 200 3000
//   (FIXME? there's a visible bump when the FET kicks in, even with just 1/255)

#define PWM2_LEVELS  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,10,11,13,14,16,17,19,21,22,24,26,28,30,32,34,37,39,41,44,46,48,51,54,56,59,62,65,68,71,74,77,81,84,87,91,94,98,102,106,110,114,118,122,126,130,135,139,144,148,153,158,163,168,173,178,184,189,195,200,206,212,218,224,230,236,242,248,255



#define PWM_TOPS     4095,2701,3200,3586,2518,2778,2834,2795,2705,2587,2455,2582,2412,2247,2256,2091,2062,1907,1860,1802,1737,1605,1542,1477,1412,1347,1284,1222,1162,1105,1050,997,946,898,853,810,768,730,693,658,625,594,564,536,503,485,462,439,418,398,384,366,353,340,327,319,307,298,292,284,280,273,269,266,263,260,258,256,256,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255



#define MAX_1x7135 75

#define DEFAULT_LEVEL 50

#define MIN_THERM_STEPDOWN 60

#define HALFSPEED_LEVEL 20

#define QUARTERSPEED_LEVEL 5



#define RAMP_SMOOTH_FLOOR    1
#define RAMP_SMOOTH_CEIL     150



// 20 38 56 [75] 93 111 130
#define RAMP_DISCRETE_FLOOR  20
#define RAMP_DISCRETE_CEIL   130
#define RAMP_DISCRETE_STEPS  7



// at Sofirn's request, use max (150) for the Simple UI ceiling
#define SIMPLE_UI_FLOOR  1
#define SIMPLE_UI_CEIL   150
#define SIMPLE_UI_STEPS  5



///   ///   ///   ///   ///   ///   ///   ///   ///   ///



// also at Sofirn's request, enable 2 click turbo (Anduril 1 style)
#define DEFAULT_2C_STYLE 1



// Allow 3C in Simple UI for switching between smooth and stepped ramping
#define USE_SIMPLE_UI_RAMPING_TOGGLE

// allow Aux Config and Strobe Modes in Simple UI
#define USE_EXTENDED_SIMPLE_UI



/*
/// stop panicking at ~75% power or ~3000 lm, this light has high thermal mass
/// #define THERM_FASTER_LEVEL (RAMP_SIZE*9/10)  // throttle back faster when high
 */



// show each channel while it scroll by in the menu
#define USE_CONFIG_COLORS



// blink numbers on the aux LEDs by default
#define DEFAULT_BLINK_CHANNEL  CM_AUX



// the default of 26 looks a bit rough, so increase it to make it smoother
#define CANDLE_AMPLITUDE 33



/* /// undef BLINK_AT_RAMP 
/// don't blink during the ramp; the button LED brightness is sufficient
/// to indicate which power channel(s) are being used
/// #ifdef BLINK_AT_RAMP_MIDDLE
/// #undef BLINK_AT_RAMP_MIDDLE
/// #endif
 */



///   ///   ///   ///   ///   ///   ///   ///   ///   ///



///   DISABLE SOME FEATURES ?   
///   BLINKIES  
///   #undef USE_BEACON_MODE
///   
#undef USE_SOS_MODE


///   STROBES  
///   #undef USE_PARTY_STROBE_MODE
///   #undef USE_TACTICAL_STROBE_MODE
///   
#undef USE_LIGHTNING_MODE
///   
#undef USE_CANDLE_MODE
///   #undef USE_BIKE_FLASHER_MODE
///   #undef USE_FIREWORK_MODE



///   ///   ///   ///   ///   ///   ///   ///   ///   ///



/* /// TACTICAL MODE LEVELS
///   TACTICAL MODE LEVELS 
///   1H,  2H , 3H : 
///   HIGH , TACTICAL STROBE , LOW
///     150 = turbo
///     (RAMP_SIZE+1) = party strobe
///     (RAMP_SIZE+2) = tactical strobe

 */
#define TACTICAL_LEVELS 120,(RAMP_SIZE+2),30



///   ///   ///   ///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///   ///   ///   ///



// voltage readings were a little high with the Q8 value
#undef VOLTAGE_FUDGE_FACTOR
#define VOLTAGE_FUDGE_FACTOR 5  // add 0.25V, not 0.35V



///   ///   ///   ///   ///   ///   ///   ///   ///   ///



/*
// the high button LED mode on this light uses too much power
// off mode: low (1)
// lockout: blinking (3)
#ifdef INDICATOR_LED_DEFAULT_MODE
#undef INDICATOR_LED_DEFAULT_MODE
#define INDICATOR_LED_DEFAULT_MODE ((3<<2) + 1)
#endif
 */


/*
///  moved this mod here from  "sofirn/anduril.h", 
///  applied and adjusted for each flashlight 

///  from "aux-leds.h" : . . . "USE_INDICATOR_LED" , 
///  "USE_INDICATOR_LED_WHILE_RAMPING" , "INDICATOR_LED_DEFAULT_MODE" . . . 

///  "USE_INDICATOR_LED" : The button lights up
///  "USE_INDICATOR_LED_WHILE_RAMPING" : button LED is ON while main LED is ON 
 */
#define USE_INDICATOR_LED
#define USE_INDICATOR_LED_WHILE_RAMPING


/*
///   NEW MOD. more-aux-patterns by SammysHP
///   using replacement files from SammysHP : 
///   "anduril/aux-leds.c"  and  "anduril/aux-leds.h" ,
///   also  "anduril/off-mode.c" 
///   and  "anduril/lockout-mode.c" ! 
 */
#define USE_EXTENDED_INDICATOR_PATTERNS

/*
///  aux LED patterns : 
    // low nibble:  off state
    // high nibble: lockout state
    // modes are:
    //   0=off
    //   1=low
    //   2=high
    //   3=fancy blinking
    //   4=low blinking
    //   5=high blinking 
///  my default for SC31 PRO T1616 : 
 */
///   LOCKOUT  :   low (1) 
///   OFF MODE :   low blinking (4) 
#undef INDICATOR_LED_DEFAULT_MODE
#define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 4)




// don't blink during the ramp; the button LED brightness is sufficient
// to indicate which power channel(s) are being used
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif
#ifdef BLINK_AT_RAMP_CEIL
#undef BLINK_AT_RAMP_CEIL
#endif



// stop panicking at ~60% power or ~3000 lm
#ifdef THERM_FASTER_LEVEL
#undef THERM_FASTER_LEVEL
#endif
#define THERM_FASTER_LEVEL 130






/*
 */






///   ///   ///   ///   ///   ///   ///   ///   ///   ///






///   END   


