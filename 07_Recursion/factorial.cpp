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
