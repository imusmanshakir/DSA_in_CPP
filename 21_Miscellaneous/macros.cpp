#include <iostream>
#define PI 3.14
#define DEBUG
#define MESSAGE "This is a long message, \
that takes more than a single line, \
but is considered a single preprocessor directive."

using namespace std;

int main()
{

    float area = PI * 10 * 10;
    cout << "area is: " << area << endl;

#ifdef DEBUG
    cout << "Debug mode ON" << endl;
#endif

    cout << MESSAGE << endl;

    return 0;
}

/* A macro is defined using #define and it tells the preprocessor:

 “Wherever you see this name, replace it with this text.”

🔹 Types of Macros

1. Object-like macros
Just replacement values:
#define MAX 100
#define NAME "Usman"

2. Function-like macros
Macros that take arguments:
#define SQUARE(x) (x * x)

int a = SQUARE(5);  // becomes (5 * 5)


🔹 Why macros were used?
Define constants
Write short reusable code
Conditional compilation

 */

// https://hitgal.medium.com/part-1-understanding-the-preprocessor-in-c-975c24484525
