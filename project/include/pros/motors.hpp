// PROS Motor class — local simulator version
#ifndef _PROS_MOTORS_HPP_
#define _PROS_MOTORS_HPP_

#include "pros/sim.h"

namespace pros {

class Motor {
    int _idx;
public:
    Motor(int port, bool reversed = false) {
        _idx = _sim::motors().size();
        _sim::motors().push_back({port, 0, reversed});
    }

    void move(int voltage) {
        int v = _sim::motors()[_idx].reversed ? -voltage : voltage;
        _sim::motors()[_idx].voltage = v;
    }

    int get_actual_velocity() {
        return _sim::motors()[_idx].voltage;
    }
};

}

#endif
