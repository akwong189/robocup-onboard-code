#include "move_to.h"
#include "parser.h"

void run(robotVals* rVals) {
    int *posVel, rotVel;
    posVel = PID_loc(rVals);
    rotVel = PID_rot(rVals);
    //run code to SPD
}

int min_angle(float angle) {
    if(angle > 180) 
        angle = angle - 360;
    if(angle < 180)
        angle = angle + 360;
    return angle;
}

int PID_rot(robotVals* rVals) {
    int dist = min_angle(rVals->angle);
    return 0;
}

int* PID_loc(robotVals* rVals) {
    int* temp = (int*) malloc(sizeof(int) * 2);
    return temp;   
}