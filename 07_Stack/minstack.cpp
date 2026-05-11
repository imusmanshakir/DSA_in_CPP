#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> S; // Main stack for elements
    stack<int> M; // Auxiliary stack for minimums
public:
    // Push an element onto the stack
    void push(int x) {
        S.push(x);
        // Push to M if M is empty or x is less than or equal to current minimum
        if (M.empty() || x <= M.top()) {
            M.push(x);
        }
    }
    
    // Remove the top element from the stack
    void pop() {
        // If top element is the current minimum, pop from M as well
        if (!S.empty() && S.top() == M.top()) {
            M.pop();
        }
        if (!S.empty()) {
            S.pop();
        }
    }
    
    // Return the top element of the stack
    int top() {
        if (!S.empty()) {
            return S.top();
        }
        return -1; // Assuming stack is non-empty as per standard problem constraints
    }
    
    // Return the current minimum element in the stack
    int getMin() {
        if (!M.empty()) {
            return M.top();
        }
        return -1; // Assuming stack is non-empty as per standard problem constraints
    }
 
};