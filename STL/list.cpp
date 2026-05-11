#include <iostream>
#include <list>
using namespace std;

int main() {
    // Create a list of integers
    list<int> myList;

    // Add elements
    myList.push_back(10);   // add at end
    myList.push_back(20);
    myList.push_front(5);   // add at beginning

    // Display elements
    cout << "List elements: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;

    // Remove elements
    myList.pop_front();  // removes first element
    myList.pop_back();   // removes last element

    // Display again
    cout << "After removing: ";
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}