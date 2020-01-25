#include "move_to.h"
#include "parser.h"
#include "matrix_helper.h"

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
    int PID = rot_p * dist - rot_d * rVals->w;

    if (PID > r_control_speed)
        PID = r_control_speed;
    else if (PID < -r_control_speed)
        PID = -r_control_speed;

    return PID;
}

float* PID_loc(robotVals* rVals) {
    float* local_PID = (float*) malloc(sizeof(float) * 2);
    float distance = norm(rVals->dx, rVals->dy), PID_mag;
    float local[2], local_vel[2];

    convert_local(local, rVals->dx, rVals->dy, -(rVals->angle));
    convert_local(local_vel, rVals->vx, rVals->vy, -(rVals->angle));

    multiply_matrix_scalar(local, loc_p);
    multiply_matrix_scalar(local_vel, loc_d);
    sub_matrices(local_PID, local, local_vel);

    PID_mag = norm(local_PID[0], local_PID[1]);

    if (PID_mag > t_control_speed)
        multiply_matrix_scalar(local_PID, t_control_speed/PID_mag);


    return local_PID;   
}