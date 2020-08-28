//
// Created by protobit on 24/08/2020.
//

#include "SMS_ROM.hpp"

SMS_ROM::SMS_ROM(int size) {
    m_Memory = (byte*)calloc(sizeof(byte),size);
}
byte& SMS_ROM::operator[](int16_t index) {
    return at(index);
}

byte& SMS_ROM::at(int16_t index) {
    return m_Memory[index];
}