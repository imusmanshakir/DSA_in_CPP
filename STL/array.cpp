#include <iostream>
#include <array>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4};

    array<int, 4> a = {1, 2, 3, 4};
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }

    cout << "Element At 2nd Index " << a.at(2) << endl;
    cout << "Is empty " << a.empty() << endl;
    cout <<"Element at front "<<  a.front() << endl;
    cout <<"Element at back "<< a.back() << endl;

    return 0;
}