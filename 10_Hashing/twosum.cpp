#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& arr, int tar) {
    unordered_map<int, int> m;
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {
        int first = arr[i];
        int sec = tar - first;

        if (m.find(sec) != m.end()) {
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }

        m[first] = i;
    }

    return ans;
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int tar = 9;

    vector<int> result = twoSum(arr, tar);

    if (!result.empty()) {
        cout << "Indices: " << result[1] << " and " << result[0] << endl;
        cout << "Values: " << arr[result[1]] << " + " << arr[result[0]] << " = " << tar << endl;
    } else {
        cout << "No two numbers found that add up to the target." << endl;
    }

    return 0;
}
