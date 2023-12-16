#include <iostream>

using namespace std;

int main()
{
    //variables for possible grades
    int possible, earned;
    double percentage;
    char grade;

    cout << "Enter points possible: ";
    cin  >> possible;
    cout << "Enter earned points: ";
    cin  >> earned;

    //compute percentage 
    percentage = static_cast<double>(earned) / possible * 100;
    cout << percentage << "%" << endl;
    int some = percentage / 10;
    if(some > 9)
    {
        some = 9;
    }
    switch (some)
    {
    case 9:
        grade = 'A';
        break;
    case 8:
        grade = 'B';
        break;
    case 7:
        grade = 'C';
        break;
    case 6:
        grade = 'D';
        break;
    default:
        grade = 'F';
    }
    
    cout << "Your grade is: " << grade;
}