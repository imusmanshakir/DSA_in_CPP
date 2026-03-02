#include <iostream>
using namespace std;

int findMajority(int arr[], int n) {
    int candidate = arr[0];  // Start with first element as candidate
    int counter = 1;         // Initialize counter

    // Iterate through the array
    for (int i = 1; i < n; i++) {
        if (arr[i] == candidate) {
            counter++;       // Same element, increment counter
        } else {
            counter--;       // Different element, decrement counter
            if (counter == 0) {
                candidate = arr[i];  // Counter zero, new candidate
                counter = 1;         // Reset counter
            }
        }
    }
    return candidate;  // Final candidate is the majority element
}

int main() {
    int arr[] = {2, 2,1,1, 1, 1, 2};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Majority element is: " << findMajority(arr, n) << endl;
    return 0;
}