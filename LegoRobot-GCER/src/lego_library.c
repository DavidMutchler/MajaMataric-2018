/*
  Code for the LEGO robot movements.
  Contains the functions:
    -- forward
    -- backward
    -- left
    -- rightd

  Authors include:  Ben G, Ben W, Blaize, Caiden, Elijah, Gavin,
                    Ian, Isaiah, Max, Ryland, Sam, and others.
  Date written:
    -- Version 1: Spring, 2018.
*/

#include <kipr/botball.h>
#include "constants.h"
#include "general_library.h"
#include "lego_library.h"

// Consider: BACKWARD could ** call ** FORWARD instead of duplicating its code.
// Ditto RIGHT and LEFT.

// Makes the robot go straight FORWARD for the given number of inches
// at the given speed (1 to 100).
void forward(float inches, int speed) {
    int ticks_robot_needs_to_move, ticks_robot_has_moved;

    ticks_robot_needs_to_move = inches * TICKS_PER_INCH;
    clear_motor_position_counter(LEFT_MOTOR);
    clear_motor_position_counter(RIGHT_MOTOR);

    start_forward(speed);
    while (TRUE) {
        ticks_robot_has_moved = get_motor_position_counter(RIGHT_MOTOR);
        if (ticks_robot_has_moved >= ticks_robot_needs_to_move) {
            freeze(LEFT_MOTOR);
            freeze(RIGHT_MOTOR);
            break;
        }
    }
    
    ticks_robot_has_moved = get_motor_position_counter(RIGHT_MOTOR);
    printf("I moved %5.1f inches (%5d ticks) FORWARD.\n",
           ticks_robot_has_moved / TICKS_PER_INCH,
           ticks_robot_has_moved);
    // CONSIDER: Move a bit more forward or backward to be more accurate?
    
    pause();
}

// Makes the robot go straight BACKWARD for the given number of inches
// at the given speed (1 to 100).
void backward(float inches, int speed) {
    int ticks_robot_needs_to_move, ticks_robot_has_moved;

    ticks_robot_needs_to_move = inches * TICKS_PER_INCH;
    clear_motor_position_counter(LEFT_MOTOR);
    clear_motor_position_counter(RIGHT_MOTOR);

    start_backward(speed);
    while (TRUE) {
        ticks_robot_has_moved = -get_motor_position_counter(RIGHT_MOTOR); // Negative because moving BACKWARDS
        if (ticks_robot_has_moved >= ticks_robot_needs_to_move) {
            freeze(LEFT_MOTOR);
            freeze(RIGHT_MOTOR);
            break;
        }
    }
    
    ticks_robot_has_moved = -get_motor_position_counter(RIGHT_MOTOR); // Negative because moving BACKWARDS
    printf("I moved %5.1f inches (%5d ticks) BACKWARD.\n",
           ticks_robot_has_moved / TICKS_PER_INCH,
           ticks_robot_has_moved);
    // CONSIDER: Move a bit more forward or backward to be more accurate?
    
    pause();
}

// Makes the robot turn RIGHT (clockwise) for the given number of degrees
// at the given speed (1 to 100).
void right(float degrees, int speed) {
    int ticks_robot_needs_to_move, ticks_robot_has_moved;
    int left_speed, right_speed;

    ticks_robot_needs_to_move = degrees * TICKS_PER_DEGREE;
    left_speed = speed * LEFT_SPEED_MULTIPLIER;
    right_speed = speed * RIGHT_SPEED_MULTIPLIER;

    clear_motor_position_counter(LEFT_MOTOR);
    clear_motor_position_counter(RIGHT_MOTOR);
    motor(LEFT_MOTOR, left_speed);
    motor(RIGHT_MOTOR, -right_speed);  // Negative to go BACKWARDS
    while (TRUE) {
        ticks_robot_has_moved = -get_motor_position_counter(RIGHT_MOTOR); // Negative because moving BACKWARDS
        if (ticks_robot_has_moved  >= ticks_robot_needs_to_move) {
            freeze(LEFT_MOTOR);
            freeze(RIGHT_MOTOR);
            break;
        }
    }
    
    ticks_robot_has_moved = -get_motor_position_counter(RIGHT_MOTOR); // Negative because moving BACKWARDS
    printf("I moved %5.1f degrees (%4d ticks) RIGHT.\n",
           ticks_robot_has_moved / TICKS_PER_DEGREE,
           ticks_robot_has_moved);
    // CONSIDER: Move a bit more right or left to be more accurate?
    
    pause();
}

// Makes the robot turn LEFT (counterclockwise) for the given number of degrees
// at the given speed (1 to 100).
void left(float degrees, int speed) {
    int ticks_robot_needs_to_move, ticks_robot_has_moved;
    int left_speed, right_speed;

    ticks_robot_needs_to_move = degrees * TICKS_PER_DEGREE;
    left_speed = speed * LEFT_SPEED_MULTIPLIER;
    right_speed = speed * RIGHT_SPEED_MULTIPLIER;

    clear_motor_position_counter(LEFT_MOTOR);
    clear_motor_position_counter(RIGHT_MOTOR);
    motor(LEFT_MOTOR, -left_speed);  // Negative to go BACKWARDS
    motor(RIGHT_MOTOR, right_speed);
    while (TRUE) {
        ticks_robot_has_moved = get_motor_position_counter(RIGHT_MOTOR);
        if (ticks_robot_has_moved  >= ticks_robot_needs_to_move) {
            freeze(LEFT_MOTOR);
            freeze(RIGHT_MOTOR);
            break;
        }
    }
    
    ticks_robot_has_moved = get_motor_position_counter(RIGHT_MOTOR);
    printf("I moved %5.1f degrees (%4d ticks) LEFT.\n",
           ticks_robot_has_moved / TICKS_PER_DEGREE,
           ticks_robot_has_moved);
    // CONSIDER: Move a bit more right or left to be more accurate?
    
    pause();
}

