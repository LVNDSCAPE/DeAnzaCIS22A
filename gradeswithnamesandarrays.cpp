//Averaging Grades with Deviations- Starting point
/*Write a program to input the name, a pin number, and score for each student until the end of file 
is reached. 
(assume maximum of 45). Compute and output the average score. Then output the name, pin number, 
score, and deviation from the average for each student.

· Alter this program so that all input by writing separate functions for input of data.

· Add to this program a function to compute the highest score. (Output this value from main()).

· Add to this program a function to compute the lowest score. (Output this value from main()).*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define MAX 45

using namespace std;
//Prototypes
int findHighest(double [], int);
int getData(ifstream& inFile, string name[], int pin[], double score[]);

int main()
{
    //Declare variables
    int pin[MAX]; double score[MAX]; double avg; 
    string name[MAX]; 
    double sum = 0.0; int count = 0; int index;
    ifstream inFile;

    //Open file 
    inFile.open("gradesWithNames.txt");
    if(inFile.fail())
    {
    cout << "No Such File" << endl;
    exit(100);
    }

    //Input each number and add it into the sum
    count = getData(inFile, name, pin, score);

    //Calculate average
    sum = 0;//accumulator
    for(int i = 0; i < count; i++)
    sum = sum + score[i];

    avg = sum/static_cast<double>(count);

    //Output the average
    cout << "Average: " << avg << endl;
    for(int i = 0; i < count; i++)
    cout << name[i] <<" " << pin[i] << " " << score[i] << " " << score[i] - avg << endl;

    //Find highest score
    index = findHighest(score, count);
    cout << "Highest score: " << score[index] << endl;
    cout << "Student with highest score: " << name[index] << endl;

    system("pause");
    return 0;
}//main
////////////////
int findHighest(double sc[], int num)
{
/*
Pre: sc[] - array of scores
num - number of values in the array
Post: subscript of highest value (assume no ties)
Purpose: Find highest value
*/
    int highIndex = 0;

    for(int i = 0; i < num; i++)
    {
    if (sc[highIndex] < sc[i])
    highIndex = i;
    }

    return highIndex;
}//
int getData(ifstream& inFile, string name[], int pin[], double score[])
{
int count = 0;
while (count < MAX && !inFile.eof())
{
getline(inFile, name[count]);
inFile >> pin[count];
inFile >> score[count];

count++;
inFile.ignore();
}
return count;
} //getData