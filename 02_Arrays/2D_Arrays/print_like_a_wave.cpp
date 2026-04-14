#include <iostream>
using namespace std;

void wavePrint(int arr[][4], int rows, int cols)
{
    for (int j = 0; j < cols; j++) // column-wise
    {
        if (j % 2 == 0)
        {
            // top to bottom
            for (int i = 0; i < rows; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        else
        {
            // bottom to top
            for (int i = rows - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    cout << "Wave Print Output:\n";

    wavePrint(arr, 3, 4); // function call

    return 0;
}

// What is print like a wave??
/* Print a 2D array in a wave pattern column-wise
Example Input
1   2   3   4
5   6   7   8
9  10  11  12
Expected Output (Wave Form)
1 5 9 10 6 2 3 7 11 12 8 4
*/