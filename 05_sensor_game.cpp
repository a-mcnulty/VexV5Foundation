// ============================================================
//  Example 5:  SENSOR GAME  (drive to the target T)
// ------------------------------------------------------------
//  A little challenge that adds a SENSOR. A target (T) sits on
//  the field. A pretend "distance sensor" tells you how far
//  away it is. Use if / else to react, and reach the target
//  to win.
//
//  This is the same idea as Day 5-6 of the camp: the robot
//  reads a sensor value and makes a decision from it.
//
//  Concepts: sensors, distance with sqrt, if / else / else,
//  a win condition.
//
//  Compile:  g++ 05_sensor_game.cpp -o robot && ./robot
// ============================================================

#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 11;

struct Robot {
    int x = 1, y = 1;     // start in a corner
    int heading = 0;      // 0=up, 90=right, 180=down, 270=left

    void turnRight() { heading = (heading + 90) % 360; }
    void turnLeft()  { heading = (heading + 270) % 360; }

    void driveForward() {
        if (heading == 0   && y < SIZE - 1) y++;
        if (heading == 180 && y > 0)        y--;
        if (heading == 90  && x < SIZE - 1) x++;
        if (heading == 270 && x > 0)        x--;
    }

    char arrow() {
        if (heading == 0)   return '^';
        if (heading == 90)  return '>';
        if (heading == 180) return 'v';
        return '<';
    }
};

int main() {
    Robot robot;
    int targetX = 8, targetY = 8;   // the object to collect

    cout << "=== Sensor Game ===\n";
    cout << "Drive your robot to the target (T).\n";
    cout << "w = forward,  a = turn left,  d = turn right,  . = quit\n";

    char key;
    bool won = false;

    while (!won && (cin >> key)) {
        if      (key == 'w') robot.driveForward();
        else if (key == 'a') robot.turnLeft();
        else if (key == 'd') robot.turnRight();
        else if (key == '.') break;
        else continue;

        // Draw the field (robot arrow + target T).
        cout << "\n";
        for (int row = SIZE - 1; row >= 0; row--) {
            for (int col = 0; col < SIZE; col++) {
                if      (col == robot.x  && row == robot.y)  cout << robot.arrow() << ' ';
                else if (col == targetX  && row == targetY)  cout << "T ";
                else                                         cout << ". ";
            }
            cout << "\n";
        }

        // The "distance sensor": straight-line distance to target.
        int dx = targetX - robot.x;
        int dy = targetY - robot.y;
        double distance = sqrt((double)(dx * dx + dy * dy));
        cout << "Distance sensor reads: " << distance << "\n";

        // React to the reading with if / else.
        if (dx == 0 && dy == 0) {
            cout << "*** You reached the target! YOU WIN! ***\n";
            won = true;
        } else if (distance < 3.0) {
            cout << "Getting close!\n";
        } else {
            cout << "Keep searching...\n";
        }
    }

    if (!won) cout << "Game over.\n";
    return 0;
}
