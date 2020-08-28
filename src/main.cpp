#include "SMS_Mapper.hpp"
#include "SMS_Support.hpp"
#include "SMS_Z80.hpp"
#include "GEN_TESTS.hpp"
#include <cstring>
#include <cstdio>

void testMode() {
    GEN_TESTS()
}

void emulatorMode(bool verbose) {

}

int main(int argc,  char** argv) {
    bool verbose = false;
    bool test_Mode = false;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i],"--test") || !strcmp(argv[i],"-t")) {
            test_Mode = true;
        }
        else if (!strcmp(argv[i],"--verbose") || !strcmp(argv[i],"-v")) {
            verbose = true;
        }
    }
    if (test_Mode) {
        testMode();
    }
    else {
        emulatorMode(verbose);
    }
}