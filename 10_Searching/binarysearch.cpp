#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target)
{
    int start = 0, end = array.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (target > array[mid])
        {
            start = mid + 1;
        }
        else if (target < array[mid])
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{

    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd
    int tar1 = 4;

    cout << binarySearch(arr1, tar1) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even
    int tar2 = 0;

    cout << binarySearch(arr2, tar2) << endl;

    return 0;
}
