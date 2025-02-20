/// mateminco/mt35-mini/anduril.h  

// Mateminco MT35 Mini / Astrolux  FT03
// Copyright (C) 2022-2023 (original author TBD), Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later


#pragma once


#include "mateminco/mt35-mini/hwdef.h"


#include "mateminco/anduril.h"


/*  /// 

 */

/*  /// 

 */



/*  /// INDICATOR LED PATTERNS
///   NEW MOD. more-aux-patterns by SammysHP
///   using replacement files from SammysHP : 
///   "anduril/aux-leds.c"  and  "anduril/aux-leds.h" ,
///   also  "anduril/off-mode.c" 
///   and  "anduril/lockout-mode.c" ! 
 */
#define USE_EXTENDED_INDICATOR_PATTERNS


/*  /// INDICATOR_LED_DEFAULT_MODE   // LOCKOUT: low (1)   // OFF MODE: low blinking (4)  
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
#undef INDICATOR_LED_DEFAULT_MODE
#define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 4)


/*  /// DEFAULT_BLINK_CHANNEL   // blink numbers on the aux LEDs by default

/// from OG "blf-q8-t1616/anduril.h" :

// blink numbers on the aux LEDs by default
#define DEFAULT_BLINK_CHANNEL  CM_AUX

 */
#define DEFAULT_BLINK_CHANNEL  CM_AUX   /// blink channel can be changed later at run-time


/* /// DEFAULT_DONT_RAMP_AFTER_MOON
///  some settings are applied per flashlight  
///  moved this mod here from  "sofirn--anduril.h", adjusted for each flashlight 
///  works great on the  sc31-pro-t1616  
///  1H = floor (moon) . stay at moon, don't ramp up 
 */
#define DEFAULT_DONT_RAMP_AFTER_MOON 1


///   ///   ///   ///   ///   ///   ///   ///   ///   ///


/*  /// BLANK   

 */

/*  /// MT35 Mini BLANK   

 */


/*  /// OG MT35 Mini, undef BLINK_AT_RAMP, etc. 

#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif


/// OG MT35 Mini INDICATOR_LED 
// the button lights up
#define USE_INDICATOR_LED
// the button is visible while main LEDs are on
#define USE_INDICATOR_LED_WHILE_RAMPING

 */

/*  /// MT35 Mini, "mateminco--anduril.h"  

/// some settings are done in "mateminco--anduril.h" , no need to repeat here 

///   Set the default ramp style to Stepped  
#undef RAMP_STYLE
#define RAMP_STYLE 1  // 0 = smooth, 1 = stepped


/// undef BLINK_AT_RAMP  (The OG default is in the  "anduril/config-default.h") 
#undef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_CEIL


/// DEFAULT_2C_STYLE.  0 = no turbo
///  1 = A1 style: Off 2C = ceil, On 2C = turbo  
#define DEFAULT_2C_STYLE 1  // Anduril 1 style

///   "USE_INDICATOR_LED". The button lights up
#define USE_INDICATOR_LED

///   button LED is ON while main LED is ON 
#define USE_INDICATOR_LED_WHILE_RAMPING

///   ALWAYS use MANUAL_MEMORY : 
#undef DEFAULT_MANUAL_MEMORY_TIMER
#define DEFAULT_MANUAL_MEMORY_TIMER 0

///   DISABLE MOMENTARY_MODE 
#undef USE_MOMENTARY_MODE

 */


///   ///   ///   ///   ///   ///   ///   ///   ///   ///



#define RAMP_SIZE 150


// level_calc.py fifth 2 150 7135 1 1 120 FET 1 10 2000
#define PWM1_LEVELS 1,2,2,3,4,5,6,7,8,9,11,13,14,16,18,21,23,26,28,31,35,38,41,45,49,53,58,63,67,73,78,84,90,96,102,109,116,124,131,139,147,156,165,174,184,194,204,215,226,237,249,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0


#define PWM2_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,20,21,22,24,25,27,28,30,31,33,35,36,38,40,42,43,45,47,49,51,53,55,57,59,62,64,66,68,71,73,75,78,80,83,86,88,91,94,96,99,102,105,108,111,114,117,120,124,127,130,134,137,140,144,148,151,155,159,162,166,170,174,178,182,186,190,195,199,203,208,212,217,221,226,231,235,240,245,250,255



#define DEFAULT_LEVEL       38

#define MAX_1x7135          52

#define HALFSPEED_LEVEL     20
#define QUARTERSPEED_LEVEL  10



