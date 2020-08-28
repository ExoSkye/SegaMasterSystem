#include "SMS_Mapper.hpp"
#include "SMS_Support.hpp"
#include <cstring>
#include <cstdio>

void testMode() {
#define TEST_INFO(name) printf("Running test: %s",name);
#define TEST_CODE(setupCode) { #setupCode;
#define TEST_CONDITION(condition)   \
if( #condition ) {                   \
printf("Test succeeded");             \
} else {                               \
printf("Test failed");                  \
exit(1);                                 \
}}
#include "tests.inl"
#undef TEST_INFO
#undef TEST_CODE
#undef TEST_CONDITION
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