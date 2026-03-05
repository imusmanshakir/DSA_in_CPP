#include <iostream>
using namespace std;

int main()
{
    int n = 3;
    int count = 1;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)

        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }

    cout << "After pattern the value should be 10: " << count << endl;

    return 0;
}