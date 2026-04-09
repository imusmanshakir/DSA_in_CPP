#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
    }

    while (j < nums.size())
    {
        nums[j] = 0;
        j++;
    }
}

int main()
{
    vector<int> nums = {1, 2, 0, 4, 5, 0, 6, 7};
    moveZeroes(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}