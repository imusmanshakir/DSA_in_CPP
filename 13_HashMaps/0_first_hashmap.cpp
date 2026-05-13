#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

    unordered_map<int, string> students;
    unordered_map<int, string> marks;

    students[101] = "Ali";
    students[102] = "Ahmed";
    students[103] = "Sara";
    marks[111] = "Physics";
    marks[112] = "math";
    marks[222] = "chemistry";

    // second hashmap
    unordered_map<string, int> result;
    result["Usman"] = 99;
    result["Sami"] = 97;
    result["Ehsan"] = 200;

    cout << students[102] << endl;
    cout << marks[222] << endl;
    cout << result["Usman"] << endl;
    cout << result.size()<< endl;

    return 0;
}