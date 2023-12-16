#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    //Constants for minimum payment and interest rate
    const double minPayRate = 0.2, interestRate = 0.26/12;
    //Declare variables
    double balance, minPay, interest, amtPaid, balanceForward;
 
    //User input of balance and amount paid on credit card
    cout << "Enter current balance on card: ";
    cin  >> balance;
    cout << "Enter amount you paid of balance: ";
    cin  >> amtPaid;
 
    //Calculate minimum payment
    minPay = balance * minPayRate;
    //Calculate interest on remaining balance (assume balance >= amtPaid)
    interest = (balance - amtPaid) * interestRate;
    //Calculate new balance brought forward to next month
    balanceForward = balance - amtPaid + interest;
 
    //Output payment details
    cout << fixed << setprecision(2);
    cout << "Beginning Balance" << right << setw(38) << balance << endl;
    cout << "Minimum Payment" << right << setw(40)  << minPay << endl;
    cout << "Amount Paid"<< right << setw(44) << amtPaid << endl;
    cout << "Next month's interest on remaining balance" << right << setw(13) << interest << endl;
    cout << "Balance Forward"<< right << setw(40)  << balanceForward << endl;
 
 return 0;
}