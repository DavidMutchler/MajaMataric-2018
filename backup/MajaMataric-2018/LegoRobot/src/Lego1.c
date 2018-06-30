/*
  Code for the LEGO robot in the SEEDING rounds
  in the Greater St. Louis Regional tournament.
  Contains the functions:
    -- run_lego1  [scores the red/green poms]
    
  Authors include:  Ben G, Ben W, Blaize, Caiden, Elijah, Gavin,
                    Ian, Isaiah, Max, Ryland, Sam, and others.
  Date written:
    -- Version 1: Spring, 2018.
*/

#include <kipr/botball.h>
#include "constants.h"
#include "general_library.h"
#include "lego_library.h"

void grab_poms(int inches);

void run_lego1()
{
    printf("Starting to score the red/green poms.\n");
    pause();

    // Get the 1st set of red/green poms into the cage.
    forward(4.5, FAST); //was 4 changed because moved back an extra 0.5 in setup to ensure inside the box
    servo(ARM, DOWN);  // To trap the poms.
    servo(ARM, DOWN_FOR_MOVING);  // To be ready to move with the poms.
    
    // Go to the 2nd set of red/green poms and get them into the cage.
    backward(3.75, FAST);//was 4
    right(33, TURN_SPEED); 
    forward(2.25, FAST); //was 1.5
    grab_poms(5.5);  // Go forward 5.5 inches, then lower cage. See the definition of  grab_poms  below.
    //was 4
    
    // Go to the 3rd set of red/green poms and get them into the cage.b
    backward(4, FAST);
    right(18, TURN_SPEED);  
    forward(9, FAST);  // Was 8.5
    grab_poms(5);  // 5 inches
    
    forward(10,FAST);
    right(28, TURN_SPEED);//was 21 then 26
    forward(20, FAST);
    grab_poms(5);
    forward(9, FAST);
    grab_poms(5);
    forward(6, SLOW);
    grab_poms(5);
    // Head toward the end zone into which we will put the red/green poms.
    // Go partway at this point.
    right(47, TURN_SPEED);  // was 43
    forward(15.5, FAST);//was 13.5
    
    // Turn left a bit to avoid the yellow cube.
    // Then raise the cage a bit to go over the FRP divider.
    // After going over the FRP divider, turn right to get back toward the PVC.
    // Continue to the end zone, letting the cage hit the PVC
    // and run along the PVC to straighten up the robot.
    
    left(5, TURN_SPEED);
    servo(ARM, DOWN_FOR_MOVING - 100);  // A bit up from its usual position
    
    // Wait for other robot to get out of the way.
    msleep(10000);
    
    forward(12.0, FAST);//was 8
    servo(ARM, DOWN_FOR_MOVING);
    right(5, TURN_SPEED); //was 10, trying to keep stress over the cage
    forward(10, FAST); //was 10.5

    // Deposit the 12 poms collected so far.  To do so:
    // Step 1: Lift the cage, go backward a bit,
    //         turn left, lower the cage, and go forward a bit.
    servo(ARM, UP);
    backward(2, SLOW);
    left(30, TURN_SPEED); //was 50
    servo(ARM, DOWN_FOR_MOVING);
    forward(1, FAST);
    
    // Step 2 for depositing the 12 poms collected so far
    //   is to gently turn right with the cage down,
    //   thus pushing the poms into the end zone if they are not already there.
    //   We want just the right amount of turn, so we use a sensor, like this:
    //      1. Turn on the motors to make the robot spin right.
    //      2. Go until the right line-sensor sees the black line of the end zone.
    //      3. Turn right a little more.
    motor(LEFT_MOTOR, TURN_SPEED);
    motor(RIGHT_MOTOR, -TURN_SPEED);
    while (1+5==6)
    {
        if (analog(RIGHT_LINE_SENSOR) > RIGHT_LINE_SENSOR_SEES_BLACK)
        {
            ao();  // Turn off all motors (i.e. stop).
            break; // Leave the WHILE loop, continuing BELOW its end.
        }
        msleep(20);
    }
    right(10, SLOW);
        
    // Go to the 4th set of red/green poms.
    /*left(70,SLOW);
    forward_until_black(50);
    msleep(3000);*/
    
    //left(85, 50);
    //forward_until_black(50);
    return;
    /*
    // Get the 4th set of red/green poms into the cage.
    servo(ARM, ANGLE);
    forward(6, SLOW);  // Was 4
	servo(ARM, DOWN);  // To trap the poms.
    servo(ARM, DOWN_FOR_MOVING);  // To be ready to move with the poms.
    
    // Deposit the 15 red/green poms currently in the cage into the end zone.
    forward(5.5, 100);
    right(80, TURN_SPEED);
    forward(5, 100);
    forward(2.5, SLOW);
    

    // Go to and get the 5th set of red/green poms into the cage.
    forward(8.5, 100);  // Was 9
    
    
    
    // Go to and get the 6th set of red/green poms into the cage.
    forward(8, 100);
    
    servo(ARM, ANGLE);
    forward(5, SLOW);
    servo(ARM, DOWN);
    servo(ARM, DOWN_FOR_MOVING);  // To be ready to move with the poms.

    // Put all the red/green poms into the endzone nearest where the robot is currently.
    // Strive to ensure all are scoring, i.e., within the zone and touching the table.
    */
}

void grab_poms(int inches)
{
    servo(ARM, ANGLE);  // Just enough to skim over the top of the pile of 4 poms
    forward(inches, SLOW);  // To avoid accidentally knocking down the pile.
	servo(ARM, DOWN);  // To trap the poms.
    servo(ARM, DOWN_FOR_MOVING);  // To be ready to move with the poms.
}

