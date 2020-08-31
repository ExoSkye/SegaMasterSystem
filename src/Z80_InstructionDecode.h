//
// Created by Bob on 30/08/2020.
//

#ifndef SEGAMASTERSYSTEM_Z80_INSTRUCTIONDECODE_H
#define SEGAMASTERSYSTEM_Z80_INSTRUCTIONDECODE_H

#include "SMS_Z80.hpp"

void SMS_Z80::nextInstruction() {
    r_PC++;
    byte curInst = memory->operator[](r_PC);
    if (curInst == 0xC7) {
        clock->tick(11);
        startExecution();
    }
#define instOpcode(num, cycles) else if (curInst == num) { clock->tick(cycles); \
byte second = memory->operator[](r_PC+1); \
byte third = memory->operator[](r_PC+2);  \
byte fourth = memory->operator[r_PC+3];
#define instCode(code) code;
#define instAddressMode(var_name, value, code) if (var_name == value) { code; }
#define instAddrReg(var_name) int reg = 0; \
if (var_name == 7) {                   \
    reg = r_A;                                   \
}\
else if (var_name == 0) {                   \
    reg = r_B;                                   \
}\
else if (var_name == 1) {                   \
    reg = r_C;                                   \
}\
else if (var_name == 2) {                   \
    reg = r_D;                                   \
}\
else if (var_name == 3) {                   \
    reg = r_E;                                   \
}\
else if (var_name == 4) {                   \
    reg = r_H;                                   \
}\
else if (var_name == 5) {                   \
    reg = r_L;                                   \
}                                      \
else if (var_name == 6) {                   \
    reg = r_HL;                                   \
}
#define instEnd() }
#include "instructions.inl"
#undef instOpcode
#undef instGetData
#undef instCode
#undef instAddressModeCode
#undef instAddressModeStart
#undef instAddressModeEnd
#undef instEnd
}


#endif //SEGAMASTERSYSTEM_Z80_INSTRUCTIONDECODE_H
