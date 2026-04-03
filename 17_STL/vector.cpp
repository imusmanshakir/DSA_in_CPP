#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);  v.push_back(2);  v.push_back(3);  v.push_back(4);  v.push_back(5);
 

    cout << "Size " << v.size() << endl;
    cout << "Capacity " << v.capacity() << endl;
    return 0;
}