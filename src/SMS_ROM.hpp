//
// Created by protobit on 24/08/2020.
//

#ifndef SEGAMASTERSYSTEM_SMS_ROM_HPP
#define SEGAMASTERSYSTEM_SMS_ROM_HPP

#include "SMS_Support.hpp"
#include <stdlib.h>

class SMS_ROM {
private:
    byte* m_Memory;
public:
    explicit SMS_ROM(int size);
    byte& operator[](int16_t index);
    byte& at(int16_t index);
};


#endif //SEGAMASTERSYSTEM_SMS_ROM_HPP
