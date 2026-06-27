#include <iostream>
using namespace std;

void printNumbers(int n)
{
    if (n == 1)
    {
        cout << "1,";
        return;
    }

    printNumbers(n - 1);
    cout << n << ",";
}

int main()
{
    int n;
    cout << "How many number will you like to print? ";
    cin >> n;
    printNumbers(n);
    cout << endl;

    return 0;
}