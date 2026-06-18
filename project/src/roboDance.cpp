

void moveDrive(int left, int right) {
    left_front.move(left);
    left_back.move(left);

    right_front.move(right);
    right_back.move(right);
}

void stopDrive() {
    moveDrive(0, 0);
}

void spinDance(int speed, int timeMs) {
    moveDrive(speed, -speed);
    pros::delay(timeMs);
    stopDrive();
    pros::delay(150);
}

void driveForward(int speed, int timeMs) {
    moveDrive(speed, speed);
    pros::delay(timeMs);
    stopDrive();
    pros::delay(150);
}

void driveBackward(int speed, int timeMs) {
    moveDrive(-speed, -speed);
    pros::delay(timeMs);
    stopDrive();
    pros::delay(150);
}

void smoothBackwardSkate() {
    moveDrive(-40, -70);
    pros::delay(400);

    moveDrive(-55, -55);
    pros::delay(200);

    moveDrive(-70, -40);
    pros::delay(400);

    moveDrive(-55, -55);
    pros::delay(200);

    stopDrive();
    pros::delay(150);
}

void wiggle(int times) {
    for(int i = 0; i < times; i++) {
        moveDrive(80, 20);
        pros::delay(120);

        moveDrive(20, 80);
        pros::delay(120);
    }

    stopDrive();
    pros::delay(250);
}

void moonwalk() {
    for(int i = 0; i < 3; i++) {
        smoothBackwardSkate();
        pros::delay(100);
    }
}

void danceRoutine() {

    // Intro
    spinDance(60, 500);
    pros::delay(300);

    spinDance(-60, 500);
    pros::delay(300);

    // Wiggle
    wiggle(8);
    pros::delay(300);

    // Forward burst
    driveForward(100, 800);
    pros::delay(250);

    // Spin section
    spinDance(100, 800);
    pros::delay(200);

    spinDance(-100, 800);
    pros::delay(300);

    // Moonwalk
    moonwalk();
    pros::delay(400);

    // Figure-8 style section
    moveDrive(50, 90);
    pros::delay(900);

    moveDrive(90, 50);
    pros::delay(900);

    moveDrive(50, 90);
    pros::delay(900);

    moveDrive(90, 50);
    pros::delay(900);

    stopDrive();
    pros::delay(500);

    // Fast shake
    for(int i = 0; i < 10; i++) {
        moveDrive(100, -100);
        pros::delay(60);

        moveDrive(-100, 100);
        pros::delay(60);
    }

    stopDrive();
    pros::delay(400);

    // Finale bounce
    for(int i = 0; i < 4; i++) {
        driveForward(127, 150);
        driveBackward(127, 150);
    }

    pros::delay(500);

    // Final spin
    spinDance(127, 2000);

    stopDrive();
    cout << "PLS CLAP" << endl;
}