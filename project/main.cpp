// ============================================================
//  VEX V5 Text Simulator — Match Project
// ------------------------------------------------------------
//  A full match simulation: autonomous period runs a script,
//  then driver control hands the robot to the keyboard.
//
//  Compile:  g++ main.cpp -o match && ./match
// ============================================================

#include "robot.h"
#include "field.h"

// --- Autonomous period (edit this!) -------------------------

void autonomous(Robot &robot, Field &field) {
    cout << "=== AUTONOMOUS PERIOD ===\n";

    field.placeTarget(8, 8);
    field.draw(robot);

    robot.driveFor(3);
    cout << "  drove forward 3\n";
    field.draw(robot);

    robot.turnFor(90);
    cout << "  turned right\n";
    field.draw(robot);

    robot.driveFor(3);
    cout << "  drove forward 3\n";
    field.draw(robot);

    if (field.robotOnTarget(robot)) {
        robot.closeClaw();
        cout << "  *** Scored in autonomous! ***\n";
        field.clearTarget();
    }

    cout << "\nAutonomous complete.\n\n";
}

// --- Driver control period ----------------------------------

void driverControl(Robot &robot, Field &field) {
    cout << "=== DRIVER CONTROL ===\n";
    cout << "w = forward   a = turn left   d = turn right\n";
    cout << "q = arm up    e = arm down    . = end match\n";
    field.draw(robot);

    char key;
    while (cin >> key) {
        if      (key == 'w') robot.driveFor(1);
        else if (key == 'a') robot.turnFor(-90);
        else if (key == 'd') robot.turnFor(90);
        else if (key == 'q') robot.armHeight += 1;
        else if (key == 'e') robot.armHeight -= 1;
        else if (key == '.') break;
        else continue;

        field.draw(robot);

        if (field.targetX >= 0 && field.robotOnTarget(robot)) {
            cout << "  *** Reached the target! ***\n";
            field.clearTarget();
        }
    }
}

// --- Match --------------------------------------------------

int main() {
    Robot robot;
    Field field;

    robot.x = 5;
    robot.y = 5;
    robot.heading = 0;

    autonomous(robot, field);
    driverControl(robot, field);

    cout << "\nMatch over. Final position:\n";
    robot.print();
    return 0;
}
