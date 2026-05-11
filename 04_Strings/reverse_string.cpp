#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string reverseWords(string s) {
    int n = s.length();
    string ans = "";

    // 1) Reverse the entire string
    reverse(s.begin(), s.end());

    // 2) Walk through it, pull out each “word” (now backwards), reverse it back,
    //    and append it to ans with a leading space
    for (int i = 0; i < n; ++i) {
        string word = "";
        while (i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }
        // reverse the characters of this word so it reads in correct order
        reverse(word.begin(), word.end());

        if (!word.empty()) {
            ans += " " + word;
        }
    }

    // 3) Drop the very first space we added
    return ans.substr(1);
}

int main() {
    // example usage:
    string input = "This is the string whose words we will reverse";
    cout << "Original: \"" << input << "\"\n";
    cout << "Reversed words: \"" << reverseWords(input) << "\"\n";
    return 0;
}
