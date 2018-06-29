/*
  Code for Lego and Create robots.
  Contains the functions:
    -- pause
    -- servo
    -- get_button

  Authors include:  Ben G, Ben W, Blaize, Caiden, Elijah, Gavin,
                    Ian, Isaiah, Max, Ryland, Sam, and others.
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
    int current_position;
    
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
    // pause();
}

// Waits for the user to press the A button, then continues.
// But if the WAIT_FOR_A global variable is FALSE, then just sleeps for MILLISECONDS_TO_PAUSE.
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

void turn_pause_on() { WAIT_FOR_A = TRUE; }
void turn_pause_off() { WAIT_FOR_A = FALSE; }

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




