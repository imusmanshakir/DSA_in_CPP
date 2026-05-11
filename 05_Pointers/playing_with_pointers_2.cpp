#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2, 5, 6};
    int *ptr = &arr[0];

    cout << "Element at first index *arr: " << *arr << " --> can be written alternatively arr[0]: " << arr[0] << endl;
    cout << "Add 1 to first index *arr+1: " << *arr + 1 << endl;
    cout << "Move pointer address by 1 *(arr+1): " << *(arr + 1) << endl;
    cout << "Add 1 to first index *(arr)+1: " << *(arr) + 1 << endl;
    cout << endl;

    // this all print address of first element
    cout << "&arr[0]--> " << &arr[0] << endl;
    cout << "&arr-----> " << &arr << endl;
    cout << "arr------> " << arr << endl;
    cout << endl;

    // Playing with ptr now
    cout << "Address of pointer block or pointer itself---------> " << &ptr << endl; //&ptr represents the memory address of the pointer variable itself. Since a pointer is a distinct variable stored in memory, it has its own unique address.
    cout << "Address of first element of arr[0]                -> " << &arr << endl; //&arr represents the memory address where the array starts. In C++, this is numerically the same as the address of the first element (&arr[0]), but it refers to the entire array block.

    return 0;
}

/*Catious⚠️
1. These rules apply to ALL arrays, int, char, double



*/
