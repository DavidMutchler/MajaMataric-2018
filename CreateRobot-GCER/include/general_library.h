/*
  Code for Lego and Create robots.
  Contains the functions:
    -- run_lego, setup_lego
    -- run_create, setup_create
    -- pause
    -- servo
    -- test_movements

  Authors include:  Ben G, Ben W, Caiden, Gavin, Elijah, Isaiah, Max, Ryland IZ A BOSS, and others.
  Date written:
    -- Version 1: Spring, 2018.
*/

#include <kipr/botball.h>

enum PROGRAM before_hands_off();
void setup_create();
void choose_pause();
enum BOOLEAN choose_lights();
enum PROGRAM choose_which_part_of_program_to_run();
void prepare_to_run(enum PROGRAM program, enum BOOLEAN use_lights);

extern int WAIT_FOR_A;
extern int MILLISECONDS_TO_PAUSE;

void setup_lego();
void setup_create();

void run_lego1();
void run_lego2();
void run_create1();
void run_create2();
void run_create3();

void run_lego1_or_lego2();
void run_create1_or_create2();

void pause();
void turn_pause_on();
void turn_pause_off();
char* get_pause_state();
                    
void servo(int port, int desired_position);
int get_button_press(char* message);

int detect_color_of_closest_cube();

void test_movements();

//BEYOND THIS POINT: Functions created either after Regionals and/or for GECR

void DRIVE_TO_COLOR(int color, float wanted_size, int tries);
