#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n < 4)
        return {};                  // Not enough elements for a quadruplet
    sort(nums.begin(), nums.end()); // Sort to use two-pointer technique and avoid duplicates

    vector<vector<int>> ans; // Store the result

    for (int i = 0; i < n; i++)
    {
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;//means again run the loop with next i

        for (int j = i + 1; j < n - 2; j++)
        {
            // Skip duplicates for j
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // Two pointers for the remaining two numbers
            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    for (const auto &quad : result) {
        for (int num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}