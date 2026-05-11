#include <iostream>
#include <bitset>
using namespace std;

/*
  Left Shift Operator (<<) in C++

  - Shifts all bits of a number to the left by 'n' positions.
  - Vacant bits on the right are filled with 0.
  - Effectively multiplies the number by 2^n (for unsigned integers).
  - Be careful: shifting too far may cause overflow.
*/

int main()
{
    int num, shift;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter number of positions to left shift: ";
    cin >> shift;

    cout << endl
         << "Original Number:" << endl;
    cout << "Decimal: " << num << endl;
    cout << "Binary : " << bitset<8>(num) << endl;

    int leftShift = num << shift;

    cout << endl
         << "After Left Shift (" << shift << " positions):" << endl;
    cout << "Decimal: " << leftShift << endl;
    cout << "Binary : " << bitset<8>(leftShift) << endl;

    cout << endl;
    return 0;
}