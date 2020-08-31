//
// Created by protobit on 31/08/2020.
//

#ifndef SEGAMASTERSYSTEM_Z80_CLOCK_HPP
#define SEGAMASTERSYSTEM_Z80_CLOCK_HPP

#include <chrono>
#include <thread>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

class Z80_Clock {
public:
    nanoseconds duration;
    explicit Z80_Clock(bool NTSC);
    void tick(int num);
};


#endif //SEGAMASTERSYSTEM_Z80_CLOCK_HPP
