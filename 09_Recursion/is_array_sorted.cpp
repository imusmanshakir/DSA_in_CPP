#include <iostream>
#include <vector>
using namespace std;

bool isArraySorted(const vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }

    return arr[n - 1] >= arr[n - 2] && isArraySorted(arr, n - 1);
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    cout << (isArraySorted(arr, arr.size()) ? "Array is sorted" : "Array is not sorted") << endl;

    return 0;
}