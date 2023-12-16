le, string crn[], string classname[], int curr[], int max[], int wl[], double fillrate[], int number)
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
