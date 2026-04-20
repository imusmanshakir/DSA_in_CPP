#include <iostream>

using namespace std;

int main()
{
    int x = 5;
    int *ptr1 = &x;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;

    cout << *ptr3 << endl; // ptr3 points to address of ptr2
    cout << ptr2 << endl;  // prints address of ptr2
    cout << *ptr2 << endl; // ptr2 points to address of ptr1
    cout << ptr1 << endl;  // prints address of ptr1
    cout << *ptr1 << endl; // ptr3 points to value at address of x(5)
    cout << ***ptr3 << endl;
    cout << endl;
    cout << &x << endl;
    cout << ptr1 << endl;
    cout << *ptr2 << endl;

    return 0;
}