/// ver-check-mode.h

/// based on "version-check-mode.h"

// version-check-mode.h: Version check mode for Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later


/////////////////////////////////////////////////////////////


#pragma once


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   


#define USE_BLINK_DIGIT  // FIXME: does nothing unless defined earlier


#ifndef MODEL_NUMBER
// if no model number, it's a build error
//#define MODEL_NUMBER "0000"
#error MODEL_NUMBER undefined
#endif



/// OG: 
///  #include "anduril/version.h"   
///   Mod : 
#include ".build-anduril/version.h"



/// const PROGMEM uint8_t version_number[] = MODEL_NUMBER "." VERSION_NUMBER;
/// const PROGMEM uint8_t ver_number[] = MODEL_NUMBER "." VERSION_NUMBER;
const PROGMEM uint8_t ver_number[] = ".." MODEL_NUMBER ".." VERSION_NUMBER "..." ;



/*  /// VERSION_NUMBER

2025-01-25 13:56:58

2025.01.25     


#define VERSION_NUMBER "25-01-25__13-42"

3131                
 "25-01-25__13-42"


__3131__25-01-25__13-42___

..3131..25-01-25..13-42...


..3131..25.01.25..13.42...

--3131--25-01-25--13-42---


 */






/// uint8_t version_check_state(Event event, uint16_t arg);
uint8_t ver_check_state(Event event, uint16_t arg);

inline void ver_check_iter();






///   END   


