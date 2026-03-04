#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> vec(5, 1);
    vector<char> ch = {'a', 'b', 'c', 'd', 'e'};
    ch.push_back('f');
    cout << "cap " << vec.capacity()<<endl;
    cout << "cap " << ch.capacity();

    for (int i : vec)
    {
        cout << i << endl;
    }

    for (char val : ch)
    {
        cout << val << endl;
    }
    return 0;
}