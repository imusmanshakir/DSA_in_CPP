#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        while (left < right && !isalnum(static_cast<unsigned char>(s[left]))) {
            left++;
        }
        while (left < right && !isalnum(static_cast<unsigned char>(s[right]))) {
            right--;
        }
        if (left < right) {
            if (tolower(static_cast<unsigned char>(s[left])) != tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }
            left++;
            right--;
        }
    }
    return true;
}

int main() {
    string s = {"Was it a car or a cat I saw?"};
    isPalindrome(s) ? cout << "Yes" << endl : cout << "No" << endl;
    // cout << "Enter a string: ";
    // getline(cin, s);
    
    // if (isPalindrome(s)) {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No" << endl;
    // }
    
    return 0;
}