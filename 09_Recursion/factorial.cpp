#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
    { // Base case: factorial of 0 or 1 is 1
        return 1;
    }
    return n * factorial(n - 1); // Recursive step: n * (n-1)!
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial is: " << factorial(n) << endl;
    return 0;
}

// here is claude visualization
// https://claude.ai/chat/b649eacb-1ec6-47a2-b102-aa8b7468289b
// www.kimi.com/share/19e5acd5-0a12-8e45-8000-0000537465cf