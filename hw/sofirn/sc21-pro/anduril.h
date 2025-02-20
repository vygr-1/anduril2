/// "sofirn/sc21-pro/anduril.h"

// Sofirn SC21 Pro - same setup as a Wurkkos TS10, but with the aux indicator on while ramping

// Copyright (C) 2022-2023 (FIXME)
// SPDX-License-Identifier: GPL-3.0-or-later


/*   // Wurkkos TS10   
// Wurkkos TS10 (originally used Sofirn SP36-t1616 firmware) config options for Anduril using the Attiny1616
// Copyright (C) 2022-2023 (FIXME)
// SPDX-License-Identifier: GPL-3.0-or-later
 */


/*   /// BLANK   

 */


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   


#pragma once


#include "sofirn/sc21-pro/hwdef.h"


#include "sofirn/anduril.h"


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   


/// Sofirn SC21 Pro   ///   uses button aux LEDs
#define USE_INDICATOR_LED


/// Sofirn SC21 Pro   // turn on the aux LED while main LED is on
#ifndef USE_INDICATOR_LED_WHILE_RAMPING
#define USE_INDICATOR_LED_WHILE_RAMPING
#endif



/*  /// SC31 Pro   /// INDICATOR LED PATTERNS
///   NEW MOD. more-aux-patterns by SammysHP
///   using replacement files from SammysHP : 
///   "anduril/aux-leds.c"  and  "anduril/aux-leds.h" ,
///   also  "anduril/off-mode.c" 
///   and  "anduril/lockout-mode.c" ! 
 */
#define USE_EXTENDED_INDICATOR_PATTERNS


/*  /// INDICATOR_LED   /// LOCKOUT: low (1)   /// OFF MODE: low blinking (4)  
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



/*  /// DEFAULT_BLINK_CHANNEL   /// blink numbers on the aux LEDs by default

///   from OG "blf-q8-t1616/anduril.h" :

// blink numbers on the aux LEDs by default
#define DEFAULT_BLINK_CHANNEL  CM_AUX

 */
#define DEFAULT_BLINK_CHANNEL  CM_AUX   /// blink channel can be changed later at run-time



/*  /// #undef BLINK_AT_RAMP
///   from old cfg file "cfg-0632-a-3f26g.h" :  
///    "don't blink during the ramp or at the ceiling" 
///   (The OG default is in the  "anduril/config-default.h") 
 */
#undef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_CEIL


/* /// DEFAULT_DONT_RAMP_AFTER_MOON
///  some settings are applied per flashlight  
///  moved this mod here from  "sofirn/anduril.h", applied and adjusted for each flashlight 
///  let's try this on the  sc31-pro-t1616  first 
///  1H = floor (moon) . stay at moon, don't ramp up 
 */
#define DEFAULT_DONT_RAMP_AFTER_MOON 1


// voltage readings were a little high with the Q8 value
#undef VOLTAGE_FUDGE_FACTOR
#define VOLTAGE_FUDGE_FACTOR 5  // add 0.25V, not 0.35V



///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   



/// copied from Wurkkos TS10   


#define RAMP_SIZE 150


#if 0  // 2022 version by SammysHP, smooth but only level 1/150 is underclocked


// level 1 by hand, for the rest
// level_calc.py 7.01 2 149 7135 3 0.5 125 FET 1 10 1200 --pwm dyn:63:2048:255


#define PWM1_LEVELS 1,3,3,4,5,6,7,8,9,10,12,13,14,16,17,19,20,22,24,25,27,29,31,33,35,37,40,42,44,47,49,52,54,57,59,62,64,67,70,72,75,77,80,82,85,87,89,91,93,95,96,98,99,100,100,101,100,100,99,97,95,93,90,86,82,87,91,96,100,106,111,116,122,128,134,141,147,155,162,169,177,186,194,203,213,222,232,243,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0


#define PWM2_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,4,6,7,9,11,12,14,16,18,20,22,24,27,29,31,34,37,39,42,45,48,51,54,57,61,64,68,72,75,79,83,88,92,97,101,106,111,116,121,126,132,138,144,150,156,162,169,176,183,190,197,205,213,221,229,237,246,255


#define PWM_TOPS 2047,2047,1198,1322,1584,1676,1701,1691,1662,1622,1774,1703,1631,1692,1613,1639,1558,1564,1559,1478,1464,1444,1420,1392,1361,1329,1331,1293,1256,1246,1207,1192,1152,1133,1094,1074,1035,1013,991,954,932,897,875,842,820,790,760,731,704,678,646,622,593,566,534,510,478,452,423,393,364,338,310,280,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255


#define MAX_1x7135 90

#define HALFSPEED_LEVEL 2

#define QUARTERSPEED_LEVEL 2

#endif



