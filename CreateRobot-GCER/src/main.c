/*******************************************************************************
  Code for the CREATE robot in 2018 Botball.  Final version for GCER.

  Contains the MAIN function, which itself calls:
    -- before_hands_off, which itself calls:
         -- 
    -- run_create, which calls:
       -- run_create1  [which scores orange dates]
       -- run_create2  [which scores yellow Crates]
       ... Maybe "run_create3," etc.

  Authors include:  Delaney, Ben G, Ben W, Blaize, Caiden, Gavin, Elijah, Isaiah, Max, Ryland, and others.
  Date written: Spring and Summer, 2018.
*******************************************************************************/

#include <kipr/botball.h>
#include "main.h"
#include "general_library.h"
#include "create_library.h"

/*******************************************************************************
  The program starts here. DONE.
*******************************************************************************/
int main() {
    enum PROGRAM program;

    program = before_hands_off();
    after_hands_off(program);

    return 0;
}

/*******************************************************************************
  Code that runs AFTER hands-off.  DONE.
*******************************************************************************/
void after_hands_off(enum PROGRAM program) {
    printf("  Robot has STARTED!\n\n");
    RUN_CREATE(program);
}

/*******************************************************************************
  Set up the Create in the starting box.
*******************************************************************************/
void setup_create() {
    // Pause is always ON during setup, to ensure that all goes correctly.
    printf("Set up the robot for starting, BEFORE hands-off...\n");
    turn_pause_on();

    // Connect to the Create robot, putting it in FULL mode.
    printf("Connecting ...\n");
    create_connect();
    create_full();
    printf("  Connected!\n\n");

    // Move the ARM servo to its starting positions.
    printf("Moving the ARM servo to its start position...\n");
    set_servo_position(0, PORT0_START);
    enable_servo(0);
    servo(0, STARTING_POSITION);  // Move here slowly, then relax (i.e., disable).
    disable_servo(0);
    
    printf("  UN-PLUG the arm servo, then GENTLY:\n");
    printf("    -- Move the arm to fit below 12 inches.\n");
    printf("    -- Plug the arm back in when you are done.\n\n");
    pause();

    // Initialize the camera.
    CAMERA_START();

    // Turn pause back off (to be set as desired later in the starting-process).
    turn_pause_off();
    
    printf("  Setup (before HANDS-OFF) is DONE!\n\n");
}

/*******************************************************************************
  TODO: Clean up this function.
  TODO: Add an appropriate comment here.
*******************************************************************************/
void testing(){
    printf("Initiating Testing Sequence...");
    create_forward(21, 60);
    msleep(1000);
    servo(RING_ARM, 600);
    msleep(1000);
    printf("Note: Robot to complete future movement in next few seconds.");
    msleep(5000);
    create_backward(10, 60);
    msleep(1000);
    create_left(90, 60);
    msleep(1000);
    create_forward(13.5, 60);
    msleep(1000);
    create_right(90, 60);
    msleep(1000);
    create_forward(10, 60);
    msleep(1000);
    servo(RING_ARM, 600);
    msleep(1000);
    printf("Note: Robot to complete future movement in next few seconds.");
    msleep(5000);
    create_backward(10, 60);
    msleep(1000);
    create_left(90, 60);
    msleep(1000);
    create_forward(13.5, 60);
    msleep(1000);
    create_right(90, 60);
    msleep(1000);
    create_forward(10, 60);
    msleep(1000);
    servo(RING_ARM, 600);
    msleep(1000);
    printf("Note: Robot to complete future movement in next few seconds.");
    msleep(5000);
    create_backward(10, 60);
    msleep(1000);
    create_left(90, 60);
    msleep(1000);
    create_forward(26, 60);
    msleep(1000);
    create_right(90, 60);
    msleep(1000);
    create_forward(10, 60);
    msleep(1000);
    servo(RING_ARM, 600);
    msleep(1000);
    printf("Note: Robot to complete future movement in next few seconds.");
    msleep(5000);
    create_backward(10, 60);
    msleep(1000);
    create_left(90, 60);
    msleep(1000);
    create_forward(13.5, 60);
    msleep(1000);
    create_right(90, 60);
    msleep(1000);
    create_forward(10, 60);
    msleep(1000);
    servo(RING_ARM, 600);
    msleep(1000);
    printf("Note: Robot to complete future movement in next few seconds.");
    msleep(5000);
    create_backward(10, 60);
    msleep(1000);
    create_left(90, 60);
    msleep(1000);
    create_forward(13.5, 60);
    msleep(1000);
    create_right(90, 60);
    msleep(1000);
    create_forward(10, 60);
    msleep(1000);
    servo(RING_ARM, 600);
    msleep(1000);
    printf("Note: Robot to complete future movement in next few seconds.");
    msleep(5000);
    create_backward(10, 60);
    msleep(1000);
    create_left(90, 60);
    msleep(1000);
    create_forward(13.5, 60);
    msleep(1000);
    create_right(90, 60);
    msleep(1000);
    printf("Testing Sequence Complete.");
}

/*******************************************************************************
  Run the specified program or program part.
*******************************************************************************/
void RUN_CREATE(enum PROGRAM program) {
    
    // Put the ARM into the position for MOVING.
    enable_servo(0);
    servo(0, MOVING_POSITION);

    // Move to Palm Tree #2.
    create_forward(27, 30);  // was 26
    create_right(45, 10);  // was 37
    ROTATE_TO_X(PINKISH_ORANGE, 78, 5);  // Was 80
    create_forward(4.5, 30); // was 4.7

    // Scrape Dates from Palm Tree #2 into the Date Bin.
    servo(0, PULLING_POSITION);
    create_backward(5.0, 5);  // was 6.0
    servo(0, MOVING_POSITION);  // Do a 2nd time just in case.
    create_forward(5.0, 30);
    servo(0, PULLING_POSITION);
    create_backward(5.0, 5);

    // Move to Palm Tree #1.
    servo(0, MOVING_POSITION);
    create_forward(5, 30);
    create_left(59, 30);

    // Scrape Dates from Palm Tree #1 into the Date Bin.
    servo(0, PULLING_POSITION);
    create_backward(5, 30);
    servo(0, MOVING_POSITION);  // Do a 2nd time just in case.
    create_forward(3, 30);
    servo(0, PULLING_POSITION);
    create_backward(5, 30);
    
    create_stop();
    create_disconnect();
}
