// PROS API master header — local simulator version
// On a real V5, the PROS toolchain provides this file.
#ifndef _PROS_API_H_
#define _PROS_API_H_

#include "pros/apitypes.h"
#include "pros/llemu.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"

// Competition callbacks (defined by user in src/main.cpp)
void initialize();
void disabled();
void competition_initialize();
void autonomous();
void opcontrol();

#endif
