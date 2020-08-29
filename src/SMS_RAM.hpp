//
// Created by protobit on 24/08/2020.
//

#ifndef SEGAMASTERSYSTEM_SMS_RAM_HPP
#define SEGAMASTERSYSTEM_SMS_RAM_HPP

#include "SMS_Support.hpp"
#include <cstring>
#include <malloc.h>

class SMS_RAM {
private:
    byte* m_Memory;
public:
    SMS_RAM();
    byte& operator[](int16_t index);
    byte& at(int16_t index);
};

#endif