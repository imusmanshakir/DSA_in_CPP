/* In C++, a null character is a special character used to mark the end of a string
🔹 Definition
 The null character is written as : '\0'
 🔹 What does it mean?
It represents a character with ASCII value 0
It is not visible (you can’t print it like normal characters)
It tells the program: “string ends here”

🔹 Example*/

#include <iostream>
using namespace std;

int main()
{
    char str[] = "Hello";

    cout << str << endl;
    return 0;
}

// Internally, this is stored as
// 'H' 'e' 'l' 'l' 'o' '\0'