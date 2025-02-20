/// wurkkos/ts25/anduril.h  


// Wurkkos TS25, modelled after the TS10 but with RGB Aux
// Copyright (C) 2022-2023 (FIXME)
// SPDX-License-Identifier: GPL-3.0-or-later


#pragma once


/// //#include "wurkkos/ts25/hwdef.h"
/// #define HWDEF_H  wurkkos/ts25/hwdef.h
#include "wurkkos/ts25/hwdef.h"


#include "wurkkos/anduril.h"


/*  /// 

 */


/*  /// RAMP_SIZE, PWM_LEVELS
/// position this RAMP_SIZE and PWM_LEVELS etc. at the top of this config file ...
/// this is kinda fixed config, not customisable 
 */
#define RAMP_SIZE 150


#if 0  // 2022 version
// level 1 by hand, for the rest
// level_calc.py 7.01 2 149 7135 3 0.5 125 FET 1 10 1200 --pwm dyn:63:2048:255
#define PWM1_LEVELS 1,3,3,4,5,6,7,8,9,10,12,13,14,16,17,19,20,22,24,25,27,29,31,33,35,37,40,42,44,47,49,52,54,57,59,62,64,67,70,72,75,77,80,82,85,87,89,91,93,95,96,98,99,100,100,101,100,100,99,97,95,93,90,86,82,87,91,96,100,106,111,116,122,128,134,141,147,155,162,169,177,186,194,203,213,222,232,243,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0
#define PWM2_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,4,6,7,9,11,12,14,16,18,20,22,24,27,29,31,34,37,39,42,45,48,51,54,57,61,64,68,72,75,79,83,88,92,97,101,106,111,116,121,126,132,138,144,150,156,162,169,176,183,190,197,205,213,221,229,237,246,255
#define PWM_TOPS 2047,2047,1198,1322,1584,1676,1701,1691,1662,1622,1774,1703,1631,1692,1613,1639,1558,1564,1559,1478,1464,1444,1420,1392,1361,1329,1331,1293,1256,1246,1207,1192,1152,1133,1094,1074,1035,1013,991,954,932,897,875,842,820,790,760,731,704,678,646,622,593,566,534,510,478,452,423,393,364,338,310,280,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
#define MAX_1x7135 90
#define HALFSPEED_LEVEL 2
#define QUARTERSPEED_LEVEL 2
#endif



/*  /// 

 */



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

#define MIN_THERM_STEPDOWN 60

#define HALFSPEED_LEVEL 20
#define QUARTERSPEED_LEVEL 5



#define DEFAULT_LEVEL 31   /// OG: #define DEFAULT_LEVEL 50 



/*  /// TS25 STEPPED RAMP FLOOR, CEIL, STEPS 



/// OG blf-q8-t1616/anduril.h: 
// 20 38 56 [75] 93 111 130
#define RAMP_DISCRETE_FLOOR  20
#define RAMP_DISCRETE_CEIL   130
#define RAMP_DISCRETE_STEPS  7



/// OG ts25/anduril.h: 
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
///   1  31  61  91   121 
#define RAMP_DISCRETE_FLOOR  1
#define RAMP_DISCRETE_CEIL   121
#define RAMP_DISCRETE_STEPS  5



/*  /// TS25 SMOOTH RAMP FLOOR AND CEIL 

/// OG ts25/anduril.h: 

#define RAMP_SMOOTH_FLOOR    1
#define RAMP_SMOOTH_CEIL     150


 */
#define RAMP_SMOOTH_FLOOR    1
#define RAMP_SMOOTH_CEIL     RAMP_DISCRETE_CEIL



/*  /// TS25 Simple UI FLOOR, CEIL, STEPS 

/// OG ts25/anduril.h: 

// at Wurkkos's request, reduce the Simple UI ceiling a little bit
// 25 50 [75] 100 125
#define SIMPLE_UI_FLOOR  25
#define SIMPLE_UI_CEIL   125
#define SIMPLE_UI_STEPS  5


/// 
#define SIMPLE_UI_FLOOR  1
#define SIMPLE_UI_CEIL   RAMP_DISCRETE_CEIL
#define SIMPLE_UI_STEPS  5


 */
/// SIMPLE_UI is disabled





/*  /// 

 */

/*  /// 

 */

/*  /// 

 */



