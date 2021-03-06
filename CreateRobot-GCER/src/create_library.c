/*
  Code for the CREATE (iRobot vacuum cleaner, Roomba) robot movements.
  Contains the functions:
    -- create_forward
    -- create_backward
    -- create_left
    -- create_right
    -- test_create_movements
    -- print_create_battery_data

  Authors include:  Delaney, Ben G, Ben W, Caiden, Gavin, Elijah, Isaiah, Max, Ryland, and others.
  Date written:
    -- Version 2: Summer, 2018.
*/

#include <kipr/botball.h>
#include <time.h>
#include "constants.h"
#include "general_library.h"
#include "create_library.h"

float MILLIMETERS_PER_INCH = 25.4;
float LEFT_SPEED_MULTIPLIER_FOR_CREATE = 0.96;  // To correct veering
float RIGHT_SPEED_MULTIPLIER_FOR_CREATE = 1.0;  // To correct veering
float POWER_MULTIPLIER = 5.0;  // 100% power -> 500 mm / second (max speed)

// Makes the robot go straight FORWARD for the given number of inches
// at the given speed (1 to 100).
void create_forward(float inches, int speed) {
    int millimeters_robot_needs_to_move, millimeters_robot_has_moved;
    int left_speed, right_speed;

    millimeters_robot_needs_to_move = inches * MILLIMETERS_PER_INCH;
    left_speed = speed * POWER_MULTIPLIER * LEFT_SPEED_MULTIPLIER_FOR_CREATE;
    right_speed = speed * POWER_MULTIPLIER * RIGHT_SPEED_MULTIPLIER_FOR_CREATE;

    //printf("speeds and mm: %3d %3d %5d\n", left_speed, right_speed, millimeters_robot_needs_to_move);

    set_create_distance(0);
    create_drive_direct(left_speed, right_speed);
    while (TRUE) {
        millimeters_robot_has_moved = get_create_distance();
        if (millimeters_robot_has_moved  >= millimeters_robot_needs_to_move) {
            create_stop();
            break;
        }
    }

    millimeters_robot_has_moved = get_create_distance();
    printf("I moved %5.1f inches (%5d millimeters) FORWARD.\n",
           millimeters_robot_has_moved / MILLIMETERS_PER_INCH,
           millimeters_robot_has_moved);
    // CONSIDER: Move a bit more forward or backward to be more accurate?

    pause();
}

// Makes the robot go straight BACKWARD for the given number of inches
// at the given speed (1 to 100).
void create_backward(float inches, int speed) {
    int millimeters_robot_needs_to_move, millimeters_robot_has_moved;
    int left_speed, right_speed;

    millimeters_robot_needs_to_move = inches * MILLIMETERS_PER_INCH;
    left_speed = -speed * POWER_MULTIPLIER * LEFT_SPEED_MULTIPLIER_FOR_CREATE;   // Negative for BACKWARDS
    right_speed = -speed * POWER_MULTIPLIER * RIGHT_SPEED_MULTIPLIER_FOR_CREATE; // Negative for BACKWARDS

    set_create_distance(0);
    create_drive_direct(left_speed, right_speed);
    while (TRUE) {
        millimeters_robot_has_moved = -get_create_distance();  // Negative for BACKWARDS
        if (millimeters_robot_has_moved  >= millimeters_robot_needs_to_move) {
            create_stop();
            break;
        }
    }

    millimeters_robot_has_moved = -get_create_distance();  // Negative for BACKWARDS
    printf("I moved %5.1f inches (%5d millimeters) BACKWARDS.\n",
           millimeters_robot_has_moved / MILLIMETERS_PER_INCH,
           millimeters_robot_has_moved);
    // CONSIDER: Move a bit more forward or backward to be more accurate?

    pause();
}

