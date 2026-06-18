#include "main.h"

using namespace pros;
using namespace pros::v5;
using namespace pros::c;

// --- Motor ports (change these to match your robot) ---
constexpr int LEFT_FRONT_PORT  = 1;
constexpr int LEFT_BACK_PORT   = 2;
constexpr int RIGHT_FRONT_PORT = 9;
constexpr int RIGHT_BACK_PORT  = 10;
constexpr int ARM_PORT         = 5;
constexpr int CLAW_PORT        = 7;

Motor left_front (LEFT_FRONT_PORT);
Motor left_back  (LEFT_BACK_PORT);
Motor right_front(RIGHT_FRONT_PORT);
Motor right_back (RIGHT_BACK_PORT);
Motor arm_motor  (ARM_PORT);
Motor claw_motor (CLAW_PORT);

void drive(int left, int right) {
    left_front .move(left);
    left_back  .move(left);
    right_front.move(-right);
    right_back .move(-right);
}

void drive_for(int left, int right, int ms) {
    drive(left, right);
    delay(ms);
    drive(0, 0);
}

void arm_up()   { arm_motor.move(80);  delay(600); arm_motor.move(10); }
void arm_down() { arm_motor.move(-60); delay(500); arm_motor.move(0);  }

void claw_open()  { claw_motor.move(50);  delay(400); claw_motor.move(0); }
void claw_close() { claw_motor.move(-50); delay(400); claw_motor.move(0); }

void initialize() {
    lcd::initialize();
    lcd::set_text(1, "Robot initialized");
}

void disabled() {}

void competition_initialize() {}
void opcontrol() {
    Controller master(CONTROLLER_MASTER);

    while (true) {
        int forward = master.get_analog(ANALOG_LEFT_Y);
        int turn    = master.get_analog(ANALOG_RIGHT_X);

        drive(forward + turn, forward - turn);

        if (master.get_digital(DIGITAL_R1))
            arm_motor.move(80);
        else if (master.get_digital(DIGITAL_R2))
            arm_motor.move(-60);
        else arm_motor.move(10);

        if (master.get_digital(DIGITAL_L1)) claw_motor.move(50);
        else if (master.get_digital(DIGITAL_L2)) claw_motor.move(-50);
        else claw_motor.move(0);
        void wheels_move(double amount) {
            left_front.move_relative(amount, 100);
            right_front.move_relative(amount, 100);
            left_back.move_relative(amount, 100);
            right_back.move_relative(amount, 100);
        }
        void right_turn(double degrees) {
            left_front.move (degrees, 100);
            left_back.move (degrees, 100);
            right_front.move (-degrees, 100);
            right_back.move (-degrees, 100); }
        if (master.get_digital(DIGITAL_A)) {
            //do dance
            for (int i = 1; i < 5; i++) {
                wheels_move(90.0);
                right_turn(30.0);
            }
            for (int a = 1; a < 7; a++) {
                wheels_move(90.0);
                right_turn(70.0);
            }
            for (int c = 0; c < 5; c++) {
                wheels_move(35.0)
                right_turn(144.0)
            for (int v = 0; v < 10; v++) {
                wheels_move(3.)
                wheels_move(-3.0)
            }
}
        


        }

        delay(20);
    }
}
