// Header for TokenFreq data structure and related functions.
// Note: keep <algorithm> available for instructor test compatibility.

#ifndef TOKEN_FREQ_H
#define TOKEN_FREQ_H

#include <algorithm>
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

vector<TokenFreq> getTokenFreqVec(const vector<string>& tokens);

void sortByTokenAsc(vector<TokenFreq>& tfVec);
void sortByFreqDescThenTokenAsc(vector<TokenFreq>& tfVec);

}  // namespace NS_TOKEN_FREQ

#endif
