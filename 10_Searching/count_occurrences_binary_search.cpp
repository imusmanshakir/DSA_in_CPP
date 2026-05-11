#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int lastOccurrence(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 3, 4, 5, 6};
    int target = 3;

    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);

    if (first == -1)
        cout << "Element not found" << endl;
    else
        cout << "Total occurrences: " << last - first + 1 << endl;

    return 0;
}