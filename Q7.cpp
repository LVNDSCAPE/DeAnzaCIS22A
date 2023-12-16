#include <iostream>

using namespace std;

int main()
{
    int year;
    double pop;

    cout << "Enter year: ";
    cin >> year;

    pop = 0.06 * (year % 1000) + 37.4;

    cout << pop << " thousand";
}