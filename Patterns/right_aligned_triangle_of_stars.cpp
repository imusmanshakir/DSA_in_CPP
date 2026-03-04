#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n; // number of rows

    for (int i = 1; i <= n; i++)
    {
        // print spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // print stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}