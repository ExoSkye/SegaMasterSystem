//
// Created by protobit on 28/08/2020.
//

#ifndef SEGAMASTERSYSTEM_SMS_Z80_HPP
#define SEGAMASTERSYSTEM_SMS_Z80_HPP
#include "SMS_Support.hpp"
#include "SMS_Mapper.hpp"
#include "Z80_Clock.hpp"

class doubleReg {
private:
    byte* m_a, *m_b;
public:
    explicit doubleReg(byte* a, byte* b);
    dbyte operator()();
    doubleReg& operator=(dbyte other);
    doubleReg& operator=(byte other);
    void operator++(int);
    void operator--(int);
    dbyte operator+=(dbyte other);
    dbyte operator+=(byte other);
    dbyte operator-=(dbyte other);
    dbyte operator-=(byte other);
    dbyte operator+(dbyte other);
    dbyte operator+(byte other);
    dbyte operator-(dbyte other);
    dbyte operator-(byte other);
};

struct flags {
    bool f_S;
    bool f_Z;
    bool f_bitFive;
    bool f_h;
    bool f_bitThree;
    bool f_pv;
    bool f_n;
    bool f_c;
};

class SMS_Z80 {
private:
    flags getFlags(byte r_F);
    bool getBit(byte in, int index);
public:
    SMS_Mapper* memory;
    Z80_Clock* clock;
    byte r_A = 0, r_B = 0, r_D = 0, r_H = 0, r_F = 0, r_C = 0, r_E = 0, r_L = 0, r_I = 0, r_R = 0;
    dbyte r_IX = 0, r_IY = 0, r_SP = 0, r_PC = 0;
    doubleReg BC = doubleReg(&r_B, &r_C), DE = doubleReg(&r_D, &r_E), HL = doubleReg(&r_H, &r_L);
    SMS_Z80();
    void startExecution();
    void nextInstruction();
};


#endif //SEGAMASTERSYSTEM_SMS_Z80_HPP
