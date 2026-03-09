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
            start = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
};
int main()
{
    vector<int> array = {0, 12, 3, 4, 5, 6, 7, 8, 9};
    int target = 7;

    cout << binarySearch(array, target) << endl;
    return 0;
};