#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_front(2);

    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Element at index 1: " << d.at(1) << endl;
    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;
    cout << "is Empty: " << d.empty() << endl;

    cout << "Before Erase: " << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);
    cout << "After Erase: " << d.size() << endl;
    return 0;
}