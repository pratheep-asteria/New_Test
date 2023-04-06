/**
 *  * @file Asteria.h
 * This file will have Asteria class details, other globals, Macros used
 * 
 */
#pragma once

#include "../Plane.h"
#include <AP_Param/AP_Param.h>

/// @brief Definitions
#define LED_STARBOARD 50
#define LED_PORT 51


class AP_Asteria
{

    public:
        AP_Asteria()
        {
            /// Variables for LED Pattern
            led_enable = 0;
            led_starboard = 0;
            led_port = 0;
            timer_2sec = 0;
            timer_40ms = 0;
            step_flag = 0;
        }

    /// @brief Function definition
    void led_status();

    private:

    /// @brief Private Variables

    /// Private variables for LED pattern
    uint8_t led_enable; ///< Stores the led toggle value.
    uint8_t led_starboard;///< Starboard led AUX pin.
    uint8_t led_port;///< Port LED AUX pin.
    uint32_t timer_2sec;///< stores HAL time for 2 second comparision.
    uint32_t timer_40ms;///< stores HAL time for 40 ms.
    uint8_t step_flag;///< step flag for number of blinks.

};