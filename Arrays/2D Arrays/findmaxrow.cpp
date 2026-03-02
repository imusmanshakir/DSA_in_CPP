#include <iostream>
#include <climits>
using namespace std;

int getMaxRowSum(int mat[][3], int rows, int cols)
{
    int maxRowSum = INT_MIN;

    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;//Iterate through each row and calculate the sum
        for (int j = 0; j < cols; j++)
        {
            rowSum += mat[i][j];
        }
        maxRowSum = max(maxRowSum, rowSum);
    }

    return maxRowSum;
}

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int rows = 3;
    int cols = 3;

    cout << "Max row sum: "
         << getMaxRowSum(matrix, rows, cols)
         << endl;

    return 0;
}