/*  /// INDICATOR_LED, AUX_RGB_LEDS R, G, B


/// OG Wurkkos TS25 anduril.h:     /// RGB-AUX in the front 
// Wurkkos TS25, modelled after the TS10 but with RGB Aux

// this light has three aux LED channels: R, G, B
#define USE_AUX_RGB_LEDS

// don't turn on the aux LEDs while main LEDs are on
#ifdef USE_INDICATOR_LED_WHILE_RAMPING
#undef USE_INDICATOR_LED_WHILE_RAMPING
#endif





/// OG Wurkkos TS10-RGB-AUX anduril.h:     /// RGB-AUX in th front 
// Wurkkos TS10 (RGB aux version) config options for Anduril

// most things are the same as TS25

// this light has three aux LED channels: R, G, B
#define USE_AUX_RGB_LEDS

// don't turn on the aux LEDs while main LEDs are on
#ifdef USE_INDICATOR_LED_WHILE_RAMPING
#undef USE_INDICATOR_LED_WHILE_RAMPING
#endif





// OG Wurkkos TS11 anduril.h: 
// Wurkkos TS11, like a TS25  but with a RGB button and RGB front aux

// this light has three aux LED channels: R, G, B
#define USE_AUX_RGB_LEDS

// turn on the aux LEDs while main LEDs are on
// (but not until the main LEDs are bright enough to overpower the aux)
// (setting this lower makes an annoying effect on some levels)
#define USE_AUX_RGB_LEDS_WHILE_ON  50
#define USE_INDICATOR_LED_WHILE_RAMPING





/// OG Wurkkos FC13 anduril.h: 
// Wurkkos FC13, like a TS25 but with a RGB button and no front aux

// this light has three aux LED channels: R, G, B
#define USE_AUX_RGB_LEDS

// turn on the aux LEDs while main LEDs are on
#define USE_AUX_RGB_LEDS_WHILE_ON  20
#define USE_INDICATOR_LED_WHILE_RAMPING


 */
#define USE_AUX_RGB_LEDS



// don't turn on the aux LEDs while main LEDs are on
#ifdef USE_INDICATOR_LED_WHILE_RAMPING
#undef USE_INDICATOR_LED_WHILE_RAMPING
#endif



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



///   ///   ///   ///   ///   ///   ///



/// INDICATOR_LED_DEFAULT_MODE. LOCKOUT= 1 = low. OFF = 5 = blinking high 

/// LOCKOUT= 1=low .  OFF-MODE= 4=low blinking 
#define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 4)
   ///2025.01.30.. tested on TS25: NOT OK, ACTUAL DEFAULT: /// LOCKOUT= 3=fancy blinking .  OFF-MODE=  low (1)  
   /// whats the default color? BLUE? 

/// This line only Works for classic (non-RGB aux LEDs) ?
/// LOCKOUT= 1=low .  OFF-MODE= 4=low blinking 
/// #define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 4)

/// This line only Works for classic (non-RGB aux LEDs) ?
/// #define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 5)

 */ 
#define USE_EXTENDED_INDICATOR_PATTERNS



/*  /// AUX_RGB_LED_DEFAULT PATTERN and COLOR 

/// aux-leds.h : 

 * 0: R
 * 1: RG
 * 2:  G
 * 3:  GB
 * 4:   B
 * 5: R B
 * 6: RGB
 * 7: rainbow
 * 8: voltage



#ifndef RGB_LED_OFF_DEFAULT
#define RGB_LED_OFF_DEFAULT 0x19  // low, voltage

//#define RGB_LED_OFF_DEFAULT 0x18  // low, rainbow

#endif



#ifndef RGB_LED_LOCKOUT_DEFAULT
#define RGB_LED_LOCKOUT_DEFAULT 0x39  // blinking, voltage

//#define RGB_LED_LOCKOUT_DEFAULT 0x37  // blinking, disco

#endif


///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///




/// 1= ? 
/// 2= ? 
/// 3= ? 
/// 4= ? 
/// 5= ? 
/// 6= ? 
/// 7= disco 
/// 8= rainbow 
/// 9= voltage 



///   ///   ///   ///   ///   ///   ///



https://www.reddit.com/r/flashlight/comments/sxr1wu/help_with_modifying_anduril_2_hardcoding_default/


Getkong

3y ago

I think high red is probably 0x20 or 0x21. The order is defined on lines 30-40 in a comment, and you can back your way into each one based one what’s already there.

https://github.com/mkong1/anduril/pull/17/files is where I changed my defaults to high voltage for off, low voltage for locked.




///   ///   ///   ///   ///   ///   ///




zumlin
OP

So before I start doing some trial and error. Do you think that the first digit after 0x defines the pattern, where

1 = low 2 = high 3 = blinking

and the second digit defines the colour from 1 to 9?




///   ///   ///   ///   ///   ///   ///




zumlin
OP


After some trial and error, I can confirm that the codes for the aux leds' colours and patterns are as follows:


0x00 = off	Low	High	Blinking
R	0x10	0x20	0x30
R+G	0x11	0x21	0x31
G	0x12	0x22	0x32
G+B	0x13	0x23	0x33
B	0x14	0x24	0x34
R+B	0x15	0x25	0x35
R+G+B	0x16	0x26	0x36
Disco	0x17	0x27	0x37
Rainbow	0x18	0x28	0x38
Voltage	0x19	0x29	0x39



///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///



0x00 = OFF 
0x1* = low
0x2* = high 
0x3* = blinking  (fancy blinking) 
0x4* = blinking low ? 
0x5* = blinking high? 


Last digit : 
0 = R
1 = R+G
2 = G
3 = G+B
4 = B
5 = R+B
6 = R+G+B

/// 7= disco 
/// 8= rainbow 
/// 9= voltage 


///   ///   ///   ///   ///   ///   ///


/// 2025.02.01.. new mods: 

#define RGB_LED_OFF_DEFAULT 0x54   /// blinking high, blue 

#define RGB_LED_LOCKOUT_DEFAULT 0x14   /// low, blue 

/// 0x54 = blinking high, blue 
/// 0x14 = low, blue 


/// yup, 2025.02.01 tested on TS25: OK, RGB_LED_DEFAULT PATTERN and COLOR work as intended 

 */
