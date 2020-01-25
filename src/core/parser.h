#ifndef PARSER_H
    #define PARSER_H

    #include <stdlib.h>

    typedef struct robotVals {
        float dx;       // change in x error
        float dy;       // change in y error
        float angle;    // current angle
        float vx;       // x velocity
        float vy;       // y velocity
        float da;       // angular error
        float w;        // omega (angular velocity)
        uint8_t flags;  // flags
        uint16_t id;    // unique id
    } robotVals;

    void parse(int* buffer, robotVals **r);
    void printBuffer(int* buffer);
    void* startMove(void* vargp);
#endif