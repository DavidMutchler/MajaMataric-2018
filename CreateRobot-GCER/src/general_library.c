/*
  Code for Lego and Create robots.
  Contains the functions:
    -- pause
    -- servo
    -- get_button

  Authors include:  Ben G, Ben W, Caiden, Gavin, Elijah, Isaiah, Max, Ryland, and others.
                    David Mutchler wrote the helper function  get_button  (which is NOT used in the tournament).
  Date written:
    -- Version 1: Spring, 2018.
*/

#include <kipr/botball.h>
#include "constants.h"
#include "general_library.h"

int WAIT_FOR_A = FALSE;
int MILLISECONDS_TO_PAUSE = PAUSE_TIME;

// Moves the servo SLOWLY to its desired position.
void servo(int port, int desired_position)
{
    int current_position; //Calling for 'current_position' to be a number; int = interger

    current_position = get_servo_position(port); 
    if (desired_position > current_position)
    {
        while (TRUE)
        {
            current_position = current_position + 30;
            if (current_position > desired_position)
            {
                break;
            }
            set_servo_position(port, current_position);
            msleep(50);
        }
        set_servo_position(port, desired_position);
        msleep(500);
    }
    else
    {
        while (TRUE)
        {
            current_position = current_position - 30;
            if (current_position < desired_position)
            {
                break;
            }
            set_servo_position(port, current_position);
            msleep(50);
        }
        set_servo_position(port, desired_position);
        msleep(500);
    }
    pause();
}

// Waits for the user to press the A button, then continues.
// But if the  WAIT_FOR_A  global variable is FALSE, then just sleeps for MILLISECONDS_TO_PAUSE.
void pause()
{
    if (WAIT_FOR_A == FALSE)
    {
        msleep(MILLISECONDS_TO_PAUSE);
        return;
    }

    printf("Press the A button to continue...\n");
    while (TRUE)
    {
        if (a_button() == 1) {
            break;
        }
        msleep(20);
    }

    printf("  Stop holding the A button!\n\n");
    while (TRUE)
    {
        if (a_button() == 0)
        {
            break;
        }
        msleep(20);
    }

    // Wait for the user to remove her hand.
    msleep(500);
}

void turn_pause_on()
{
    WAIT_FOR_A = TRUE;
}

void turn_pause_off()
{
    WAIT_FOR_A = FALSE;
}

char* get_pause_state() {
    if (WAIT_FOR_A) {
        return "ON";
    } else {
        return "OFF";
    }
}

int get_button_press(char* message)
{
    int button;

    printf("\n");
    printf(message);

    while (TRUE)
    {
        if (a_button()) {
            button = A_BUTTON;
            break;
        }
        if (b_button()) {
            button = B_BUTTON;
            break;
        }
        if (c_button()) {
            button = C_BUTTON;
            break;
        }
    }

    printf("Stop holding the button.\n");
    msleep(500);
    return button;
}

/*int detect_color_of_closest_cube()
{
    int yellow_area, green_area, red_area;

    while(1)
    {
        camera_update();

        if(get_object_count(YELLOW)>0)
        {
            yellow_area=get_object_area(YELLOW, 0);
        }else{
            yellow_area=0;
        }
        if(get_object_count(RED)>0)
        {
            red_area=get_object_area(RED, 0);
        }else{
            red_area=0;
        }
        if(get_object_count(GREEN)>0)
        {
            green_area=get_object_area(GREEN, 0);
        }else{
            green_area=0;
        }
        if(yellow_area>500)
        {
            printf("swap closest and middle\n");
            // exchange the closest cube with the middle cube.
        }
        else if (yellow_area>200)
        {
            printf("do nothing\n");
            // Do nothing.
        }
        else
        {
            printf("swap farthest and middle\n");
            // exchange the farthest cube with the middle cube.
        }
        printf("%4d %4d %4d\n", yellow_area, red_area, green_area);
        msleep(1000);
    }
} */

//BEYOND THIS POINT: Functions either after Regionals and/or for GECR

void DRIVE_TO_COLOR(int color, float wanted_size, int tries) {

    //Program Expectancy: Create Robot is to drive forward or backward until it reaches DELTA of 'wanted_size' of thing of
    //'color' and attempts 'tries' amount of times

    //Program Depicted In Conversational English: 
    //|1|Camera detects if the object's color is equal to 'color'
    //|2|If too far from object, Create moves forward 1 inch; If too close to the object, Create moves backward 1 inch
    //|3|Continues until either the DELTA of the object is reached or Create has passed number of 'tries'amounted
    //|4|Create reports if 'DRIVE_TO_COLOR' was a success or fail

}



