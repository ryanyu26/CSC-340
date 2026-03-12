// Call your unit tests in this program file.

#include <iostream>

#include "unitTests.h"

using namespace std;

int main() {
    using namespace NS_UNIT_TESTS;

    // Keep track of total tests and how many passed.
    int passed = 0;
    int total = 0;

    // Helper that runs one test, prints the result, and updates counters.
    auto run = [&](const char* name, bool result) {
        ++total;
        if (result) {
            ++passed;
        }
        cout << name << ": " << (result ? "PASS" : "FAIL") << '\n';
    };

    // matrixInit tests
    run("test1_matrixInit", test1_matrixInit());
    run("test2_matrixInit", test2_matrixInit());
    run("test3_matrixInit", test3_matrixInit());

    // operator<= tests
    run("test1_operatorLE", test1_operatorLE());
    run("test2_operatorLE", test2_operatorLE());
    run("test3_operatorLE", test3_operatorLE());

    // operator+ tests
    run("test1_operatorPlus", test1_operatorPlus());
    run("test2_operatorPlus", test2_operatorPlus());
    run("test3_operatorPlus", test3_operatorPlus());

    // getTokenFreqVec tests
    run("test1_getTokenFreqVec", test1_getTokenFreqVec());
    run("test2_getTokenFreqVec", test2_getTokenFreqVec());
    run("test3_getTokenFreqVec", test3_getTokenFreqVec());

    // sortByTokenAsc tests
    run("test1_sortByTokenAsc", test1_sortByTokenAsc());
    run("test2_sortByTokenAsc", test2_sortByTokenAsc());
    run("test3_sortByTokenAsc", test3_sortByTokenAsc());

    // sortByFreqDescThenTokenAsc tests
    run("test1_sortByFreqDescThenTokenAsc", test1_sortByFreqDescThenTokenAsc());
    run("test2_sortByFreqDescThenTokenAsc", test2_sortByFreqDescThenTokenAsc());
    run("test3_sortByFreqDescThenTokenAsc", test3_sortByFreqDescThenTokenAsc());

    // fail-safe tests
    run("test_failSafe_operatorPlusOverflowMax", test_failSafe_operatorPlusOverflowMax());
    run("test_failSafe_operatorPlusUnderflowMin", test_failSafe_operatorPlusUnderflowMin());
    run("test_failSafe_matrixInitInvalidDims", test_failSafe_matrixInitInvalidDims());

    // Final summary shown at the end.
    cout << "\nSummary: " << passed << "/" << total << " tests passed.\n";

    // Return 0 only when everything passes.
    return (passed == total) ? 0 : 1;
}