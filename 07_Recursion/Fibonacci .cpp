#include <iostream>

using namespace std;

int feb(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return feb(n - 1) + feb(n - 2);
}

int main()
{

    cout << feb(10);
    return 0;
}