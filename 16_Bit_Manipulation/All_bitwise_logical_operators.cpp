#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter first number ";
    cin >> a;
    cout << "Enter second number ";

    cin >> b;

    int AND_operator = a & b;
    int OR_operator = a | b;
    int NOT_operator = ~a;
    int XOR_operator = a ^ b;

    cout << "Result in Decimal: " << endl;
    cout << a << " & " << b << " : " << AND_operator << endl;
    cout << a << " | " << b << " : " << OR_operator << endl;
    cout << a << " ~ " << b << " : " << NOT_operator << endl;
    cout << a << " ^ " << b << " : " << XOR_operator << endl;

    cout << "Result in Binary: " << endl;
    cout << bitset<8>(a) << " & " << bitset<8>(b) << " = " << bitset<8>(AND_operator) << endl;
    cout << bitset<8>(a) << " | " << bitset<8>(b) << " = " << bitset<8>(OR_operator) << endl;
    cout << bitset<8>(a) << " ~ " << bitset<8>(b) << " = " << bitset<8>(NOT_operator) << endl;
    cout << bitset<8>(a) << " ^ " << bitset<8>(b) << " = " << bitset<8>(XOR_operator) << endl;

    return 0;
};






//For NOT Operator 

// Original number
//       ↓
// ~ operator flips bits
//       ↓
// Result starts with 1 → treated as negative
//       ↓
// Two's complement used to calculate its value
// Two's complement:
// Positive number
// 00000101   (5)

// Flip bits
// 11111010

// Add 1
// 11111011   (-5)
// ********Example****************
// // ~x = -(x + 1)
// // ~5 = -(5 + 1) = -6
// // ~7 = -(7 + 1) = -8