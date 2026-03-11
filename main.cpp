#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    int start = 0;
    int end = arr.size() - 1;

    int mid = start + (end - start) / 2;
    cout << mid << " " << endl;
};