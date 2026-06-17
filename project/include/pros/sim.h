// Simulator internals — not part of the real PROS API.
// This file only exists for local compilation.
#ifndef _PROS_SIM_H_
#define _PROS_SIM_H_

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

namespace pros { namespace _sim {

    struct MotorInfo {
        int port;
        int voltage;
        bool reversed;
    };

    inline std::vector<MotorInfo>& motors() {
        static std::vector<MotorInfo> m;
        return m;
    }

    inline char& key() {
        static char k = 0;
        return k;
    }

    inline bool& opcontrol_mode() {
        static bool b = false;
        return b;
    }

    inline void print_motors() {
        std::cout << "  Motors:";
        for (auto& m : motors())
            std::cout << " [port " << m.port << " = " << m.voltage << "]";
        std::cout << "\n";
    }

}}

#endif
