//Training Heart Rate
/*

The American College of Sports Medicine recommends that you maintain your training heart rate during
an aerobic workout. Your training heart rate is computed as .7 * (220 – a) + .3 * r,
where a is your age and r is your resting heart rate (your pulse when you first awaken).
Write a program to prompt and input a person’s age and resting heart rate.
Calculate the training heart rate using a separate function. Call this function from main().
Output this value using a function which is also called from main().*/

#include <iostream>
#include <cstdlib>
using namespace std;

//protoype
double calcTHR(int age, double restHR);
void output(double);

int main()
{
    int age;
    double restHR, trainHR;

    //input age and restHR
    cout << "Enter a positive number for age: ";
    cin  >> age;
    if(age > 0)
    {
        cout << "Enter resting heart rate: ";
        cin  >> restHR;
        trainHR = calcTHR(age, restHR);
        output(trainHR);
    }
    else
    {
        cout << "Invalid output";
        exit;
    }


    //Calculate HR



    //Output trainHR


    return 0;

} // end of main

double calcTHR(int age, double resting)
{
    /*Age is an int, restingHR is double*/
    double trainHR;
    trainHR = 0.7 * (220 - age) + 0.3 * resting;
    return trainHR;
}

void output(double trainingHR)
{
    cout << "Training Heartrate: " << static_cast<int>(trainingHR) + 0.5;
    return;
}