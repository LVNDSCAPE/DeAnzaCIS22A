

#include <iostream>
using namespace std; 

int main(void)
{
         int a=5;
         int b=9;

         if (a < b)
           if(b < 0)
              a = b;
         else
           a = b + 10;
         cout << "a = "<<a<<"   b= " << b;
         if(a = 3)
            b = 18;
         if(a = 0)
           b = 25;
         cout << "  a = "<<a<<"   b= "<< b<<endl;

        return 0;
}