// 7135 at 90/150
// level_calc.py 5.7895 2 150 7135 0 0.1 125.25 FET 1 10 1200 --pwm dyn:61:4096:255:2.5 --clock 5:11:2.0
// (with heavy manual tweaks up to ~15/150)
#define PWM1_LEVELS     1,   1,   2,   2,   3,   3,   4,   5,   6,   6,   8,   9,   9,  10,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  19,  20,  21,  22,  23, 23, 24, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31, 32, 32, 33, 33, 34, 35, 36, 37, 38, 40, 41, 43, 45, 47, 50, 53, 56, 60, 63, 67, 71, 75, 79, 84, 89, 94, 99,104,110,116,122,129,136,143,150,158,166,174,183,192,202,211,222,232,243,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0


#define PWM2_LEVELS     0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  3,  5,  7,  8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 29, 31, 34, 37, 39, 42, 45, 48, 51, 54, 58, 61, 65, 68, 72, 76, 80, 84, 88, 93, 97,102,107,112,117,122,127,133,139,145,151,157,163,170,177,183,191,198,205,213,221,229,238,246,255


#define PWM_TOPS     4095,2893,3917,2806,3252,2703,2684,2660,2640,2370,3000,2900,2630,2549,2246,2193,2030,1961,1889,1716,1642,1569,1497,1428,1290,1232,1176,1122,1070,976,932,890,849,779,745,685,656,605,579,536,514,476,457,424,407,379,364,340,327,314,302,291,280,276,266,262,257,253,253,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255



#define MAX_1x7135 90

#define MIN_THERM_STEPDOWN 60

#define HALFSPEED_LEVEL 11

#define QUARTERSPEED_LEVEL 5

#define DEFAULT_LEVEL 50



#define RAMP_SMOOTH_FLOOR    1
#define RAMP_SMOOTH_CEIL     130


// 10 30 50 70 [90] 110 130
#define RAMP_DISCRETE_FLOOR  10
#define RAMP_DISCRETE_CEIL   130
#define RAMP_DISCRETE_STEPS  7



/*  /// TS10:

// at Wurkkos's request, reduce the Simple UI ceiling a little bit
// (i.e. not 150; original config had it at 144/150, or DD FET 204/255)
// 10 30 50 70 [90] 110 130

 */
#define SIMPLE_UI_FLOOR  10
#define SIMPLE_UI_CEIL   130
#define SIMPLE_UI_STEPS  7



///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   



/* /// DEFAULT MANUAL MEMORY  
/// adopted from sofirn--sc31-pro-t1616
///   stepped ramp :   1   38  75  112   
///   stepped ramp default level = 2/4 

OG TS10:
 * stepped ramp :   10 30 50 70 [90] 110 130
 */
#define DEFAULT_MANUAL_MEMORY 30



/*   /// BLANK   

 */



/// Wurkkos TS10   // stop panicking at ~50% power
#define THERM_FASTER_LEVEL 130  // throttle back faster when high


/// Wurkkos TS10   // show each channel while it scroll by in the menu
#define USE_CONFIG_COLORS


/// Wurkkos TS10   // the default of 26 looks a bit rough, so increase it to make it smoother
#define CANDLE_AMPLITUDE 33


/// Wurkkos TS10   // enable factory reset on 13H without loosening tailcap (required)
// #define USE_SOFT_FACTORY_RESET   /// defined in the  "sofirn--anduril.h" 


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   


/* /// TACTICAL MODE LEVELS
///   TACTICAL MODE LEVELS 
///   1H,  2H , 3H : 
///   HIGH , TACTICAL STROBE , LOW
///     150 = turbo
///     (RAMP_SIZE+1) = party strobe
///     (RAMP_SIZE+2) = tactical strobe

 */
#define TACTICAL_LEVELS 120,(RAMP_SIZE+2),30


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   



/* /////    BLINKIES AND STROBES     /////  
///  from `config-default.h` :  
// enable beacon mode
#define USE_BEACON_MODE

// enable various strobe modes
#define USE_BIKE_FLASHER_MODE
#define USE_PARTY_STROBE_MODE
#define USE_TACTICAL_STROBE_MODE

#define USE_LIGHTNING_MODE
#define USE_CANDLE_MODE


///  from  `sofirn--anduril.h` :  
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



///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   



/* /// more mods ?   :::  
#undef USE_RAMP_SPEED_CONFIG
#undef USE_RAMP_AFTER_MOON_CONFIG
#undef USE_2C_STYLE_CONFIG


#undef USE_SUNSET_TIMER


 */
#undef USE_SIMPLE_UI

#undef USE_POLICE_STROBE_MODE
#undef USE_CHANNEL_PER_STROBE



///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   

///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   

///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   



/*   /// BLANK   

 */



///   END   


