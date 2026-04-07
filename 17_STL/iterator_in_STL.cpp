#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s = {10, 20, 30, 40};

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << endl; // dereferencing to get value
    }


    return 0;
}

/*🔸 What is an iterator?
An iterator is like a pointer that points to an element inside a container (set, vector, etc.).
 Range base loop can automatically dereference. Like we can use
for (const auto &int i : v)
{
    cout << v << endl;
}
This loop is called a range-based for loop, and internally it automatically dereferences the iterator for you.

*/