/*
At a certain take-out pizza house the price of each soft drink is $1.49
and the price of a pizza is $10.99. Assume a tax rate of 9.25%.

Write a C++ program to input the number of pizzas ordered and the number
of soft drinks ordered prompting the user for each separately. Calculate
the bill subtotal, amount of tax, and the total. If the bill subtotal is greater than $100.00
give the customer a 9% discount (before tax).

Input, calculations, and output must be done in three separate functions
different from main. Use a global preprocessor statement to set the tax rate.
*/
#include <iostream>
#include <iomanip>

#define TAX_RATE 9.25
#define PIZZA 10.99
#define DRINK 1.49

using namespace std;

void getInput(int& ,int&);
double calBill(int, int, double&, double&);
void output(double , double, double);

int main()
{
    int nPizza, nDrink;
    double subtotal, total, tax;
    getInput(nPizza, nDrink);                           //function call numPizza and Drinks

    total = calBill(nPizza, nDrink, subtotal, tax);     //function call for calculation
    output(subtotal, tax, total);                      //function call for output

}

void getInput(int& nPizza,int& nDrink)
{
    /*pre: number of pizzas and drinks (reference value to nPizz and nDrink)
      post: 
      purpose: get input
    */
    cout << "How many pizzas?" << endl;
    cin  >> nPizza;
    cout << "How many drinks?" << endl;
    cin  >> nDrink;
}

double calBill(int nPizza, int nDrink, double& subtotal, double& tax)
{
    double total;
    subtotal = nPizza * PIZZA + nDrink * DRINK;

    if(subtotal > 100)
    {
        subtotal = subtotal * 0.9;
    }
    tax = subtotal * TAX_RATE / 100.0 ;

    total = subtotal + tax;
    return total;
}

void output(double subtotal, double tax, double total)
{
    cout << fixed << setprecision(2);
    cout << "Subtotal    :" << setw(10) << subtotal << endl;
    cout << "Tax         :" << setw(10) << tax << endl;
    cout << "Total       :" << setw(10) << total << endl;
}