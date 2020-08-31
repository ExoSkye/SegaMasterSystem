//
// Created by protobit on 28/08/2020.
//

#include "SMS_Z80.hpp"

doubleReg::doubleReg(byte *a, byte *b) {
    m_a = a; m_b = b;
}

dbyte doubleReg::operator()() {
    dbyte ret;
    ret = (*m_a << 8) | *m_b;
    return ret;
}

void doubleReg::operator++(int) {
    operator+=((byte)1);
}

dbyte doubleReg::operator-(dbyte other) {
    return operator()() - other;
}

void doubleReg::operator--(int) {
    operator-=((byte)1);
}

dbyte doubleReg::operator+=(dbyte other) {
    operator=(operator+(other));
    return operator()();
}

dbyte doubleReg::operator+=(byte other) {
    operator=(operator+(other));
    return operator()();
}

dbyte doubleReg::operator-=(dbyte other) {
    operator=(operator-(other));
    return operator()();
}

dbyte doubleReg::operator-=(byte other) {
    operator=(operator-(other));
    return operator()();
}

dbyte doubleReg::operator+(dbyte other) {
    return operator()() + other;
}

dbyte doubleReg::operator+(byte other) {
    return operator()() + other;
}

dbyte doubleReg::operator-(byte other) {
    return operator()() - other;
}

doubleReg& doubleReg::operator=(dbyte other) {
    *m_a = other >> 8;
    *m_b = other & 0b0000000011111111;
    return *this;
}

doubleReg& doubleReg::operator=(byte other) {
    *m_a = other;
    *m_b = 0;
    return *this;
}


SMS_Z80::SMS_Z80() {
    //FIXME: Add config for NTSC/PAL
    clock = new Z80_Clock(true);
    //FIXME: Add config for cartridge size
    memory = new SMS_Mapper(1);
}

void SMS_Z80::startExecution() {
    r_PC = 0x0000;
}

flags SMS_Z80::getFlags(byte r_F) {
    return flags{getBit(r_F,0),
                 getBit(r_F,1),
                 getBit(r_F,2),
                 getBit(r_F,3),
                 getBit(r_F,4),
                 getBit(r_F,5),
                 getBit(r_F,6),
                 getBit(r_F,7)};
}

bool SMS_Z80::getBit(byte in, int index) {
    return (in & 1 << index) >> index;
}
