/// wurkkos/ts21/anduril.h 
/// TS21 version check: 0614 (sp36-t1616) 
/// Wurkkos TS21 uses firmware of Sofirn SP36 


/// BLF Q8 t1616    : 0613
/// SP36 t1616      : 0614 
/// SC31 Pro t1616  : 0614
/// TS21 t1616      : 0614

/// SC31 Pro and TS21 dont have its own model number 
/// Custom SC31 Pro t1616 : 3131
/// Custom TS21 t1616     : 3121 


// BLF Q8 config options for Anduril using the Attiny1616
// Sofirn SP36 (small Q8) config options for Anduril using the Attiny1616
// Copyright (C) 2021-2023 (FIXME)
// SPDX-License-Identifier: GPL-3.0-or-later


#pragma once


#include "wurkkos/ts21/hwdef.h"


#include "wurkkos/anduril.h"


/*  /// 

 */


/*  /// RAMP_SIZE, PWM_LEVELS
/// position this RAMP_SIZE and PWM_LEVELS etc. at the top of this config file ...
/// this is kinda fixed config, not customisable 
 */
/// mostly copied from  "sofirn-blf-q8-t1616/anduril.h" :


// copied from Wurkkos TS25 ramp

#define RAMP_SIZE 150


// 7135 at 75/150
// level_calc.py 5.7895 2 150 7135 1 0.1 130 FET 1 10 3000 --pwm dyn:74:4096:255:3
// (with some manual tweaks)
//
#define PWM1_LEVELS  1,1,2,3,3,4,5,6,7,8,9,11,12,13,15,16,18,19,21,23,26,27,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,71,74,76,78,80,82,85,87,90,93,96,100,103,107,112,116,122,127,133,140,147,154,163,171,182,192,203,215,228,241,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0



// non-zero part of FET channel calculated with:
//   level_calc.py 3 1 75 7135 1 200 3000
//   (FIXME? there's a visible bump when the FET kicks in, even with just 1/255)
//
#define PWM2_LEVELS  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,10,11,13,14,16,17,19,21,22,24,26,28,30,32,34,37,39,41,44,46,48,51,54,56,59,62,65,68,71,74,77,81,84,87,91,94,98,102,106,110,114,118,122,126,130,135,139,144,148,153,158,163,168,173,178,184,189,195,200,206,212,218,224,230,236,242,248,255



#define PWM_TOPS     4095,2701,3200,3586,2518,2778,2834,2795,2705,2587,2455,2582,2412,2247,2256,2091,2062,1907,1860,1802,1737,1605,1542,1477,1412,1347,1284,1222,1162,1105,1050,997,946,898,853,810,768,730,693,658,625,594,564,536,503,485,462,439,418,398,384,366,353,340,327,319,307,298,292,284,280,273,269,266,263,260,258,256,256,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255



#define MAX_1x7135 75

#define MIN_THERM_STEPDOWN 60

#define HALFSPEED_LEVEL 20
#define QUARTERSPEED_LEVEL 5



#define DEFAULT_LEVEL 38   /// OG: #define DEFAULT_LEVEL 50 



/*  /// TS21 STEPPED RAMP FLOOR, CEIL, STEPS 

/// OG blf-q8-t1616/anduril.h: 

// 20 38 56 [75] 93 111 130
#define RAMP_DISCRETE_FLOOR  20
#define RAMP_DISCRETE_CEIL   130
#define RAMP_DISCRETE_STEPS  7



/// CALC_INTERVAL = (ceiling - floor) / (steps - 1) 

/// calc and/or tested: 
///   STEPPED RAMP FLOOR, CEIL, STEPS 
///   1  38  75  112   
///   1  38  75  112   149 
///   1  42  83  124 
///   1  43  85  127 
///   1  44  87  130 
///   1  45  89  133 



/// 5 steps : 
///   1  34  67  100  133 
///   1  33  65  97   129 
///   1  32  63  94   125 
///   1  31  61  91   121 


 */
///   1  38  75  112   
#define RAMP_DISCRETE_FLOOR  1
#define RAMP_DISCRETE_CEIL   112
#define RAMP_DISCRETE_STEPS  4



/*  /// TS21 SMOOTH RAMP FLOOR AND CEIL 

/// OG blf-q8-t1616/anduril.h: 

#define RAMP_SMOOTH_FLOOR    1
#define RAMP_SMOOTH_CEIL     150


 */
#define RAMP_SMOOTH_FLOOR    1
#define RAMP_SMOOTH_CEIL     RAMP_DISCRETE_CEIL



/*  /// TS21 Simple UI FLOOR, CEIL, STEPS 

/// OG blf-q8-t1616/anduril.h: 

// at Sofirn's request, use max (150) for the Simple UI ceiling
#define SIMPLE_UI_FLOOR  1
#define SIMPLE_UI_CEIL   150
#define SIMPLE_UI_STEPS  5


 */
/// SIMPLE_UI is disabled





/*  /// 

 */

/*  /// 

 */

/*  /// 

 */



// The button lights up
#define USE_INDICATOR_LED
#define USE_INDICATOR_LED_WHILE_RAMPING


