// Implementation of TokenFreq operators, frequency extraction, and sorting helpers.

#include "tokenFreq.h"

#include <limits>
#include <sstream>
#include <unordered_map>

using namespace std;

namespace NS_TOKEN_FREQ {

bool operator<=(const TokenFreq& lhs, const TokenFreq& rhs) {
    // Time complexity: O(1)
    // Compare token text first, then compare frequency if tokens match.
    if (lhs.token != rhs.token) {
        return lhs.token < rhs.token;
    }
    return lhs.freq <= rhs.freq;
}

TokenFreq operator+(const TokenFreq& lhs, const TokenFreq& rhs) {
    // Time complexity: O(1)
    // Combine frequencies only when both objects represent the same token.
    if (lhs.token != rhs.token) {
        return {lhs.token, lhs.freq};
    }

    // Fail-safe: protect against integer overflow.
    if (rhs.freq > 0 && lhs.freq > numeric_limits<int>::max() - rhs.freq) {
        return {lhs.token, numeric_limits<int>::max()};
    }
    if (rhs.freq < 0 && lhs.freq < numeric_limits<int>::min() - rhs.freq) {
        return {lhs.token, numeric_limits<int>::min()};
    }

    return {lhs.token, lhs.freq + rhs.freq};
}

ostream& operator<<(ostream& os, const TokenFreq& tf) {
    os << "{" << tf.token << ", " << tf.freq << "}";
    return os;
}

vector<TokenFreq> getTokenFreqVec(const vector<string>& tokens) {
    // Time complexity: O(n) average, where n is the number of input tokens.
    // Builds the output in one pass and avoids a second map-to-vector pass.
    unordered_map<string, size_t> tokenIndex;
    vector<TokenFreq> tfVec;
    tokenIndex.reserve(tokens.size());
    tfVec.reserve(tokens.size());

    try {
        for (const string& token : tokens) {
            auto it = tokenIndex.find(token);
            if (it == tokenIndex.end()) {
                tokenIndex[token] = tfVec.size();
                tfVec.push_back({token, 1});
            } else if (tfVec[it->second].freq < numeric_limits<int>::max()) {
                ++tfVec[it->second].freq;
            }
        }
    } catch (...) {
        // Fail-safe: if memory allocation fails, return the partial result collected so far.
        return tfVec;
    }

    return tfVec;
}

void getTokenFreqVec(const string& istr, vector<TokenFreq>& tfVec) {
    istringstream iss(istr);
    vector<string> tokens;
    string token;

    while (iss >> token) {
        tokens.push_back(token);
    }

    tfVec = getTokenFreqVec(tokens);
}

void sortByTokenAsc(vector<TokenFreq>& tfVec) {
    // Time complexity: O(k log k), where k is the number of TokenFreq entries.
    // Sort by token ascending, then frequency ascending.
    if (tfVec.size() < 2) {
        return;
    }

    sort(tfVec.begin(), tfVec.end(), [](const TokenFreq& a, const TokenFreq& b) {
        if (a.token != b.token) {
            return a.token < b.token;
        }
        return a.freq < b.freq;
    });
}

void sortByFreqDescThenTokenAsc(vector<TokenFreq>& tfVec) {
    // Time complexity: O(k log k), where k is the number of TokenFreq entries.
    // Sort by frequency descending, then token ascending for ties.
    if (tfVec.size() < 2) {
        return;
    }

    sort(tfVec.begin(), tfVec.end(), [](const TokenFreq& a, const TokenFreq& b) {
        if (a.freq != b.freq) {
            return a.freq > b.freq;
        }
        return a.token < b.token;
    });
}

}  // namespace NS_TOKEN_FREQ