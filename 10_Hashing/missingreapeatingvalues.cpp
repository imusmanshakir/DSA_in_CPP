#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_set<int> s;
    int duplicate = -1;

    // Traverse the grid to find the duplicate
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s.count(grid[i][j])) {
                duplicate = grid[i][j];
            } else {
                s.insert(grid[i][j]);
            }
        }
    }

    // Find the missing number
    int missing = -1;
    for (int num = 1; num <= n * n; num++) {
        if (s.count(num) == 0) {
            missing = num;
            break;
        }
    }

    return {missing, duplicate};
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 8} // Example grid with a duplicate
    };

    vector<int> result = findMissingAndRepeatedValues(grid);

    if (result.size() == 2) {
        cout << "Missing value: " << result[0] << ", Repeated value: " << result[1] << endl;
    } else {
        cout << "Error in finding missing and repeated values." << endl;
    }

    return 0;
}