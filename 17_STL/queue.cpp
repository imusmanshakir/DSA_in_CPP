#include <iostream>
#include <queue>
using namespace std;

// Function to print queue (by value so original remains unchanged)
void printQueue(queue<int> q)
{
    cout << "Queue elements (front to back): ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// Function to find maximum element
int findMax(queue<int> q)
{
    int mx = q.front();
    while (!q.empty())
    {
        if (q.front() > mx)
        {
            mx = q.front();
        }
        q.pop();
    }
    return mx;
}

int main()
{
    // 1. Create queue
    queue<int> q;

    // 2. Push elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(5);

    cout << "Original Queue:" << endl;
    printQueue(q);

    // 3. Front and Back
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // 4. Pop element
    q.pop();
    cout << "After pop, front: " << q.front() << endl;

    // 5. Size
    cout << "Size: " << q.size() << endl;

    // 6. Copy queue
    queue<int> q2 = q;
    cout << "\nCopied Queue:" << endl;
    printQueue(q2);

    // 7. Find maximum
    cout << "Maximum element: " << findMax(q) << endl;

   

    return 0;
}