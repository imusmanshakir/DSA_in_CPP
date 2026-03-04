#include <iostream>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int size = 4; // Size of the array
    int target = 30; // Element to search for
    int result = linearSearch(arr, size, target);
    cout << "Element found at index: " << result << endl;

    return 0;
}