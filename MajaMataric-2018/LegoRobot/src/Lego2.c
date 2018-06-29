/*
  Code for the LEGO robot in the SEEDING rounds
  in the Greater St. Louis Regional tournament.
  Contains the functions:
    -- run_lego2  [scores the blue poms]

  Authors include:  Ben G, Ben W, Blaize, Caiden, Elijah, Gavin,
                    Ian, Isaiah, Max, Ryland, Sam, and others.
  Date written:
    -- Version 1: Spring, 2018.
*/

#include <kipr/botball.h>
#include "constants.h"
#include "general_library.h"
#include "lego_library.h"

void run_lego_transition()
{
    // Run with arm up because we don't have any poms at this point.
    servo(ARM, UP);
    
    // Get away from the end zone PVC.
    left(45, TURN_SPEED);
    forward(10, FAST);
    right(60, TURN_SPEED);//was 35
    
    // Square up against the PVC.
    forward(26, FAST);
    left(180, MEDIUM);
    backward(8, FAST);
    backward(4, SLOW);
    
    // Head toward blue poms.
    forward(6.5, FAST);//was 4
    right(90, TURN_SPEED);
    
    // sense the edge of starting box
    forward_until_black(50);
    forward(3, MEDIUM); //get past edge of starting box and before irrigation line
    forward_until_black(30);
    
    forward(5.5, MEDIUM); //get past edge of irrigation line
    right(87, TURN_SPEED);//was 90
}

void run_lego2()
{
    // Go toward the blue poms.
    //forward(7, 100);  // was 6.5  // No longer needed

    // Get all 12 blue poms into the cage and out of the blue-pom starting box.
    forward(0.5, FAST);
    servo(ARM, DOWN);  // Best position for moving backwards
    backward(12, 30);  // No faster, since pulling the poms out of the cage here
    servo(ARM, DOWN_FOR_MOVING);  // Best position for turning or going forwards

    // Go to the 1st blue tape.
    left(50, TURN_SPEED);  // was 50
    forward(11, FAST);  // Was 11.5
    left(23, TURN_SPEED);  //was 20

    // Leave 1 to 3 poms on the 1st blue tape.
    servo(ARM, DOWN_FOR_LEAVING_A_POM);
    backward(4, FAST);  // was 2
    servo(ARM, DOWN);  // Push down to release a pom or two
    forward(4.5, 30);  // Push released poms into the blue tape, must be SLOWLY  // was 2.5
    servo(ARM, DOWN_FOR_MOVING); // Continue to the next blue tape at regular speed

    // Go to the 2nd blue tape.
    backward(9, FAST);
    left(31, TURN_SPEED);  // was 30
    forward(9, FAST);  // was 8

    // Leave 1 to 3 poms on the 2nd blue tape.
    servo(ARM, DOWN_FOR_LEAVING_A_POM);
    backward(6, FAST);  // was 4
    servo(ARM, DOWN);  // Push down to release a pom or two
    forward(7.5, 30);  // Push released poms into the blue tape, must be SLOWLY // was 7.5
    backward(4, FAST);
    servo(ARM, DOWN_FOR_MOVING); // Continue to the next blue tape at regular speed
    
    // Go to the 3rd blue tape.
    left(30, TURN_SPEED);
    servo(ARM, ANGLE);
   	backward(3, FAST);
    servo(ARM, DOWN_FOR_MOVING);
    forward(16, FAST);
    forward(1, SLOW);
          
    disable_servos();
    /*

    // Leave 1 to 3 poms on the 3rd blue tape.
    servo(ARM, UP);
    backward(2, 100);
    servo(ARM, DOWN);

    servo(ARM, UP+845);  // David asks:  Why this?

    // Go to the 4th blue tape.
    backward(10, 100);
    servo(ARM, DOWN);
    backward(10, 100);
    left(45, 30);
    forward(40, 100);
    right(70, 30);
    forward(16, 100);
    */
}





