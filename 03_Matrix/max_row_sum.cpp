#include <iostream>
#include <climits>

using namespace std;

int getMaxSum(int matrix[][5], int rows, int columns)
{
    int maxRowSum = INT_MIN;

    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < columns; j++)
        {
            rowSum += matrix[i][j];
        }
        maxRowSum = max(maxRowSum, rowSum);
    }
    return maxRowSum;
};

int main()
{
    int matrix[4][5] = {
        {1, 2, 3, 4, 5},
        {5, 6, 7, 8, 9},
        {9, 10, 11, 12, 12},
        {13, 14, 15, 16, 17},

    };

    int rows = 4;
    int columns = 5;

    int result = getMaxSum(matrix, rows, columns);
    cout << result << endl;

    return 0;
}