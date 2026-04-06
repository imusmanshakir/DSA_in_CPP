#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;

    minHeap.push(100);
    minHeap.push(200);
    minHeap.push(300);
    maxHeap.push(100);
    maxHeap.push(200);
    maxHeap.push(300);

    priority_queue<int, vector<int>, greater<int>> temp(minHeap);

    cout << "While Loop: ";
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    cout << "Min element: " << minHeap.top() << endl;

    minHeap.pop();

    cout << "After poping now Min element is: " << minHeap.top() << endl;
    cout << "Max element: " << maxHeap.top() << endl;

    maxHeap.pop();

    cout << "After poping now Max element is: " << maxHeap.top() << endl;

    return 0;
}