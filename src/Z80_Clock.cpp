//
// Created by protobit on 31/08/2020.
//

#include "Z80_Clock.hpp"

Z80_Clock::Z80_Clock(bool NTSC) {
    int Hz = NTSC ? 3579545 : 3546894;
    duration = nanoseconds(1000000000/Hz);
}

void Z80_Clock::tick(int num) {
    for (int i = 0; i < num; i++)
        sleep_for(duration);
}
