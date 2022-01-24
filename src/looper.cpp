#include "looper.hpp"

Looper::Looper() {
}

void Looper::set_interval(LOOPER_TYPE new_interval) {
    if (new_interval > 0) {
        this->interval = new_interval;
    }
}

LOOPER_TYPE Looper::get_interval() {
    return this->interval;
}

void Looper::enable_first_run() {
    this->use_first_run = true;
}

void Looper::disable_first_run() {
    this->use_first_run = false;
}

/**
 * Invoked every time inside a loop to compare the current timestamp
 * with the stored timestamp. If the delta of those two is at least the
 * requested interval OR first run is enabled and hasn't already occurred,
 * then return TRUE to indicate we've been looped. Return FALSE for all other
 * conditions.
 */
bool Looper::tick() {
    // Get the current time
    this->currentMillis = millis();

    // Do we do anything yet?
    if ((this->first_run && this->use_first_run) || this->currentMillis - this->previousMillis >= this->interval) {
        this->first_run = false;

        // Save the last time
        this->previousMillis = this->currentMillis;

        return true;
    }

    return false;
}

void Looper::reset() {
    // Overwrite the last time
    previousMillis = currentMillis;
}
