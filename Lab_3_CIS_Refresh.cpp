/*  Thaw Zin Phyo
    jack748lim@gmail.com
    Lab-3
*/

#include <iostream>
#include <iomanip>

#define TAX 0.0913
using namespace std;

int main()
{
    int numTable, numPc, numiMac, numOwl, numhqOwl;
    //declaration for calculated amount
    double priceTable, pricePc, priceiMac, priceOwl, pricehqOwl;    
    double subtotal, tax, total;
    //memory constant declaration for unit price
    const double table = 429.88;
    const double pc    = 1001;
    const double imac  = 1299;
    const double owl   = 1049;
    const double hqowl = 1817.93;

    //user input for quantities of each item
    cout << "How many 24 x72 inch tablets ordered? ";
    cin  >> numTable;
    cout << "How many Dell All-in-One Thin Clients ordered? ";
    cin  >> numPc;
    cout << "How many Apple iMac computers? ";
    cin  >> numiMac;
    cout << "How many Meeting Owl 3 ordered? ";
    cin  >> numOwl;
    cout << "How many Meeting Owl HQ devices ordered? ";
    cin  >> numhqOwl;

    //Calculation for subtotal and total price
    priceTable = numTable * table;
    pricePc    = numPc    * pc;
    priceiMac  = numiMac  * imac;
    priceOwl   = numOwl   * owl;
    pricehqOwl = numhqOwl * hqowl;
    subtotal   = priceTable + pricePc + priceiMac + priceOwl + pricehqOwl;
    tax        = subtotal * TAX;
    total      = subtotal + tax;
    //to get fixed point notation
    cout << fixed << setprecision(2);
    //padding for numbers and items
    cout << right << setw(3) << "QTY   " << left << setw(30) << "Description" << right << setw(12) << "Unit Price" << right << setw(15) << "Total Price" << "\n";
    cout << right << setw(3) << numTable << "   " << left << setw(30) << "TABLES 24 X 72 INCH" << right << setw(12) << table << right << setw(15) << priceTable << "\n";
    cout << right << setw(3) << numPc << "   " << left << setw(30) << "DELL ALL-IN-ONE THIN CLIENTS" << right << setw(12) << pc << right << setw(15) << pricePc << "\n";
    cout << right << setw(3) << numiMac << "   " << left << setw(30) << "APPLE iMac 24-inch" << right << setw(12) << imac << right << setw(15) << priceiMac << "\n";
    cout << right << setw(3) << numOwl << "   " << left << setw(30) << "MEETING OWL 3" << right << setw(12) << owl << right << setw(15) << priceOwl << "\n";
    cout << right << setw(3) << numhqOwl << "   " << left << setw(30) << "MEETING OWL HQ" << right << setw(12) << hqowl << right << setw(15) << pricehqOwl << "\n";
    cout << right << setw(30) << "SUBTOTAL" << right << setw(18) << subtotal << "\n";
    cout << right << setw(30) << "TAX" << right << setw(18) << tax << "\n";
    cout << right << setw(30) << "TOTAL" << right << setw(18) << total << "\n";

    cout << "Thaw Zin Phyo" << "\n";
    cout << "Lab_3_CIS_REFRESH" << "\n";
    cout << "Date: 10/18/23" << "\n";
}