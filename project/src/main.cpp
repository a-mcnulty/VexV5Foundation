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

void autonomous() {
    lcd::set_text(2, "Autonomous running");
    Motor left_wheels (LEFT_WHEELS_PORT);
    Motor right_wheels (RIGHT_WHEELS_PORT, true); // This reverses the motor


  right_wheels.move_relative(1000, MOTOR_MAX_SPEED);
  left_wheels.move_relative(1000, MOTOR_MAX_SPEED);

    claw_close();
    arm_up();

    lcd::set_text(2, "Autonomous done");
}
 void turn(int amount) {
    left_front.move_relative(amount, MOTOR_MAX_SPEED);
    left_back.move_relative(-amount, MOTOR_MAX_SPEED);
    right_front.move_relative(-amount, MOTOR_MAX_SPEED);
    right_back.move_relative(amount, MOTOR_MAX_SPEED);
}
void forward(int amount) {
    left_front.move_relative(amount, MOTOR_MAX_SPEED);
    left_back.move_relative(amount, MOTOR_MAX_SPEED);
    right_front.move_relative(amount, MOTOR_MAX_SPEED);
    right_back.move_relative(amount, MOTOR_MAX_SPEED);
}
void backward(int amount) {
    left_front.move_relative(-amount, MOTOR_MAX_SPEED);
    left_back.move_relative(-amount, MOTOR_MAX_SPEED);
    right_front.move_relative(-amount, MOTOR_MAX_SPEED);
    right_back.move_relative(-amount, MOTOR_MAX_SPEED);
}
void square() {
 forward(127);
    turn(90);
    forward(127);
    turn(90);
    forward(127);
    turn(90);
    forward(127);
    turn(90);
void 


}
 }
void opcontrol() {
    Controller master(CONTROLLER_MASTER);
   
    return 0;
}
    while (true) {
        int forward = master.get_analog(ANALOG_LEFT_Y);
        int turn    = master.get_analog(ANALOG_RIGHT_X);

        drive(forward + turn, forward - turn);

        if (master.get_digital(DIGITAL_R1))
            arm_motor.move(80);
        else if (master.get_digital(DIGITAL_R2))
            arm_motor.move(-60);
        else
            arm_motor.move(10);

        if (master.get_digital(DIGITAL_L1))
            claw_motor.move(50);
        else if (master.get_digital(DIGITAL_L2))
            claw_motor.move(-50);
        else
            claw_motor.move(0);

        if (master.get_digital(DIGITAL_A))
            square();
            turn(90);
            forward(127);
            turn(90);
            backward(127);
            turn(90);
            

        delay(20);
    }
}
