#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;     // Pointer to last element in nums1's valid data
    int j = n - 1;     // Pointer to last element in nums2
    int p = m + n - 1; // Pointer to last position in nums1

    // Merge from the end while both arrays have elements
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[p] = nums1[i];
            i--;
        }
        else
        {
            nums1[p] = nums2[j];
            j--;
        }
        p--;
    }

    // Copy any remaining elements from nums2
    while (j >= 0)
    {
        nums1[p] = nums2[j];
        j--;
        p--;
    }
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7, 0, 0, 0, 0}; // Size m + n = 8
    vector<int> arr2 = {2, 4, 6, 8};
    int m = 4;
    int n = 4;
    merge(arr1, m, arr2, n);
    for (int num : arr1)
    {
        cout << num << " "; // Should print: 1 2 3 4 5 6 7 8
    }
    cout << endl;
    return 0;
}