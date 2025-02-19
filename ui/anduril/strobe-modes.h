// strobe-modes.h: Strobe modes for Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later


#pragma once


///   ///   ///   ///   ///   ///   ///   ///   ///   ///


/*   /// 

 */


/*   /// starryalley Anduril2, New-repo. strobe-modes.h, 
/// no edit on the code, only EFC, adding new lines etc., for ease of reading
 */


///   ///   ///   ///   ///   ///   ///   ///   ///   ///



#ifdef USE_STROBE_STATE

strobe_mode_te current_strobe_type;



// which strobe mode is active?
/// #ifdef USE_CANDLE_MODE

#ifdef USE_BIKE_FLASHER_MODE

    #define DEFAULT_STROBE bike_flasher_e

#else
    #define DEFAULT_STROBE 0
#endif

#endif  // ifdef USE_STROBE_STATE



// full FET strobe can be a bit much...  use max regulated level instead,
// if there's a bright enough regulated level
#ifndef STROBE_BRIGHTNESS
#ifdef MAX_Nx7135
#define STROBE_BRIGHTNESS MAX_Nx7135
#else
#define STROBE_BRIGHTNESS MAX_LEVEL
#endif
#endif



// some drivers need to keep the regulator chip on between pulses,
// so set this to 1 to keep the light on at moon mode between pulses,
// and thus keep the regulator powered up for the next flash
#ifndef STROBE_OFF_LEVEL
#define STROBE_OFF_LEVEL 0
#endif



// party and tactical strobes
#ifdef USE_STROBE_STATE
uint8_t strobe_state(Event event, uint16_t arg);
inline void strobe_state_iter();
#endif



#if defined(USE_PARTY_STROBE_MODE) || defined(USE_TACTICAL_STROBE_MODE)
inline void party_tactical_strobe_mode_iter(uint8_t st);
#endif



#ifdef USE_POLICE_COLOR_STROBE_MODE
inline void police_color_strobe_iter();
#endif



#ifdef USE_LIGHTNING_MODE
#ifndef LIGHTNING_BUSY_FACTOR
#define LIGHTNING_BUSY_FACTOR 14 // max 16384ms (max ~16 sec interval)
#endif

#define LIGHTNING_BUSY_FACTOR_MAX 16 // max 65536ms (max ~65 sec interval)
#define LIGHTNING_BUSY_FACTOR_MIN 12 // max 4096ms (max ~4 sec interval)
inline void lightning_storm_iter();
#endif



// bike mode config options
#ifdef USE_BIKE_FLASHER_MODE
    #if !defined(DEFAULT_BIKING_LEVEL)
        #define DEFAULT_BIKING_LEVEL  (RAMP_SIZE/3)
    #elif DEFAULT_BIKING_LEVEL > MAX_BIKING_LEVEL
        #undef DEFAULT_BIKING_LEVEL
        #define DEFAULT_BIKING_LEVEL  MAX_BIKING_LEVEL
    #endif
    #define MAX_BIKING_LEVEL 120  // should be 127 or less
    inline void bike_flasher_iter();
#endif  // ifdef USE_BIKE_FLASHER_MODE



#ifdef USE_FIREWORK_MODE
#define MIN_FIREWORK_LEVEL DEFAULT_LEVEL // max is always MAX_LEVEL
inline void firework_iter();
#endif



#ifdef USE_LIGHTHOUSE_MODE
uint8_t lighthouse_phase = 0;
#define LIGHTHOUSE_MAX_DELAY 30
#define LIGHTHOUSE_MIN_DELAY 0
#define DEFAULT_LIGHTHOUSE_DELAY 5
inline void lighthouse_iter();
#endif



#ifdef USE_BROKEN_FLUORESCENT_MODE
uint8_t fluoresent_flicker_random = 1;
uint8_t fluoresent_flicker_index = 0;
uint8_t fluoresent_ramp_up_increment = 0;
inline void bad_fluorescent_iter();
#endif





///   ///   ///   ///   ///   ///   ///   ///   ///   ///
/// 2025-02-10

#ifdef USE_BEACONN_MODE

/// 2025-02-11:
/// #define MIN_FIREWORK_LEVEL DEFAULT_LEVEL  // max is always MAX_LEVEL
/// #define DEFAULT_BIKING_LEVEL  (RAMP_SIZE/3)
/// #define MAX_BIKING_LEVEL 120  



/// 2025/02/11:
#define MIN_BEACONN_LEVEL DEFAULT_LEVEL
#define DEFAULT_BEACONN_LEVEL  (RAMP_SIZE/3)
#define MAX_BEACONN_LEVEL 120  

uint8_t beaconn_seconds = 2;

inline void beaconn_mode_iter();

#endif

///   ///   ///   ///   ///   ///   ///   ///   ///   ///





#ifdef USE_CANDLE_MODE
#include "anduril/candle-mode.h"
#endif



#if defined(USE_POLICE_STROBE_MODE) || defined(USE_SOS_MODE_IN_FF_GROUP)
#define USE_BORING_STROBE_STATE
#include "anduril/ff-strobe-modes.h"
#endif





/*   ///  USE_BEACON_MODE_ISG, didnt work.
#ifdef USE_BEACON_MODE_ISG
#include "anduril/beacon-mode-isg.h"
#include "anduril/beacon-mode.h"
#endif

 */






/*   /// 

 */


/*   /// 

 */



/*   /// 

 */



///   ///   ///   ///   ///   ///   ///   ///   ///   ///



///   END   


