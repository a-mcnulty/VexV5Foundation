// ============================================================
//  Example 3:  AUTONOMOUS ROBOT  (no keyboard -- it runs a plan)
// ------------------------------------------------------------
//  Same Robot model as Example 2, but instead of reading keys
//  the robot follows a SCRIPT -- exactly like the autonomous
//  period in a VEX match.
//
//  Watch the coordinates trace out a square, then a little
//  "drive over and score" routine. This for-loop is the SAME
//  shape students will later run on the real robot.
//
//  Concepts: functions, a for loop, reusing the same methods
//  to build a bigger behavior.
//
//  Compile:  g++ 03_autonomous.cpp -o robot && ./robot
// ============================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

struct Robot {
    double x = 0.0, y = 0.0, heading = 0.0, armHeight = 0.0;

    void driveFor(double distance) {
        double radians = heading * PI / 180.0;
        x += distance * sin(radians);
        y += distance * cos(radians);
    }
    void turnFor(double degrees) {
        heading += degrees;
        while (heading >= 360.0) heading -= 360.0;
        while (heading <  0.0)   heading += 360.0;
    }
    void closeClaw() { armHeight = 0.0; cout << "  [claw closed - grabbed it!]\n"; }
    void openClaw()  { armHeight = 5.0; cout << "  [claw opened - dropped it!]\n"; }

    void print() {
        double px = (fabs(x) < 0.001) ? 0.0 : x;
        double py = (fabs(y) < 0.001) ? 0.0 : y;
        cout << fixed << setprecision(1);
        cout << "    x=" << px << "  y=" << py
             << "  facing=" << heading << " deg\n";
    }
};

int main() {
    Robot robot;

    cout << "=== Autonomous Demo ===\n\n";
    cout << "Part 1: drive in a square\n";
    robot.print();

    // A for loop drives the four sides of a square.
    for (int side = 1; side <= 4; side++) {
        cout << "  Side " << side << ":\n";
        robot.driveFor(50);
        robot.turnFor(90);
        robot.print();
    }

    cout << "\nPart 2: a scoring routine\n";
    robot.closeClaw();        // grab the game object
    robot.driveFor(60);
    robot.print();
    robot.turnFor(45);
    robot.driveFor(30);
    robot.print();
    robot.openClaw();         // release it in the goal

    cout << "\nAutonomous complete!\n";
    return 0;
}
