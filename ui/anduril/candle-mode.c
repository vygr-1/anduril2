// candle-mode.c: Candle mode for Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later

///  starryalley (new repo) candle-mode.c 
///  https://github.com/starryalley/anduril



#pragma once

#include "anduril/candle-mode.h"

#ifdef USE_SUNSET_TIMER
#include "anduril/sunset-timer.h"
#endif





#define CANDLE_AMPLITUDE_MAX 60
#define CANDLE_AMPLITUDE_MIN 10
#define MAX_CANDLE_LEVEL (RAMP_SIZE-CANDLE_AMPLITUDE-15)
static uint8_t max_candle_level = MAX_CANDLE_LEVEL;
// these should add up to 100
static uint8_t candle_wave1_maxdepth = 30;
static uint8_t candle_wave2_maxdepth = 45;
static uint8_t candle_wave3_maxdepth = 25;

static uint8_t candle_wave1_depth;
static uint8_t candle_wave2_depth;
static uint8_t candle_wave3_depth;





///  wobble_style 

static inline void reset_parameters() {
    max_candle_level = RAMP_SIZE-cfg.candle_amplitude-15;
    switch (wobble_style) {
    case fireplace_slow_wobble_e:
        //use wave1/wave2 only
        candle_wave3_depth = candle_wave3_maxdepth = 0;
        candle_wave1_maxdepth = 50;
        candle_wave2_maxdepth = 50;
        candle_wave1_depth = candle_wave1_maxdepth * cfg.candle_amplitude / 100;
        candle_wave2_depth = candle_wave2_maxdepth * cfg.candle_amplitude / 100;
        // #ifdef USE_AUX_RGB_LEDS
        // rgb_led_update(RGB_RED|RGB_HIGH, 0);
        // #endif
        break;
    case fireplace_fast_wobble_e:
        //use wave2/wave3 only
        candle_wave1_depth = candle_wave1_maxdepth = 0;
        candle_wave2_maxdepth = 20;
        candle_wave3_maxdepth = 80;
        candle_wave2_depth = candle_wave2_maxdepth * cfg.candle_amplitude / 100;
        candle_wave3_depth = candle_wave3_maxdepth * cfg.candle_amplitude / 100;
        // #ifdef USE_AUX_RGB_LEDS
        // rgb_led_update(RGB_YELLOW|RGB_HIGH, 0);
        // #endif
        break;
    default:
        candle_wave1_maxdepth = 30;
        candle_wave2_maxdepth = 45;
        candle_wave3_maxdepth = 25;
        candle_wave1_depth = candle_wave1_maxdepth * cfg.candle_amplitude / 100;
        candle_wave2_depth = candle_wave2_maxdepth * cfg.candle_amplitude / 100;
        candle_wave3_depth = candle_wave3_maxdepth * cfg.candle_amplitude / 100;
        // #ifdef USE_AUX_RGB_LEDS
        // rgb_led_update(RGB_OFF, 0);
        // #endif
    }
}





///  candle_mode_state

