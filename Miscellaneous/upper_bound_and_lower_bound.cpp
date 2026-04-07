#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s = {1, 3, 5, 7};

    auto lb = s.lower_bound(4);
    auto ub = s.upper_bound(4);

    cout << "Lower Bound of 4: " << *lb << endl;
    cout << "Upper Bound of 4: " << *ub << endl;

    return 0;
}
// lower bound checks if value exist in array if so then it return if value does not exist then it return value greater than value we wants to find.
// More Precisely:
// 🔹 Lower Bound

// Returns an iterator to the first element ≥ value, whether the value exists or not.

// ✔ If value exists → returns first occurrence
// ✔ If value does NOT exist → returns next greater element

// 🔹 Upper Bound

// Returns an iterator to the first element > value

// ✔ Always returns strictly greater element
// ✔ Skips all occurrences of the value
// upper bound simply returns greater value than the value we are looking for