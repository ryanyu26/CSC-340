#ifndef MATRIX_INIT_H
#define MATRIX_INIT_H

#include <vector>

using namespace std;

namespace NS_MATRIX {

vector<vector<int>> matrixInit(int rows, int cols, int initValue = 0);
void matrixInit(vector<vector<int>>& matrix, int rows, int cols, int initValue = 0);

}  // namespace NS_MATRIX

#endif