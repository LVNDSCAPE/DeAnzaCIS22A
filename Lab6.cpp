#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
void output(ofstream& fileout, string coursenum, string classname, double fill);
double calcFillrate(int current, int max, int waitlist);

int main()
{
    ifstream filein;
    ofstream fileout;

    filein.open("Fall2023.txt");
    fileout.open("Fall2023output.txt");
    fileout<< "CRN"  << setw(15) << "Course" << setw(25) << "Fill Rate %" << endl;
    int count = 0, totalcurr = 0, totalmax = 0, totalwl = 0;
    //while(!filein.eof())
    while(count < 1) //test for 6 numbers
    {
        string course, classname;               //coursenumber, classname
        int curr, max, wl;                      //enrollment current, max and waitlist
        double fillrate = 0;
        filein >> course;
        //fileout << course;
        getline(filein, classname);
        filein >> curr;
        //fileout << curr;
        filein >> max;
        //fileout << max; 
        filein >> wl;
        fileout << wl;
        output(fileout, course, classname, calcFillrate(curr, max, wl));
        //totalcurr += curr;
        //totalmax  += max;
        //totalwl   += wl;
        count ++;
    }
    //fileout << totalcurr << " " << totalmax;
    //fileout << "Average fill rate: " << calcFillrate(totalcurr, totalmax, totalwl) << "%";

}

void output(ofstream& fileout, string coursenum, string classname, double fill)
{
    //pre    :coursenum - course, classname - name of class, fill - fill rate
    //post   :none
    //purpose:output the course, classname and fillrate
    fileout << fixed << setprecision(1);
    fileout << coursenum << setw(19) << classname << setw(18) << right << fill << endl;
}

double calcFillrate(int current, int max, int waitlist)
{
    //pre     : current - enrolled students, max - max students , waitlist - waitlisted students
    //post    : fill rate
    //purpose : compute fill rate
    double fill;
    if(max == 0)
    return fill = static_cast<double>((current + waitlist ) / max);
}
