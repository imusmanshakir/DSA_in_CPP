#include <iostream>
#include <vector>
using namespace std;

int binarySearchHelper(const vector<int> &arr, int tar, int st, int end)
{
    if (st > end)
        return -1;

    int mid = st + (end - st) / 2;

    if (arr[mid] == tar)
        return mid;
    else if (arr[mid] < tar)
        return binarySearchHelper(arr, tar, mid + 1, end);
    else
        return binarySearchHelper(arr, tar, st, mid - 1);
}

int binarySearch(const vector<int> &arr, int tar)
{
    return binarySearchHelper(arr, tar, 0, (arr.size()) - 1);
}

int main()
{

    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int tar = 1;

    int idx = binarySearch(arr, tar);
    if (idx != -1)
        cout << "Found " << tar << " at index " << idx << "\n";
    else
        cout << tar << " not found in the array\n";

    return 0;
}
