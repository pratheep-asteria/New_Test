/**
 * @file AP_Asteria.cpp
 * @author Rohith R M
 * This file contains Asteria added features for ARTY-5 Centaur Requirements.
 */

#include "../Plane.h"
#include <GCS_MAVLink/GCS.h>
#include "AP_Asteria.h"

/** 
 * @brief This function implements the LED patterns.
 * @details This function executes the led blink patterns for CENTAUR ARTY-5 Air vehicle.
 * @return None
 */
void AP_Asteria::led_status()
{

    ///Store the LED_ENABLE parameter in the led_enable variable.
    led_enable = plane.g.aled_enable;

    ///Set AUX PWM1(50) and PWM2(52) pinmode to gpio output 
    hal.gpio->pinMode(LED_STARBOARD, HAL_GPIO_OUTPUT);
    hal.gpio->pinMode(LED_PORT, HAL_GPIO_OUTPUT);
 
    if(led_enable > 0)
    {
        power_on_flag=true;
        ///Radio Failsafe Condition, Double flash with 2 second delay
        if(plane.failsafe.rc_failsafe)
            {
                if((AP_HAL::millis() - timer_2sec) > 1999)
                {
                    if((AP_HAL::millis() - timer_40ms) > 99)
                    {
                        hal.gpio->toggle(LED_STARBOARD);
                        hal.gpio->toggle(LED_PORT);
                        step_flag +=1;
                        timer_40ms = AP_HAL::millis();
                    }

                    if(step_flag >= 4)
                    {   
                        hal.gpio->write(LED_STARBOARD,0);
                        hal.gpio->write(LED_PORT,0);
                        timer_2sec = AP_HAL::millis();
                        step_flag = 0;

                    }
                }
                return;
            }

        /// Battery Failsafe condition, triple flash with 2 second delay
        else if(plane.battery.has_failsafed())
            {
                if((AP_HAL::millis() - timer_2sec) > 1999)
                {
                    if((AP_HAL::millis() - timer_40ms) > 99)
                    {
                        hal.gpio->toggle(LED_STARBOARD);
                        hal.gpio->toggle(LED_PORT);
                        step_flag +=1;
                        timer_40ms = AP_HAL::millis();
                    }

                    if(step_flag >= 6)
                    {   
                        hal.gpio->write(LED_STARBOARD,0);
                        hal.gpio->write(LED_PORT,0);
                        timer_2sec = AP_HAL::millis();
                        step_flag = 0;

                    }
                }
                return;
            }
        /// Default condition, Solid LED for both LED functions.
        else 
            {
                hal.gpio->write(LED_STARBOARD,1);
                hal.gpio->write(LED_PORT,1);
            }
    }
    else{power_on_flag=false;}

    ///set all leds low if LED_ENABLE parameter is changed to 0 while operation.
    if (!power_on_flag)
    {
        hal.gpio->write(LED_STARBOARD,0);
        hal.gpio->write(LED_PORT,0);
    }

    return;
}