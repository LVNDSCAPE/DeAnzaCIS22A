/*
Name - Thaw Zin Phyo
Email - jack748lim@gmail.com
Lab - 7
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int getData(ifstream&,string crn[], string classname[], int curr[], int max[], int wl[], double fillrate[], int number);
void output(ofstream& outputfile, string crn[], string classname [], int curr[], int max[], int wl[], double fillrate[], int number);
double avgFill(double fillrate[], int number);
void promptUser(ofstream& outputfile, string crn[], string classname[], int curr[], int max[], int wl[], double fillrate[], int number);
int userSearch(string crn[], string classname[], double fillrate[], int number, string req_CRN);
void selectionsort(ofstream& outputfile, string crn[], string classname[], int curr[], int max[], int wl[], double fillrate[], int number);

int main()
{
    //variable declaration
    ifstream filein;
    ofstream fileout;
    int const size = 100;  //arraysize
    string crn[size], classname[size];
    int curr[size], max[size], wl[size];
    double fillrate[size];
    int num = 0;           //numofclassesoffered
    string user_CRN;
    int user_Search;                 //index location for user search

    //fstream
    filein.open("Fall2023.txt");
    fileout.open("Lab7.txt");
    if(filein.fail())
    {
        "No such file exists";
        exit(1);
    }
    num = getData(filein, crn, classname, curr, max, wl, fillrate, size); 

    //debug if total classes are correct
    //cout << num;
    //Debug for array output
    /*for(int i = 0; i < num; i++)
    {
        cout << crn[i] << " " << classname[i] << " " << curr[i] << " " << max[i] << " " << wl[i] << endl;
    }
    */

    output(fileout, crn, classname, curr, max, wl, fillrate, num);
    cout << "Average fill rate is: " << fixed << setprecision(1) << avgFill(fillrate, num) << endl;
    fileout << fixed << setprecision(1);
    promptUser(fileout, crn, classname, curr, max, wl, fillrate, num);
    //user-requested CRN
    cout << "Enter a class registration number: ";
    cin  >> user_CRN;
    user_Search = userSearch(crn, classname, fillrate, num, user_CRN);
    fileout << endl;
    if(user_Search != -1)
    {
        cout << "Name of class user searched for is " << classname[user_Search] << " and fill rate is " << fillrate[user_Search] << "%" << endl;
    }
    else
    {
        cout << "No such class with that class number!" << endl;
    }
    
    //call sort function(ascending order)
    selectionsort(fileout, crn, classname, curr, max, wl, fillrate, num);

    //debug for swap
    //cout << crn[0] << " " << classname[0] << " " << curr[0] << " "  << max[0] << " "  << wl[0] << " "  << fillrate[0] << endl;
    //cout << crn[1] << " " << classname[1] << " " << curr[1] << " "  << max[1] << " "  << wl[1] << " "  << fillrate[1] << endl;
    //cout << crn[2] << " " << classname[2] << " " << curr[2] << " "  << max[2] << " "  << wl[2] << " "  << fillrate[2] << endl;
    //cout << crn[3] << " " << classname[3] << " " << curr[3] << " "  << max[3] << " "  << wl[3] << " "  << fillrate[3] << endl;


    output(fileout, crn, classname, curr, max, wl, fillrate, num);

    fileout << "Name: Thaw Zin Phyo" << endl;
    fileout << "Email: jack748lim@gmail.com" << endl;
    fileout << "Lab 7" << endl;
}

int getData(ifstream& inputfile,string crn[], string classname[], int curr[], int max[], int wl[], double fillrate[], int number)
{
    /*  Pre    : inputfile - reference to inputfile
                 crn - array of course registration number
                 classname - array of class names
                 curr, max, wl - array of current students, max students, waitlisted students
                 fillrate - array of fill rates
                 number - size of array
        Post   : return number of classes
        Purpose: get input from file to store in arrays
    */
   int count = 0;
   while(!inputfile.eof() && count < number)
   {
        inputfile >> crn[count];
        getline(inputfile, classname[count]); 
        inputfile >> curr[count] >> max[count] >> wl[count];
        if(max[count] == 0)
        {
            fillrate[count] = -1;
        }
        else
        {
            fillrate[count] = static_cast<double>(curr[count] + wl[count])* 100.0/ max[count];
        }                     
        count++;
   }
   return count;
}

