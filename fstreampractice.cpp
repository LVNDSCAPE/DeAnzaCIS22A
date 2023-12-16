#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //declare variables
    double avg;
    int sum = 0, count, num, i = 0;
    ifstream input;
    ofstream output;
    input.open("test.txt");
    output.open("testresults.txt");
    if(input.fail())
    {
        cout << "Please make an input file and test again.";
        exit(1);
    }
    
    input >> count;
    while(i < count)
    {
        input >> num;
        sum += num;
        i++;
    }
    input.close();
    avg = static_cast<double>(sum) / static_cast<double>(count);

    output << "Total sum: " << sum << endl;
    output << "Average  : " << avg << endl;
    output.close();


    

    
}