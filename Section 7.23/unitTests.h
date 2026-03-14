// Header file that includes all unit tests as inline functions.
// Include 3 unit tests for each of the following functions in namespace NS_UNIT_TESTS:
// 1. matrixInit()
// 2. operator<=  for TokenFreq objects
// 3. operator+  for TokenFreq objects
// 4. getTokenFreqVec()
// 5. each of the two sorting algorithms

// Naming convention:
//   test1_[function name]
//   test2_[function name]
//   test3_[function name]

// Note 1: for operators <= and +, use the following function names
//    test?_operatorLE();      // replace ? with 1, 2 or 3
//    test?_operatorPlus();    // replace ? with 1, 2 or 3

// Note 2: all unit tests should return true/false like in Lab#1 and Lab#2.

#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include "matrixInit.h"
#include "tokenFreq.h"

#include <limits>
#include <vector>

using namespace std;

namespace NS_UNIT_TESTS {

using NS_TOKEN_FREQ::TokenFreq;

inline bool hasTokenFreq(const vector<TokenFreq>& vec, const string& token, int expectedFreq) {
    // Helper: checks whether a token with a specific frequency exists in a vector.
    for (const auto& entry : vec) {
        if (entry.token == token && entry.freq == expectedFreq) {
            return true;
        }
    }
    return false;
}

inline bool test1_matrixInit() {
    // Positive case: build a 2x3 matrix initialized to 7.
    // Expect all cells to be 7 and dimensions to match 2 rows x 3 columns.
    auto mat = NS_MATRIX::matrixInit(2, 3, 7);
    return mat.size() == 2 && mat[0].size() == 3 && mat[1].size() == 3 &&
           mat[0][0] == 7 && mat[0][2] == 7 && mat[1][1] == 7;
}

inline bool test2_matrixInit() {
    // Edge case: zero rows is invalid.
    // Expect an empty matrix.
    auto mat = NS_MATRIX::matrixInit(0, 3, 5);
    return mat.empty();
}

inline bool test3_matrixInit() {
    // Edge case: negative columns is invalid.
    // Expect an empty matrix.
    auto mat = NS_MATRIX::matrixInit(3, -1, 5);
    return mat.empty();
}

inline bool test1_operatorLE() {
    // Compare different tokens alphabetically: "apple" comes before "banana".
    // Expect true.
    TokenFreq a{"apple", 3};
    TokenFreq b{"banana", 1};
    return a <= b;
}

inline bool test2_operatorLE() {
    // Same token, compare frequencies: 2 <= 5.
    // Expect true.
    TokenFreq a{"cat", 2};
    TokenFreq b{"cat", 5};
    return a <= b;
}

inline bool test3_operatorLE() {
    // Different tokens where left should not be less-or-equal by token order.
    // "zebra" is after "yak", so expect false.
    TokenFreq a{"zebra", 2};
    TokenFreq b{"yak", 20};
    return !(a <= b);
}

inline bool test1_operatorPlus() {
    // Same token names should combine frequencies: 3 + 4.
    // Expect {"dog", 7}.
    TokenFreq a{"dog", 3};
    TokenFreq b{"dog", 4};
    TokenFreq c = a + b;
    return c.token == "dog" && c.freq == 7;
}

inline bool test2_operatorPlus() {
    // Same token with one zero frequency.
    // Expect frequencies to add correctly to 5.
    TokenFreq a{"x", 0};
    TokenFreq b{"x", 5};
    TokenFreq c = a + b;
    return c.token == "x" && c.freq == 5;
}

inline bool test3_operatorPlus() {
    // Different token names still sum frequencies; left token label is retained.
    TokenFreq a{"left", 10};
    TokenFreq b{"right", 20};
    TokenFreq c = a + b;
    return c.token == "left" && c.freq == 30;
}

inline bool test1_getTokenFreqVec() {
    // Mixed repeated tokens.
    // Expect counts a=3, b=2, c=1 (order is not required).
    vector<string> tokens = {"a", "b", "a", "c", "b", "a"};
    auto out = NS_TOKEN_FREQ::getTokenFreqVec(tokens);
    return out.size() == 3 && hasTokenFreq(out, "a", 3) && hasTokenFreq(out, "b", 2) && hasTokenFreq(out, "c", 1);
}

inline bool test2_getTokenFreqVec() {
    // Empty input should produce empty output.
    vector<string> tokens = {};
    auto out = NS_TOKEN_FREQ::getTokenFreqVec(tokens);
    return out.empty();
}

inline bool test3_getTokenFreqVec() {
    // Single unique token repeated multiple times.
    // Expect one entry with frequency 3.
    vector<string> tokens = {"same", "same", "same"};
    auto out = NS_TOKEN_FREQ::getTokenFreqVec(tokens);
    return out.size() == 1 && hasTokenFreq(out, "same", 3);
}

inline bool test1_sortByTokenAsc() {
    // Sort by token name alphabetically.
    // Expect ant, cat, dog.
    vector<TokenFreq> vec = {{"dog", 2}, {"cat", 5}, {"ant", 3}};
    NS_TOKEN_FREQ::sortByTokenAsc(vec);
    return vec[0].token == "ant" && vec[1].token == "cat" && vec[2].token == "dog";
}

inline bool test2_sortByTokenAsc() {
    // All token names are equal, so tie is broken by frequency ascending.
    // Expect frequencies 2, 3, 4.
    vector<TokenFreq> vec = {{"bee", 4}, {"bee", 2}, {"bee", 3}};
    NS_TOKEN_FREQ::sortByTokenAsc(vec);
    return vec[0].freq == 2 && vec[1].freq == 3 && vec[2].freq == 4;
}

inline bool test3_sortByTokenAsc() {
    // Single-element input should remain unchanged.
    vector<TokenFreq> vec = {{"x", 1}};
    NS_TOKEN_FREQ::sortByTokenAsc(vec);
    return vec.size() == 1 && vec[0].token == "x" && vec[0].freq == 1;
}

inline bool test1_sortByFreqDescThenTokenAsc() {
    // Sort by frequency descending.
    // Expect b(3), c(2), a(1).
    vector<TokenFreq> vec = {{"a", 1}, {"b", 3}, {"c", 2}};
    NS_TOKEN_FREQ::sortByFreqDescThenTokenAsc(vec);
    return vec[0].token == "b" && vec[1].token == "c" && vec[2].token == "a";
}

inline bool test2_sortByFreqDescThenTokenAsc() {
    // Equal frequencies tie-break by token ascending.
    // Expect a, m, z.
    vector<TokenFreq> vec = {{"z", 5}, {"a", 5}, {"m", 5}};
    NS_TOKEN_FREQ::sortByFreqDescThenTokenAsc(vec);
    return vec[0].token == "a" && vec[1].token == "m" && vec[2].token == "z";
}

inline bool test3_sortByFreqDescThenTokenAsc() {
    // Empty vector should stay empty after sorting.
    vector<TokenFreq> vec = {};
    NS_TOKEN_FREQ::sortByFreqDescThenTokenAsc(vec);
    return vec.empty();
}

inline bool test1_selectionSort() {
    vector<TokenFreq> vec = {{"a", 1}, {"b", 3}, {"c", 2}};
    NS_TOKEN_FREQ::selectionSort(vec);
    return vec[0].token == "b" && vec[1].token == "c" && vec[2].token == "a";
}

inline bool test2_selectionSort() {
    vector<TokenFreq> vec = {{"z", 5}, {"a", 5}, {"m", 5}};
    NS_TOKEN_FREQ::selectionSort(vec);
    return vec[0].token == "a" && vec[1].token == "m" && vec[2].token == "z";
}

inline bool test3_selectionSort() {
    vector<TokenFreq> vec = {};
    NS_TOKEN_FREQ::selectionSort(vec);
    return vec.empty();
}

inline bool test1_insertionSort() {
    vector<TokenFreq> vec = {{"a", 1}, {"b", 3}, {"c", 2}};
    NS_TOKEN_FREQ::insertionSort(vec);
    return vec[0].token == "b" && vec[1].token == "c" && vec[2].token == "a";
}

inline bool test2_insertionSort() {
    vector<TokenFreq> vec = {{"z", 5}, {"a", 5}, {"m", 5}};
    NS_TOKEN_FREQ::insertionSort(vec);
    return vec[0].token == "a" && vec[1].token == "m" && vec[2].token == "z";
}

inline bool test3_insertionSort() {
    vector<TokenFreq> vec = {};
    NS_TOKEN_FREQ::insertionSort(vec);
    return vec.empty();
}

inline bool test_failSafe_operatorPlusOverflowMax() {
    // Fail-safe: adding beyond INT_MAX should clamp to INT_MAX.
    TokenFreq a{"cap", numeric_limits<int>::max()};
    TokenFreq b{"cap", 1};
    TokenFreq c = a + b;
    return c.token == "cap" && c.freq == numeric_limits<int>::max();
}

inline bool test_failSafe_operatorPlusUnderflowMin() {
    // Fail-safe: subtracting below INT_MIN should clamp to INT_MIN.
    TokenFreq a{"floor", numeric_limits<int>::min()};
    TokenFreq b{"floor", -1};
    TokenFreq c = a + b;
    return c.token == "floor" && c.freq == numeric_limits<int>::min();
}

inline bool test_failSafe_matrixInitInvalidDims() {
    // Fail-safe: invalid dimensions should be rejected immediately.
    auto mat = NS_MATRIX::matrixInit(-100, numeric_limits<int>::max(), 1);
    return mat.empty();
}

}  // namespace NS_UNIT_TESTS

#endif