//
// Created by Mnenmenth on 1/6/2016.
//

#include <chrono>
#include "Time.h"

long Time::second = 1000;
double Time::delta;
unsigned long Time::NANO_SECOND = 1000000000;

void Time::setDelta(double delta) {
    Time::delta = delta;
}

double Time::getDelta() {
    return Time::delta;
}

long long int Time::getTime() {
    long long int time = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    return time;
}