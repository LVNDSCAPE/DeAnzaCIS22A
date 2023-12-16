//Run this program twice
//First time enter your first name
//Second time enter first name and last name separated by a space

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{

string greeting = "Good Morning, ";
string name; char grade = 'F';
char gender;

cout << "What is your name? ";
getline(cin, name);

cout << "Enter ""F"" for female and ""M"" for male: ";
cin  >> gender;
gender = toupper(gender);
cout <<"What grade do you wish for in this class? ";
cin  >> grade;
grade = toupper(grade);

greeting = greeting + name;

cout << greeting << endl << endl;

cout << "Your wish of " << grade << " will be granted "<< endl;
system("pause");

return 0;
}