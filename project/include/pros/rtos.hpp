// PROS RTOS functions — local simulator version
#ifndef _PROS_RTOS_HPP_
#define _PROS_RTOS_HPP_

#include "pros/sim.h"

namespace pros {

inline void delay(int ms) {
    _sim::print_motors();
    if (_sim::opcontrol_mode()) {
        std::cout << "  [w/s=drive  a/d=turn  r/f=arm  e/q=claw  .=quit]\n  > ";
        char c;
        if (std::cin >> c) {
            if (c == '.') { std::cout << "Match ended.\n"; std::exit(0); }
            _sim::key() = c;
        }
    } else {
        std::cout << "  (delay " << ms << "ms)\n";
    }
}

}

#endif
