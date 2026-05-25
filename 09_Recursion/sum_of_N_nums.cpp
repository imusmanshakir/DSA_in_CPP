#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n - 1);
}

int main()
{
    int n;
    cout << "Enter number for N Sum: ";
    cin >> n;
    cout << "The sum is: " << sum(n) << endl;

    return 0;
}
//Step by step visulization
//https://www.kimi.com/share/19e5b0ae-4c32-8190-8000-00009a120620