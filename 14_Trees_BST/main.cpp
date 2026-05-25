#include <iostream>
using namespace std;

// Recursive function to print array elements
void printArray(int arr[], int size, int index)
{
    // Base Case: Stop if the current index reaches the size of the array
    if (index >= size)
    {
        return;
    }

    // Print the current element
    cout << arr[index] << " ";

    // Recursive Call: Move to the next index
    printArray(arr, size, index + 1);
}

int main()
{
    int digits[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(digits) / sizeof(digits[0]); // Calculate array length

    cout << "Array digits: ";
    printArray(digits, n, 0); // Start recursion from index 0
    cout << endl;

    return 0;
}
