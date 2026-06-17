// PROS Controller class — local simulator version
#ifndef _PROS_MISC_HPP_
#define _PROS_MISC_HPP_

#include "pros/sim.h"

namespace pros {

class Controller {
public:
    Controller(controller_id_e_t /*id*/ = CONTROLLER_MASTER) {}

    int get_analog(controller_analog_e_t channel) {
        char k = _sim::key();
        if (channel == ANALOG_LEFT_Y)  return (k == 'w') ? 127 : (k == 's') ? -127 : 0;
        if (channel == ANALOG_RIGHT_X) return (k == 'd') ? 127 : (k == 'a') ? -127 : 0;
        return 0;
    }

    bool get_digital(controller_digital_e_t button) {
        char k = _sim::key();
        if (button == DIGITAL_R1) return k == 'r';
        if (button == DIGITAL_R2) return k == 'f';
        if (button == DIGITAL_L1) return k == 'e';
        if (button == DIGITAL_L2) return k == 'q';
        return false;
    }
};

}

#endif
