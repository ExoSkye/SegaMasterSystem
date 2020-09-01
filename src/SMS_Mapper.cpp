//
// Created by protobit on 24/08/2020.
//

#include "SMS_Mapper.hpp"

SMS_Mapper::SMS_Mapper(int cartridge_size) {
    smsRam = new SMS_RAM();
    smsRam->at(0xFFFE) = 1;
    smsRam->at(0xFFFF) = 2;
    smsRom = new SMS_ROM(cartridge_size);
}

byte& SMS_Mapper::operator[](unsigned int index) {
    byte zero = 0;
    if (index <= 0xffff) {
        byte bankZero = smsRam->at(0xfffd);
        byte bankOne = smsRam->at(0xfffe);
        byte bankTwo = smsRam->at(0xffff);
        if (index <= 0x3fff && index > 0x400) {
            return smsRom->at(bankZero * 16384 + index);
        }
        else if (index <= 0x7fff) {
            return smsRom->at(bankOne * 16384 + (index-0x3fff));
        }
        else if (index <= 0xbfff) {
            return smsRom->at(bankTwo * 16384 + (index-0x7fff));
        }
        else if(index <= 0xdfff) {
            return smsRam->at(index-0xc000);
        }
        else if (index <= 0xffff) {
            return smsRam->at(index-0xe000);
        }
        else {
            return zero;
        }
    }
    else {
        throw std::out_of_range("Access to memory over 64K is not allowed");
    }
}


byte& SMS_Mapper::at(int16_t index) {
    return operator[](index);
}


