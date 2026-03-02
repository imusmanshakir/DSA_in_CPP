#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search in a rotated sorted array
int searchRotatedArray(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid potential integer overflow

        // If target is found at mid, return its index
        if (arr[mid] == target) {
            return mid;
        }

        // Check if left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if target lies in the sorted left half
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1; // Search left half
            } else {
                low = mid + 1;  // Search right half
            }
        }
        // Otherwise, right half is sorted
        else {
            // Check if target lies in the sorted right half
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;  // Search right half
            } else {
                high = mid - 1; // Search left half
            }
        }
    }
    return -1; // Target not found
}

int main() {
    // Example usage
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = searchRotatedArray(arr, target);
    if (result != -1) {
       cout << "Found at index " << result << std::endl;
    } else {
       cout << "Not found" << std::endl;
    }

    return 0;
}