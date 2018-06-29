/*
  Code for the CREATE (iRobot vacuum cleaner, Roomba) robot movements.
  Contains the functions:
    -- create_forward
    -- create_backward
    -- create_left
    -- create_right
    -- test_create_movements
    -- test_create_forward_backward
    -- test_create_spin
    -- print_create_battery_data

  Authors include:  Ben G, Ben W, Caiden, Gavin, Elijah, Isaiah, Max, Ryland, and others.
  Date written:
    -- Version 1: Spring, 2018.
*/

#include <kipr/botball.h>

extern float TICKS_PER_INCH;
extern float TICKS_PER_DEGREE;
extern float LEFT_SPEED_MULTIPLIER_FOR_CREATE;  // To correct veering
extern float RIGHT_SPEED_MULTIPLIER_FOR_CREATE;

void create_forward(float inches, int speed);
void create_backward(float inches, int speed);
void create_left(float degrees, int speed);
void create_right(float degrees, int speed);

void ROTATE_TO_X(int color, int desired_x);
void PRINT_BLOB(int color);
void CAMERA_START();
void CAMERA_TESTING();

void test_create_movements();
void test_create_forward_backward(int speed);
void test_create_spin(int speed);
void print_create_battery_data();

