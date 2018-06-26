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

//To Do...Put functions below in a more sensable place
void choose_pause();
void choose_which_part_of_program_to_run();
void RUN_CREATE();
void testing();

int main() {
    // Set up the robot for starting:
    printf("Set up the robot for starting...\n");
    setup_create();  // Runs BEFORE hands-off
    printf("  Setup is DONE!\n\n");

    // Decide whether PAUSE should be ON
    //   (i.e., the program waits for the human to press the A button,
    // or OFF (i.e., the program runs without interruption).
    //choose_pause();

    //turn_pause_off();    // Use this for REAL runs.
    turn_pause_on();     // Use this for TUNING and practice.

    // Do the light calibration:
    //printf("Do the   wait_for_lights   steps...\n");
    //wait_for_light(LEGO_LIGHT_SENSOR);

    // The rest happens when the lights come back on.
    printf("  Robot has STARTED!\n\n");

    //For REAL runs, use the following:
    RUN_CREATE(); 
    return 0;


    // But for TUNING and PRACTICE runs use the following
    // Select the program to run by using the A, B or C button:
    //choose_which_part_of_program_to_run();

    return 0;
}

void setup_create()
{
    turn_pause_on();
    
    printf("Connecting ...\n");
    create_connect();
    create_full();
    printf("  Connected!\n\n");
    
    // Initial positions of all ports:
    /*set_servo_position(0, PORT0_START);
    set_servo_position(1, PORT1_START);
    set_servo_position(2, PORT2_START);
    set_servo_position(3, PORT3_START);*/

    enable_servo(0);
    enable_servo(1);
    enable_servo(2);
    enable_servo(3);

    turn_pause_off();
}

void RUN_CREATE() {
    //run_create1();
    //run_create2();
    servo(0, 791);
    create_forward(17, 30);
    create_right(26, 30);
    create_forward(12, 30);
    servo(0, 1660);
    create_backward(5, 30);
    servo(0, 791);
    create_forward(5, 30);
    servo(0, 1660);
    create_backward(5, 30);
    create_left(46, 30);
    create_forward(3, 30);
    servo(0, 1660);
    create_backward(6, 30);
    servo(0, 791);
    create_forward(6, 30);
    servo(0, 1660);
    create_backward(6, 30);
    servo(0, 791);
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

