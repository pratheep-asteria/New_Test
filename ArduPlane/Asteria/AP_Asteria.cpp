/**
 * @file AP_Asteria.cpp
 * @author Rohith R M
 * This file contains Asteria added feature of RTL battery consumption estimation and distance based battery failsafe.
 */

#include "../Plane.h"
#include <GCS_MAVLink/GCS.h>


/** 
 * @brief This function sends gcs messages at 1Hz loop
 * @details This is a temperory function to verify Asteria floder compilation
 * @return None
 */
void AP_Asteria::gcs_test()
{
     gcs().send_text(MAV_SEVERITY_CRITICAL, "Asteria Build 4.3.4");
    return;
}