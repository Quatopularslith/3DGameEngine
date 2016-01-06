//
// Created by Razim on 1/6/2016.
//

#include <chrono>
#include "Time.h"

long Time::second = 1000;
double Time::delta;

void Time::setDelta(double delta) {
    Time::delta = delta;
}

double Time::getDelta(){
    return Time::delta;
}

long Time::getTime() {
    unsigned long milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return milliseconds_since_epoch;
}