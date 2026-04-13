#include <iostream>
using namespace std;

int getSum(int matrix[][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < columns; j++)
        {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i << " = " << sum << endl;
    }
    return 0;
}

int main()
{
    int matrix[4][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9},
                        {10, 11, 12}};

    cout << getSum(matrix, 4, 3);

    return 0;
}