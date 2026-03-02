#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> v;

public:
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v[v.size() - 1];
    }

    bool empty()
    {
        return v.empty();
    }
};

int main()
{

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl; // Should print 30
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Should print 20
    s.pop();
    cout << "Top element after another pop: " << s.top() << endl; // Should print 10
    s.pop();
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;           // Should print Yes
    s.pop();                                                                    // Attempting to pop from an empty stack, should be handled gracefully
    cout << "Is stack empty after pop? " << (s.empty() ? "Yes" : "No") << endl; // Should still print Yes
    return 0;
}