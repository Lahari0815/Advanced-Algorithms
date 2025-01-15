#include <iostream>
#include <vector>
using namespace std; 

void createSparseMatrix(const vector<vector<int>>& matrix, vector<vector<int>>& sparseMatrix) {
    int nonZeroCount = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] != 0) {
                ++nonZeroCount;
            }
        }
    }

    sparseMatrix.resize(nonZeroCount, vector<int>(3));

    int k = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k++][2] = matrix[i][j];
            }
        }
    }
}

void printSparseMatrix(const vector<vector<int>>& sparseMatrix) {
    cout << "Row    : [ ";
    for (const auto& row : sparseMatrix) {
        cout << row[0] << " ";
    }
    cout << "]\n";

    cout << "Column : [ ";
    for (const auto& row : sparseMatrix) {
        cout << row[1] << " ";
    }
    cout << "]\n";

    cout << "Value  : [ ";
    for (const auto& row : sparseMatrix) {
        cout << row[2] << " ";
    }
    cout << "]\n";
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    if (rows <= 0) {
        cout << "Invalid input: Number of rows must be greater than 0.\n";
        return 1; 
    }
    
    cout << "Enter the number of columns: ";
    cin >> cols;
    if (cols <= 0) {
        cout << "Invalid input: Number of columns must be greater than 0.\n";
        return 1; 
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the matrix elements (row by row):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> sparseMatrix;
    createSparseMatrix(matrix, sparseMatrix);

    cout << "Array representation of the sparse matrix:\n";
    printSparseMatrix(sparseMatrix);

    return 0;
}