// Makes the robot turn RIGHT (clockwise) for the given number of degrees
// at the given speed (1 to 100).
void create_right(float degrees, int speed) {
    int degrees_robot_needs_to_move, degrees_robot_has_moved;
    int wheel_speed;

    degrees_robot_needs_to_move = degrees;
    wheel_speed = speed * POWER_MULTIPLIER;

    set_create_total_angle(0);
    create_spin_CW(wheel_speed);

    while (TRUE) {
        degrees_robot_has_moved = -get_create_total_angle(); // Negative because moving CLOCKWISE
        if (degrees_robot_has_moved  >= degrees_robot_needs_to_move) {
            create_stop();
            break;
        }
    }

    degrees_robot_has_moved = -get_create_total_angle(); // Negative because moving CLOCKWISE
    printf("I moved %5d degrees RIGHT (clockwise).\n",
           degrees_robot_has_moved);
    // CONSIDER: Move a bit more right or left to be more accurate?

    pause();
}

// Makes the robot turn LEFT (counterclockwise) for the given number of degrees
// at the given speed (1 to 100).
void create_left(float degrees, int speed) {
    int degrees_robot_needs_to_move, degrees_robot_has_moved;
    int wheel_speed;

    degrees_robot_needs_to_move = degrees;
    wheel_speed = speed * POWER_MULTIPLIER;

    set_create_total_angle(0);
    create_spin_CCW(wheel_speed);

    while (TRUE) {
        degrees_robot_has_moved = get_create_total_angle();
        if (degrees_robot_has_moved  >= degrees_robot_needs_to_move) {
            create_stop();
            break;
        }
    }

    degrees_robot_has_moved = get_create_total_angle();
    printf("I moved %5d degrees LEFT (counterclockwise).\n",
           degrees_robot_has_moved);
    // CONSIDER: Move a bit more right or left to be more accurate?

    pause();
}

void spin_until_cube(int color) {
    int count;
    int area;

    // Spin until the camera sees an object of the desired color.
    create_spin_CW(30);
    while(1==1) {
        camera_update();
        count=get_object_count(color);
        if(count==0) {
            continue;
        }
        area=get_object_area(color, 0);
        // printf("area: %5d\n", area);
        if(area > BIG_ENOUGH_TO_BE_CONSIDERED) {
            create_stop();
            break;
        }
    }
}

// Rotate the robot until the center of the biggest blob of the given color
// that the camera sees is within DELTA_X of the given desired_x value.
void ROTATE_TO_X(int color, int desired_x, float rotate_seconds) {
    //CW = Clockwise = Create_right, CCW = Counter clockwise = Create_left
    int count, x, LOW, HIGH, PROG_START, pixel_diff;
    time_t seconds;
    time_t seconds_2;

    LOW = desired_x - L_DELTA;
    HIGH = desired_x + H_DELTA;
    
    seconds = time(NULL);

    while (TRUE) {
        // Quit if it has been trying too long.
        seconds_2 = time(NULL);
        PROG_START = seconds_2 - seconds;
        if (PROG_START > rotate_seconds) {
            //Does "seconds_2" - "seconds" equal greater than r_s?
            printf("Camera has exceded searching time limit.\n");
            break;
        }
        
        // Take a picture and rotate appropriately.
        camera_update();
        PRINT_BLOB(color);
        count=get_object_count(color);
        if (count == 0) {
            continue;
        }
        x = get_object_center(color, 0).x;
        if (x > LOW && x < HIGH) {
            create_stop();
            break;
        }
        if (x < LOW) {
            create_spin_CCW(MINIMUM_CCW_SPEED);
        }
        else if (x > HIGH) {
            create_spin_CW(MINIMUM_CW_SPEED);
        }
    }
    
    // The rest adjusts for overshoot.
    
    msleep(0.25);  // Let the robot come to rest.
    camera_update();
    x = get_object_center(color, 0).x;
    printf("Final spot is: %3d and desired is: %3d\n", desired_x);

    if (x < desired_x - L_DELTA) {
        pixel_diff = desired_x - x;
        create_left(pixel_diff * DEGREES_PER_PIXEL, MINIMUM_CCW_SPEED);
    }
    else if (x > desired_x) {
        pixel_diff = (x - desired_x) / 2;
        create_right(pixel_diff  * DEGREES_PER_PIXEL, MINIMUM_CW_SPEED);
    }
    
    msleep(0.25);  // Let the robot come to rest.
    camera_update();
    x = get_object_center(color, 0).x;
    printf("Final spot after adjustment is: %3d\n", x);
    
    pause();
}

