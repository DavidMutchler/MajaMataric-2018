//NEEDED COMMENT UP IN HERE!!!!

#define PORT0_START 800
#define PORT1_START 100
#define PORT2_START 100
#define PORT3_START 100

#define LEFT_LINE_SENSOR_SEES_BLACK   2500
#define RIGHT_LINE_SENSOR_SEES_BLACK  2500

/*****************************************************************************************
* The following constants specify the power to use for various speeds.
* You can change them if you HAVE to, but BE CAUTIOUS about doing so!
*****************************************************************************************/
#define SLOW        15
#define TURN_SPEED  30
#define MEDIUM      50
#define FAST       100
#define PAUSE_TIME  1000  // Milliseconds to sleep at each PAUSE

/*****************************************************************************************
* The following constants specify the servo positions to use for the arm.
* You can change them if you HAVE to, but BE CAUTIOUS about doing so!
*****************************************************************************************/

#define RING_ARM_DOWN 1610
#define RING_ARM_UP_FULL 750
#define RING_CLAW_OPEN 1700
#define RING_CLAW_CLOSE 750
#define RING_ARM_START 1510

#define CUBE_ARM_BACK 100
#define CUBE_ARM_UP 600
#define CUBE_ARM_DOWN 2000
#define CUBE_CLAW_CLOSE 1500
#define CUBE_CLAW_OPEN 1200

// The following are for the LEGO robot.

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

/*****************************************************************************************
* The following constants tell the program what ports various wires
* (motors, servos, and sensors) are plugged into.
* Do NOT change these unless you change what a wire is plugged into.
*****************************************************************************************/

#define CUBE_ARM 0
#define CUBE_CLAW 2
#define RING_CLAW 1
#define RING_ARM 3

#define CREATE_LIGHT_SENSOR 5


// I think that these two are no longer relevant.
//#define CUBE_CLAW_CAPTURE_BIG 1679
//#define CUBE_CLAW_CAPTURE SMALL 1784


// Ignore these, they are for the Lego robot.
//#define UP 100
//#define DOWN 1440
//#define ANGLE 1125
//#define ARM 0

//PORT 0 IS DEAD!!! I REPEAT PORT 0 IS DEAD PORT 2 IS DEAD

// Not used yet:
#define BIG_ENOUGH_TO_BE_CONSIDERED 80

// Ignore these, they are for the Lego robot.
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

#define YELLOW 0
#define RED 1
#define GREEN 2
#define BIG_YELLOW 3
