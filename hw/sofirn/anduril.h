/// sofirn/anduril.h 
/// fav config for all Sofirn units
/// a copy of wurkkos--anduril.h , 
/// plus tons of edits 


// Sofirn config options for Anduril
// Copyright (C) 2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later


#pragma once


/*  /// 

 */


/*  /// USE_SIMPLE_UI, etc. etc. 

/// "USE_SIMPLE_UI" is defined in the  "anduril/config-default.h" 
// Include a simplified UI for non-enthusiasts?"
#define USE_SIMPLE_UI


/// from "wurkkos/anduril.h" : 
// allow Aux Config and Strobe Modes in Simple UI 
#define USE_EXTENDED_SIMPLE_UI

// Allow 3C in Simple UI for switching between smooth and stepped ramping  
#define USE_SIMPLE_UI_RAMPING_TOGGLE

 */
#define USE_EXTENDED_SIMPLE_UI
#define USE_SIMPLE_UI_RAMPING_TOGGLE


/*  /// don't default to Simple UI 
/// from old "cfg-0631-sp10p-071.h" 
#undef SIMPLE_UI_ACTIVE
#define SIMPLE_UI_ACTIVE 0

 */
#undef SIMPLE_UI_ACTIVE
#define SIMPLE_UI_ACTIVE 0



/*  /// DEFAULT_2C_STYLE  2C = turbo
/// 0 = no turbo
/// 1 = A1 style: Off 2C = ceil, On 2C = turbo
/// 2 = A2 style: Off 2C = ceil, On 2C = ceil,
///                     Ramped ceil 2C = turbo 
#define DEFAULT_2C_STYLE 1  // Anduril 1 style


/// in the user manual this setting is a part of 
/// Ramp Extra Config.
/// ON, 10H = Ramp Extra Config

 */
#define DEFAULT_2C_STYLE 1  // Anduril 1 style


/*  /// set the default ramp style to Stepped 
/// from "sp10-pro/anduril.h" :
// ... set the default ramp style to Stepped
#undef RAMP_STYLE
#define RAMP_STYLE 1  // 0 = smooth, 1 = stepped


/// ramp style can be changed at runtime,
/// ON, 3C  or  ON, 6C 

 */
#undef RAMP_STYLE
#define RAMP_STYLE 1  // 0 = smooth, 1 = stepped


/*  /// #define USE_RAMP_CONFIG

/// the ramps configurability is listed in the 
/// "anduril/config-default.h" : 
/// #define USE_RAMP_CONFIG

 */


/*  /// USE_SOFT_FACTORY_RESET 

/// "USE_FACTORY_RESET" is defined in the  "anduril/config-default.h" . 


/// "SOFT FACTORY RESET" : 
/// OFF, 13H = factory reset without loosening tailcap
/// only really needed on TS10, but doesn't hurt on other models
#define USE_SOFT_FACTORY_RESET

 */
#define USE_SOFT_FACTORY_RESET


/*  /// undef BLINK_AT_RAMP
/// (The OG default is in the "anduril/config-default.h") 

/// from "sp10-pro/anduril.h" :
// don't blink during the ramp or at the ceiling
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif
#ifdef BLINK_AT_RAMP_CEIL
#undef BLINK_AT_RAMP_CEIL
#endif

 */
#undef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_CEIL


/*  /// AUTO_REVERSE_TIME = 1 
/// AUTO_REVERSE_TIME timed out in 1 tick
/// effect: 1H= ramp up, no AUTO_REVERSE to ramp down. 2H= ramp down

#undef AUTO_REVERSE_TIME
#define AUTO_REVERSE_TIME 1

 */
#undef AUTO_REVERSE_TIME
#define AUTO_REVERSE_TIME 1


/*  /// MANUAL_MEMORY, MANUAL_MEMORY_TIMER, DEFAULT_MANUAL_MEMORY 

/// "USE_MANUAL_MEMORY"  and  "USE_MANUAL_MEMORY_TIMER" are
/// defined in the  "anduril/config-default.h" : 
#define USE_MANUAL_MEMORY
#define USE_MANUAL_MEMORY_TIMER


/// The DEFAULT brightness LEVEL  is set individually in each 
    flashlight's "anduril.h" file, e.g.: 
#define DEFAULT_MANUAL_MEMORY 45



/// "anduril/ramp-mode.c", "USE_MANUAL_MEMORY" : 
// turn on manual memory and save current brightness

/// Mod., use 5C instead of 10C
/// correlated mod. in "anduril/ramp-mode.c" : 
#ifdef USE_MANUAL_MEMORY
 ... (event == EV_5clicks) 

/// ALWAYS use MANUAL_MEMORY : 
#undef DEFAULT_MANUAL_MEMORY_TIMER
#define DEFAULT_MANUAL_MEMORY_TIMER 0

 */
