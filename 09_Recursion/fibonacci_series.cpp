#include <iostream>

using namespace std;

int feb(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return feb(n - 1) + feb(n - 2);  //under the hood recursion tree is made. like for three recursion will call 2 and one and 2 will call 0 amd 1
}

int main()
{

    cout << feb(2) << endl; 
    return 0;
}

/*
The Fibonacci sequence is a series of numbers where each number (Fibonacci number) is the sum of the two preceding ones,
typically starting from 0 and 1. It follows the pattern: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, and so on.
*/