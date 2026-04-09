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

// Example Walkthrough
// Initial vector:
// nums = {1, 0, 2, 0, 3, 0, 4}
// Size = 7.

// First loop (i from 0 to 6)

// +---+---------+----------------------------------------+---------+-----------------------------+|
// | i | nums[i] | Action                                 | j after | Vector state (after action)  |
// +---+---------+----------------------------------------+---------+-----------------------------+|
// | 0 |    1    | non-zero -> nums[0] = 1, j++            |    1    | {1, 0, 2, 0, 3, 0, 4}       |
// | 1 |    0    | zero -> skip                            |    1    | unchanged                   |
// | 2 |    2    | non-zero -> nums[1] = 2, j++            |    2    | {1, 2, 2, 0, 3, 0, 4}       |
// | 3 |    0    | zero -> skip                            |    2    | unchanged                   |
// | 4 |    3    | non-zero -> nums[2] = 3, j++            |    3    | {1, 2, 3, 0, 3, 0, 4}       |
// | 5 |    0    | zero -> skip                            |    3    | unchanged                   |
// | 6 |    4    | non-zero -> nums[3] = 4, j++            |    4    | {1, 2, 3, 4, 3, 0, 4}       |
// +---+---------+----------------------------------------+---------+-----------------------------+|