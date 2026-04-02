#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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

    vector<int> arr = {10,5,6,7,9,1,4,8,2,3};

    selectionSort(arr);
    printResult(arr);

    return 0;
}