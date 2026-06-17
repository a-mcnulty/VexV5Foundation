// PROS API types and enums — local simulator version
#ifndef _PROS_API_TYPES_H_
#define _PROS_API_TYPES_H_

enum controller_id_e_t      { CONTROLLER_MASTER = 0, CONTROLLER_PARTNER };
enum controller_analog_e_t  { ANALOG_LEFT_X = 0, ANALOG_LEFT_Y, ANALOG_RIGHT_X, ANALOG_RIGHT_Y };
enum controller_digital_e_t {
    DIGITAL_L1 = 0, DIGITAL_L2, DIGITAL_R1, DIGITAL_R2,
    DIGITAL_UP, DIGITAL_DOWN, DIGITAL_LEFT, DIGITAL_RIGHT,
    DIGITAL_X, DIGITAL_B, DIGITAL_Y, DIGITAL_A
};

#endif
