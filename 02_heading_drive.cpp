// ============================================================
//  Example 2:  HEADING ROBOT  (drives the way it is facing)
// ------------------------------------------------------------
//  Now the robot has a HEADING (which direction it faces).
//  Pressing W drives forward in that direction; A/D turn it.
//
//  The Robot's method names -- driveFor, turnFor -- are chosen
//  to MATCH the real VEXcode commands on purpose. The code a
//  student writes here will look almost identical to the code
//  that runs on a real V5 robot.
//
//  Concepts: a struct (object), methods, headings, and the
//  trig that turns "drive forward" into x/y movement.
//
//  Compile:  g++ 02_heading_drive.cpp -o robot && ./robot
// ============================================================

#include <iostream>
#include <iomanip>   // for clean number formatting
#include <cmath>     // for sin() and cos()
using namespace std;

const double PI = 3.14159265358979;

// A simple model of a VEX robot.
struct Robot {
    double x = 0.0;          // position on the field
    double y = 0.0;
    double heading = 0.0;    // degrees. 0 = facing up (north)
    double armHeight = 0.0;  // the "Z" axis: our claw/arm

    // Drive forward (or backward) in the direction we face.
    void driveFor(double distance) {
        double radians = heading * PI / 180.0;
        x += distance * sin(radians);
        y += distance * cos(radians);
    }

    // Turn by some number of degrees (negative = left).
    void turnFor(double degrees) {
        heading += degrees;
        while (heading >= 360.0) heading -= 360.0;   // keep it 0..359
        while (heading <  0.0)   heading += 360.0;
    }

    void closeClaw() { armHeight = 0.0; }
    void openClaw()  { armHeight = 5.0; }

    void print() {
        // Snap tiny values (like 0.0000001) down to a clean 0.
        double px = (fabs(x) < 0.001) ? 0.0 : x;
        double py = (fabs(y) < 0.001) ? 0.0 : y;
        cout << fixed << setprecision(1);
        cout << "x=" << px << "  y=" << py
             << "  facing=" << heading << " deg"
             << "  arm=" << armHeight << "\n";
    }
};

int main() {
    Robot robot;

    cout << "=== Heading Robot ===\n";
    cout << "The robot drives in the direction it is FACING.\n";
    cout << "  w = forward     s = backward\n";
    cout << "  a = turn left   d = turn right\n";
    cout << "  q = arm up      e = arm down\n";
    cout << "  . = quit\n\n";
    robot.print();

    char key;
    while (cin >> key) {
        if      (key == 'w') robot.driveFor(10);
        else if (key == 's') robot.driveFor(-10);
        else if (key == 'a') robot.turnFor(-90);
        else if (key == 'd') robot.turnFor(90);
        else if (key == 'q') robot.armHeight += 1;
        else if (key == 'e') robot.armHeight -= 1;
        else if (key == '.') break;
        else { cout << "Unknown key '" << key << "'\n"; continue; }

        robot.print();
    }

    cout << "Goodbye!\n";
    return 0;
}
