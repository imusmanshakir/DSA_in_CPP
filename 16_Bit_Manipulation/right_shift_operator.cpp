#include <iostream>
#include <bitset>
using namespace std;

/*
  Right Shift Operator (>>) in C++

  - Shifts all bits of a number to the right by 'n' positions.
  - Vacant bits on the left depend on the type:
      - Unsigned integers: filled with 0 (logical shift)
      - Signed integers: usually filled with sign bit (arithmetic shift)
  - Effectively divides the number by 2^n (integer division).
*/

int main()
{
    int num, shift;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter number of positions to right shift: ";
    cin >> shift;

    cout << endl
         << "Original Number:" << endl;
    cout << "Decimal: " << num << endl;
    cout << "Binary : " << bitset<8>(num) << endl;

    int rightShift = num >> shift;

    cout << endl
         << "After Right Shift (" << shift << " positions):" << endl;
    cout << "Decimal: " << rightShift << endl;
    cout << "Binary : " << bitset<8>(rightShift) << endl;

    cout << endl;
    return 0;
}