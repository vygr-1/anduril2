// beacon-mode.c: Beacon mode for Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   


#pragma once

#include "anduril/beacon-mode.h"


///   ///   ///   ///   ///   ///   ///   ///   ///   ///   ///   



/// beacon_mode_iter
inline void beacon_mode_iter() {

    // one iteration of main loop()
    if (! button_last_state) {
        set_level(memorized_level);
        nice_delay_ms(100);
        set_level(0);
        nice_delay_ms(((cfg.beacon_seconds) * 1000) - 100);
    }

}
/// beacon_mode_iter



   /// beacon_state

uint8_t beacon_state(Event event, uint16_t arg) {


    // 1 click: off
    if (event == EV_1click) {
        set_state(off_state, 0);
        return EVENT_HANDLED;
    }



    // TODO: use sleep ticks to measure time between pulses,
    //       to save power



    // 2 clicks: next blinky mode
    else if (event == EV_2clicks) {

        #if defined(USE_SOS_MODE) && defined(USE_SOS_MODE_IN_BLINKY_GROUP)
        set_state(sos_state, 0);

        #elif defined(USE_BATTCHECK)
        set_state(battcheck_state, 0);

        #elif defined(USE_THERMAL_REGULATION)
        set_state(tempcheck_state, 0);



        /*  ///  VER_CHECK_MODE
        ///  tested on the SC31 Pro t1616 
        ///  mod in the "sofirn/sc31-pro-t1616/anduril.h" :  
              #define USE_VER_CHECK_MODE
         */
        #elif defined(USE_VER_CHECK_MODE)
        set_state(ver_check_state, 0);   ///   ///   ///   ///   ///



        #endif

        return EVENT_HANDLED;

    }





    /// 1H
    // hold: configure beacon timing
    else if (event == EV_click1_hold) {
        if (0 == (arg % TICKS_PER_SECOND)) {

            blink_once();

        }

        return EVENT_HANDLED;

    }
    /// 1H



    /// 1H RELEASE 
    // release hold: save new timing
    else if (event == EV_click1_hold_release) {
        cfg.beacon_seconds = 1 + (arg / TICKS_PER_SECOND);
        save_config();
        return EVENT_HANDLED;
    }
    /// 1H RELEASE 


    return EVENT_NOT_HANDLED;

}
   /// beacon_state





///   END   


