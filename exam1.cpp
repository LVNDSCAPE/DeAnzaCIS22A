#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double x = 999998;
    double y = 99929;
cout << setprecision(3) << x << "\n" << y << endl;
cout << setprecision(3) << fixed << setw(10) << x << "\n" << y << endl;
cout << setprecision(3) << fixed << setw(10) << x << "\n" << setw(10) << y << endl;
cout << setprecision(3) << fixed << x << setw(5) << endl << y << setw(5) << endl;

}





/*What is the output if 4 is entered for age?

#include <iostream>
using namespace std;
int main()
{
int age;
float admission;

cout << "Enter the age " << endl;
cin >> age;
if (age < 7)
  age = 0;
if (age >= 65)
  age = 60;
switch (age)
{
case 0: admission = 0; break;
case 60: admission = 15;
default: admission = 40;
}

cout << admission << endl;

return 0;
}*/
