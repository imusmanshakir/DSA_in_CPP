#include <iostream>
#include <climits>
using namespace std;

int getMaxColSum(int mat[][3], int rows, int cols)
{
    int maxColSum = INT_MIN;

    for (int i = 0; i < cols; i++)
    {
        int ColSum = 0; // Iterate through each row and calculate the sum
        for (int j = 0; j < rows; j++)
        {
            ColSum += mat[j][i];
        }
        maxColSum = max(maxColSum, ColSum);
    }

    return maxColSum;
}

int main()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int rows = 3;
    int cols = 3;

    cout << "Max col sum: "
         << getMaxColSum(matrix, rows, cols)
         << endl;

    return 0;
}
