#include <iostream>
using namespace std;
void backwards(int [], int);

int main()
{
    int arr[] = {2,8,17,3,5,16}; int i;

    backwards(arr,6);
    for (i = 0; i< 6; i++)
    cout<<arr[i]<<endl;

    //system("pause");
    return 0;
}

void backwards(int array[], int number)
{
    /*Pre: array[] - array of integers
    number - number of elements in the array that have values
    Post: Nothing
    Purpose: Reverse the order of the elements of an array */
    int i; int temp;int j;//Declare NO NEW ARRAYS

    for(i = 0; i < number/2 ; i++)
    {
        temp     = array[i];
        array[i] = array[number - 1 - i];
        array[number - 1 - i] = temp;   
    }
    return;
}