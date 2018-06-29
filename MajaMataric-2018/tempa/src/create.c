/*
  Code for the CREATE robot in the SEEDING rounds
  in the Greater St. Louis Regional tournament.
  Contains the functions:
    -- run_create1
    -- run_create2
    -- setup_create

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

void spin_until_cube(int color)
{
    int count;
    int area;

    // Spin until the camera sees an object of the desired color.
    create_spin_CW(30);
    while(1==1)
    {
        camera_update();
        count=get_object_count(color);
        if(count==0)
        {
            continue;
        }
        area=get_object_area(color, 0);
        // printf("area: %5d\n", area);
        if(area > BIG_ENOUGH_TO_BE_CONSIDERED)
        {
            create_stop();
            break;
        }
    }
}

void center(int color)
{
    int count, x;

    while(1)
    {
        camera_update();
        count=get_object_count(color);
        if(count==0)
        {
            continue;
        }
        x = get_object_center(color, 0).x;
        if (x>78 && x<82)
        {
            create_stop();
            break;
        }
        if(x<78)
        {
            create_spin_CCW(30);
        }
        if(x>82)
        {
            create_spin_CW(30);
        }
    }
}

void print_colors(int color)
{
    int count, size, x;
    while (1)
    {

        camera_update();
        count = get_object_count(color);
        if (count > 0) {
            size = get_object_area(color, 0);
            x = get_object_center(color, 0).x;
            printf("x coordinate and size = %4d %4d\n", x, size);
        }

        msleep(2000);
    }
}




