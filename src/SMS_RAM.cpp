//
// Created by protobit on 24/08/2020.
//

#include "SMS_RAM.hpp"

SMS_RAM::SMS_RAM() {
    m_Memory = (byte*)malloc(sizeof(byte)*0x2000);
    memset(m_Memory,0,0x2000);
}

byte &SMS_RAM::operator[](int16_t index) {
    return at(index);
}

byte &SMS_RAM::at(int16_t index) {
    return m_Memory[index];
}
