//
// Created by protobit on 24/08/2020.
//

#ifndef SEGAMASTERSYSTEM_SMS_MAPPER_HPP
#define SEGAMASTERSYSTEM_SMS_MAPPER_HPP

#include "SMS_Support.hpp"
#include "SMS_RAM.hpp"
#include "SMS_ROM.hpp"

class SMS_Mapper {
public:
    SMS_ROM* smsRom;
    SMS_RAM* smsRam;
    explicit SMS_Mapper(int cartridge_size);
    byte& operator[](int index);
private:
    int m_GetROMBank(int index);
};


#endif //SEGAMASTERSYSTEM_SMS_MAPPER_HPP