uint8_t candle_mode_state(Event event, uint16_t arg) {

    static int8_t ramp_direction = 1;
    static uint8_t candle_wave1 = 0;
    static uint8_t candle_wave2 = 0;
    static uint8_t candle_wave3 = 0;
    static uint8_t candle_wave2_speed = 0;
    static uint8_t candle_mode_brightness = 24;



    #ifdef USE_SUNSET_TIMER
    // let the candle "burn out" and shut itself off
    // if the user told it to
    // cache this in case it changes when the timer is called
    uint8_t sunset_active = sunset_timer;
    // clock tick
    sunset_timer_state(event, arg);
    // if the timer just expired, shut off
    if (sunset_active  &&  (! sunset_timer)) {
        set_state(off_state, 0);
        return EVENT_HANDLED;
    }
    #endif  // ifdef USE_SUNSET_TIMER



    if (event == EV_enter_state) {
        wobble_style = cfg.candle_wobble_style;
        ramp_direction = 1;
        reset_parameters();
        return EVENT_HANDLED;
    }



    ///  2C
    ///  rotate forward through strobe/flasher modes
    #ifdef USE_SUNSET_TIMER
    // 2 clicks: cancel timer
    else if (event == EV_2clicks) {
        // parent state just rotated through strobe/flasher modes,
        // so cancel timer...  in case any time was left over from earlier
        sunset_timer = 0;
        return EVENT_HANDLED;
    }
    #endif  // ifdef USE_SUNSET_TIMER



    /// 1H : brighter 
    // hold: change brightness (brighter)
    else if (event == EV_click1_hold) {
        // ramp away from extremes
        if (! arg) {
            if (candle_mode_brightness >= max_candle_level) { ramp_direction = -1; }
            else if (candle_mode_brightness <= 1) { ramp_direction = 1; }
        }
        // change brightness, but not too far
        candle_mode_brightness += ramp_direction;
        if (candle_mode_brightness < 1) candle_mode_brightness = 1;
        else if (candle_mode_brightness > max_candle_level) candle_mode_brightness = max_candle_level;
        return EVENT_HANDLED;
    }
    // reverse ramp direction on hold release
    else if (event == EV_click1_hold_release) {
        ramp_direction = -ramp_direction;
        return EVENT_HANDLED;
    }



    ///  2H : dimmer 
    // click, hold: change brightness (dimmer)
    else if (event == EV_click2_hold) {
        ramp_direction = 1;
        // difference of level 2 and 3 is huge. Avoid going too low or the candle will wobble too much
        if (candle_mode_brightness > 3)
            candle_mode_brightness --;
        return EVENT_HANDLED;
    }



    ///  4H 
    // 4H: set wobble style
    else if (event == EV_click4_hold) {
        if (0 == (arg & 0x3f)) {
            wobble_style = cfg.candle_wobble_style = (wobble_style + 1) % NUM_WOBBLE;
            reset_parameters();
            if (wobble_style == candle_wobble_e)
                blip_ms(12);
            else if (wobble_style == fireplace_slow_wobble_e)
                blip_ms(96);
            else if (wobble_style == fireplace_fast_wobble_e)
                blip_ms(192);
        }
        return EVENT_HANDLED;
    }
    else if (event == EV_click4_hold_release) {
        save_config();
        return EVENT_HANDLED;
    }



    ///   4C  
    ///   candle amplitude smaller (candle in sort of stillness)
    ///   OG : // 6C: making candle amplitude smaller (candle in sort of stillness)
    else if (event == EV_4clicks) {
        cfg.candle_amplitude -= 3;
        if (cfg.candle_amplitude < CANDLE_AMPLITUDE_MIN)
            cfg.candle_amplitude = CANDLE_AMPLITUDE_MIN;
        reset_parameters();
        save_config();
        blip();
        return EVENT_HANDLED;
    }



    ///   5C  
    ///   candle amplitude bigger (candle in the wind)
    ///   OG : // 7C: making candle amplitude bigger (candle in the wind)
    else if (event == EV_5clicks) {
        cfg.candle_amplitude += 3;
        if (cfg.candle_amplitude > CANDLE_AMPLITUDE_MAX)
            cfg.candle_amplitude = CANDLE_AMPLITUDE_MAX;
        reset_parameters();
        save_config();
        blip();
        return EVENT_HANDLED;
    }



    ///   6C:
    ///   reset candle amplitude 
    ///   OG : // 8C: reset candle amplitude
    else if (event == EV_6clicks) {
        cfg.candle_amplitude = CANDLE_AMPLITUDE;
        reset_parameters();
        save_config();
        blink_once();
        blip();
        return EVENT_HANDLED;
    }



    // clock tick: animate candle brightness
    else if (event == EV_tick) {
        // un-reverse after 1 second
        if (arg == AUTO_REVERSE_TIME) ramp_direction = 1;

        // 3-oscillator synth for a relatively organic pattern
        uint8_t add;
        add = ((triangle_wave(candle_wave1) * candle_wave1_depth) >> 8)
            + ((triangle_wave(candle_wave2) * candle_wave2_depth) >> 8)
            + ((triangle_wave(candle_wave3) * candle_wave3_depth) >> 8);
// limit add if we are on lower level because brightness varies a lot
        // when we use lower level
        if (add > candle_mode_brightness/2) add >>= 1;
        if (wobble_style == fireplace_fast_wobble_e) add >>=1; // cut the add in half
        uint16_t brightness = candle_mode_brightness + add;

        // self-timer dims the light during the final minute
        #ifdef USE_SUNSET_TIMER
        if (1 == sunset_timer) {
            brightness = brightness
                         * ((TICKS_PER_MINUTE>>5) - (sunset_ticks>>5))
                         / (TICKS_PER_MINUTE>>5);
        }
        #endif  // ifdef USE_SUNSET_TIMER

        set_level(brightness);



        ///  WAVE1 
        // wave1: slow random LFO
        // TODO: make wave slower and more erratic?
        if (wobble_style != fireplace_fast_wobble_e){
            if ((arg & 1) == 0) candle_wave1 += pseudo_rand() & 1;
        }



        ///  WAVE2 
        // wave2: medium-speed erratic LFO
        candle_wave2 += candle_wave2_speed;



        ///  WAVE3 
        // wave3: erratic fast wave
        if (wobble_style == fireplace_fast_wobble_e)
            candle_wave3 += pseudo_rand() % 31; //slightly slower



        else
            candle_wave3 += pseudo_rand() % 37;
        // S&H on wave2 frequency to make it more erratic
        if ((pseudo_rand() & 0b00111111) == 0)
            candle_wave2_speed = pseudo_rand() % 13;
        // downward sawtooth on wave2 depth to simulate stabilizing
        if ((candle_wave2_depth > 0) && ((pseudo_rand() & 0b00111111) == 0))
            candle_wave2_depth --;
        // less random factor when we are in fireplace wobble mode
        if (wobble_style > candle_wobble_e) {
            if (0 == (arg & 0x7f))
                reset_parameters();
            return MISCHIEF_MANAGED;
        }



        // random sawtooth retrigger
        if (pseudo_rand() == 0) {
            // random amplitude
            //candle_wave2_depth = 2 + (pseudo_rand() % ((CANDLE_WAVE2_MAXDEPTH * cfg.candle_amplitude / 100) - 2));
            candle_wave2_depth = pseudo_rand() % (candle_wave2_maxdepth * cfg.candle_amplitude / 100);
            //candle_wave3_depth = 5;
            candle_wave2 = 0;
        }



        // downward sawtooth on wave3 depth to simulate stabilizing
        if ((candle_wave3_depth > 2) && ((pseudo_rand() & 0b00011111) == 0))
            candle_wave3_depth --;
        if ((pseudo_rand() & 0b01111111) == 0)
            // random amplitude
            //candle_wave3_depth = 2 + (pseudo_rand() % ((CANDLE_WAVE3_MAXDEPTH * cfg.candle_amplitude / 100) - 2));
            candle_wave3_depth = pseudo_rand() % (candle_wave3_maxdepth * cfg.candle_amplitude / 100);
        return EVENT_HANDLED;
    }
    return EVENT_NOT_HANDLED;
}





///   ///   ///   ///   ///   ///   ///   ///   ///   ///



///   END   


