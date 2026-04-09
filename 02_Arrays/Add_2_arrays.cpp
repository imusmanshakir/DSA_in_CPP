#include <iostream>
#include <vector>
using namespace std;

vector<int> addArraysElementwise(const vector<int> &a, const vector<int> &b)
{
    // Assume both vectors have the same size
    vector<int> result(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        result[i] = a[i] + b[i];
    }
    return result;
}

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};
    vector<int> sum = addArraysElementwise(a, b);

    for (int x : sum)
        cout << x << " "; // Output: 5 7 9
    return 0;
}