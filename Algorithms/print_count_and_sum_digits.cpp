#include <iostream>
#include <utility>
using namespace std;

pair<int, int> sumDigits(int n)
{
    int sum = 0;
    int count = 0;

    while (n > 0)
    {
        int mod = n % 10;
        sum += mod;
        n = n / 10;
        count++;
    }

    return {sum, count};
}

int main()
{
    int digits;
    cout << "Enter digits greater than 4 values " << endl;
    cin >> digits;

    pair<int, int> result = sumDigits(digits);

    cout << "Sum: " << result.first << endl;
    cout << "Count: " << result.second << endl;

    return 0;
}