// Header for TokenFreq data structure and related functions.
// Note: keep <algorithm> available for instructor test compatibility.

#ifndef TOKEN_FREQ_H
#define TOKEN_FREQ_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace NS_TOKEN_FREQ {

struct TokenFreq {
    string token;
    int freq;
};

bool operator<=(const TokenFreq& lhs, const TokenFreq& rhs);
TokenFreq operator+(const TokenFreq& lhs, const TokenFreq& rhs);
ostream& operator<<(ostream& os, const TokenFreq& tf);

vector<TokenFreq> getTokenFreqVec(const vector<string>& tokens);
void getTokenFreqVec(const string& istr, vector<TokenFreq>& tfVec);

void sortByTokenAsc(vector<TokenFreq>& tfVec);
void sortByFreqDescThenTokenAsc(vector<TokenFreq>& tfVec);

}  // namespace NS_TOKEN_FREQ

#endif
