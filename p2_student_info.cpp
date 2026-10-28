#include <iostream>
#include <string>
using namespace std;

// Answer 1: We dont have exact match as there is no function that can handle
// two character values but if there is no exact match the compiler chooses promotion and here
// printInfo(string name, int rollNo) runs because char 'B'
// can be promoted to int giving its ASCII value 66.

// Answer 2: int printInfo(char grade) gives a compile error because
// functions cannot be overloaded by return type alone. It has the
// same parameter as void printInfo(char grade).

// Answer 3: These two versions differ only in parameter order:
// printInfo(string name, int rollNo)
// printInfo(int rollNo, string name)
void printInfo(string name) {
    cout << "Name: " << name << endl;
}
void printInfo(string name, int rollNo) {
    cout << "Name: " << name << " | Roll No: " << rollNo << endl;
}
void printInfo(int rollNo, string name) {
    cout << "Roll No: " << rollNo << " | Name: " << name << endl;
}
void printInfo(string name, double cgpa) {
    cout << "Name: " << name << " | CGPA: " << cgpa << endl;
}
void printInfo(char grade) {
    cout << "Grade: " << grade << endl;
}
int main() {
    printInfo("Ali");
    printInfo("Ali", 12);
    printInfo(12, "Ali");
    printInfo("Ali", 3.5);
    printInfo('A');
    printInfo("Sara", 'B');
    return 0;
}
