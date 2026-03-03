#include <iostream>
#include <vector>
using namespace std;

bool isPossible(const vector<int>& arr, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if (studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocatedBooK(const vector<int>& arr, int m) {
    int start = 0;
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    int end = sum;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> pages = {60, 45, 26, 90};
    int student = 2;
    cout << "Allocated Total Pages Book is : " << allocatedBooK(pages, student) << endl;
    return 0;
}