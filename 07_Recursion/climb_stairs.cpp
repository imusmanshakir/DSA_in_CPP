#include <iostream>
using namespace std;
int climbStairs(int n)
{
    // Base cases
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Recursive step: Sum of ways from the previous two stairs
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    int n = 5;
    cout << "Ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}
