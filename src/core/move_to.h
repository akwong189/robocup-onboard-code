#ifndef MOVE_TO_H
    #define MOVE_TO_H

    #include "parser.h"

    #define loc_p               60
    #define loc_d               22
    #define t_control_speed     150
    #define rot_p               200
    #define rot_d               50
    #define r_control_speed     100

    void run(robotVals* rVals);
    int min_angle(float angle);
    int PID_rot(robotVals* rVals);
    int* PID_loc(robotVals* rVals);

#endif