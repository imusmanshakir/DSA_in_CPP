#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search on a specific row of the matrix
bool searchInRow(const vector<vector<int>>& mat, int target, int row) {
    int n = mat[row].size(); // Number of columns in the row
    int st = 0, end = n - 1; // Start and end indices for binary search
    while (st <= end) {
        int mid = st + (end - st) / 2; // Calculate mid index
        if (mat[row][mid] == target) {
            return true; // Target found
        } else if (mat[row][mid] < target) {
            st = mid + 1; // Search in the right half
        } else {
            end = mid - 1; // Search in the left half
        }
    }
    return false; // Target not found in this row
}

// Function to search for a target in a sorted 2D matrix
bool searchMatrix(const vector<vector<int>>& mat, int target) {
    if (mat.empty() || mat[0].empty()) {
        return false; // Matrix is empty
    }
    int m = mat.size(); // Number of rows
    int n = mat[0].size(); // Number of columns
    int startRow = 0, endRow = m - 1; // Initialize row search range
    while (startRow <= endRow) {
        int midRow = startRow + (endRow - startRow) / 2; // Calculate mid row
        if (target >= mat[midRow][0] && target <= mat[midRow][n-1]) {
            // Target is within this row's range, search in this row
            return searchInRow(mat, target, midRow);
        } else if (target > mat[midRow][n-1]) {
            // Target is larger than the last element of this row, search lower rows
            startRow = midRow + 1;
        } else {
            // Target is smaller than the first element of this row, search upper rows
            endRow = midRow - 1;
        }
    }
    return false; // Target not found in any row
}

int main(){
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {20, 23, 30, 34, 50},
        {60, 63, 70, 74, 80}
    };

    vector<int> targets = {7};

    for (int target : targets) {
        cout << "Searching for " << target << ": ";
        if (searchMatrix(mat, target)) {
            cout << "Found" << endl;
        } else {
            cout << "Not Found" << endl;
        }
    }
}