#include <iostream>
#include <map>

using namespace std;

int main()
{
    // A map stores data in key → value pairs.
    // map<key_type, value_type> name;
    // Creating an empty map
    map<int, string> m1;
    m1[1] = "Ali";
    m1[2] = "Usman";
    m1[3] = "Ahmed";

    map<int, string> m2 = {{1, "Geeks"}, {2, "For"}, {3, "Geeks"}};

    // Updating value
    m2[0] = "Tweaks";
    m2.at(1) = "By";
    for (const auto &p : m2)
    {
        cout << p.first << " -> " << p.second << endl;
    }

    // You can also use structured binding (C++17):
    for (const auto &[key, value] : m1)
    {
        cout << key << " -> " << value << endl;
    }

    return 0;
}
