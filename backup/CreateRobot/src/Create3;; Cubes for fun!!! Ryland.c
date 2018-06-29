#include <kipr/botball.h>
#include "constants.h"
#include "general_library.h"
#include "create_library.h"

void run_create3()
{
    WAIT_FOR_A = TRUE;
    pause();
    
    servo(CUBE_ARM, CUBE_ARM_UP);
    servo(CUBE_CLAW, CUBE_CLAW_OPEN);
    pause();
    
    create_right(10,50);
    create_forward(8, 25);
    servo(RING_ARM, 140);
    create_right(82,15);
    
    create_forward(9,25);
    servo(CUBE_CLAW, 1300);
    create_forward(1, 25);
    servo(CUBE_CLAW, 1500);
    
    
    
        
        
    create_backward(13.5,15);
    create_right(125,20);
	create_right(1.5, 10);
    servo(CUBE_ARM, 2000);
    servo(CUBE_CLAW, 1225);
}