#include <iostream>
using namespace std;

int main()
{
    int rows = 3, cols = 4;

    // Step 1: create array of pointers (rows)
    int **arr = new int*[rows];

    // Step 2: allocate each row
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    // Step 3: use the array
    arr[0][0] = 10;
    arr[1][2] = 20;

    cout << arr[0][0] << endl;
    cout << arr[1][2] << endl;

    // Step 4: free memory
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}