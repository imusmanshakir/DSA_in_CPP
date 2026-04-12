#include <iostream>
using namespace std;

// Computes the sum of both the main and secondary diagonals
int diagonalSum(int mat[][4], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                // main diagonal element
                sum += mat[i][j];
            }
            else if (j == n - i - 1) {
                // secondary (anti-) diagonal element
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

int main() {
    // example 4×4 matrix
    int matrix[4][4] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int n = 4;

    cout << "Sum of both diagonals is: "
         << diagonalSum(matrix, n) << endl;  
    // For this matrix: (1+6+11+16) + (4+7+10+13) = 68

    return 0;
}