/*  /// EXTENDED_INDICATOR_PATTERNS

/// NEW MOD. more-aux-patterns. by SammysHP

/// "Works for classic and RGB aux LEDs."

/// PATTERNS:
    // low nibble:  off state
    // high nibble: lockout state
    // modes are:
    //   0=off
    //   1=low
    //   2=high
    //   3=fancy blinking
    //   4=low blinking
    //   5=high blinking 



#define USE_EXTENDED_INDICATOR_PATTERNS

/// LOCKOUT= 1=low .  OFF-MODE= 4=low blinking 
#define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 4)

 */ 
#define USE_EXTENDED_INDICATOR_PATTERNS
/// LOCKOUT= 1=low .  OFF-MODE= 5=high blinking    ///low blinking is too dim  
#define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 5)


// voltage readings were a little high with the Q8 value
#undef VOLTAGE_FUDGE_FACTOR
#define VOLTAGE_FUDGE_FACTOR 5  // add 0.25V, not 0.35V


/* /// throttle back faster when high
///   from   "sp36-t1616/anduril.h" :
///   stop panicking at ~60% power ...  


/// blf-q8-t1616:
// stop panicking at ~75% power or ~3000 lm, this light has high thermal mass
#define THERM_FASTER_LEVEL (RAMP_SIZE*9/10)  // throttle back faster when high

 */
#define THERM_FASTER_LEVEL 130


/*  /// DEFAULT_BLINK_CHANNEL   

///   from OG blf-q8-t1616/anduril.h:
// blink numbers on the aux LEDs by default
#define DEFAULT_BLINK_CHANNEL  CM_AUX

/// CM_AUX is too dim in TS21. Lets change it to CM_MAIN

 */
#define DEFAULT_BLINK_CHANNEL  CM_MAIN   /// CM_AUX is too dim in TS21   /// blink channel can be changed at run-time



/*  /// 

 */



/* /////    BLINKIES AND STROBES     /////  
///  from `config-default.h` : 

#define USE_SOS_MODE
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


#undef USE_FIREWORK_MODE
#undef USE_LIGHTHOUSE_MODE

 */
#undef USE_LIGHTNING_MODE
#undef USE_CANDLE_MODE
#undef USE_BAD_FLUORESCENT_MODE



/*  /// "VER_CHECK_MODE" in the blinky group  
 * idea: "version-check"  in the blinky group? 
 * tested on the SC31 Pro t1616 
   additional line in the "sofirn/sc31-pro-t1616/anduril.h" :  
     #define USE_VER_CHECK_MODE		
 * additional lines in the "battcheck-mode.c" : 
     #elif defined(USE_VER_CHECK_MODE)
     set_state(ver_check_state, 0);
 */
/*  /// "USE_VER_CHECK_MODE" 
 * in "config-default.h" , for reference: 
     "include a function to blink out the firmware version" 
     "#define USE_VERSION_CHECK"

 * sc31-pro-t1616: "USE_VER_CHECK_MODE" 
 */
#define USE_VER_CHECK_MODE


/* /// DEFAULT_DONT_RAMP_AFTER_MOON
/// some settings are applied per flashlight  
/// adjusted for each flashlight 
/// tested on the  sc31-pro-t1616 
/// 1H = floor (moon). stay at moon, don't ramp up 
 */
#define DEFAULT_DONT_RAMP_AFTER_MOON 1


/* /// DEFAULT MANUAL MEMORY  
///   stepped ramp:   1   38  75  112   
 */
#define DEFAULT_MANUAL_MEMORY 38



/* /// TACTICAL MODE LEVELS

///   1H,  2H , 3H : 
///   HIGH , TACTICAL STROBE , LOW  
///     150 = turbo
///     (RAMP_SIZE+1) = party strobe
///     (RAMP_SIZE+2) = tactical strobe
///     (RAMP_SIZE+3) = bike flasher  


///example:
#define TACTICAL_LEVELS 129,(RAMP_SIZE+2),DEFAULT_MANUAL_MEMORY
#define TACTICAL_LEVELS 130,(RAMP_SIZE+2),DEFAULT_MANUAL_MEMORY
#define TACTICAL_LEVELS RAMP_DISCRETE_CEIL,(RAMP_SIZE+2),DEFAULT_MANUAL_MEMORY


 */
#define TACTICAL_LEVELS RAMP_DISCRETE_CEIL,(RAMP_SIZE+2),DEFAULT_MANUAL_MEMORY



/* /// MORE MODS ? ..

#undef USE_RAMP_SPEED_CONFIG
#undef USE_RAMP_AFTER_MOON_CONFIG
#undef USE_2C_STYLE_CONFIG


#undef USE_POLICE_STROBE_MODE
#undef USE_CHANNEL_PER_STROBE

#undef USE_TACTICAL_MODE

#undef USE_SUNSET_TIMER

 */
#undef USE_SIMPLE_UI



///   ///   ///   ///   ///   ///   ///



/*  /// 

 */



/// wurkkos-ts21/anduril.h 



///   END   


