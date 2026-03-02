#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelfOptimal(const vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n, 1);

    // Step 1: Prefix products
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        output[i] = prefix;
        prefix *= nums[i];
    }

    // Step 2: Suffix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        output[i] *= suffix;
        suffix *= nums[i];
    }

    return output;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelfOptimal(nums);

    cout << "Optimal result: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
