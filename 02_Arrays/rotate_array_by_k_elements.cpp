#include <iostream>
using namespace std;

// Helper function to reverse a part of array
void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate array
void rotate(int arr[], int n, int k)
{
    k = k % n; // handle k > n

    // Reverse whole array
    reverse(arr, 0, n - 1);

    // Reverse first k elements
    reverse(arr, 0, k - 1);

    // Reverse remaining n-k elements
    reverse(arr, k, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotate(arr, n, k);

    cout << "Rotated array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}