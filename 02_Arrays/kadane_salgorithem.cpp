#include <iostream>
using namespace std;

int kadanesAlgorithm(int arr[], int n) {
    int currSum = arr[0]; // Initialize with first element
    int maxSum = arr[0];  // Initialize with first element

    for (int i = 1; i < n; i++) {
        // Choose: start new subarray or extend existing one
        currSum = max(arr[i], currSum + arr[i]);
        // Update maxSum if currSum is larger
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum subarray sum is: " << kadanesAlgorithm(arr, n) << endl;

    return 0;
}