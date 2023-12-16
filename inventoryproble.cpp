/*Using the products.txt file, write a function to input the
info into parallel arrays. Output the entire inventory to the screen.
· Add to this program a selection sort to output the products
  from the lowest to the highest. Output the result from main().
· Add a function that will output the quantity on hand and the
  price when given the product ID code.
· Add a function to output the product IDs and current number
  in stock for all products needing to be reordered.
*/

#include <iostream>
#include <fstream>
using namespace std;

#define MAX 50
//declare functions
int getData(ifstream& inFile, int id[], double price[], int qty[], int rop[]);
void output(int id[], double price[], int qty[], int rop[], int num);
int seqSearch(int id[], int number, int target);
void sortSelection(double price[], int number, int id[], int qty[], int rop[]);
int mostexpensive(double price[],int number);
double avg(double price[], int number);

int main(void)
{
  //Declare variables
    ifstream inFile;
    int id[MAX];
    double price[MAX];
    int qty[MAX];
    int rop[MAX];
    int number;
    int target, loc, expensive;

  //Open file
  inFile.open("products.txt");
  if(inFile.fail())
  {
    cout << "Such file does not exist";
    exit(10);
  }
  //Input the entire contents of the product file
    number = getData(inFile, id, price, qty, rop);
  //Looking for a particular product - next week
    cout << "Enter product number you are looking for: ";
    cin  >> target;
    loc = seqSearch(id, number, target);
    if(loc == -1)
    {
      cout << "No such product" << endl;
    }
    else
    {
      cout << "Price: " << price[loc] << " Quanity" << " " << qty[loc] << endl;
    }


  //Sort by the price of product
  sortSelection(price, number, id, qty, rop);


    
  //Output each product's id, quantity on hand, re-order point, and price
    output(id, price, qty, rop, number);
  //most expensive
  expensive = mostexpensive(price,number);
  cout << "Most expensive item " << id[expensive] << " " << price[expensive] << " " << qty[expensive] << " " << rop[expensive] << endl;


  cout << "Average price: " << avg(price, number) << endl;

    system("pause");
    return 0;
}

int getData(ifstream& inFile, int id[], double price[], int qty[], int rop[])
{
    /*Pre:inFile - reference to data file
           id[] - array of products
           price[] - array of price
           qt[] - array of quantities
           rop[] - array of when to reorder
      Post: how many products
      Purpose: input inventory from data file
    */
    int count = 0;
    while (count < MAX && !inFile.eof())
    {
        inFile >> id[count] >> price[count] >> qty[count] >> rop[count];
        count++;
    }
    return count;
}

void output(int id[], double price[], int qty[], int rop[], int number)
{
    /*Pre:n - number of items in inventory
          id[] - array of products
          price[] - array of price
          qt[] - array of quantities
          rop[] - array of when to reorder
      Post: nothing
      Purpose: output inventory to the screen
    */
   for(int i = 0; i < number ; i++)
   {
        cout << id[i] << " " << price[i] << " " << qty[i] << " " << rop[i] << endl;
   }
   return;
}

int seqSearch(int id[], int number, int target)
{
  /*pre     : arr - array of values , number - number of values in array, target - desired product
    post    : location of the desired product
    purpose : search the desired product through the array
  */
  int loc = -1;
  for(int i = 0; i < number; i++)
  {
    if(target == id[i])
    {
      loc = i;
    }
  }



  return loc;
}

void sortSelection(double price[], int number, int id[], int qty[], int rop[])
{
  /* Pre: price[] - array of elements, number - number of elements
     Post: nothing
     Purpose: sort element from low to high
  */
  int walker, smallestindex, current, tempint;
  double tempdoub; 

  for(current = 0; current < number-1; current++)
  {
    smallestindex = current;
    for(walker = current + 1; walker < number; walker++)
    {
      if(price[walker] < price[smallestindex])
      {
        smallestindex = walker;
      }
    }
    //Swap
    tempdoub = price[current];
    price[current] = price[smallestindex];
    price[smallestindex] = tempdoub;

    tempint = id[current];
    id[current] = id[smallestindex];
    id[smallestindex] = tempint;
    
    tempint = qty[current];
    qty[current] = qty[smallestindex];
    qty[smallestindex] = tempint;

    tempint = rop[current];
    rop[current] = rop[smallestindex];
    rop[smallestindex] = tempint;
  }
}

int mostexpensive(double price[],int number)
{
  int highest = 0;
  for(int i = 0; i < number; i++)
  {
    if(price[i] > price[highest])
    {
      highest = i;
    }
  }
  return highest;
}

double avg(double price[], int number)
{
  double sum = 0;
  for(int i = 0; i < number; i++)
  {
    sum = sum + price[i];
  }
  return sum / number;
}