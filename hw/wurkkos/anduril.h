/// wurkkos/anduril.h 
/// fav config for all Wurkkos units
/// OG Wurkkos' anduril.h ,  plus tons of edits 


// Wurkkos config options for Anduril
// Copyright (C) 2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later


#pragma once


/*  /// OG Wurkkos' anduril.h 

// Wurkkos config options for Anduril
// Copyright (C) 2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// allow Aux Config and Strobe Modes in Simple UI
#define USE_EXTENDED_SIMPLE_UI

// Allow 3C in Simple UI for switching between smooth and stepped ramping
#define USE_SIMPLE_UI_RAMPING_TOGGLE

// enable 2 click turbo (Anduril 1 style)
#define DEFAULT_2C_STYLE 1

// enable SOS in the blinkies group
#define USE_SOS_MODE
#define USE_SOS_MODE_IN_BLINKY_GROUP

// enable factory reset on 13H without loosening tailcap
// only really needed on TS10, but doesn't hurt on other models
#define USE_SOFT_FACTORY_RESET

// higher temperature limit because attiny1616 is more accurate
#undef DEFAULT_THERM_CEIL
#define DEFAULT_THERM_CEIL 50

 */


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


/*  /// USE_SOFT_FACTORY_RESET 

/// "USE_FACTORY_RESET" is defined in the  "anduril/config-default.h" . 


/// "SOFT FACTORY RESET" : 
/// OFF, 13H = factory reset without loosening tailcap
/// only really needed on TS10, but doesn't hurt on other models
#define USE_SOFT_FACTORY_RESET

 */
#define USE_SOFT_FACTORY_RESET


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



///   from old cfg file of sc21-pro:  
///    "don't blink during the ramp or at the ceiling" 
///   (The OG default is in the  "anduril/config-default.h") 


///   from OG blf-q8-t1616/anduril.h:
// don't blink during the ramp; the button LED brightness is sufficient
// to indicate which power channel(s) are being used
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
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



/*  /// SIMPLE BATTCHECK MODE 

/// config-default.h : 
#if ROM_SIZE > 10000
    // battcheck displays 1.25V instead of 1.2V
    #define USE_EXTRA_BATTCHECK_DIGIT
#endif


/// SIMPLE BATTCHECK MODE, no extra digit : 
#undef USE_EXTRA_BATTCHECK_DIGIT


 */
#undef USE_EXTRA_BATTCHECK_DIGIT   ///2025.01.30.. tested on TS25: OK



/*  /// DISABLE POVD 

/// DISABLE POVD ? 

/// battcheck-mode-fsm.h:  

// battcheck-mode-fsm.h: FSM config for battery check mode in Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define USE_BATTCHECK

#ifdef USE_AUX_RGB_LEDS

    // show voltage colors for a few seconds after going to standby
    #define USE_POST_OFF_VOLTAGE

    #ifndef DEFAULT_POST_OFF_VOLTAGE_SECONDS

        #define DEFAULT_POST_OFF_VOLTAGE_SECONDS  4
    #endif



=====   =====   =====   =====   =====   =====   =====



#undef USE_POST_OFF_VOLTAGE   /// tested on TS25: NOT WORK? POVD still active?
/// tested on TS25: NOT WORK? POVD still active? Why this doesn't work? Maybe it should be moved to target config file, after "#define USE_AUX_RGB_LEDS". Maybe? Maybe not ..



=====   =====   =====   =====   =====   =====   =====



/// a potential correction :

#define DEFAULT_POST_OFF_VOLTAGE_SECONDS  0

/// yup, I think that's gonna work, to disable POVD 
/// yup, 2025.02.01 tested on TS25: OK, no more POVD 

 */
#define DEFAULT_POST_OFF_VOLTAGE_SECONDS  0



/*  /// 

 */


/*  /// BLINKIES AND STROBES 
=====   =====   =====   =====   =====

/// ToyKeeper  "anduril/config-default.h" : 

#define USE_SOS_MODE

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


/// ts25/anduril.h:
// use aux red + aux blue for police strobe
#define USE_POLICE_COLOR_STROBE_MODE


=====   =====   =====   =====   =====


///   ENABLE ADDITIONAL STROBE MODES
#define USE_FIREWORK_MODE
#define USE_LIGHTHOUSE_MODE
#define USE_BAD_FLUORESCENT_MODE


/// strobe modes can be disabled in each build target, 
/// as needed/preferred 

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


/*  /// Wurkkos DEFAULT_THERMAL_CEILING 50 
/// all wurkkos anduril units use attiny1616  

// higher temperature limit because attiny1616 is more accurate
#undef DEFAULT_THERM_CEIL
#define DEFAULT_THERM_CEIL 50

 */
#undef DEFAULT_THERM_CEIL
#define DEFAULT_THERM_CEIL 50


/*  /// AUTOLOCK 
/// config-default.h  Line 178 

// add an optional setting to lock the light after being off for a while
#define USE_AUTOLOCK

 */
#undef USE_AUTOLOCK



/// FIXME: FIXED: move this config to each build target, adjust per each build target.
/// DO NOT ENABLE THIS CONFIG IN THIS GLOBAL CONFIG FILE
/*  /// INDICATOR_LED, EXTENDED_INDICATOR_PATTERNS, etc. 

=====   =====   =====   =====   =====


/// 2025.01.28.  
/// targets with rgb LEDS:  "ERROR: build failed" 
/// this line dont work as a global config,
/// this must be applied only for the compatible target,
///  i.e. : ts10, ts21  

#define USE_INDICATOR_LED


=====   =====   =====   =====   =====


/// DO NOT ENABLE THIS CONFIG IN THIS GLOBAL CONFIG FILE,  ERROR for aux RGB targets :
// #define USE_INDICATOR_LED

/// THIS ONE SEEMS OK BUT IT'S BETTER TO BE APPLIED PER BUILD TARGEET, NOT GLOBALLY :
// #define USE_INDICATOR_LED_WHILE_RAMPING


=====   =====   =====   =====   =====


/// in the "aux-leds.h" : 
  . "USE_INDICATOR_LED" 
    "USE_INDICATOR_LED_WHILE_RAMPING" 
    "INDICATOR_LED_DEFAULT_MODE" . . . 


=====   =====   =====   =====   =====


/// targets with rgb LEDS have different config:



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



=====   =====   =====   =====   =====


for target with single aux led, e.g. sigle color button LED, 
 e.g.: sc31-pro, ts10, ts21  :
#define USE_INDICATOR_LED



for target with three aux LED channels: R, G, B, 
 e.g.: FC13, TS10-RGBAUX, TS25:
#define USE_AUX_RGB_LEDS


=====   =====   =====   =====   =====

=====   =====   =====   =====   =====

=====   =====   =====   =====   =====


/// EXTENDED_INDICATOR_PATTERNS

/// NEW MOD. more-aux-patterns. by SammysHP

/// "Works for classic and RGB aux LEDs."

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

/// LOCKOUT: low (1) .  OFF-MODE: low blinking (4) 
#define INDICATOR_LED_DEFAULT_MODE ((1<<INDICATOR_LED_CFG_OFFSET) + 4)

 */ 








///   ///   ///   ///   ///   ///   ///   ///   ///   ///



/*  /// 

 */



/// wurkkos/anduril.h 



///   END   


