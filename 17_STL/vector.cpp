#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "Size " << v.size() << endl;
    cout << "Capacity " << v.capacity() << endl;
    cout << "Front " << v.front() << endl;
    cout << "Back " << v.back() << endl;

    cout << "Before pop " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

    cout << "After pop " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Before clear size " << v.size() << endl;
    cout << "Before clear capacity " << v.capacity() << endl;
    v.clear();
    cout << "After clear size " << v.size() << endl;
    cout << "After clear capacity " << v.capacity() << endl;

    cout << "Woring with new vector a " << endl;

    vector<int> a(5, 1);
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> last(a);
    cout << "Vector copied from a instead of created " << endl;
    for (int i : last)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}