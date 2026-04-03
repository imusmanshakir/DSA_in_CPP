#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];   // element to insert
        int j = i - 1;

        // shift elements greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // place key at correct position
        arr[j + 1] = key;
    }
}

void printResult(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
}

int main()
{
    vector<int> arr = {4, 3, 2, 5, 1};

    insertionSort(arr);
    printResult(arr);

    return 0;
}