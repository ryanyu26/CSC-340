#include "matrixInit.h"

#include <limits>

using namespace std;

namespace NS_MATRIX {

vector<vector<int>> matrixInit(int rows, int cols, int initValue) {
    // Return an empty matrix for invalid dimensions.
    if (rows <= 0 || cols <= 0) {
        return {};
    }

    const size_t rowCount = static_cast<size_t>(rows);
    const size_t colCount = static_cast<size_t>(cols);

    // Fail-safe: avoid impossible allocations that exceed vector limits.
    if (rowCount > vector<vector<int>>().max_size() || colCount > vector<int>().max_size()) {
        return {};
    }

    // Create a rows x cols matrix where each cell starts as initValue.
    try {
        return vector<vector<int>>(rows, vector<int>(cols, initValue));
    } catch (...) {
        // Fail-safe: return empty matrix if allocation fails.
        return {};
    }
}

void matrixInit(vector<vector<int>>& matrix, int rows, int cols, int initValue) {
    matrix = matrixInit(rows, cols, initValue);

    if (initValue == 0) {
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                matrix[row][col] = row * col;
            }
        }
    }
}

}  // namespace NS_MATRIX