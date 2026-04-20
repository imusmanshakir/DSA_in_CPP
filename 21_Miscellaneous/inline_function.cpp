#include <iostream>

using namespace std;

inline int add(int a, int b)
{
    return a + b;
}

int main()
{
    int x = add(2, 3);
    cout << x << endl;

    return 0;
}

/* An inline function in C++ is a function where the compiler tries to replace the function call with the actual function code at compile time.

 Goal: avoid function call overhead (like jumping to another memory location and coming back).

 🔹 How it works
Normal function call:
int x = add(2, 3);
Internally (simplified):
Call function
Jump to function memory
Execute
Return back

Inline function:
int x = add(2, 3);
Compiler may convert it to:
int x = 2 + 3;
No jump, no call — just direct code.
 */