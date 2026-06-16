// ============================================================
//  Example 1:  GRID ROBOT  (the simplest version)
// ------------------------------------------------------------
//  The robot lives on a grid. It has an x and a y position.
//  W/A/S/D move it North/West/South/East by one step.
//
//  Concepts: variables, a while loop, if / else.
//  No functions, no objects yet -- just the basics.
//
//  Compile:  g++ 01_grid_drive.cpp -o robot && ./robot
// ============================================================

#include <iostream>
using namespace std;

int main() {
    int x = 0;   // left/right position
    int y = 0;   // up/down position
    char key;    // the letter the user types

    cout << "=== Grid Robot ===\n";
    cout << "Type a letter, then press Enter.\n";
    cout << "  w = up      s = down\n";
    cout << "  a = left    d = right\n";
    cout << "  . = quit\n\n";
    cout << "Start:  x=" << x << "  y=" << y << "\n";

    // Keep reading keys until the user quits.
    while (cin >> key) {
        if      (key == 'w') y = y + 1;
        else if (key == 's') y = y - 1;
        else if (key == 'a') x = x - 1;
        else if (key == 'd') x = x + 1;
        else if (key == '.') break;            // stop the loop
        else {
            cout << "I don't know the key '" << key << "'\n";
            continue;                          // skip the print below
        }

        cout << "Robot is now at  x=" << x << "  y=" << y << "\n";
    }

    cout << "Goodbye!\n";
    return 0;
}
