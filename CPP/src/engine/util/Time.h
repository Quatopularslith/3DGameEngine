//
// Created by Razim on 1/6/2016.
//

#ifndef INC_3DGAMEENGINE_TIME_H
#define INC_3DGAMEENGINE_TIME_H


class Time {
public:
    static long second;
    static double delta;
    static unsigned long NANO_SECOND;
    static void setDelta(double delta);
    static double getDelta();
    static long long int getTime();
};


#endif //INC_3DGAMEENGINE_TIME_H
