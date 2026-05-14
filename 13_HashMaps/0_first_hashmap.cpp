#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

    unordered_map<int, string> students;
    unordered_map<string, int> result;

    students[101] = "Ali";
    students[102] = "Ahmed";
    students[103] = "Sara";

    // second hashmap
    result["Usman"] = 77;
    result["Sami"] = 97;
    result["Ehsan"] = 200;
    students.insert({1, "Mohsin"});
    // printing
    cout << "Student on key 1-> " << students[1] << endl;
    cout << "Student on key 103-> " << students[103] << endl;
    cout << "Usman Marks are -> " << result["Usman"] << endl;
    cout << "Size of result is:" << result.size() << endl<<endl;

    // find
    auto find = result.find("usman");
    cout << "Searching for Usman's makrs: \n";
    if (find != result.end())
    {
        cout << "Found\n";
    }
    else
    {
        cout << "Not found\n";
    }

    return 0;
}