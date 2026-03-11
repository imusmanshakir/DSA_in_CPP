#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid < end && arr[mid] > arr[mid + 1])
            return mid;

        if (mid > start && arr[mid] < arr[mid - 1])
            return mid - 1;

        if (arr[start] >= arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int main()
{
    // vector<int> arr = {10, 11, 12, 13, 1, 2, 3};   // for condition 1
    // vector<int> arr = {6, 7, 8, 9, 1, 2, 3, 4, 5}; // for condition 2
    // vector<int> arr = {8, 9, 1, 2, 3, 4, 5, 6, 7}; // for condition 3
    vector<int> arr = {4, 5, 6, 7, 8, 1, 2}; // for condition 4

    int pivot = findPivot(arr);

    cout << "Pivot index: " << pivot << endl;
    cout << "Pivot value: " << arr[pivot] << endl;

    return 0;
}