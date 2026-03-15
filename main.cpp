#include <iostream>
using namespace std;

int findSquare(int n)
{
    int start = 0;
    int ans = 0;
    int end = n;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        long long square = (long long)mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
};

int main()
{
    int n = 20;
    cout << findSquare(n) << " " << endl;

    return 0;
};