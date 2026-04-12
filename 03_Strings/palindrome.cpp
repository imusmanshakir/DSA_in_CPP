#include <iostream>

using namespace std;

bool checkPalindrome(string str)
{
    int left = 0;
    int right = str.length() - 1L;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }

    return true;
}

int main()
{
    string str;
    cout << "Enter string to check if it is a string " << endl;
    cin >> str;
    char result = checkPalindrome(str);
    if (result)
    {
        cout << "True " << endl;
    }
    else
    {
        cout << "False " << endl;
    }

    return 0;
}