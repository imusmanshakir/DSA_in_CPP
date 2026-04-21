#include <iostream>
using namespace std;

void countDown(int n)
{

    cout << "Print somethng while stack overflow happens " << endl;

    countDown(n - 1);
}

int main()
{
    countDown(4);
    return 0;
}