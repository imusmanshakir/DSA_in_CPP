#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    char ch = 'A';

    for (int i = 0; i < n; i++)
    {

        ch++;
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch; // You can put the i to print the value of numbers
        }
        cout << endl;
    }

    return 0;
}