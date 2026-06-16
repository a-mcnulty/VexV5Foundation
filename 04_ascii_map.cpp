// ============================================================
//  Example 4:  ASCII MAP ROBOT  (you can SEE the robot move)
// ------------------------------------------------------------
//  Same idea as Example 2, but every move redraws the field as
//  a grid, with an arrow ( ^ > v < ) showing which way the
//  robot faces. It feels like a little game -- still just cout.
//
//  To keep the grid tidy we use whole-number cells and only
//  turn in 90-degree steps.
//
//  Concepts: a grid drawn with nested loops, mapping a position
//  onto a picture.
//
//  Compile:  g++ 04_ascii_map.cpp -o robot && ./robot
// ============================================================

#include <iostream>
using namespace std;

const int SIZE = 11;   // field is 11 x 11 cells (0..10)

struct Robot {
    int x = 5, y = 5;     // start in the middle
    int heading = 0;      // 0=up, 90=right, 180=down, 270=left

    void turnRight() { heading = (heading + 90) % 360; }
    void turnLeft()  { heading = (heading + 270) % 360; }

    void driveForward() {
        if (heading == 0   && y < SIZE - 1) y++;   // up
        if (heading == 180 && y > 0)        y--;   // down
        if (heading == 90  && x < SIZE - 1) x++;   // right
        if (heading == 270 && x > 0)        x--;   // left
    }

    char arrow() {
        if (heading == 0)   return '^';
        if (heading == 90)  return '>';
        if (heading == 180) return 'v';
        return '<';
    }
};

void drawField(Robot &robot) {
    cout << "\n";
    // Draw top row first (high y at the top, like a real map).
    for (int row = SIZE - 1; row >= 0; row--) {
        for (int col = 0; col < SIZE; col++) {
            if (col == robot.x && row == robot.y) cout << robot.arrow() << ' ';
            else                                  cout << ". ";
        }
        cout << "\n";
    }
    cout << "(x=" << robot.x << ", y=" << robot.y
         << ", facing " << robot.heading << ")\n";
}

int main() {
    Robot robot;

    cout << "=== ASCII Field Map ===\n";
    cout << "w = forward,  a = turn left,  d = turn right,  . = quit\n";
    drawField(robot);

    char key;
    while (cin >> key) {
        if      (key == 'w') robot.driveForward();
        else if (key == 'a') robot.turnLeft();
        else if (key == 'd') robot.turnRight();
        else if (key == '.') break;
        else continue;

        drawField(robot);
    }

    cout << "Goodbye!\n";
    return 0;
}
