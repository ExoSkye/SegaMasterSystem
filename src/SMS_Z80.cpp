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


SMS_Z80::SMS_Z80() {

}
