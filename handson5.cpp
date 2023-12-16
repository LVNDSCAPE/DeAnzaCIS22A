#include <iostream>

using namespace std;

int main()
{
    int start;
    int end;
    cout << "Enter a starting integer: ";
    cin  >> start;
    cout << "Enter an ending integer: ";
    cin  >> end;
    int p = 0;          //count prime

    for(int i = start; i <=  end; i++)
    {
        int d = 0;      //count divisors
        for(int j = 1; j < i+1; j++)
        {
            if (i % j == 0)
            {
                d++;
            }
        }


        if(d == 2)
        {
            p++;
        }
    }
    
    cout << "There are " << p << " prime numbers in the given range." << endl;
    cout << "Thaw Zin Phyo";

}