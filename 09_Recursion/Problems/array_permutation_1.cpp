// using matrix
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive helper: fix one element at position idx, permute the rest
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        // Base case: we've fixed every position
        if (idx == (int)nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        // Try every possibility for nums[idx]
        for (int i = idx; i < (int)nums.size(); i++) {
            swap(nums[idx], nums[i]);               // choose nums[i] for position idx
            getPerms(nums, idx + 1, ans);          // permute the remainder
            swap(nums[idx], nums[i]);               // backtrack: undo the swap
        }
    }
    
    // Public API: returns all permutations of nums
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    
    auto perms = sol.permute(nums);
    cout << "Permutations of {1,2,3}:\n";
    for (auto& p : perms) {
        cout << "[ ";
        for (int x : p) cout << x << ' ';
        cout << "]\n";
    }

    return 0;
}
