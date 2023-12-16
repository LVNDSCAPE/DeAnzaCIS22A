/*  Name: Thaw Zin Phyo
    Lab-4
    jack748lim@gmail.com
*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdlib.h>

using namespace std;

double calcFare(char car, char surge, double miles, int minutes, double surgeamount);
double calcPay(double, double);
void output(double);

int main()
{
    int timeinMins;
    double tip, surgemultiplier, distinMiles;
    char cartype, surge;
    cout << "Enter time in mintues: ";
    cin  >> timeinMins;
    cout << "Enter distance in miles: ";
    cin  >> distinMiles;
    cout << "Enter X for uberX, S for SUV or L for luxury car: ";
    cin  >> cartype;

    if(cartype == 'x' || cartype == 's' || cartype == 'l' || cartype == 'X' || cartype == 'S' || cartype == 'L')   //First if loop to decide type of car
    {
        cartype = toupper(cartype);
    }
    else
    {
        cout << "Program exited with error " << EXIT_FAILURE;
        exit(EXIT_FAILURE);
    }
    
    cout << "Enter Y if there is a surge or N if not: ";                                                            
    cin  >> surge;
    if(surge == 'y' || surge == 'Y')                      //Second if loop to decide if there's a surge or not
    {
        surge = toupper(surge);
        if(surge == 'Y')                                  //Asking for surge multiplier if there is a surge
        {
            cout << "Enter surge multiplier: ";
            cin  >> surgemultiplier;
        }
        else
        {
            cout << "Program exited with error " <<  EXIT_FAILURE;
            exit(EXIT_FAILURE);
        }
    }
    else if (surge == 'n' || surge == 'N')
    {
        surgemultiplier = 1;                             //setting surge to 1 to avoid redundant calculation in calcFare function
    }
    else
    {
        cout << "Program exited with error " <<  EXIT_FAILURE;
        exit(EXIT_FAILURE);
    }
    cout << "Enter the amount of tip: ";
    cin  >> tip;

    cout << "Fare:"<< setw(13) << "$";
    output(calcFare(cartype, surge, distinMiles, timeinMins, surgemultiplier));

    cout << "Driver Earnings: $";
    output(calcPay(tip, calcFare(cartype, surge, distinMiles, timeinMins, surgemultiplier)));
}



double calcFare(char car, char surge, double miles, int minutes, double surgeamount)
{   
    /*Pre : car - type of car
            surge - if there is a surge or not
            miles - distance in miles
            minutes - time in minutes
            surgeamount - how much surgeamount is
      Post: total cost of fare
      Purpose: compute fare d/p on cartype,distance,time and surge amount
    */
    double totalfare;
    if(car == 'X')
    {
        totalfare = 2.00 * surgeamount + 0.22 * minutes + 1.15 * miles;      //uberX fare calculation
        if(totalfare < 6.55)
        {
            totalfare = 6.55;
        }
    }
    else if(car == 'S')
    {
        totalfare = 15.00 * surgeamount + 0.90 * minutes + 3.75 * miles;    //SUV fare calculation
            if(totalfare < 25.00)
        {
            totalfare = 25.00;
        }
    }
    else if(car == 'L')
    {
        totalfare = 5.00 * surgeamount + 0.50 * minutes + 2.75 * miles;     //Luxury fare calculation
        if(totalfare < 10.55)
        {
            totalfare = 10.55;
        }
    }
    return totalfare;
}

double calcPay(double tip, double fare)
{   
    /* Pre: tip - amount of tip
            fare - total fare cost before uber cut
       Post:
       Purpose: calculate total earnings of driver
    */
    double earnings;
    const double tax = 0.153;                  //self-employment tax
    earnings = ((fare * 0.75) + tip) * tax;      //tax cut of remaining 75% added with tip
    earnings = ((fare * 0.75) + tip) - earnings; //total earnings 
    return earnings;
}



void output(double computedamount)
{
    /* Pre: amount of fare or earnings
       Post:
       Purpose:output comptued amount
    */
    cout << fixed << setprecision(2) << computedamount << "\n";
}

/*  Enter time in mintues: 70
    Enter distance in miles: 55
    Enter X for uberX, S for SUV or L for luxury car: X
    Enter Y if there is a surge or N if not: Y
    Enter surge multiplier: 1.9
    Enter the amount of tip: 3
    Fare:            $82.45
    Driver Earnings: $54.92
*/

/*  Enter time in mintues: 15
    Enter distance in miles: 16.8
    Enter X for uberX, S for SUV or L for luxury car: L
    Enter Y if there is a surge or N if not: N
    Enter the amount of tip: 0
    Fare:            $58.70
    Driver Earnings: $37.29
*/

/*  Enter time in mintues: 45
    Enter distance in miles: 13.8
    Enter X for uberX, S for SUV or L for luxury car: C
    Program exited with error 1
*/