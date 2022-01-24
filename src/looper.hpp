#ifndef __LOOPER_LIB__HPP
#define __LOOPER_LIB__HPP

/**
 * 
 * Simple library that will let you execute code at a regular(ish) interval.
 * It's ideal for simple tasks and shouldn't be depended on for high resolution
 * timing. Nor should it be used for task switching. Perhaps you want to quickly
 * scan a sensor or print something every 1s as an experiement, but don't want to
 * use interrupts. This isn't the best option if you're working in a low power
 * (e.g. battery backed) environment!
 */
#include <Arduino.h>

#if defined (__AVR_ATtiny85__)
   typedef unsigned int LOOPER_TYPE;
#else
   typedef unsigned long LOOPER_TYPE;
#endif

class Looper {
   private:
    // Last timestamp the looper ran the periodic code
    LOOPER_TYPE previousMillis = 0;

    // Stores current time
    LOOPER_TYPE currentMillis = 0;

    // Interval at which to do work (milliseconds)
    LOOPER_TYPE interval = 1000;

    // First run action has been performed?
    bool first_run = true;

    // Flag to perform an action on first run or not
    bool use_first_run = false;

   public:
    Looper();
    void set_interval(LOOPER_TYPE new_interval);
    LOOPER_TYPE get_interval();
    void enable_first_run();
    void disable_first_run();
    bool tick();
    void reset();
};

#endif
