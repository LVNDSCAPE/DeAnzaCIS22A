#include <iostream>
#include <iomanip>
using namespace std;
// Function Prototype
double calcTotal(double, int);

int main(void)
{
  int people; double hours, total;
  //Input number of pairs and length of rental in hours
  cout << "Enter number of pairs needed: ";
  cin >> people;
  cout << "Enter number of hours: ";
  cin >> hours;

  //Calculate the total cost of the rental
  total = calcTotal(hours, people);
  //Output total cost of food
  cout << setprecision(2) << fixed;
  cout << "Bill Total: $ " << total << endl;

return 0;
}//main

double calcTotal(double hours,int people)
{
    //pre  : hours = number of hours rented, people = number of pairs needed
    //post : cost of rental for rollerskates
    //purpose: compute total cost of rental
    double total;
    double const rent = 3.75;
    total = hours * people * rent;
    if(people > 2)
    {
        double discount;
        discount = total * 0.2;
        total = total - discount;
    }
 return total;
}