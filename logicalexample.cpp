#include <iostream>

using namespace std;

int main()
{
    int a = 100;
    if(!(a > 99))
    {
        cout << "The value of a is less than " << 99 << "\n";
    }
    else
    {
        cout << "The value of a is greater than " << 99 << "\n";
    }
    return 0;
}