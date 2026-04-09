#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return true; // An array with 0 or 1 element is always sorted and rotated

    int countDrops = 0;

    for (int i = 0; i < n; i++)
    {
        // Compare current element with next (circularly)
        if (nums[i] > nums[(i + 1) % n]) // Normally we would compare nums[i] with nums[i+1], but for the last element (i = n-1), i+1 would be n (out of bounds).The modulo operator % n wraps the index around:
        {
            countDrops++;
        }
        // Early exit if more than 1 drop found
        if (countDrops > 1)
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int>> testCases = {
        {3, 4, 5, 1, 2},
        {2, 1, 3, 4},
        {1, 2, 3},
        {1, 1, 1},
        {6, 10, 6}};

    for (auto &arr : testCases)
    {
        cout << "[ ";
        for (int x : arr)
            cout << x << " ";
        cout << "] -> " << (check(arr) ? "true" : "false") << endl;
    }
    return 0;
}

// Understanding the problem:
/*
1. We will count how many times an element is greater than the next element.
2. In a perfectly sorted non‑decreasing array, this never happens (countDrops = 0).
3. In a sorted array that has been rotated once, there will be exactly one such "drop".
4. If there are two or more drops, the array cannot be a rotated sorted array.
*/
