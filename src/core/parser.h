#ifndef PARSER_H
    #define PARSER_H
    #include <stdlib.h>

    typedef struct robotVals {
        float dx;
        float dy;
        float angle;
        uint8_t flags;
        uint16_t id;
    } robotVals;

    void parse(int* buffer, robotVals **r);
    void printBuffer(int* buffer);
    void* startMove(void* vargp);
#endif