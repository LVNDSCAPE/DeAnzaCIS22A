/* Name - Thaw Zin Phyo
   Email - jack748lim@gmail.com
   Lab   - Lab 6
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
void output(ofstream& fileout, string coursenum, string classname, double fill);
double calcFill(int current, int max, int waitlist);

int main()
{
    ifstream filein;
    ofstream fileout;

    filein.open("Fall2023.txt");
    fileout.open("Fall2023output.txt");
    if(filein.fail())
    {
        cout << "No such file!" << endl;
        exit(100);
    }
    fileout<< "CRN"  << setw(15) << "Course" << setw(25) << "Fill Rate %" << endl;
    int count = 0, totalcurr = 0, totalmax = 0, totalwl = 0;
    double totalfr = 0.0;
    string lowestclass;
    double lowestfillrate = 100.0, currentfillrate = 0;     //initialize lowestfillrate to large numb
    while(!filein.eof())
    //while(count < 6) //test for 6 numbers
    {
        string course, classname;                           //coursenumber, classname
        int curr, max, wl;                                  //enrollment current, max and waitlist
        filein >> course;
        //fileout << course;                                //testing output to Fall2023output.txt
        getline(filein >> ws, classname);
        filein >> curr;
        //fileout << curr;
        filein >> max;
        //fileout << max; 
        filein >> wl;
        //fileout << wl;
        output(fileout, course, classname, calcFill(curr, max, wl));
        currentfillrate = calcFill(curr, max, wl);          //get fillrate for current class
        if(currentfillrate < lowestfillrate && currentfillrate > 0)                
        {
            lowestfillrate = currentfillrate;               //assign lowestfillrate with currentfillrate if currentfillrate is lower than lowest
            lowestclass    = classname;
        }
        totalfr   += currentfillrate;
        totalcurr += curr;
        totalmax  += max;
        totalwl   += wl;
        count ++;
    }
    //fileout << totalcurr + totalwl << " " << totalmax;                                             //check to see if curr + wl total is correct
    //fileout << "Average fill rate: " << calcFill(totalcurr, totalmax, totalwl) << "%" << endl;
    //fileout << "Lowest fill rate : " << lowestfillrate << "%"<< endl;
    fileout << "Name - Thaw Zin Phyo" << endl;
    fileout << "Email - jack748lim@gmail.com "<< endl;
    fileout << "Lab 6 "<< endl;
    cout    << fixed << setprecision(1);
    cout    << "Average fill rate           : " << calcFill(totalcurr, totalmax, totalwl) << "%" << endl;
    cout    << "Lowest fill rate            : " << lowestfillrate << "%" << endl;
    cout    << "Class with lowest fill rate : " << lowestclass << endl;
    cout    << "current " << totalcurr << endl;
    cout    << "max " << totalmax << endl;
    cout    << "wl " << totalwl << endl;


}

void output(ofstream& fileout, string coursenum, string classname, double fill)
{
    //pre    :coursenum - course, classname - name of class, fill - fill rate
    //post   :none
    //purpose:output the course, classname and fillrate
    if(fill == -1)
    {
        exit;
    }
    else
    {
        fileout << fixed << setprecision(1);
        fileout << coursenum << setw(19) << classname << setw(18) << right << fill << endl;
    }
}
double calcFill(int current, int max, int waitlist)
{
    //pre     :current - current students, max - max students, waitlist - waitlisted students
    //post    :fill rate
    //purpose :compute fill rate
    if(max == 0)
    {
        return -1;
    }
    else
    {
        return static_cast<double>(current + waitlist) * 100.0 / max;
    }
}

