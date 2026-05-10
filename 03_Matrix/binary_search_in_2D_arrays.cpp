#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();    // prints row size(3)
    int n = matrix[0].size(); // prints columns size(4)

    int low = 0;
    int high = m * n - 1; // last element of matrix(3*4-1 = 11)

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << "This is mid " << mid << endl;
        int row = mid / n;
        cout << "This row calculating: " << mid << " / " << n << "-->" << row << endl;
        int col = mid % n;
        cout << "This column calculating: " << mid << " % " << n << "-->" << col << endl;

        int value = matrix[row][col];

        if (value == target)
            return true;
        else if (value < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target = 16;

    cout << (searchMatrix(matrix, target) ? "Found" : "Not Found") << endl;

    return 0;
}