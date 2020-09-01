//
// Created by protobit on 24/08/2020.
//

#ifndef SEGAMASTERSYSTEM_SMS_MAPPER_HPP
#define SEGAMASTERSYSTEM_SMS_MAPPER_HPP

#include "SMS_Support.hpp"
#include "SMS_RAM.hpp"
#include "SMS_ROM.hpp"
#include <stdexcept>

class SMS_Mapper {
public:
    SMS_ROM* smsRom;
    SMS_RAM* smsRam;
    explicit SMS_Mapper(int cartridge_size);
    byte& operator[](unsigned int index);
    byte &at(int16_t index);
private:
};


#endif //SEGAMASTERSYSTEM_SMS_MAPPER_HPP
