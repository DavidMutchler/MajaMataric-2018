/*
  Code for the LEGO robot movements.
  Contains the functions:
    -- forward
    -- backward
    -- left
    -- right
    -- test_movements

  Authors include:  Ben G, Ben W, Blaize, Caiden, Elijah, Gavin,
                    Ian, Isaiah, Max, Ryland, Sam, and others.
  Date written:
    -- Version 1: Spring, 2018.
*/

#include <kipr/botball.h>

void forward(float inches, int speed);
void backward(float inches, int speed);
void left(float degrees, int speed);
void right(float degrees, int speed);
void forward_until_black(int speed);

void test_movements();


