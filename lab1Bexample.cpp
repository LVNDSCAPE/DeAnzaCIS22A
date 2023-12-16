/*  Thaw Zin Phyo
    Conversion from miles to kilometers
    1 mile = 1.60934 kilometers
*/

#include <iostream>

using namespace std;

int main()
{   
    //Declare variables
    double miles, km;


    //Input number of miles
    cout << "Enter the number of miles: ";
    cin >> miles;

    //Convert miles to kilometers
    km = miles * 1.60934;

    //Output distance in kilometers
    cout << "Distance in kilometers: " << km << " kilometers\n";

    //Signature
    cout << "Programmed by Thaw Zin Phyo";

    return 0;
}