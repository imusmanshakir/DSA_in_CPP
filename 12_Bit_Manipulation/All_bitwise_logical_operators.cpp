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

// How the Bitwise NOT (~) Operator Works

// Step 1: Start with the original number
// Example:
 // 5  → 00000101

// Step 2: The ~ operator flips all bits (0 → 1, 1 → 0)
 // 00000101
 // ↓
 // 11111010

// Step 3: Since the leftmost bit becomes 1,
// the result is interpreted as a negative number
// (C++ uses two's complement representation for signed integers).

// Understanding Two's Complement
// Two's complement is used to represent negative numbers in binary.

// Steps to compute two's complement:
// 1. Flip all bits (one's complement)
// 2. Add 1

// Example for -5:

// Positive number
//  00000101   (5)

// Flip bits
//  11111010

// Add 1
//  11111011   (-5)


// Important Identity
// ~x = -(x + 1)

// Examples
// ~5 = -(5 + 1) = -6
// ~7 = -(7 + 1) = -8