void output(ofstream& outputfile, string crn[], string classname[], int curr[], int max[], int wl[], double fillrate[], int number)
{
/*  Pre    :outputfile - reference to outputfile
            crn - array of course registration number
            classname - array of class names
            curr, max, wl - array of current students, max students, waitlisted students
            fillrate - array of fill rates
            number - size of array
    Post   :nothing
    Purpose:output to file
*/
    int i = 0;  //counter
    outputfile << "CRN" << setw(15) << "Course" << setw (16) << "Current" << setw (12) << "Max" << setw(18) << "Number on" <<  setw(18) << "Fill Rate %" << endl;
    outputfile << setw(36) << "Enrollment" << setw(14) << "Enrollment" << setw(14) << "waitlist" << endl;
    while(i < number)
    {
        if(max[i] > 0)
        {
            outputfile << fixed << setprecision(1);
            outputfile << crn[i] << setw(18) << classname[i] << setw(9) << curr[i] << setw(13)  << max[i] << setw(15) << wl[i] << setw(18) << fillrate[i] << "%" << endl;
        }
        else
        {
            fillrate[i] = -1;
            outputfile << fixed << setprecision(1);
            outputfile << crn[i] << setw(18) << classname[i] << setw(9) << curr[i] << setw(13)  << max[i] << setw(15) << wl[i] << setw(18) << fillrate[i] << endl;
        }
        i++;
    }
}

double avgFill(double fillrate[], int number)
{
/*  Pre    :fillrate - an array of fill rates
            number - size of array
    Post   :return average fill rate
    Purpose:compute average fill rate
*/
    double total = 0.0;
    int count   = 0; // counter for loop
    int frcount = 0; // counter for fill rates > 0
    int badfr   = 0; // counter for fill rate == -1
    while(count < number)
    {
        if(fillrate[count] == -1)
        {
            badfr++;
        }
        else
        {
            //fillrate[count] = static_cast<double>(curr[count] + wl[count])* 100.0/ max[count];
            total += fillrate[count];
            frcount++;
        }
        count++;
    }
    return total / frcount;
}

void promptUser(ofstream& outputfile, string crn[], string classname[], int curr[], int max[], int wl[], double fillrate[], int number)
{
/*  Pre    :outputfile - reference to outputfile
            crn - array of course registration number
            classname - array of class names
            curr, max, wl - array of current students, max students, waitlisted students
            fillrate - array of fill rates
            number - size of array
    Post   :nothing
    Purpose:output classes with fillrate lower than user input to the file 
*/
    double minimum;
    cout << "Enter lowest acceptable fillrate: ";
    cin  >> minimum;
    bool classfound = false;
    outputfile << endl;
    //outputfile << "Class with fillrate lower than user minimum are below."    << endl;
    //outputfile << "CRN"  << setw(15) << "Course" << setw(25) << "Fill Rate %" << endl;
    for(int i = 0; i < number; i++)
    {
        if(fillrate[i] < minimum && fillrate[i] > 0)
        {
            outputfile << crn[i] << setw(18) << classname[i] << setw(18) << right << fillrate[i] << "%" << endl;
            classfound = true;
        }
    }
    if(!classfound)
    {
        cout << "No classes with fill rate below " << minimum << "%" << endl;
    }
}

int userSearch(string crn[], string classname[], double fillrate[], int number, string req_CRN)
{
/*  Pre    :crn - array of course registration number
            classname - array of class names
            fillrate - array of fill rates
            number - size of array
            req_CRN - class registration number user is looking for
    Post   :return index position of user requested class
    Purpose:find index of user requested class
*/
    int i;
    bool classfound = false;
    for(i = 0; i < number; i++)
    {
        if(crn[i] == req_CRN)
        {
            classfound = true;
            return i;
        }
    }
    if(!classfound)
    {
        return -1;
    }
}

void selectionsort(ofstream& outputfile, string crn[], string classname[], int curr[], int max[], int wl[], double fillrate[], int number)
{
/*  Pre    :outputfile - reference to outputfile
            crn - array of course registration number
            classname - array of class names
            curr, max, wl - array of current students, max students, waitlisted students
            fillrate - array of fill rates
            number - size of array
    Post   :nothing
    Purpose:sort classes in ascending order of fill rate
*/
    int temp;
    double dbtemp;
    string stemp;     //to hold swap value
    for(int i = 0; i < (number - 1) ; i++)
    {
        int minimum_pos = i;
        for(int j = i + 1; j < number ; j++)
        {
            if(fillrate[j] < fillrate[minimum_pos])
            {
                minimum_pos = j;
            }
        }

        stemp                  = crn[i];
        crn[i]                 = crn[minimum_pos];
        crn[minimum_pos]       = stemp;

        stemp                  = classname[i];
        classname[i]           = classname[minimum_pos];
        classname[minimum_pos] = stemp;

        temp                   = curr[i];
        curr[i]                = curr[minimum_pos];
        curr[minimum_pos]      = temp;

        temp                   = max[i];
        max[i]                 = max[minimum_pos];
        max[minimum_pos]       = temp;

        temp                   = wl[i];
        wl[i]                  = wl[minimum_pos];
        wl[minimum_pos]        = temp;

        dbtemp                 = fillrate[i];
        fillrate[i]            = fillrate[minimum_pos];
        fillrate[minimum_pos]  = dbtemp;
    }
}