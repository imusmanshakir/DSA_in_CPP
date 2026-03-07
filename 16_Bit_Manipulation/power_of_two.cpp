#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {

    if(n <= 0)
        return false;

    return (n & (n - 1)) == 0;
}

int main() {

    int n;
    cout << "Enter number: ";
    cin >> n;

    if(isPowerOfTwo(n))
        cout << "Power of Two";
    else
        cout << "Not a Power of Two";

    return 0;
}