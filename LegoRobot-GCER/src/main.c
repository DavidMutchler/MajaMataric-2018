/*
  Code for the LEGO robot in 2018 Botball.  Final version for GCER.
  Contains the MAIN function, which itself calls:
    -- before_lights_on
    -- after_lights_on

  Authors include:  Delaney, Ben G, Ben W, Blaize, Caiden, Gavin, Elijah, Isaiah, Max, Ryland, and others.
  Date written: Spring and Summer, 2018.
*/

#include <kipr/botball.h>
#include "constants.h"
#include "general_library.h"
#include "create_library.h"

// TODO: Put the functions below in a more sensible place.  End up with only generic code in this file?
void choose_pause();
int choose_lights();
enum PROGRAM choose_which_part_of_program_to_run();
void prepare_to_run(enum PROGRAM program_part, int use_lights);

void RUN_CREATE();
void testing();

int main() {
    enum PROGRAM program_part;
    int use_lights;

    // Step 1: Set up the robot for starting:
    setup_create();  // Runs BEFORE hands-off

    // Step 2: Decide whether PAUSE should be ON or OFF:
    //  -- ON:  the program waits for the human to press the A button.
    //  -- OFF: the program runs without interruption.
    choose_pause();

    // Step 3: Decide whether or not to use the lights to start the robot.
    use_lights = choose_lights();

    // Step 4: Decide which program to run by using the A, B or C button:
    program_part = choose_which_part_of_program_to_run();

    // Step 5: Calibrate lights or otherwise prepare to run:
    prepare_to_run(program_part, use_lights);

    // The rest happens when the lights come back on.
    printf("  Robot has STARTED!\n\n");

    RUN_CREATE();
    return 0;
}

// Runs BEFORE hands-off.
void setup_create()
{
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
    printf("Disabling the arm servo so that it fits in the starting box...\n");
    disable_servo(0);
    printf("  Un-plug the arm servo, then GENTLY:\n");
    printf("  -- Move the arm to fit below 12 inches.\n");
    printf("  -- Plug the arm back in when you are done.\n\n");
    pause();

    // Initialize the camera.
    CAMERA_START();

    // Turn pause back off (to be set as desired later in the starting-process).
    printf("  Setup (before HANDS-OFF) is DONE!\n\n");
    turn_pause_off();
}

