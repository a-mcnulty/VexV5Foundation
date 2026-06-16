#ifndef FIELD_H
#define FIELD_H

#include "robot.h"

struct Field {
    int targetX = -1, targetY = -1;

    void placeTarget(int tx, int ty) {
        targetX = tx;
        targetY = ty;
    }

    void clearTarget() {
        targetX = -1;
        targetY = -1;
    }

    void draw(Robot &robot) {
        cout << "\n";
        for (int row = FIELD_SIZE - 1; row >= 0; row--) {
            for (int col = 0; col < FIELD_SIZE; col++) {
                if (col == robot.x && row == robot.y)
                    cout << robot.arrow() << ' ';
                else if (col == targetX && row == targetY)
                    cout << "T ";
                else
                    cout << ". ";
            }
            cout << "\n";
        }
        robot.print();
    }

    double distanceToTarget(Robot &robot) {
        int dx = targetX - robot.x;
        int dy = targetY - robot.y;
        return sqrt((double)(dx * dx + dy * dy));
    }

    bool robotOnTarget(Robot &robot) {
        return robot.x == targetX && robot.y == targetY;
    }
};

#endif
