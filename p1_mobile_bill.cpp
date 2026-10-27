// Answer 1: We must write 0 for SMS because we cant just leave the middle value in arguements like mobileBill(60, , 1.5) 
// as it gives error so we have to provide the value for sms
//Answer 2: mobileBill(60, , 1.5) gives a compilation error because
//an argument is missing between the commas. C++ does not
//allow this.
#include <iostream>
using namespace std;

double mobileBill(int minutes, int sms = 0, double data = 0.0);  // (a)
void printLine(char ch = '-', int n = 30);                       // (b)

int main() {
    printLine();
    cout << "Bill 1: " << mobileBill(100) << endl;
    cout << "Bill 2: " << mobileBill(100, 50) << endl;
    cout << "Bill 3: " << mobileBill(100, 50, 2.5) << endl;
    printLine('*', 10);
    cout << "Bill 4: " << mobileBill(60, 0, 1.5) << endl;        // (c)
    printLine('=');
    return 0;
}

double mobileBill(int minutes, int sms, double data) {           // (d)
    return minutes * 2 + sms * 1 + data * 150;                   // (e)
}

void printLine(char ch, int n) {                                 // (f)
    for (int i = 0; i < n; i++) cout << ch;                      // (g)
    cout << endl;
}
