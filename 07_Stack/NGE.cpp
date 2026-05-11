#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> arr = {6, 8, 0, 1, 2, 3};

    stack<int> s;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        { // Compare current element with the element at the index stored at the top of the stack
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1; // If stack is empty, no greater element found
        }
        else
        {
            ans[i] = arr[s.top()]; // If stack is not empty, the top element is the next greater element
        }
        s.push(arr[i]); // Push the current index onto the stack
    }

    for (int val : ans)
    {
        cout << val << " ";
        cout << endl;
    }

    return 0;
}