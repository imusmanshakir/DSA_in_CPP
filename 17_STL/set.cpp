#include <iostream>
#include <set>

using namespace std;

int main()
{
    // creating an empty set
    set<int> st1;

    // Initialize set with list
    set<int> st2 = {1, 2, 3, 2, 1};
    cout << "Insering in st1: " << endl;
    st1.insert(1);
    for (const int &i : st1)
    {
        cout << i << endl;
    }
    cout << "Working with st2: " << endl;
    for (const int &i : st2)
    {
        cout << i << endl;
    }

    if (st2.count(6))
    {
        cout << "True value exist " << endl;
    }

    return 0;
}

// A set is a container that:

// Stores unique elements only
// Keeps elements in sorted order automatically