/*
  Code for the CREATE robot in 2018 Botball.  Final version for GCER.
  Contains the functions:

  Authors include:  Ben G, Ben W, Caiden, Gavin, Elijah, Isaiah, Max, Ryland, and others.
  Date written: Spring, 2018.
*/

#include <kipr/botball.h>
#include "constants.h"
#include "general_library.h"
#include "create_library.h"

void center();
void spin_until_cube(int color);

// Starting in the opposite starting box from where the robot started,
// score the yellow Crates.
void run_create2()
{    
    create_forward(11, 100);
    create_right(88, 50);
    create_forward(38, 100);
    create_left(100, 50);
    create_forward(2, 100);

    // Grab the cube.
    create_backward(3, 100);
    create_left(190, 50);

    // Drop the cube.
    create_right(182, 50);

    // Turn 
    //create_left(180, 50);   

    create_disconnect();
}
// CREATE TEAM WE NEED HELP
void run_create1() 
{
    enable_servo(CUBE_ARM);
    servo(CUBE_ARM, CUBE_ARM_UP);  // Actual starting position
    
    servo(RING_ARM, 1525);
    servo(RING_CLAW, RING_CLAW_OPEN);
    
    create_drive_direct(60,70);
    msleep(260); 
    create_drive_direct(60,60);
    msleep(4140); 
    
    create_stop();
    servo(RING_ARM, 1300);
    //msleep(5000);
    //return;
    servo(RING_CLAW, RING_CLAW_CLOSE);
    servo(RING_ARM, 1000);
    create_drive_direct(60,60);
    msleep(1300);
     create_drive_direct(60,75);
    msleep(500);
    
    create_stop();
    
    
    servo(RING_ARM, 700);
    create_drive_direct(60,65);
    msleep(1580);
    create_drive_direct(60,70);
    msleep(1250);
    
    create_stop();
    create_drive_direct(65,20); 
    msleep(250);
   
     create_drive_direct(60,60); 
    msleep(1650);
    servo(RING_ARM, 500);
     create_drive_direct(65,60); 
    msleep(1500);
    create_stop();
    servo(RING_ARM, 360);
    create_drive_direct(65,0);
    msleep(225);
    create_drive_direct(60,62);
    msleep(1200);
    create_stop();

    servo(RING_CLAW, RING_CLAW_OPEN);
    //DO NOT MESS WITH CODE ABOVE THIS LINE!!! Everything below this is extra work
     //servo(RING_ARM, 100);
     //create_drive_direct(80,0);
     //msleep(350);
    //create_drive_direct(60,60);
    //msleep(1100);
    //create_drive_direct(0,80);
    //msleep(350);
     //create_drive_direct(60,70);
    ////msleep(1600);
    //create_drive_direct(60,60);
    //msleep(450);
    
    
}

