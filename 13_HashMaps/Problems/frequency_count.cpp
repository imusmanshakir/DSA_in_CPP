#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> nums = {1, 2, 8, 3, 2, 2, 2, 5, 1};

    unordered_map<int, int> freqMap;

    for (int x : nums)
    {
        // If key does not exist
        if (freqMap.find(x) == freqMap.end()) // we did not have key so we will create it with value 0 and assign 1.
        {
            freqMap[x] = 1;
        }
        else
        {
            freqMap[x] = freqMap[x] + 1; // key exist update its value
        }
    }

    cout << "Element | Frequency" << endl;

    for (auto item : freqMap)
    {
        cout << item.first
             << "       | "
             << item.second
             << endl;
    }

    return 0;
}

/*
unordered_map<int, int> count;

count[5]++;  // 5 didn't exist, so C++ creates it as 0, then ++ makes it 1
count[5]++;  // 5 exists as 1, ++ makes it 2
count[5]++;  // 5 exists as 2, ++ makes it 3

cout << count[5];  // prints 3
*/