#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(const vector<vector<int>> &matrix)
{
    vector<int> result;
    if (matrix.empty() || matrix[0].empty())
        return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        // Traverse from left to right
        for (int col = left; col <= right; ++col)
            result.push_back(matrix[top][col]);
        ++top;

        // Traverse downwards
        for (int row = top; row <= bottom; ++row)
            result.push_back(matrix[row][right]);
        --right;

        // Traverse from right to left
        if (top <= bottom)
        {
            for (int col = right; col >= left; --col)
                result.push_back(matrix[bottom][col]);
            --bottom;
        }

        // Traverse upwards
        if (left <= right)
        {
            for (int row = bottom; row >= top; --row)
                result.push_back(matrix[row][left]);
            ++left;
        }
        // ++top;
        // --right;
        // --bottom;
        // ++left;
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    vector<int> spiral = spiralOrder(matrix);

    cout << "Spiral order: ";
    for (int num : spiral)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
