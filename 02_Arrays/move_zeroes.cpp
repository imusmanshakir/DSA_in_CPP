#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int j = 0; // position for next non-zero

    // Step 1: move non-zero elements forward
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[j] = nums[i];
            j++;
        }
    }

    // Step 2: fill remaining with zeros
    while (j < nums.size())
    {
        nums[j] = 0;
        j++;
    }
}

int main()
{

    vector<int> nums = {1, 0, 2, 0, 3, 0, 4};

    moveZeroes(nums);

    for (int n : nums)
    {
        cout << n << " ";
    }

    return 0;
}