// PROS LCD Emulation — local simulator version
#ifndef _PROS_LLEMU_HPP_
#define _PROS_LLEMU_HPP_

#include <iostream>
#include <string>

namespace pros { namespace lcd {

    inline void initialize() {
        std::cout << "[LCD] initialized\n";
    }

    inline void set_text(int line, std::string text) {
        std::cout << "[LCD line " << line << "] " << text << "\n";
    }

}}

#endif
