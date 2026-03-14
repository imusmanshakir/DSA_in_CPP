#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findSecondLargestSinglePass(vector<int> &arr)
{
    if (arr.size() < 2)
    {
        cout << "Array needs at least 2 elements" << endl;
        return -1;
    }

    int first = INT_MIN;
    int second = INT_MIN;

    for (int num : arr)
    {
        if (num > first)
        {
            second = first; // Update second to old first
            first = num;    // Update first to new largest
        }
        else if (num > second && num < first)
        {
            second = num; // Update second only if num is between first and second
        }
    }

    if (second == INT_MIN)
    {
        cout << "No second largest element (all elements are same)" << endl;
        return -1;
    }

    return second;
}

int main()
{
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << "Largest: " << findSecondLargestSinglePass(arr) << endl;

    return 0;
}
