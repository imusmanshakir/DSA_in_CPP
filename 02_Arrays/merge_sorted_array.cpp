#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;     // last valid element of nums1
    int j = n - 1;     // last element of nums2
    int k = m + n - 1; // last position of merged array

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    // if nums2 still has elements remaining, copy them
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }

    // if nums1 still has elements remaining, they're already in place — do nothing
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    merge(nums1, 3, nums2, 3);

    for (int n : nums1)
        cout << n << " ";
    // Output: 1 2 2 3 5 6
}