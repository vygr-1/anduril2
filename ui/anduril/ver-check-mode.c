/// ver-check-mode.c

/// based on "version-check-mode.c"

// version-check-mode.c: Version check mode for Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   


#pragma once


#include "anduril/ver-check-mode.h"


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   




uint8_t ver_check_state(Event event, uint16_t arg) {


    // 1 click: off
    if (event == EV_1click) {
        set_state(off_state, 0);
        return EVENT_HANDLED;
    }





    // 2 clicks: next blinky mode
    else if (event == EV_2clicks) {


        #if defined(USE_BEACON_MODE)
        set_state(beacon_state, 0);

        #elif defined(USE_SOS_MODE) && defined(USE_SOS_MODE_IN_BLINKY_GROUP)
        set_state(sos_state, 0);

        #elif defined(USE_BATTCHECK_MODE)
        set_state(battcheck_state, 0);

        #elif defined(USE_THERMAL_REGULATION)
        set_state(tempcheck_state, 0);


        #endif

        return EVENT_HANDLED;

    }


    return EVENT_NOT_HANDLED;

}





/*  OG: 
// this happens in FSM loop()
inline void ver_check_iter() {
    for (uint8_t i=0; i<sizeof(version_number)-1; i++) {
        uint8_t digit = pgm_read_byte(version_number + i) - '0';
        //       digits: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        //   hex digits: 0 1 2 3 4 5 6 7 8 9  a  b  c  d  e  f
        // 'model' file: 0 1 2 3 4 5 6 7 8 9  :  ;  <  =  >  ?
        if (digit < 16) blink_digit(digit);
        else {  // "buzz" for non-numeric characters
            for(uint8_t frame=0; frame<25; frame++) {
                set_level((frame&1) << 5);
                nice_delay_ms(16);
            }
            nice_delay_ms(BLINK_SPEED * 8 / 12);
        }
        nice_delay_ms(300);
    }

    set_state_deferred(off_state, 0);
}
 */


/*  Mods: 
 */
inline void ver_check_iter() {

    for (uint8_t i=0; i<sizeof(ver_number)-1; i++) {

        uint8_t digit = pgm_read_byte(ver_number + i) - '0';
        //       digits: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        //   hex digits: 0 1 2 3 4 5 6 7 8 9  a  b  c  d  e  f
        // 'model' file: 0 1 2 3 4 5 6 7 8 9  :  ;  <  =  >  ?

        if (digit < 16) blink_digit(digit);


        else {  // "buzz" for non-numeric characters

            for(uint8_t frame=0; frame<25; frame++) {
                set_level((frame&1) << 5);
                nice_delay_ms(16);
            }

            nice_delay_ms(BLINK_SPEED * 8 / 12);

        }

        nice_delay_ms(700);

    }



    /* commented: VER_CHECK_MODE repeats
	 * un-commented: VER_CHECK_MODE runs once 

       set_state_deferred(off_state, 0);

     */



    /* "nice_delay" after each VER_CHECK_MODE run, 
     * (spacer/separator between VER_CHECK_MODE runs) 
     */ 
    nice_delay_ms(1400);   ///

}






///   END   


