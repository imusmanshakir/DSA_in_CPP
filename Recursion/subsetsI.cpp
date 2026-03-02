#include <iostream>
#include <vector>
using namespace std;

void printSubsets(const vector<int> arr, vector<int> ans, int i) {
    // Base case: we've considered every element
    if (i == arr.size()) {
        // Print the current subset
        cout << "{ ";
        for (int val : ans) {
            cout << val << " ";
        }
        cout << "}" << endl;
        return;
    }

    // **Include** arr[i] in the current subset
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    // **Backtrack**: remove arr[i] and move on
    ans.pop_back();

    // **Exclude** arr[i] from the current subset
    printSubsets(arr, ans, i + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans;  // will hold one subset at a time

    cout << "All subsets of {1, 2, 3}:\n";
    printSubsets(arr, ans, 0);

    return 0;
}
