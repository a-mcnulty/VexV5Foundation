// Entry point for local simulator builds only.
// On a real V5, PROS provides main() — this file is not uploaded.
#include "main.h"

int main() {
    std::cout << "========== PROS LOCAL SIMULATOR ==========\n\n";

    initialize();
    competition_initialize();

    std::cout << "\n---------- AUTONOMOUS PERIOD ----------\n";
    autonomous();

    std::cout << "\n---------- DRIVER CONTROL ----------\n";
    pros::_sim::opcontrol_mode() = true;
    pros::_sim::key() = 0;
    opcontrol();

    return 0;
}
