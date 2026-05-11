#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        // If it's an opening bracket, push it
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } 
        // Else it's a closing bracket
        else {
            if (st.size() == 0) {
                return false;
            }

            if ((st.top() == '(' && str[i] == ')') ||
                (st.top() == '{' && str[i] == '}') ||
                (st.top() == '[' && str[i] == ']')) {
                st.pop();
            } else {
                return false; // mismatched pair
            }
        }
    }

    return st.empty(); // valid if stack is empty at the end
}

int main() {
    string test1 = "()[]{}";        // valid
    string test2 = "([{}])";        // valid
    string test3 = "(]";            // invalid
    string test4 = "((())";         // invalid
    string test5 = "{[(])}";        // invalid

    cout << test1 << " -> " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << test2 << " -> " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << test3 << " -> " << (isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << test4 << " -> " << (isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << test5 << " -> " << (isValid(test5) ? "Valid" : "Invalid") << endl;

    return 0;
}
