#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col_occupied(n, 0); // Tracks occupied columns
        vector<int> diag_occupied(2 * n, 0); // Tracks occupied diagonals
        vector<int> anti_diag_occupied(2 * n, 0); // Tracks occupied anti-diagonals
        vector<vector<string>> solutions; // Stores all solutions
        vector<string> board(n, string(n, '.')); // Represents the board

        // Backtracking function to place queens row by row
        function<void(int)> backtrack = [&](int row) -> void {
            if (row == n) {
                // If we've placed queens on all rows, add the current board to solutions
                solutions.push_back(board);
                return;
            }
            for (int column = 0; column < n; ++column) {
                // Check if the current position (row, column) is safe
                if (!col_occupied[column] && !diag_occupied[row + column] 
                    && !anti_diag_occupied[n - row + column]) {
                    // Place a queen at (row, column)
                    board[row][column] = 'Q';
                    // Mark the column, diagonal, and anti-diagonal as occupied
                    col_occupied[column] = diag_occupied[row + column] = anti_diag_occupied[n - row + column] = 1;
                    // Recur to the next row
                    backtrack(row + 1);
                    // Backtrack: Remove the queen and unmark the occupied positions
                    col_occupied[column] = diag_occupied[row + column] = anti_diag_occupied[n - row + column] = 0;
                    board[row][column] = '.';
                }
            }
        };

        // Start backtracking from the first row
        backtrack(0);
        return solutions;
    }
};