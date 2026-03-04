#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;   // number of rows

    for (int i = 1; i <= n; i++)
    {
        int num = i;   // start number for each row

        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }

        cout << endl;
    }

    return 0;
}