// Print the x, y and size of the biggest blob of the given color that
// the camera sees. But do not print anything if the camera sees no blob of that color.
void PRINT_BLOB(int color) {
    int count, size, x, y;
    count = get_object_count(color);
    if (count > 0) {
        size = get_object_area(color, 0);
        x = get_object_center(color, 0).x;
        y = get_object_center(color, 0).y;
        printf("x and y coordinates and size = (%4d, %4d) %5d\n", x, y, size);
    }
}

void test_create_movements()
{
    //test_create_forward_backward(40);
    test_create_spin(20);
    test_create_spin(40);
    test_create_spin(60);
    test_create_spin(100);
}

void test_create_forward_backward(int speed)
{
    WAIT_FOR_A = TRUE;

    create_connect();
    create_full();

    print_create_battery_data();

    printf("\nTesting FORWARD  12.0 inches at %3d%% of full speed.\n", speed);
    create_forward(12.0, speed);

    printf("\nTesting BACKWARD 12.0 inches at %3d%% of full speed.\n", speed);
    create_backward(12.0, speed);

    printf("\nTesting FORWARD   6.0 inches at %3d%% of full speed.\n", speed);
    create_forward(6.0, speed);
    printf("\nTesting BACKWARD  6.0 inches at %3d%% of full speed.\n", speed);
    create_backward(6.0, speed);

    printf("\nTesting FORWARD   3.0 inches at %3d%% of full speed.\n", speed);
    create_forward(3.0, speed);
    printf("\nTesting BACKWARD  3.0 inches at %3d%% of full speed.\n", speed);
    create_backward(3.0, speed);

    printf("\nTesting FORWARD  24.0 inches at %3d%% of full speed.\n", speed);
    create_forward(24.0, speed);
    printf("\nTesting BACKWARD 24.0 inches at %3d%% of full speed.\n", speed);
    create_backward(24.0, speed);

    printf("\nTesting FORWARD  36.0 inches at %3d%% of full speed.\n", speed);
    create_forward(36.0, speed);
    printf("\nTesting BACKWARD 36.0 inches at %3d%% of full speed.\n", speed);
    create_backward(36.0, speed);

    create_disconnect();
}

void test_create_spin(int speed)
{
    WAIT_FOR_A = TRUE;

    create_connect();
    create_full();

    print_create_battery_data();

    printf("\nTesting RIGHT 90 degrees at %3d%% of full speed.\n", speed);
    create_right(90.0, speed);
    printf("\nTesting LEFT 90 degrees at %3d%% of full speed.\n", speed);
    create_left(90.0, speed);

    printf("\nTesting RIGHT 45 degrees at %3d%% of full speed.\n", speed);
    create_right(45.0, speed);
    printf("\nTesting LEFT 45 degrees at %3d%% of full speed.\n", speed);
    create_left(45.0, speed);

    printf("\nTesting RIGHT 180 degrees at %3d%% of full speed.\n", speed);
    create_right(180.0, speed);
    printf("\nTesting LEFT 90 degrees at %3d%% of full speed.\n", speed);
    create_left(180.0, speed);

    create_disconnect();
}

void print_create_battery_data()
{
    printf("\nBattery data:\n");
    printf("Charging state: %5d\n", get_create_battery_charging_state());
    printf("Voltage:        %5d\n", get_create_battery_voltage());
    printf("Current:        %5d\n", get_create_battery_current());
    printf("Temperature:    %5d\n", get_create_battery_temp());
    printf("Charge:         %5d\n", get_create_battery_charge());
    printf("Capacity:       %5d\n", get_create_battery_capacity());
    printf("\n");
}

void CAMERA_START() {
    int K;

    printf("STARTING CAMERA...\n");
    camera_open();
    for (K = 0; K < 10; K = K + 1) {
        camera_update();
        printf("UPDATING CAMERA...\n");
    }
    printf("CAMERA STARTED!\n");
}

void CAMERA_TESTING() {
    CAMERA_START();
    ROTATE_TO_X(GREEN, 80, 3);
    camera_close();
}
