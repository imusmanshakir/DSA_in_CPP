#include <iostream>
using namespace std;

int main()
{
    char arr[6] = {'a', 'b', 'c', 'd', 'e', '\0'}; // null terminator needed
    char *ptr = &arr[0];

    cout << "Element at first index *arr: " << *arr << " --> can be written alternatively arr[0]: " << arr[0] << endl;
    cout << "Add 1 to ASCII value *arr+1: " << (char)(*arr + 1) << " (ASCII of 'a' is 97, +1 = 98 = 'b')" << endl;
    cout << "Move pointer address by 1 *(arr+1): " << *(arr + 1) << endl;
    cout << "Add 1 to first index *(arr)+1: " << (char)(*(arr) + 1) << endl;
    cout << endl;

    // ⚠️ char* is special — cout prints CONTENT not address
    // must cast to void* to see actual addresses
    cout << "&arr[0]--> " << (void *)&arr[0] << "  (cast needed or cout prints string)" << endl;
    cout << "&arr-----> " << &arr << "  ← no cast: prints 'abcde' (cout char* overload)" << endl;
    cout << "arr------> " << (void *)arr << "  (cast to see address)" << endl;
    cout << endl;

    // Playing with ptr now
    cout << "Address of pointer block or pointer itself---------> " << (void *)&ptr << endl; // &ptr = address of the pointer variable itself
    cout << "Address of entire array &arr (same value, type int(*)[6])-> " << &arr << endl;  // prints "abcde" because char* overload kicks in

    return 0;
}

/*Caution⚠️
1. These rules apply to ALL arrays, int, char, double

2. char arrays follow SAME pointer arithmetic rules as int arrays
   BUT cout has a special overload for char*:
       int*  → prints address
       char* → prints content (treats it as a C-string)
   To print address of a char array: cast to (void*)

3. Always null-terminate char arrays '\0'
   otherwise cout will keep reading memory until it finds one (undefined behavior)

4. *arr + 1 on char = ASCII arithmetic
   'a' + 1 = 'b'  (ASCII 97 + 1 = 98)
   cast back to (char) to display as character, not integer
*/