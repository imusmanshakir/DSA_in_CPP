#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (mid % 2 == 0) {  // Even index
            if (mid + 1 < n && nums[mid] == nums[mid + 1]) {
                low = mid + 2;  // Move to next pair
            } else {
                high = mid;     // Single element at/before mid
            }
        } else {  // Odd index
            if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                low = mid + 1;  // Move to next element
            } else {
                high = mid - 1; // Single element before mid
            }
        }
    }
    
    return nums[low];
}

int main() {
    // Example usage
    vector<int> arr1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    vector<int> arr2 = {3, 3, 7, 7, 10, 11, 11};
    
    cout << "Single element: " << singleNonDuplicate(arr1) << endl;  // Output: 2
    cout << "Single element: " << singleNonDuplicate(arr2) << endl;  // Output: 10
    
    return 0;
}