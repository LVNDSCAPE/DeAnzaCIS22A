/*  Thaw Zin Phyo
    Lab 2 - Swag for De Anza
    Calculating costs for items given on Spring Open House
*/

#include <iostream>
#include <string>
#include <iomanip>

#define TAX_RATE 0.0913

using namespace std;

int main()
{   
    //Constant declaration for item prices
    //usb drive 1156.25$ for a package of 125 drives
    const double pen_cost = 65.50, shirt_cost = 192.50, usbdrive_cost = 1156.25;
    //variable declaration for items
    double pens_total, shirts_total, usbdrives_total, subtotal, tax, total;
    string month_year;
    int numPeople, packagepen, packageshirt, packageusb;

    cout << "Enter the month and the year: ";
    getline(cin, month_year);
    cout << "Enter the number of attendees: ";
    cin  >> numPeople;

    //no: of package required for each item 
    packagepen = (numPeople + 50 - 1) / 50;
    packageshirt = (numPeople + 25 - 1) / 25;
    packageusb = (numPeople + 125 - 1) / 125;

    //total cost of each item
    pens_total = packagepen * pen_cost;
    shirts_total = packageshirt * shirt_cost;
    usbdrives_total = packageusb * usbdrive_cost;
    subtotal = pens_total + shirts_total + usbdrives_total;

    tax = subtotal * TAX_RATE;
    total = subtotal + tax;
    
    cout << fixed << setprecision(2);
    cout << "Month: " << month_year << "\n";
    cout << "ITEM           " << setw(10) << "#PACKAGES     " << setw(15) << "UNITCOST     " << setw(5) << "SUBTOTAL" << "\n";
    cout << "Pens           " << setw(6) << packagepen << setw(15) << pen_cost << setw(15) << pens_total << "\n";
    cout << "Shirts         " << setw(6) << packageshirt << setw(15) << shirt_cost << setw(15) << shirts_total << "\n";
    cout << "USB Drives     " << setw(6) << packageusb << setw(15) << usbdrive_cost << setw(15) << usbdrives_total << "\n";
    cout << "Subtotal       " << setw(15) << subtotal << "\n";
    cout << "Tax            " << setw(15) << tax << "\n";
    cout << "Total          " << setw(15) << total << "\n";

    cout << "Programmed by Thaw Zin Phyo";
}


/*
Month: January 1980
ITEM           #PACKAGES       UNITCOST     SUBTOTAL
Pens              184          65.50       12052.00
Shirts            368         192.50       70840.00
USB Drives         74        1156.25       85562.50
Subtotal             168454.50
Tax                   15379.90
Total                183834.40
Programmed by Thaw Zin Phyo
*/