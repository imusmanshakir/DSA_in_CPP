#include <iostream>
using namespace std;

bool linearsearch(int mat[][3], int rows, int cols, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mat[i][j] == key)
            {
                cout << "Element " << key << " found at index: " << i << ", " << j << endl;
                return true;
            }
        }
    }
    cout << "Element not found" << endl;
    return false;
}

int main()
{

    int matrix[4][3] =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {10, 11, 12}};

    int rows = 4;
    int cols = 3;

    linearsearch(matrix, rows, cols, 12);

    return 0;
}