#undef DEFAULT_MANUAL_MEMORY_TIMER
#define DEFAULT_MANUAL_MEMORY_TIMER 0


/*  /// SIMPLE BATTCHECK MODE, DISABLE POVD 

/// SIMPLE BATTCHECK MODE, no extra digit  
#undef USE_EXTRA_BATTCHECK_DIGIT

/// DISABLE POVD ? 
///  "battcheck-mode-fsm.h" :
///    // show voltage colors for a few seconds after going to standby
///    #define USE_POST_OFF_VOLTAGE
#undef USE_POST_OFF_VOLTAGE

 */
#undef USE_EXTRA_BATTCHECK_DIGIT
#undef USE_POST_OFF_VOLTAGE


/*  /// 

 */


/*  /// BLINKIES AND STROBES 
=====   =====   =====   =====   =====

/// ToyKeeper  "anduril/config-default.h" : 

// enable beacon mode
#define USE_BEACON_MODE

// enable various strobe modes
#define USE_BIKE_FLASHER_MODE
#define USE_PARTY_STROBE_MODE
#define USE_TACTICAL_STROBE_MODE
#define USE_LIGHTNING_MODE
#define USE_CANDLE_MODE


=====   =====   =====   =====   =====


/// starryalley  "anduril/config-default.h" :

// enable beacon mode
#define USE_BEACON_MODE

// enable various strobe modes
#define USE_BIKE_FLASHER_MODE
#define USE_PARTY_STROBE_MODE
#define USE_TACTICAL_STROBE_MODE
#define USE_LIGHTNING_MODE
#define USE_CANDLE_MODE

#define USE_FIREWORK_MODE
#define USE_LIGHTHOUSE_MODE
#define USE_BAD_FLUORESCENT_MODE


=====   =====   =====   =====   =====


/// weird strobes ???
/// #define USE_POLICE_COLOR_STROBE_MODE
/// #define USE_POLICE_STROBE_MODE


=====   =====   =====   =====   =====


///   ENABLE ADDITIONAL STROBE MODES
#define USE_FIREWORK_MODE
#define USE_LIGHTHOUSE_MODE
#define USE_BAD_FLUORESCENT_MODE

 */
/// ENABLE ADDITIONAL STROBES
#define USE_FIREWORK_MODE
#define USE_LIGHTHOUSE_MODE
#define USE_BAD_FLUORESCENT_MODE


/*  /// USE_TACTICAL_MODE, DISABLE MOMENTARY_MODE 

/// DISABLE MOMENTARY_MODE 
#undef USE_MOMENTARY_MODE



/// TACTICAL_MODE is defined in the "anduril/config-default.h" : 
// enable tactical mode
#define USE_TACTICAL_MODE

/// DISABLE TACTICAL_MODE ? 
#undef USE_TACTICAL_MODE

 */
#undef USE_MOMENTARY_MODE


/*  /// 

 */


/*  /// INDICATOR_LED, EXTENDED_INDICATOR_PATTERNS, etc. 

/// in the "aux-leds.h" : 
  . "USE_INDICATOR_LED" 
    "USE_INDICATOR_LED_WHILE_RAMPING" 
    "INDICATOR_LED_DEFAULT_MODE" . . . 


// "USE_INDICATOR_LED". The button lights up
#define USE_INDICATOR_LED

/// button LED is ON while main LED is ON 
#define USE_INDICATOR_LED_WHILE_RAMPING


=====   =====   =====   =====   =====


/// EXTENDED_INDICATOR_PATTERNS

/// NEW MOD. more-aux-patterns. by SammysHP
/// using replacement files from SammysHP : 
/// "anduril/aux-leds.c"  and  "anduril/aux-leds.h" ,
/// also  "off-mode.c"  and  "lockout-mode.c" ! 
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

/// LOCKOUT: low (1)      OFF MODE: low blinking (4) 
#undef INDICATOR_LED_DEFAULT_MODE
#define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 4)

 */

#define USE_INDICATOR_LED
#define USE_INDICATOR_LED_WHILE_RAMPING
#define USE_EXTENDED_INDICATOR_PATTERNS

/// LOCKOUT: low (1)      OFF MODE: low blinking (4) 
#undef INDICATOR_LED_DEFAULT_MODE
#define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 4)


/*  /// 

 */


/*  /// AUTOLOCK 
/// config-default.h  Line 178 

// add an optional setting to lock the light after being off for a while
#define USE_AUTOLOCK

/// Mod.: #undef USE_AUTOLOCK

 */
#undef USE_AUTOLOCK








///   ///   ///   ///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///   ///   ///   ///

///   ///   ///   ///   ///   ///   ///   ///   ///   ///



/*  /// 

 */

/*  /// 

 */

/*  /// 

 */



/// sofirn--anduril.h  



///   END   


