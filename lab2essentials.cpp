#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
//Declare variables
double rentAmt = 1400,
foodAmt = 475,
utilitiesAmt = 275;
double income, expendable, total;

//Input income
cout << "Enter income for the month" << endl;
cin  >> income;

//Compute Expendable Income
total = rentAmt + foodAmt + utilitiesAmt;
expendable = income - total;

//Output Fun Money
cout << setprecision(2) << fixed;
cout << "Expense     $" << "Amount " << "       Percentage"<< endl;
cout << "                           of Income" << endl;
cout << "Rent        $" << setw(10) << rentAmt << setw(10) << rentAmt/income * 100 << " %" << endl;
cout << "Food        $" << setw(10) << foodAmt << setw(10) << foodAmt/income * 100 << " %" << endl;
cout << "Utilities   $" << setw(10) << utilitiesAmt << setw(10) << utilitiesAmt/income * 100 << " %" << endl;

cout<<"\n\nExpendable Income: $ " << expendable << endl; cout << endl;


system("pause");
return 0;
}
