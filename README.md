# VEX Text Sim

C++ programs that simulate a VEX V5 robot using **keyboard input and `cout` output** — no hardware required. Runs in any C++ compiler, including browser-based ones like Replit.

Robot methods (`driveFor`, `turnFor`) match real VEXcode commands, so simulator code transfers directly to the V5.

## How to run

```
g++ 02_heading_drive.cpp -o robot
./robot
```

Type a letter + **Enter** for each move. Type `.` to quit.

**Browser:** paste a file into a Replit C++ project and hit Run.

## The five examples

| File | What it does | Key concepts |
|---|---|---|
| `01_grid_drive.cpp` | WASD moves on a grid; prints x, y | variables, `while`, `if/else` |
| `02_heading_drive.cpp` | Robot drives the way it's **facing**; A/D turn, Q/E arm | struct, methods, headings, trig |
| `03_autonomous.cpp` | Robot runs a **script** — no keyboard | functions, `for` loop, composing methods |
| `04_ascii_map.cpp` | Redraws the field as a grid with an arrow for the robot | nested loops, rendering from data |
| `05_sensor_game.cpp` | Drive to target `T` using a distance sensor; reach it to win | sensors, `sqrt`, win condition |

Each builds on the last. Start at `01`, work forward.

## Match project

The `project/` folder is a complete match simulation that combines the examples into one structured program:

```
project/
  robot.h    — Robot struct with driveFor, turnFor, claw methods
  field.h    — ASCII field renderer with target tracking
  main.cpp   — Autonomous period → driver control, like a real match
```

```
cd project
g++ main.cpp -o match && ./match
```

Edit `autonomous()` in `main.cpp` to write your own auto routine, then drive in the control period.

## Why it mirrors the real robot

```cpp
robot.driveFor(3);
robot.turnFor(90);
```

Same method names as VEXcode. Students debug logic with instant text feedback, then port proven routines to hardware.
