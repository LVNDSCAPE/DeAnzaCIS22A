#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double const retain = 0.87;
    int cups;
    double caffeine;
    cout << "Enter number of cups : ";
    cin  >> cups;
    cout << "Caffeine consumed(mg): ";
    cin  >> caffeine;
    cout << "After Hour        "  << "mg Caffeine" << endl;
    cout << fixed << setprecision(1);
    for(int i = 1; i < 25; i++)
    {
        caffeine *= retain;
        cout << setw(3) << left << i << setw(20) << right << caffeine << endl;
    }
    
}