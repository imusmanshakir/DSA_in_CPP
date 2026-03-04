#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1, pivot = arr[end];

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx - 1);  // left half
        quickSort(arr, pivIdx + 1, end); // right half
    }
}

int main()
{
    vector<int> arr = {5, 2, 6, 4, 1, 3};
    quickSort(arr, 0, arr.size() - 1);
    for (int val : arr)
    {
        cout << val << " ";
    }

    return 0;
}

// Example wlakthrough of quickSort

/*
quickSort(0,5)   // arr = {5,2,6,4,1,3}
│
└─ partition around pivot = 3 ⇒
     after partition: arr = {2,1,3,4,5,6}
     returned pivIdx = 2
   ├─ quickSort(0,1)   // left of 3  ⇒ {2,1}
   │   └─ partition around pivot = 1 ⇒
   │        after partition: arr = {1,2,3,4,5,6}
   │        returned pivIdx = 0
   │      ├─ quickSort(0, −1)  // empty ⇒ return immediately
   │      └─ quickSort(1, 1)   // size 1 ⇒ return immediately
   │
   └─ quickSort(3,5)   // right of 3 ⇒ {4,5,6}
       └─ partition around pivot = 6 ⇒
            after partition: arr = {1,2,3,4,5,6}
            returned pivIdx = 5
         ├─ quickSort(3,4)   // {4,5}
         │   └─ partition around pivot = 5 ⇒
         │        after partition: arr = {1,2,3,4,5,6}
         │        returned pivIdx = 4
         │      ├─ quickSort(3,3)  // size 1 ⇒ return
         │      └─ quickSort(5,4)  // empty ⇒ return
         │
         └─ quickSort(6,5)  // empty ⇒ return
*/
