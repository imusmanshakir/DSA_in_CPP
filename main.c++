#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    int *ptr = new int(100);

    delete ptr;
    // delete ptr;
    // delete x;

    return 0;
}