// Makes the robot START moving straight FORWARD at the given speed (1 to 100).
void start_forward(int speed) {
    int left_speed, right_speed;

    left_speed = speed * LEFT_SPEED_MULTIPLIER;
    right_speed = speed * RIGHT_SPEED_MULTIPLIER;

    motor(LEFT_MOTOR, left_speed);
    motor(RIGHT_MOTOR, right_speed);
}

// Makes the robot START moving straight BACKWARD at the given speed (1 to 100).
void start_backward(int speed) {
    start_forward(-speed);
}

// Makes the robot START turning RIGHT (clockwise) at the given speed (1 to 100).
void start_right(int speed) {
    int left_speed, right_speed;

    left_speed = speed * LEFT_SPEED_MULTIPLIER;
    right_speed = speed * RIGHT_SPEED_MULTIPLIER;

    motor(LEFT_MOTOR, left_speed);
    motor(RIGHT_MOTOR, -right_speed);  // Negative to go BACKWARDS
}

// Makes the robot START turning LEFT (counterclockwise) at the given speed (1 to 100).
void start_left(int speed) {
    start_right(-speed);
}

void test_movements() {
    WAIT_FOR_A = TRUE;
    
    printf("\nTesting FORWARD  12.0 inches at full speed.\n");
    forward(12.0, 100);
    printf("\nTesting BACKWARD 12.0 inches at full speed.\n");
    backward(12.0, 100);
    
    printf("\nTesting FORWARD   6.0 inches at full speed.\n");
    forward(6.0, 100);
    printf("\nTesting BACKWARD  6.0 inches at full speed.\n");
    backward(6.0, 100);
    
    printf("\nTesting FORWARD   3.0 inches at full speed.\n");
    forward(3.0, 100);
    printf("\nTesting BACKWARD  3.0 inches at full speed.\n");
    backward(3.0, 100);
    
    printf("\nTesting FORWARD  24.0 inches at full speed.\n");
    forward(24.0, 100);
    printf("\nTesting BACKWARD 24.0 inches at full speed.\n");
    backward(24.0, 100);
    
    printf("\nTesting FORWARD  36.0 inches at full speed.\n");
    forward(36.0, 100);
    printf("\nTesting BACKWARD 36.0 inches at full speed.\n");
    backward(36.0, 100);
}

// Go forward at the given speed until either line sensor sees BLACK.
void forward_until_black(int speed) {
    int left_speed, right_speed;
    int left_sensor_reading, right_sensor_reading;
    
    // Adjust speed for possible veer, then turn on the motors:
	left_speed = speed * LEFT_SPEED_MULTIPLIER;
    right_speed = speed * RIGHT_SPEED_MULTIPLIER;
    motor(LEFT_MOTOR, left_speed);
    motor(RIGHT_MOTOR, right_speed);
    
    // Keep going until a line sensor sees BLACK.
    while (TRUE) {
        left_sensor_reading = analog(LEFT_LINE_SENSOR);
        right_sensor_reading = analog(RIGHT_LINE_SENSOR);
        
        if (left_sensor_reading >= LEFT_LINE_SENSOR_SEES_BLACK || right_sensor_reading >= RIGHT_LINE_SENSOR_SEES_BLACK)
        {
            ao();
            break;
        }
        msleep(10);//was 20
	}
}

// Go forward at the given speed following a black line for a given distance.
void forward_on_line(int speed,float inches)
{
    int ticks_robot_needs_to_move, ticks_robot_has_moved;
	int left_speed, right_speed;
    int left_sensor_reading, right_sensor_reading;
    
    // Adjust speed for possible veer, then turn on the motors:
    ticks_robot_needs_to_move = inches * TICKS_PER_INCH;
    left_speed = speed * LEFT_SPEED_MULTIPLIER;
    right_speed = speed * RIGHT_SPEED_MULTIPLIER;
    motor(LEFT_MOTOR, left_speed);
    motor(RIGHT_MOTOR, right_speed);
    
    // Keep following a line sensor until inches is reached.
    while (TRUE)
    {
        left_sensor_reading = analog(LEFT_LINE_SENSOR);
        right_sensor_reading = analog(RIGHT_LINE_SENSOR);
        ticks_robot_has_moved = get_motor_position_counter(RIGHT_MOTOR);
    //
    // CHANGE TO FOLLOW LINE INSTEAD OF STOP AT BLACK
    //
        if (left_sensor_reading >= LEFT_LINE_SENSOR_SEES_BLACK || right_sensor_reading >= RIGHT_LINE_SENSOR_SEES_BLACK || ticks_robot_has_moved  >= ticks_robot_needs_to_move)
        {
            ao();
            break;
        }

        msleep(10);//was 20
	}
}