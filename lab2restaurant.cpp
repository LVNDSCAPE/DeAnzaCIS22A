//Restaurant Problem
/*Sales tax rate set at 8.75%
  Tip rate set with global preprocessor directive at 20%
  
  User enters amount of bill
  Compute tax, tip (memory constant), and total
  Output amount of bill, tax, tip, and total in tabular format

*/
#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>

using namespace std;

//Set Tax Rate
#define TAX_RATE 0.0875;

int main()
{
    //Declare variables
    string waiterName;
    const double tipRate = 0.20;
    double tip, tax, bill, total;

    //Input amount of bill
    cout << "Enter waiter's name: ";
    getline(cin, waiterName);
    cout << "Enter amount of bill: ";
    cin  >> bill;

    //Compute tax, bill, total
    tax = bill * TAX_RATE;
    tip = (bill + tax) * tipRate;
    total = tax + tip;

    //Output the total amount
    cout << fixed << setprecision(2);
    cout << "Amount of bill: " << right << setw(9) << bill << "\n";
    cout << "Amount of tax: " << right << setw(10) << tax << "\n";
    cout << "Amount of tip: " << right << setw(10) << tip << "\n";
    cout << "Bill total: " << right << setw(13) << total << "\n";
}