#ifndef ROBOT_H
    #define ROBOT_H

    #define DEFAULT_TIME_ELAPSED 1.0/60

    typedef struct {
        float *loc;
        float rot;
        float rot_vel;
        int observed;
        float *velocity;
        int last_time;
        int smoothing;
        int first;
        int last_timestamp;
        int kick_cooldown;
        float *facing;
    } robot;
#endif