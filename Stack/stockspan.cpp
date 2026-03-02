#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans(price.size(), 1);
    stack<int> s;

    for (int i = 0; i < price.size(); i++)
    {
        while (!s.empty() && price[s.top()] <= price[i]) // Compare current price with the price at the index stored at the top of the stack
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = i + 1;// If stack is empty, it means all previous prices are less than or equal to current price
        }
        else
        {
            ans[i] = i - s.top();// If stack is not empty, the top element is the last price greater than current price
        }
        s.push(i);// Push the current index onto the stack
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
