#include <iostream>

using namespace std;

int isPresent(int arr[][4], int target, int rows, int columns)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] == target)
            {
                cout << "Found at " << i << ", " << j << endl;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {7, 8, 9, 0},

    };

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }

    cout << "Here is your 2D Array: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the element you are looking for? " << endl;
    int target;
    cin >> target;
    int result = isPresent(arr, target, 3, 4);
    if (result)
    {
        cout << target << " Exist in your 2D Array " << endl;
    }
    else
    {
        cout << "Did not found " << endl;
    }

    return 0;
}

// Why do we need to specify the column size when passing a 2D array as a parameter?
//  https://stackoverflow.com/questions/12813494/why-do-we-need-to-specify-the-column-size-when-passing-a-2d-array-as-a-parameter