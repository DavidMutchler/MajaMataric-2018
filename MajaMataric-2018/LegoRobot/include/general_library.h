/*
  Code for the LEGO robot:
  Contains the functions:
    -- setup_lego
    -- pause
    -- servo

  Authors include:  Ben G, Ben W, Blaize, Caiden, Elijah, Gavin,
                    Ian, Isaiah, Max, Ryland, Sam, and others.
  Date written:
    -- Version 1: Spring, 2018.
*/

#include <kipr/botball.h>

void servo(int port, int desired_position);

void pause();
void turn_pause_on();
void turn_pause_off();

int get_button_press(char* message);

extern int WAIT_FOR_A;
extern int MILLISECONDS_TO_PAUSE;

/************************************************************************************
*  The following is for the LEGO robot:
************************************************************************************/
void setup_lego();

void run_lego();
void run_lego1();
void run_lego_transition();
void run_lego2();

// The following is for the CREATE robot:
void setup_create();

void run_create1();
void run_create2();

void run_lego1_or_lego2();



void test_movements();
void try_poms();