// Runs AFTER  setup  but BEFORE hands-off.
// Allows the user to choose whether PAUSE should be ON or OFF:
//    -- ON:  the program waits for the human to press the A button.
//    -- OFF: the program runs without interruption.
void choose_pause() {
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

// Runs AFTER  choose_pause  but BEFORE hands-off.
// Allows the user to choose whether PAUSE should be ON or OFF:
//    -- ON:  the program waits for the human to press the A button.
//    -- OFF: the program runs without interruption.
enum PROGRAM choose_which_part_of_program_to_run() {
    return PROGRAM_DATES;
    /*
    int button;

    button = get_button_press("Press:\n  B to run the Ring program.\n  C to run the yellow Crate program.\n   A to run everthing.\n");
    if (button == B_BUTTON) {
        run_create1();
    } else if (button == C_BUTTON) {
        run_create2();
    } else {
        RUN_CREATE();
    }*/
}

// Runs AFTER  choose_pause  but BEFORE hands-off.
// Allows the user to choose whether or not to use the lights for starting the robot.
// Returns either TRUE (use the lights) or FALSE (do not choose the lights), per the user's choice.
int choose_lights() {
    int button;

    while (TRUE) {
        button = get_button_press(
            "Press:\n  B to NOT use the lights\n  C to USE the lights.\n");
        if (button == B_BUTTON) {
            return FALSE;
        } else if (button == C_BUTTON) {
            return TRUE;
        } else {
            printf(" *** READ THE ABOVE. *** You must choose B or C.\n");
        }
    }
}

void prepare_to_run(enum PROGRAM program_part, int use_lights) {
    printf("IMPORTANT: Check that the following is correct!\n");
    printf("  Pause is:   %s.\n", get_pause_state());
    printf("  Program is: DATES.\n");

    if (use_lights) {
    	// Do the light calibration:
    	printf("Do the   wait_for_lights   steps...\n");
    	wait_for_light(LIGHT_SENSOR);
    } else {
        printf("Ready for the run to start!\n");
        pause();
    }
}

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

void RUN_CREATE() {
    // Put the ARM into the position for MOVING.
    enable_servo(0);
    servo(0, MOVING_POSITION);

    // Move to Palm Tree #2.
    create_forward(22.5, 30);  // was 21
    create_right(37, 10);  // was 32
    ROTATE_TO_X(PINKISH_ORANGE, 75);
    create_forward(4.5, 30); // was 4.9
    // ROTATE_TO_X(PINKISH_ORANGE, 75);
    create_forward(5.1, 30);
    pause();

    // Scrape Dates from Palm Tree #2 into the Date Bin.
    servo(0, PULLING_POSITION);
    create_backward(6.0, 5);  // was 5.0
    servo(0, MOVING_POSITION);  // Do a 2nd time just in case.
    create_forward(6.0, 30);
    servo(0, PULLING_POSITION);
    create_backward(6.0, 5);

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
}


/*
  Code for the LEGO robot in the SEEDING rounds
  in the Greater St. Louis Regional tournament, April 14, 2018.

  Contains the MAIN function, which itself calls:
    -- setup_lego
    -- run_lego, which calls:
       -- run_lego1  [which scores the red/green poms]
       -- run_lego_transition  [which moves the robot into position to get the blue poms]
       -- run_lego2  [which scores the blue poms]

  Authors include:  Delaney, Ben G, Ben W, Blaize, Caiden, Elijah, Gavin,
                    Ian, Isaiah, Max, Ryland, Sam, and others.
  Date written:
    -- Version 1: Spring, 2018.
*/

#include <kipr/botball.h>
#include "constants.h"
#include "general_library.h"
#include "lego_library.h"
void choose_pause();
void choose_which_part_of_program_to_run();
void run_lego();
void testing();

int main()
{
    testing();
    return 0;
    // Set up the robot for starting:
    printf("Set up the robot for starting...\n");
    setup_lego();  // Runs BEFORE hands-off
    printf("  Setup is DONE!\n\n");

    // Decide whether PAUSE should be ON
    //   (i.e., the program waits for the human to press the A button,
    // or OFF (i.e., the program runs without interruption).
    choose_pause();
    /*
    if (WAIT_FOR_A == TRUE) {
        printf("\n\n\n\n\n\n\n   ** Pause is ON **.\n");
        printf("   If this is a REAL (tournament) run,\n");
        printf("   STOP the program and RESTART it NOW!\n\n\n");
        pause();
    }

    // Do the light calibration:
    printf("Do the   wait_for_lights   steps...\n");
    wait_for_light(LEGO_LIGHT_SENSOR);
    shut_down_in(119.5);
*/
    // The rest happens when the lights come back on.
    printf("  Robot has STARTED!\n\n");

    // For REAL runs, use the following:
    run_lego(); return 0;


    // But for TUNING and PRACTICE runs use the following
    // Select the program to run by using the A, B or C button:
    choose_which_part_of_program_to_run();

    return 0;
}

void setup_lego()
{
    turn_pause_on();
    
    /*  The team is practiced enough to skip these instructions:
    
    // Put the ARM into its starting position:
    printf("Is the arm at the half-way up position (approximately)?\n");
    printf("If NOT:\n");
    printf("  UN-plug the sole servo.\n");
    printf("  Then GENTLY, using your hands on the WHITE beam\n");
    printf("  that is attached to the servo, put the arm into\n");
    printf("  the half-way up position (approximately).\n");
    printf("  Then plug the servo back into port 0.\n");
    printf("Be ready for the arm to move to its UP position soon.\n");
    printf("\n *** READ THE ABOVE BEFORE PROCEEDING. ***\n\n");
    pause();
    */

    set_servo_position(ARM, HALF_WAY_UP);
    enable_servos();
    servo(ARM, UP);

    // Put the ROBOT into its starting position:
    printf("\n\n\n");
    printf("Locate the bottom black bar on the robot.\n");
    printf("Line the robot up so that:\n");
    printf("  -- The robot points toward the closest red/green\n");
    printf("       pile of poms, and is centered on that pile.\n");
    printf("  -- The bottom black bar on the robot is on the black\n");
    printf("       tape just BARELY ** OUTSIDE ** the starting box.\n");
    printf("\nThe robot will soon move backwards\n");
    printf("  to get into its starting position.\n");
    pause();

    turn_pause_off();
    backward(4, 30); //was 3.5
}

void run_lego()
{
    //turn_pause_on();
    run_lego1();
    run_lego_transition();
    run_lego2();
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

void choose_which_part_of_program_to_run()
{
    int button;

    button = get_button_press("Press:\n  B to run the red/green pom program.\n  C to run the blue pom program.\n   A to run everthing.\n");
    if (button == B_BUTTON) {
        run_lego1();
    } else if (button == C_BUTTON) {
        run_lego2();
    } else {
        run_lego();
    }
}

void testing(){
    forward(23.5, 35);
    right(90, 35);
    forward(6.25, 35);
    backward(9.5, 35);
    
    
    
    
}
    
   
