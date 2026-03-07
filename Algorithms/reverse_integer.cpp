#include <iostream>
#include <climits>
using namespace std;

int reverseInteger(int x)
{

    int reverse = 0;

    while (x != 0)
    {

        int digit = x % 10;

        // Overflow check
        if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10)
        {
            return 0;
        }

        reverse = reverse * 10 + digit;

        x = x / 10;
    }

    return reverse;
}

int main()
{

    int x = 321;

    cout << reverseInteger(x) << endl;

    return 0;
}