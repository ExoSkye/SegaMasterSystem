//
// Created by protobit on 28/08/2020.
//

#ifndef SEGAMASTERSYSTEM_GEN_TESTS_HPP
#define SEGAMASTERSYSTEM_GEN_TESTS_HPP

#include <cstdio>

#define GEN_TESTS() runTests();

void runTests() {
    bool allTests = true;
    int success = 0;
    int failure = 0;
#define TEST_INFO(name) printf("Running test: %s",name);
#define TEST_CODE(setupCode) { setupCode;
#define TEST_CONDITION(condition)   \
if( condition ) {                   \
allTests &= true;                   \
printf("Test succeeded\n");         \
success++;                          \
} else {                            \
allTests &= false;                  \
printf("Test failed\n");            \
failure++;                          \
}}
#include "tests.inl"
    if(allTests) {
        printf("All tests completed successfully");
    }
    else {
        printf("%u/%u tests completed successfully", success, success+failure);
    }
#undef TEST_INFO
#undef TEST_CODE
#undef TEST_CONDITION
}

#endif //SEGAMASTERSYSTEM_GEN_TESTS_HPP
