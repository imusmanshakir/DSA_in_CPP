#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}

int main()
{
    vector<int> arr = {1, 3, 7, 5, 9, 6, 2};

    int peak = findPeakElement(arr);

    cout << "Peak element index: " << peak << endl;
    cout << "Peak element value: " << arr[peak] << endl;

    return 0;
}