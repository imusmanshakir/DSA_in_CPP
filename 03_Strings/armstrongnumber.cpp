#include <iostream>
using namespace std;

bool isArmstrong(int n)
{
    int copyN = n;
    int sumOfCubes = 0;

    // for a three‑digit number, an Armstrong check is sum of each digit³
    while (n != 0)
    {
        int dig = n % 10;
        sumOfCubes += dig * dig * dig;
        n /= 10;
    }

    return sumOfCubes == copyN;
}

int main()
{
    int n = 153; // try 153, 370, 371, 407 (all are 3‑digit Armstrong numbers)

    if (isArmstrong(n))
    {
        cout << n << " is an Armstrong number\n";
    }
    else
    {
        cout << n << " is NOT an Armstrong number\n";
    }

    return 0;
}
