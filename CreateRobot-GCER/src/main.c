/*
  Code for the CREATE robot in the SEEDING rounds
  in the GECR competition, July, 2018.

  Contains the MAIN function, which itself calls:
    -- setup_create
    -- run_create, which calls:
       -- run_create1  [which scores orange dates]
       -- run_create2  [which scores yellow Crates]
       ... Maybe "run_create3," etc.

  Authors include:  Delaney, Ben G, Ben W, Blaize, Caiden, Gavin, Elijah, Isaiah, Max, Ryland, and others.
  Date written: Spring, 2018.
*/

#include <kipr/botball.h>
#include "constants.h"
#include "general_library.h"
#include "create_library.h"

// TODO: Put the functions below in a more sensable place.  End up with only generic code in this file.
void choose_pause();
void choose_which_part_of_program_to_run();
void RUN_CREATE();
void testing();

int main() {
    // Set up the robot for starting:
    setup_create();  // Runs BEFORE hands-off

    // Decide whether PAUSE should be ON or OFF:
    //  -- ON:  the program waits for the human to press the A button.
    //  -- OFF: the program runs without interruption.
    choose_pause();

    // Do the light calibration:
    // printf("Do the   wait_for_lights   steps...\n");
    // wait_for_light(LIGHT_SENSOR);
    printf("Ready for the run to start!\n");
    pause();

    // The rest happens when the lights come back on.
    printf("  Robot has STARTED!\n\n");

    RUN_CREATE();
    return 0;

	// TODO: Fix the following or delete it.
    // But for TUNING and PRACTICE runs use the following
    // Select the program to run by using the A, B or C button:
    //choose_which_part_of_program_to_run();
    // return 0;
}

// Runs BEFORE hands-off.
void setup_create()
{
    printf("Set up the robot for starting, BEFORE hands-off...\n");
    turn_pause_on();  // No downside to pause being ON during setup.
    
    // Connect:
    printf("Connecting ...\n");
    create_connect();
    create_full();
    printf("  Connected!\n\n");
    
    // Move servos to their starting positions:
    printf("Moving the servos to their start positions...\n");
    
    // Arm servo:
    set_servo_position(0, PORT0_START);
    enable_servo(0);
    servo(0, STARTING_POSITION);  // Move here slowly, then relax (i.e., disable).
    printf("Disabling the arm servo so that it fits in the starting box...\n");
    disable_servo(0);
    printf("  Arm servo is disabled.\n\n");
    printf("Un-plug the arm servo, then GENTLY\n");
    printf("  move the arm to fit below 12 inches.\n");
    printf("  Plug the arm back in when you are done.\n\n");
    pause();
    
    // Not yet using the following ports, so commented out for now:
    /*
    set_servo_position(1, PORT1_START);
    set_servo_position(2, PORT2_START);
    set_servo_position(3, PORT3_START);
    enable_servo(1);
    enable_servo(2);
    enable_servo(3);
    */
    
    printf("  Setup (before HANDS-OFF) is DONE!\n\n");
    turn_pause_off();
}

void RUN_CREATE() {
    //run_create1();
    //run_create2();
    enable_servo(0);
    servo(0, MOVING_POSITION);
   
    // Move to Palm Tree #2.
    create_forward(21, 30);
    create_right(32, 28);  // was 35
    create_forward(10.25, 30); // was 10
    
    // Scrape Dates from Palm Tree #1 into the Date Bin.
    servo(0, PULLING_POSITION);
    create_backward(3.5, 10);  // was 4
    servo(0, MOVING_POSITION);  // Do a 2nd time just in case.
    create_forward(3.5, 30);
    servo(0, PULLING_POSITION);
    create_backward(3.5, 10);
    
    // Move to Palm Tree #2.
    servo(0, MOVING_POSITION);
    create_forward(5, 30);
    create_left(59, 30);
    
    // Scrape Dates from Palm Tree #2 into the Date Bin.
    servo(0, PULLING_POSITION);
    create_backward(5, 30);
    servo(0, MOVING_POSITION);  // Do a 2nd time just in case.
    create_forward(3, 30);
    servo(0, PULLING_POSITION);
    create_backward(5, 30);
}

void choose_pause()
{
    int button;

    while (TRUE) {
        button = get_button_press(
            "Press:\n  B to turn  pause  ON (i.e., waits for A)\n  C to turn  pause  OFF (i.e., runs without stopping).\n");
        if (button == B_BUTTON) {
            turn_pause_on();
            break;
        } else if (button == C_BUTTON) {
            turn_pause_off();
            break;
        } else {
            printf(" *** READ THE ABOVE. *** You must choose B or C.\n");
        }
    }
}

/*void choose_which_part_of_program_to_run()
{
    int button;

    button = get_button_press("Press:\n  B to run the Ring program.\n  C to run the yellow Crate program.\n   A to run everthing.\n");
    if (button == B_BUTTON) {
        
        
        
        
        
        
        
        +
            \]'
0        run_create1();
/
    } else if (button == C_BUTTON) {
        run_create2();
    } else {
        RUN_CREATE();
    }
}

void testing(){
    printf("Initiating Tetsting Sequence...");
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
}*/

