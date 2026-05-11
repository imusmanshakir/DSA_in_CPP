#include <iostream>

using namespace std;

int main()
{
    // Declare and init an array
    int arr[5] = {10, 20, 30, 40, 50};
    // pointer point first element of array
    int *ptr = arr;
    // print address and value of pointer
    std::cout << "address of pointer is " << ptr << ", and value of pointer is: " << *ptr << std::endl;
    // // incremnet the pointer
    ptr++;
    // // incremented value of pointer
    std::cout << "incremented address of pointer " << ptr << ", and incremented value of pointer is: " << *ptr << std::endl;
    // // Decrement the pointer
    ptr--;
    // // print address and value of decremented pointer
    std::cout << "Decremented address of pointer " << ptr << ", and Decremented value of pointer is: " << *ptr << std::endl;

    // adding 2 to move forward
    ptr = ptr + 2;
    // // print
    std::cout << "after adding 2 " << ptr << ", the value of pointer " << *ptr << std::endl;
    // // adding 2 to move backward
    ptr = ptr - 2;
    // // print
    std::cout << "after adding -2 " << ptr << ", the value of pointer " << *ptr << std::endl;

    // comparsion operator

    int *ptr1 = &arr[1];
    int *ptr2 = &arr[2];

    if (ptr1 < ptr2)
    {
        std::cout << "ptr1 come first in memory address then ptr2" << std::endl;
    }
    else if (ptr1 > ptr2)
    {
        std::cout << "ptr2 is come first in memory address then ptr2" << std::endl;
    }
    else
    {
        std::cout << "ptr1 and ptr2 both are same memory location" << std::endl;
    }
    if (ptr1 == &arr[1])
    {
        std::cout << "ptr1 points to the 2nd element of the array" << std::endl;
    }

    return 0;
}
