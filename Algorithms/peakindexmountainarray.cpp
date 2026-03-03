#include <iostream>
#include <vector>
using namespace std;


int peakIndexInMountainArray(const vector<int>& arr) {
    int left = 0, right = int(arr.size()) - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        // If we're on the ascending slope, the peak is to the right
        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        }
        // Otherwise, we're on the descending slope (or at the peak)
        else {
            right = mid;
        }
    }
    // left == right is the peak index
    return left;
}

int main() {
    // Example usage:
    vector<int> mountain1 = {0, 2, 5, 3, 1};
    vector<int> mountain2 = {0, 10, 20, 15, 5, 2};
    
    cout << "Peak index of mountain1: "
         << peakIndexInMountainArray(mountain1) << endl;  // outputs 2
    
    cout << "Peak index of mountain2: "
         << peakIndexInMountainArray(mountain2) << endl;  // outputs 2

    return 0;
}
