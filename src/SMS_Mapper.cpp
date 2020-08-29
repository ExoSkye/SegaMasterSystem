//
// Created by protobit on 24/08/2020.
//

#include "SMS_Mapper.hpp"

SMS_Mapper::SMS_Mapper(int cartridge_size) {
    smsRam = new SMS_RAM();
    smsRom = new SMS_ROM(cartridge_size);
}

byte& SMS_Mapper::operator[](unsigned int index) {
    if (index <= 0xbfff) {
        return smsRom->at(m_GetROMBank(index));
    }
    else if (index <= 0xdfff) {
        return smsRam->at(index-0xc000);
    }
    else if (index <= 0xffff) {
        return smsRam->at(index-0xe000);
    }
    else {
        throw std::out_of_range("Access to memory over 64K is not allowed");
    }
}

int SMS_Mapper::m_GetROMBank(int index) {
    return 0;
}


