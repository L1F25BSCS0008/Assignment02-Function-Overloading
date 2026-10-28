#include <iostream>
#include <fstream>
using namespace std;
double fare(double km, double ratePerKm = 40.0);
double fare(double km, double ratePerKm, bool peakHour);
double fare(double km, char vehicle);
double fare(double km, char vehicle, int promoPercent);
int main() {
    cout << "fare(10) = " << fare(10) << endl;
    cout << "fare(10, 30.0) = " << fare(10, 30.0) << endl;
    cout << "fare(10, 30.0, true) = " << fare(10, 30.0, true) << endl;
    cout << "fare(8, 'B') = " << fare(8, 'B') << endl;
    cout << "fare(8, 'C') = " << fare(8, 'C') << endl;
    cout << "fare(8, 'C', 10) = " << fare(8, 'C', 10) << endl;
    // ---- Part B: write your code below this line ----
    int n;
    cout << "How many rides? ";
    cin >> n;
    ofstream file("C:\\Users\\HP\\Downloads\\rides.txt");
    if (!file) {
        cout << "File rides.txt not found" << endl;
        return 1;
    }
    double total = 0;
    for (int i = 1; i <= n; i++) {
        char vehicle;
        double km;
        int promo;
        cout << "Ride " << i << " vehicle (B/R/C), km, promo %: ";
        cin >> vehicle >> km >> promo;
        double amount;
        if (promo == 0) {
            amount = fare(km, vehicle);
        }
        else {
            amount = fare(km, vehicle, promo);
        }
        file << "Ride " << i << " (" << vehicle << "), " << km << " km -> Rs. " << amount << endl;
        total += amount;
    }

    file << "Total collected: Rs. " << total << endl;
    file.close();
    cout << "Receipts saved to rides.txt" << endl;
    // ---- Part C: Explain an ambiguous call ----

    /* fare(10, 40);*/

    // Error= 'fare': ambiguous call to overloaded function
   //*reason = fare(double, double) : 10 converts from int to double, and 40 also converts from int to double.
   // fare(double, char) : 10 converts from int to double, and 40 converts from int to char Both calls require 
   // conversions so compiler cant decide. Therefore, the call is ambiguous.

    // Fix 1: we can use:
    // fare(10, 40.0);
    // Fix 2: we can use:
    // fare(10, 40, false);
    //This selects fare(double, double, bool)

    return 0;
}
double fare(double km, double ratePerKm) {
    return 100 + km * ratePerKm;
}
double fare(double km, double ratePerKm, bool peakHour) {
    double amount = fare(km, ratePerKm);
    if (peakHour) {
        amount = amount * 1.20;
    }
    return amount;
}
double fare(double km, char vehicle) {
    if (vehicle == 'B') {
        return fare(km, 25.0);
    }
    else if (vehicle == 'R') {
        return fare(km, 35.0);
    }
    else if (vehicle == 'C') {
        return fare(km, 50.0);
    }
    return 0;
}
double fare(double km, char vehicle, int promoPercent) {
    double amount = fare(km, vehicle);
    return amount - (amount * promoPercent / 100.0);
}
