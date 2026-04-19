#include <iostream>
using namespace std;

// ═══════════════════════════════════════════════════════════
// CASE 1: Pass by Value (NO pointer) — function gets a COPY
// ═══════════════════════════════════════════════════════════
void addTen_ByValue(int x)
{
    x = x + 10; // only modifies local copy
    cout << "  Inside addTen_ByValue: " << x << endl;
}

// ═══════════════════════════════════════════════════════════
// CASE 2: Pass by Pointer — function gets ADDRESS, can modify original
// ═══════════════════════════════════════════════════════════
void addTen_ByPointer(int *x)
{
    *x = *x + 10; // dereference to modify original
    cout << "  Inside addTen_ByPointer: " << *x << endl;
}

// ═══════════════════════════════════════════════════════════
// CASE 3: Pass by Reference — cleaner syntax, same effect as pointer
// ═══════════════════════════════════════════════════════════
void addTen_ByReference(int &x)
{
    x = x + 10; // no * needed, directly modifies original
    cout << "  Inside addTen_ByReference: " << x << endl;
}

// ═══════════════════════════════════════════════════════════
// CASE 4: Return a Pointer from a function
// ═══════════════════════════════════════════════════════════
int *getPointerToElement(int arr[], int index)
{
    return &arr[index]; // returns address of that element
}

// ═══════════════════════════════════════════════════════════
// CASE 5: Pass Array to function (array decays to pointer automatically)
// ═══════════════════════════════════════════════════════════
void printArray(int *arr, int size)
{ // int arr[] also works — same thing
    cout << "  Array elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ═══════════════════════════════════════════════════════════
// CASE 6: Swap using pointers (classic interview question)
// ═══════════════════════════════════════════════════════════
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ═══════════════════════════════════════════════════════════
// CASE 7: Pointer to Pointer (double pointer) as function param
// ═══════════════════════════════════════════════════════════
void changePointer(int **ptr, int *newTarget)
{
    *ptr = newTarget; // changes what the original pointer points to
}

// ═══════════════════════════════════════════════════════════
// CASE 8: const pointer param — protect data from modification
// ═══════════════════════════════════════════════════════════
void printValue(const int *x)
{
    cout << "  Value (read-only): " << *x << endl;
    // *x = 99;  ← compiler ERROR — cannot modify const
}

int main()
{
    cout << "\n======= CASE 1: Pass by Value =======" << endl;
    int num = 5;
    addTen_ByValue(num);
    cout << "  After function, num is still: " << num << endl; // 5 — unchanged

    cout << "\n======= CASE 2: Pass by Pointer =======" << endl;
    num = 5;
    addTen_ByPointer(&num);                                  // pass ADDRESS using &
    cout << "  After function, num is now: " << num << endl; // 15 — changed

    cout << "\n======= CASE 3: Pass by Reference =======" << endl;
    num = 5;
    addTen_ByReference(num);                                 // no & needed at call site
    cout << "  After function, num is now: " << num << endl; // 15 — changed

    cout << "\n======= CASE 4: Return Pointer =======" << endl;
    int arr[] = {10, 20, 30, 40, 50};
    int *p = getPointerToElement(arr, 2);
    cout << "  Pointer returned to index 2, value: " << *p << endl;         // 30
    *p = 99;                                                                // modify through returned pointer
    cout << "  arr[2] after modifying through pointer: " << arr[2] << endl; // 99

    cout << "\n======= CASE 5: Array to Function =======" << endl;
    printArray(arr, 5);

    cout << "\n======= CASE 6: Swap using Pointers =======" << endl;
    int a = 3, b = 7;
    cout << "  Before swap: a=" << a << " b=" << b << endl;
    swap(&a, &b);
    cout << "  After swap:  a=" << a << " b=" << b << endl;

    cout << "\n======= CASE 7: Pointer to Pointer =======" << endl;
    int x = 100, y = 200;
    int *ptr = &x;
    cout << "  ptr points to x: " << *ptr << endl; // 100
    changePointer(&ptr, &y);
    cout << "  ptr now points to y: " << *ptr << endl; // 200

    cout << "\n======= CASE 8: const Pointer Param =======" << endl;
    int val = 42;
    printValue(&val);

    return 0;
}

/*
╔══════════════════════════════════════════════════════════════╗
║           CASES TO REMEMBER — POINTERS + FUNCTIONS           ║
╠══════════════════════════════════════════════════════════════╣
║                                                              ║
║  CASE 1: Pass by Value      void f(int x)                   ║
║          → copy made, original SAFE, cannot modify          ║
║                                                              ║
║  CASE 2: Pass by Pointer    void f(int *x)                  ║
║          → pass &var, use *x inside, CAN modify original    ║
║                                                              ║
║  CASE 3: Pass by Reference  void f(int &x)                  ║
║          → cleaner than pointer, CAN modify original        ║
║          → no * or & needed at call site                    ║
║                                                              ║
║  CASE 4: Return Pointer     int* f()                        ║
║          → returns address, caller can modify through it    ║
║          ⚠️ NEVER return pointer to local variable!         ║
║             (local dies when function ends)                 ║
║                                                              ║
║  CASE 5: Array Parameter    void f(int *arr, int size)      ║
║          → array always decays to pointer automatically     ║
║          → int arr[] and int *arr are identical here        ║
║          → size must be passed separately                   ║
║                                                              ║
║  CASE 6: Swap Pattern       void swap(int *a, int *b)       ║
║          → classic use of pointers, must pass &a, &b        ║
║                                                              ║
║  CASE 7: Double Pointer     void f(int **ptr)               ║
║          → pointer to a pointer                             ║
║          → used to change what a pointer points to          ║
║                                                              ║
║  CASE 8: const Pointer      void f(const int *x)           ║
║          → can READ *x but cannot WRITE *x                  ║
║          → use when function should not modify data         ║
║                                                              ║
╠══════════════════════════════════════════════════════════════╣
║  GOLDEN RULE:                                                ║
║  Pass by value   → when you don't want changes              ║
║  Pass by pointer → when you NEED to modify original         ║
║  Pass by ref     → same as pointer but cleaner syntax       ║
╚══════════════════════════════════════════════════════════════╝
*/