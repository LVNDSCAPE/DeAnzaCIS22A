#include <iostream>
#include <iomanip>
using namespace std;

//Write Prototypes for getData()and computeCosts() here:
double getData(double& length, double& width, double& padPricePerSqYd);
double computeCosts(double length, double width, double carpetPricePerSqFt, double padPricePerSqYd, double& carpetCost, double& padCost);

int main() {
    // Variable declarations
    double length, width, carpetPricePerSqFt, padPricePerSqYd, totalCost, carpetCost, padCost;

    // Input measurements of room and unit costs for materials
    carpetPricePerSqFt = getData(length, width, padPricePerSqYd);

    // Calculation of area and costs
    totalCost = computeCosts(length, width, carpetPricePerSqFt, padPricePerSqYd, carpetCost, padCost );

    // Output cost of carpet, carpet pad, and total for the room
    cout << fixed << setprecision(2);
    cout << "Cost of Carpet:            $" << setw(10) << carpetCost << endl;
    cout << "Cost of Carpet Pad:        $" << setw(10) << padCost << endl;
    cout << "Total Cost (Carpet + Pad): $" << setw(10) << totalCost << endl;

    return 0;
}//Define functions below

double getData(double& length, double& width, double& padPricePerSqYd)
{
    double pricepersqft;
    cout << "Enter the length of the room in feet: ";
    cin  >> length;
    cout << "Enter the width of the room in feet: ";
    cin  >> width;
    cout << "Enter the price of carpet per square foot: $";
    cin  >> pricepersqft;
    cout << "Enter the price of carpet pad per square yard: $";
    cin  >> padPricePerSqYd;
    return pricepersqft;
}
double computeCosts(double length, double width, double carpetPricePerSqFt, double padPricePerSqYd, double& carpetCost, double& padCost)
{
    carpetCost = length * width * carpetPricePerSqFt;
    padCost    = static_cast<double>(length * width / 9) * padPricePerSqYd ;   // 1 yard == 9 sqfeet
    return carpetCost + padCost;
}