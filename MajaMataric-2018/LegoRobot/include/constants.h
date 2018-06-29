/*
  CONSTANTS for the LEGO robot:
  Contains:
  Authors include:  Ben G, Ben W, Blaize, Caiden, Elijah, Gavin,
                    Ian, Isaiah, Max, Ryland, Sam, and others.
  Date written:
    -- Version 1: Spring, 2018.
*/

/*****************************************************************************************
* The following constants tell the program what sensor readings
* the program should treat as BLACK and what to treat as WHITE.
*
*   IMPORTANT: THESE  ** MUST **  BE TUNED AT THE TOURNAMENT.
*      You MUST use the Sensor List menu on the Wallaby
*      to come up with good values for these.  Here is what to do:
*        1. Make sure that the robot is in its DOWN_FOR_MOVING position.
*
*        2. Put the robot so that the LEFT line sensor
*           is INSIDE a black line, but just barely so.
*        3. Using the Sensor List menu on the Wallaby,
*           find out what the current reading is.
*        4. Repeat the above at various places at the table until you
*           know the approximate reading that the LEFT sensor gives
*           when INSIDE a BLACK line (but just barely so).
*
*        5. Move the robot so that the LEFT line sensor is on a
*           completely WHITE part of the table (NOT near a black line).
*        6. Using the Sensor List menu on the Wallaby, find out
*           what the current reading is (on the WHITE part of the table).
*        7. Repeat the above at various places at the table until you
*           know the approximate reading that the LEFT sensor gives
*           when on a completely WHITE portion of the table.
*
*        8. Set the value for   LEFT_LINE_SENSOR_SEES_BLACK   below
*           to some number that is:
*             -- clearly LESS THAN the readings that you saw when
*                the sensor was INSIDE a BLACK line (but just barely so), AND
*             -- clearly GREATER THAN the readings that you saw when
*                the sensor was on a completely WHITE portion of the table.
*
*        9. Repeat the above, but using the RIGHT line sensor, to determine
*           and set the value for   RIGHT_LINE_SENSOR_SEES_BLACK   below.
*      
*****************************************************************************************/

#define LEFT_LINE_SENSOR_SEES_BLACK   2500
#define RIGHT_LINE_SENSOR_SEES_BLACK  2500

/*****************************************************************************************
* The following constants specify the power to use for various speeds.
* You can change them if you HAVE to, but BE CAUTIOUS about doing so!
*****************************************************************************************/
#define SLOW        30  // was 15
#define TURN_SPEED  30
#define MEDIUM      50
#define FAST       100
#define PAUSE_TIME 250  // Milliseconds to sleep at each PAUSE // was 500

/*****************************************************************************************
* The following constants specify the servo positions to use for the arm.
* You can change them if you HAVE to, but BE CAUTIOUS about doing so!
*****************************************************************************************/

#define UP                208  // This is straight up.  Used as the starting position.
#define HALF_WAY_UP       750  // This is halfway up.
#define ANGLE             925  // This allows the arm to clear the pom piles reliably.
#define DOWN             1600  // This is ALL the way down (squashing poms).
                               // The caster wheel rises ABOVE the board at this position. 
#define DOWN_FOR_MOVING  1300  // This is the normal position for when the robot moves.
                               // The caster wheel touches the ground in this position.

#define DOWN_FOR_LEAVING_A_POM  1000  // This is the position for leaving behind BLUE poms.

/*****************************************************************************************
* The following constants help the robot go straight with accurate distances.
* DO NOT CHANGE THEM unless:
*   1. The robot starts VEERING a ** LOT **,  ** AND **
*   2. You have examined the robot carefully and fixed any PHYSICAL problems
*      that might have caused the robot to start veering.
*****************************************************************************************/

#define LEFT_SPEED_MULTIPLIER   1.00  // To correct veering
#define RIGHT_SPEED_MULTIPLIER  0.98  // The robot veers a little to the right at FULL power.
#define TICKS_PER_INCH        205.00
#define TICKS_PER_DEGREE        9.83

/*****************************************************************************************
* The following constants tell the program what ports various wires
* (motors, servos, and sensors) are plugged into.
* Do NOT change these unless you change what a wire is plugged into.
*****************************************************************************************/

#define ARM 0
#define LEFT_MOTOR 3
#define RIGHT_MOTOR 0

#define LEFT_LINE_SENSOR 1
#define RIGHT_LINE_SENSOR 0
#define LEGO_LIGHT_SENSOR 5

/*****************************************************************************************
* DO NOT CHANGE ANY OF THE FOLLOWING.
* They are needed for various helper functions.
*****************************************************************************************/

#define TRUE 1
#define FALSE 0

#define A_BUTTON 1
#define B_BUTTON 2
#define C_BUTTON 3
