/* Name - Thaw Zin Phyo
   Email - jack748lim@gmail.com
   Lab 5
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
#define YEARLY_TAX_RATE 0.0125                //TAX RATE FOR PROPERTY
#define YEARLY_INSURANCE 3250
#define EXPENSE_RATIO 0.31
#define DOWNPAYMENT 0.20

void getInput(double&, double&, double&);
void calcDownLoanMortgage(double, double, double, double&, double&, double&);
void mortgageCalc(double ,double ,double , double& , double& , double& , double& tax, double& costs,double& insurance, double& income);
void output(double, double, double, double, double, double, double, double, double, double);
void signature();

int main()
{
    double sellprice, rofinterest, numyears;       //var for getInput
    double down, loan, mortgage;                   //var for calcDownMortgage
    double propertytax, totalcosts, monthlyincome, insurance;
    getInput(sellprice, rofinterest, numyears);
    mortgageCalc(sellprice, rofinterest, numyears, down, loan, mortgage, propertytax, totalcosts, insurance, monthlyincome);
    //cout << sellprice << " " << rofinterest << " " << numyears << endl;                        //TEST
    //cout << down << " " << loan << " " << mortgage << endl;                                    //TEST
    //cout << propertytax << " " << totalcosts << " " << monthlyincome;                          //TEST
    output(sellprice, rofinterest, numyears, down, loan, mortgage, propertytax, totalcosts, insurance, monthlyincome);
    signature();
}

void getInput(double& sell, double& interest, double& years)
{
    //pre - sell:price of property(ref of sellprice)
    //      interest: annual interest rate (ref of rofinterest)
    //      years : num of years for loan(ref of numyears)
    //post - 
    //purpose - get input from user
    cout << "Enter selling price: ";
    cin  >> sell;
    cout << "Enter rate of interest: ";
    cin  >> interest;
    cout << "Enter number of years for loan: ";
    cin  >> years;
}

void calcDownLoanMortgage(double sell, double interest, double years, double& down, double& loan, double& mortgage)
{
    // pre     : sell: selling price of property(amount required to buy property)
    //           interest: interest rate
    //           years : num of years loan 
    //           down - downpayment, loan - loan amount, mortgage (passby ref to update var in main)
    // post    : none
    // purpose : calculate down payment, loan and monthly mortgage
    double i;
    int n;
    i = interest / 1200 ;
    n = years * 12;
    down = DOWNPAYMENT * sell;
    loan = sell - down;
    mortgage = ((loan * i * pow(1 + i, n)) /  (pow(1 + i, n) - 1) );

}

void mortgageCalc(double sell,double interest,double numyears, double& down, double& loan, double& mortgage, double& tax, double& costs,double& insurance, double& income)
{
    //pre: sell - price of proprerty, interest - rate of interest, numyears - loan years
    //     tax  - property tax(ref to propertytax), costs - total costs of house(ref to totacosts), income - monthly income(ref to monthlyincome), insurance (ref to insurance)
    //post: none
    //purpose: calculate property tax, total costs of house, minimum income;
    calcDownLoanMortgage(sell, interest, numyears, down, loan, mortgage);
    tax = (sell * YEARLY_TAX_RATE ) / 12 ; //monthly tax
    insurance = YEARLY_INSURANCE /12;      //monthly insurance
    costs = mortgage + tax + insurance;    // total cost of house per month
    income = costs / EXPENSE_RATIO;

}

void output(double sellprice, double interest, double years, double down, double loan, double mortgage,double tax, double totalcosts, double insurance, double monthlyincome)
{
    /*pre   : sellprice - price of property, interest - interest rate p year, years - num of years for loan, down - downpayment, mortgage - monthly mortgage,
              tax - monthly property tax, totalcosts - total costs per month(mortgage + insurance + property tax) , insurance - monthly insurance, monthlyincome - minimum income every month
    post    : none
    purpose :output the inputs and values used for calculation like loan,downpayment,mortgage etc.
    */
    cout << fixed << setprecision(2);
    cout << "MONTHLY COST OF HOUSE   " << endl;
    cout << "SELLING PRICE           " << setw(15) << sellprice << endl;
    cout << "DOWN PAYMENT            " << setw(15) << down << endl;
    cout << "AMOUNT OF LOAN          " << setw(15) << loan << endl;
    cout << "INTEREST RATE           " << setw(14) << interest << "%" << endl;
    cout << "TAX RATE                " << setw(14) << YEARLY_TAX_RATE*100 << "%" << endl;
    cout << "DURATION OF LOAN (YEARS)" << setw(15) << years << endl;
    cout << endl;
    cout << "MONTHLY PAYMENT         " << endl;
    cout << "MORTGAGE                " << setw(15) << mortgage << endl;
    cout << "PROPERTY TAXES          " << setw(15) << tax << endl;                     
    cout << "INSURANCE               " << setw(15) << insurance << endl;               
    cout << endl;
    cout << setw(39) << "--------"<< endl;
    cout << "                        " << setw(6) << "$" << setw(9) << right << totalcosts << endl;
    //cout << setw(30) << "$" << setw(12) << right << totalcosts << endl;
    //cout << endl;
    cout << "MINIMUM MONTHLY INCOME  " << setw(6) << "$" << setw(9) << right << monthlyincome << endl;
}

void signature()
{
    cout << "Name: Thaw Zin Phyo" << endl;
    cout << "Email: jack748lim@gmail.com" << endl;
    cout << "Lab 5 - Mortgage Payment" << endl;
}

/*
Enter selling price: 700000
Enter rate of interest: 2.75
Enter number of years for loan: 30
MONTHLY COST OF HOUSE
SELLING PRICE                 700000.00
DOWN PAYMENT                  140000.00
AMOUNT OF LOAN                560000.00
INTEREST RATE                     2.75%
TAX RATE                          1.25%
DURATION OF LOAN (YEARS)          30.00

MONTHLY PAYMENT
MORTGAGE                        2286.15
PROPERTY TAXES                   729.17
INSURANCE                        270.00

                               --------
                             $  3285.32
MINIMUM MONTHLY INCOME       $ 10597.80
Name: Thaw Zin Phyo
Email: jack748lim@gmail.com
Lab 5 - Mortgage Payment
*/

/*
Enter selling price: 700000
Enter rate of interest: 7.75
Enter number of years for loan: 30
MONTHLY COST OF HOUSE
SELLING PRICE                 700000.00
DOWN PAYMENT                  140000.00
AMOUNT OF LOAN                560000.00
INTEREST RATE                     7.75%
TAX RATE                          1.25%
DURATION OF LOAN (YEARS)          30.00

MONTHLY PAYMENT
MORTGAGE                        4011.91
PROPERTY TAXES                   729.17
INSURANCE                        270.00

                               --------
                             $  5011.08
MINIMUM MONTHLY INCOME       $ 16164.76
Name: Thaw Zin Phyo
Email: jack748lim@gmail.com
Lab 5 - Mortgage Payment
*/

