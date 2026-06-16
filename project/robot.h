#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;
const int FIELD_SIZE = 11;

struct Robot {
    int x = 5, y = 5;
    int heading = 0;       // 0=up, 90=right, 180=down, 270=left
    double armHeight = 0.0;

    void driveFor(int steps) {
        for (int i = 0; i < steps; i++) {
            if (heading == 0   && y < FIELD_SIZE - 1) y++;
            if (heading == 180 && y > 0)              y--;
            if (heading == 90  && x < FIELD_SIZE - 1) x++;
            if (heading == 270 && x > 0)              x--;
        }
    }

    void turnFor(int degrees) {
        heading = (heading + degrees % 360 + 360) % 360;
    }

    void closeClaw() {
        armHeight = 0.0;
        cout << "  [claw closed]\n";
    }

    void openClaw() {
        armHeight = 5.0;
        cout << "  [claw opened]\n";
    }

    char arrow() {
        if (heading == 0)   return '^';
        if (heading == 90)  return '>';
        if (heading == 180) return 'v';
        return '<';
    }

    void print() {
        cout << "  x=" << x << "  y=" << y
             << "  facing=" << heading << " deg"
             << "  arm=" << armHeight << "\n";
    }
};

#endif
