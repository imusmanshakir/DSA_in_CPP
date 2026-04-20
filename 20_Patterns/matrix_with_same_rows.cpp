#include <iostream>
using namespace std;

int main()
{
   int n;
   cin>>n;
   char CH = 'A';
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << count << " ";
            cout<<CH<<" ";
        }
        count = count + 1;
        CH++;
        cout << endl;
    }

    return 0;
};