#include <iostream>
#include <stack>
using namespace std;

// Function to print stack (by value so original stays safe)
void printStack(stack<int> st)
{
    cout << "Stack elements (top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Function to reverse a stack
void reverseStack(stack<int> &st)
{
    stack<int> temp;

    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }

    st = temp;
}

// Function to find maximum element in stack
int findMax(stack<int> st)
{
    int mx = st.top();
    while (!st.empty())
    {
        if (st.top() > mx)
        {
            mx = st.top();
        }
        st.pop();
    }
    return mx;
}

int main()
{
    // 1. Create stack
    stack<int> st;

    // 2. Push elements
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(5);

    cout << "Original Stack:" << endl;
    printStack(st);

    // 3. Top element
    cout << "Top element: " << st.top() << endl;

    // 4. Pop element
    st.pop();
    cout << "After pop, top: " << st.top() << endl;

    // 5. Size
    cout << "Size: " << st.size() << endl;

    // 6. Copy stack
    stack<int> st2 = st;
    cout << "\nCopied Stack:" << endl;
    printStack(st2);

    // 7. Find maximum
    cout << "Maximum element: " << findMax(st) << endl;

    // 8. Reverse stack
    reverseStack(st);
    cout << "\nReversed Stack:" << endl;
    printStack(st);

    return 0;
}