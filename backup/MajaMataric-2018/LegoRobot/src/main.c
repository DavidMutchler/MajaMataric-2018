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
    
   