///   SMOOTH RAMP FLOOR AND CEIL   
#define RAMP_SMOOTH_FLOOR    1
#define RAMP_SMOOTH_CEIL     112



/// OG:   10  27  44  61  78  95  112   
/// Mod : 1   38  75  112 
#define RAMP_DISCRETE_FLOOR  1
#define RAMP_DISCRETE_CEIL   112
#define RAMP_DISCRETE_STEPS  4


///   ///   ///   ///   ///   ///   ///   ///   ///   ///


///   DEFAULT MANUAL MEMORY  
///   stepped ramp :   1   38  75  112   
///   stepped ramp default level = 2/4 
#define DEFAULT_MANUAL_MEMORY 38


// this light should be fine running a bit hotter than most
#undef DEFAULT_THERM_CEIL
#define DEFAULT_THERM_CEIL 55


// stop panicking at ~40% power
#define THERM_FASTER_LEVEL 120
#define MIN_THERM_STEPDOWN 95 // ~600 lumens
#define THERM_RESPONSE_MAGNITUDE 16  // smaller adjustments, big body.  default = 64


// enable extra features
#define USE_SMOOTH_STEPS



///   ///   ///   ///   ///   ///   ///   ///   ///   ///



/*  /// OG MT35 Mini  // turn off extra features 

// too big, turn off extra features
#undef USE_TACTICAL_MODE
#undef USE_SOS_MODE
//#undef USE_RAMP_AFTER_MOON_CONFIG
//#undef USE_RAMP_SPEED_CONFIG
//#undef USE_VOLTAGE_CORRECTION
//#undef USE_2C_STYLE_CONFIG

 */


/* /////    BLINKIES AND STROBES     /////  

///  from `config-default.h` :  
#define USE_BEACON_MODE

// enable various strobe modes
#define USE_BIKE_FLASHER_MODE
#define USE_PARTY_STROBE_MODE
#define USE_TACTICAL_STROBE_MODE

#define USE_LIGHTNING_MODE
#define USE_CANDLE_MODE


///  from  `sofirn/anduril.h` :  
#define USE_FIREWORK_MODE
#define USE_LIGHTHOUSE_MODE
#define USE_BAD_FLUORESCENT_MODE

 */

/* /// DISABLE SOME BLINKIES ? 

#undef USE_BEACON_MODE 

 */
#undef USE_SOS_MODE


/* /// DISABLE SOME STROBES ? 

#undef USE_BIKE_FLASHER_MODE
#undef USE_PARTY_STROBE_MODE
#undef USE_TACTICAL_STROBE_MODE

 */
#undef USE_LIGHTNING_MODE
#undef USE_CANDLE_MODE

#undef USE_FIREWORK_MODE
#undef USE_LIGHTHOUSE_MODE
#undef USE_BAD_FLUORESCENT_MODE



/* /// MORE MODS ? ..

#undef USE_RAMP_SPEED_CONFIG
#undef USE_RAMP_AFTER_MOON_CONFIG
#undef USE_VOLTAGE_CORRECTION
#undef USE_2C_STYLE_CONFIG


#undef USE_TACTICAL_MODE


 */
#undef USE_SIMPLE_UI
#undef USE_SUNSET_TIMER



///   ///   ///   ///   ///   ///   ///   ///   ///   ///



/* /// TACTICAL MODE LEVELS

///   1H,  2H , 3H : 
///   HIGH , TACTICAL STROBE , LOW  
///     150 = turbo
///     (RAMP_SIZE+1) = party strobe
///     (RAMP_SIZE+2) = tactical strobe
///     (RAMP_SIZE+3) = bike flasher 
 */
#define TACTICAL_LEVELS 120,(RAMP_SIZE+2),DEFAULT_MANUAL_MEMORY

/*  /// MT35 Mini TACTICAL MODE LEVELS tests ...  
#define TACTICAL_LEVELS 120,(RAMP_SIZE+2),DEFAULT_LEVEL
#define TACTICAL_LEVELS 120,(RAMP_SIZE+2),DEFAULT_MANUAL_MEMORY
#define TACTICAL_LEVELS 120,(RAMP_SIZE+2),30
#define TACTICAL_LEVELS 120,(RAMP_SIZE+2),38
 */








///   ///   ///   ///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///   ///   ///   ///



/*  /// MT35 Mini   

 */






/// "mateminco--mt35-mini/anduril.h"  






///   END   


