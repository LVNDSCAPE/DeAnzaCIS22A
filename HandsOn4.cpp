/*  Name: Thaw Zin Phyo
    Student ID: 20552871
    Hands-On#4
*/

#include <iostream>
using namespace std;

#define UNIT_COST 270 //non-resident tuition fee (239 + 31)

double calcTution(double, double, double);                               //function protoype for computing fees
void output(double);                                                     //protoype for output (void for no return val)

int main()
{
    double units, studentfees, medinsurance;

    cout << "Enter number of units: ";
    cin  >> units;

    cout << "Enter the amount of student fees: ";
    cin  >> studentfees;

    cout << "Enter cost of medical insurance: ";
    cin  >> medinsurance;

    output(calcTution(units, studentfees, medinsurance));

    cout << "Name: Thaw Zin Phyo" << "\n";
    cout << "Hands On #4" << "\n";
    cout << "Student ID: 20552871";

}


double calcTution(double units, double studentFees, double medical)
{
    double total = units * UNIT_COST + studentFees + medical;
    return total;
}

void output(double total)
{
    cout << total << "\n";
}

/*  Enter number of units: 15 
    Enter the amount of student fees: 55.75
    Enter cost of medical insurance: 552
    4657.75
    Name: Thaw Zin Phyo
    Hands On #4
    Student ID: 20552871
*/