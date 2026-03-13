#ifndef TOKEN_FREQ_H
#define TOKEN_FREQ_H

#include <vector>
#include <string>

struct TokenFreq {
    std::string token;
    int freq;
};

void getTokenFreqVec(std::string&, std::vector<TokenFreq>&);
void selectionSort(std::vector<TokenFreq>&);
void insertionSort(std::vector<TokenFreq>&);

#endif // TOKEN_FREQ_H
