#include <iostream>
#include <iomanip>
using namespace std;
#define inctax 0.12

//Function Prototypes
void input(double& hour, double& worked);
double calc(double hours, double worked, double& tax, double& net);

int main(void)
{
 //Variable declaration
    double hourly; //hourly wage
    double hoursWorked; //number of hours worked
    double gross; //earnings before tax deducted
    double tax; // amount of income tax 12% of gross
    double net; //net earnings = gross - tax

 //Call getData to input hourly wage and hours worked
    input(hourly, hoursWorked);
 
 //Call calc() to compute gross earnings, income tax and net earnings
    gross = calc(hourly, hoursWorked, tax, net);
    cout << setprecision(2) << fixed;
    cout << "GROSS EARNINGS: $" << setw(11) << gross << endl;
    cout << "INCOME TAX: $" << setw(11) << tax << endl;
    cout << "NET EARNINGS: $" << setw(11) << net << endl;
    return 0;
}

//Define functions
void input(double& hour, double& worked)
{
    //pre     : hour - wage per hour , worked - hoursworked
    //post    : none
    //purpose : ask for input
    cout << "Enter hourly pay: ";
    cin  >> hour;
    cout << "Enter hours worked: ";
    cin  >> worked;
}

double calc(double hours, double worked, double& tax, double& net)
{
    //pre     : hour - wage per hour , worked - hoursworked, tax - 12 % of gross, net - net earnings
    //post    : gross earning
    //purpose : calculate gross earnings
    double gross;
    if(worked > 40)
    {
        gross = 40 * hours + 1.5 * hours * (worked - 40);
    }
    else
    {
        gross = hours * worked;
    }
    tax   = gross * inctax;
    net   = gross - tax;
    return gross;
}