#define RGB_LED_LOCKOUT_DEFAULT 0x14   /// LOCKOUT = 0x14 = low, blue 
#define RGB_LED_OFF_DEFAULT 0x54   /// OFF = 0x54 = blinking high, blue 








// voltage readings were a little high with the Q8 value
#undef VOLTAGE_FUDGE_FACTOR
#define VOLTAGE_FUDGE_FACTOR 5  // add 0.25V, not 0.35V


// stop panicking at ~50% power
#define THERM_FASTER_LEVEL 120  // throttle back faster when high


// show each channel while it scroll by in the menu
#define USE_CONFIG_COLORS



/*  /// DEFAULT_BLINK_CHANNEL 

/// OG TS25:

// blink numbers on the main LEDs by default
// (so battcheck will be visible while charging)
#define DEFAULT_BLINK_CHANNEL  CM_MAIN
// blink numbers on the aux LEDs by default
//#define DEFAULT_BLINK_CHANNEL  CM_AUXWHT

 */
#define DEFAULT_BLINK_CHANNEL  CM_AUXRED



// use aux red + aux blue for police strobe
#define USE_POLICE_COLOR_STROBE_MODE
#define POLICE_STROBE_USES_AUX
#define POLICE_COLOR_STROBE_CH1        CM_AUXRED
#define POLICE_COLOR_STROBE_CH2        CM_AUXBLU



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

#undef USE_SOS_MODE
#undef USE_BEACON_MODE

 */
#undef USE_SOS_MODE



/* /// DISABLE SOME STROBES ? 
#undef USE_BIKE_FLASHER_MODE
#undef USE_PARTY_STROBE_MODE
#undef USE_TACTICAL_STROBE_MODE

#undef USE_LIGHTNING_MODE


#undef USE_BAD_FLUORESCENT_MODE
#undef USE_FIREWORK_MODE
#undef USE_LIGHTHOUSE_MODE

 */

#undef USE_CANDLE_MODE




/// 2025-02-10: #define USE_BEACONN_MODE
/*  /// 2025-02-09: BEACONN_MODE in STROBE_GROUP 


/// 2025-02-07: BMISG
/// BEACON_MODE_ISG
/// USE_BEACON_MODE_IN_STROBE_GROUP 
/// #define USE_BEACON_MISG


/// 2025-02-09: BMISG
/// BEACON-MISG
/// USE_BEACON_MODE_ISG 
/// #define USE_BEACON_MODE_ISG
#define USE_BEACON_MODE_ISG


/// 2025-02-11: BEACONN_MODE
/// config integrated into strobe-modes files
/// works very well
/// 1H timing / interval adjustment works very well
#define USE_BEACONN_MODE


 */
#define USE_BEACONN_MODE





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
///   stepped ramp:   1  31  61  91   121 

 */
#define DEFAULT_MANUAL_MEMORY 31


/* /// TACTICAL MODE LEVELS

///   1H,  2H , 3H : 
///   HIGH , TACTICAL STROBE , LOW  
///     150 = turbo
///     (RAMP_SIZE+1) = party strobe
///     (RAMP_SIZE+2) = tactical strobe
///     (RAMP_SIZE+3) = bike flasher  


///example:
#define TACTICAL_LEVELS 129,(RAMP_SIZE+2),DEFAULT_MANUAL_MEMORY
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



/// wurkkos-ts25/anduril.h  



///   END   


