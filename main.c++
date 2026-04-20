#include <iostream>
using namespace std;

int update(int n)
{
    n++;
    return n;
}

int& update1(int& n)
{
    n++;
    return n;
}

int main()
{
    int n = 5;
    cout << update(n) << endl;
    cout << update1(n) << endl;
    return 0;
}