#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printResult(vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
}

int main()
{
vector<int> arr = {43, 7, 91, 15, 62, 38, 74, 5, 29, 83, 11, 57, 66, 3, 48, 20, 95, 34, 72, 19};
    bubbleSort(arr);
    printResult(arr);

    return 0;
}


//claude visulization
// https://claude.ai/share/b0e399ec-26ff-4d91-93a9-247395f362f8