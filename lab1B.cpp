/*  Thaw Zin Phyo
    jack748lim@gmail.com
    Lab 1B - Paying in Coins
*/

#include <iostream>

using namespace std;

int main()
{
    //variables declaration
    float amountOwed;                                               
    int numQuarters, numDimes, numNickels, numPennies, totalCents;

    //prompts user input for amount owed
    cout << "Enter amount owed: ";                                  
    cin  >> amountOwed;                                                     

     
    totalCents = amountOwed * 100;

    //calculate number of quarters required                                     
    numQuarters = totalCents / 25;

    //using % operator to obtain remainder
    numDimes = (totalCents % 25) / 10;                              
    numNickels = (totalCents % 25) % 10 / 5;
    numPennies = (totalCents % 25) % 10 % 5;

    cout << numQuarters << " quarter(s)\n";                         
    cout << numDimes << " dimes(s)\n";
    cout << numNickels << " nickel(s)\n";
    cout << numPennies << " pennie(s)\n";
    cout << "Thaw Zin Phyo";

    return 0;
}

/*  Enter amount owed: 15.45
    61 quarter(s)
    2 dimes(s)
    0 nickel(s)
    0 pennie(s)
    Thaw Zin Phyo
*/