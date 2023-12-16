#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void outputfor(int, int);

int main()
{
    int first;
    int last;
    cout << "Enter starting integer: ";
    cin >> first;
    cout << "Enter ending integer: ";
    cin >> last;

    //function call
    outputfor(first, last);
    
}

void outputfor(int start, int end)
{
    /*  Pre     : start - starting integer , end - ending integer
        Post    : none
        Purpose : while loop to keep outputting values within a given range
    */
    for(int i = start; i < end + 1 ; i++)
    {
        cout << fixed << setprecision(5);
        cout << "The square root of " << i << " is " << sqrt(i) << endl;
    }



 
}