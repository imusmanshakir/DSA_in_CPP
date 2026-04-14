#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6}};

    int rows = arr.size();
    int cols = arr[0].size();
    cout << rows << " " << cols << " " << endl;

    return 0;
}
