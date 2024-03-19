/*****+----*--*-**--*--**-**--**--*--***-***--******************************
 *
 *  Homework #: 07
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: this program uses srand to create an array of 1000
 *  random numbers, from a range of 10 to the power of a user input minus
 *  one. The program then rearranges each digit to become its maximum based
 *  off of its digits. For example, 438 becomes 843. After rearrangement,
 *  the program prints the 5 smallest and 5 largest values of the array.
 *
 ******+----*--*-**--*--**-**--**--*--***-***--*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1000
#define LOWER 0
#define NUMOUTPUTS 5

void inputSeed(int*);
void inputPow(int*);
void randFill(int[],int);
int digiCount(int);
int getMax(int,int*);
int addMax(int,int);
int subtractMax(int,int,int);
void rearrange(int[]);
void output(int[]);

int main (void)
{
  int seed; //seed value for srand that user inputs
  int power; //power to raise 10 to for randomly generated values between 0 and 10^power
  int randArray[SIZE]; //array of randomly generated numbers

  inputSeed(&seed);
  inputPow(&power);

  srand(seed);

  randFill(randArray,power);
  rearrange(randArray);
                                               
  output(randArray);
  
  return(0);
}

/*****+----*-----*--*--**-***--*--*--***-***--******************************
*
*  Function Information
*
*  Name of Function: inputSeed
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int*,seed, user inputted seed value for srand
*    2.
*    3.
*
*  Function Description: this function uses pass by address and a do-while
*  loop for input validation to get the user inputted seed.
*
******+----*-----*--*--**-***--*--*--***-***--*****************************/

void inputSeed(int* seed)
{
  do
  {
    printf("Enter seed value -> ");
    scanf("%d",seed);

    if(*seed <= 0) // prints error message if the seed is less than or equal to zero
    {
      printf("\n");
      printf("Error! Positive seed values only!!\n");
      printf("\n");
    }

  }while(*seed <= 0);
}

/*****+----*-----*--*--**-***--*--*--***-***--******************************
*
*  Function Information
*
*  Name of Function: inputPow
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int*,power, user inputted power to raise 10 
*    2.
*    3.
*
*  Function Description: this function uses pass by address and a do-while
*  loop for input validation to get the user inputted power.
*
******+----*-----*--*--**-***--*--*--***-***--*****************************/

void inputPow(int* power)
{
  do
  {
    printf("Enter maximum power of ten for range -> ");
    scanf("%d",power);

    if(*power <= 0) // prints error message if the seed is less than or equal to zero
    {
      printf("\n");
      printf("Error! Power of ten must be positive!!\n");
      printf("\n");
    }

    if(*power > 8)
    {
      printf("\n");
      printf("Error! Power of ten cannot exceed eight!");
      printf("\n");
      printf("\n");
    }

  }while(*power <= 0 || *power > 8);
}

/*****+----*-----*--*--**-***--*--*--***-***--******************************
*
*  Function Information
*
*  Name of Function: randFill
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int[],array, array to be filled with random numbers
*    2. int,pow, power that user inputted to raise 10 to
*    3.
*
*  Function Description: this function uses a for loop and the rand() 
*  function to fill an array from 0 to a user inputted power of 10 to that
*  power.
*
******+----*-----*--*--**-***--*--*--***-***--*****************************/

void randFill(int array[], int power)
{
  int i; //loop control variable for for loop
  int range; //maximum value to be generated

  range = (int)(pow(10,power) - 1);

  for(i = 0;i < SIZE;i++)
  {
    array[i] = rand() % (range - LOWER + 1) + LOWER;
  }
}

/*****+-*-***-*-***----**-***--*--*--***-***--******************************
*
*  Function Information
*
*  Name of Function: digiCount
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,num, one of the 1000 numbers in the array to be evaluated
*    2.
*    3.
*
*  Function Description: this function counts the number of digits in 
*  a number and returns the count.
*
******+-*-***-*-***----**-***--*--*--***-***--*****************************/

int digiCount(int num)
{
  int count; //number of digits

  count = 0;

  while(num > 0)
  {
    if(num % 10 == 0)
    {
      count++;
    }

    num = num / 10;

  }

  return(count);

}

/*****+----*-----*--*--**-***--*--*--***-***--******************************
*
*  Function Information
*
*  Name of Function: getMax
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,num, one of the 1000 numbers in the array to be evaluated
*    2. int*,maxLocation, index in the number where the highest digit is
*    3.
*
*  Function Description: this function calculates the largest digit in the
*  number being evaluated and returns it. The function also finds out
*  where the largest digit occurs in the number.
*
******+----*-----*--*--**-***--*--*--***-***--*****************************/

int getMax(int num,int* maxLocation)
{
  int max; //maximum digit
  int loc; //location of the max digit

  max = 0;
  loc = 0;

  while(num > 0)
  {
    if(num % 10 > max)
    {
      max = num % 10;
      *maxLocation = loc;
    }

    num = num / 10;
    loc++;
  }

  return(max);
}

/*****+----*-----*--*--**-***--*--*--***-***--******************************
*
*  Function Information
*
*  Name of Function: addMax
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,sort, number currently being sorted
*    2. int,maximum, maximum digit of the number being sorted
*    3.
*
*  Function Description: this function multiplies the number being sorted
*  by 10 and adds the maximum digit in preparation for the subtractMax
*  function.
*
******+----*-----*--*--**-***--*--*--***-***--*****************************/

int addMax(int sort,int maximum)
{
  return(sort * 10 + maximum);
}

/*****+----*-----*--*--**-***--*--*--***-***--******************************
*
*  Function Information
*
*  Name of Function: subtractMax
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,num, number being evaluated
*    2. int,maximum, max digit of number
*    3. int,location, location of the largest digit
*
*  Function Description: this function subtracts the maximum digit 
*  multiplied 10 to the index of the max digit from the number being 
*  evaluated. This in combination with the addMax and getMax inside a loop
*  will completely rearrange the number 
*
******+----*-----*--*--**-***--*--*--***-***--*****************************/

int subtractMax(int num,int maximum,int location)
{
  return(num - maximum * (int)pow(10,location));
}

/*****+-*-***-*-***----**-***--*--*--***-***--******************************
*
*  Function Information
*
*  Name of Function: rearrange
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,array[], array of randomly generated values
*    2.
*    3.
*
*  Function Description: this function acts as a main function. It calls
*  three functions inside a for loop to rearrange the number to its maximum
*  possible number. Once the current value placeholder of the  array reaches 
*  0 from changing throughout the function calls, the maximum number is
*  calculated using the sorted number and the number of digits.
*  
*
******+-*-***-*-***----**-***--*--*--***-***--*****************************/

void rearrange(int array[])
{
  int sorted; //sorted number
  int max; //max digit
  int maxLocation; //location of the maximum digit
  int count; //number of digits
  int i; //loop control variable
  int placehold; //placeholder so current value of array does not change

  for(i = 0;i < SIZE;i++)
  {
    placehold = array[i];
    count = digiCount(placehold); 
    sorted = 0;

    while(placehold > 0)
    {
      max = getMax(placehold,&maxLocation);
      sorted = addMax(sorted,max);
      placehold = subtractMax(placehold,max,maxLocation);
    }

    array[i] = (sorted * (int)pow(10,count));
   
  }

}

/*****+-*-***-*-***----**-***--*--*--***-***--******************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int[],array, array of new numbers in their largest form
*    2.
*    3.
*
*  Function Description: this function prints the 5 largest and 5 smallest
*  values of the array. It does this by looping through the array 5 times, 
*  printing the maximum value of that iteration, and replacing it with 0 so
*  is not printed again. Likewise for the smallest values, the function
*  iterates through the array, prints the current min value, and replaces it
*  with the absolute maximum so it is not printed again.
*
******+-*-***-*-***----**-***--*--*--***-***--*****************************/

void output(int array[])
{
  int outer; //outer loop for printing 5 values
  int inner; //inner loop for iterating through entire array
  int absMax; //absolute maximum of the array
  int max; //placeholder for the current max value of the array
  int min; //placeholder fort the current min value of the array
  int maxDex;  //index of the current max value of the array
  int minDex; //index of the current min value of the array

  max = 0;
  absMax = 0;

  for(inner = 0;inner < SIZE;inner++)
  {
    if(array[inner] > absMax)
    {
      absMax = array[inner];
    }
  }

  min = absMax;

  printf("\nLargest 5 values in data:");

  for(outer = 0;outer < NUMOUTPUTS;outer++)
  {

    for(inner = 0;inner < SIZE;inner++)
    {
      if(array[inner] > max)
      {
        max = array[inner];
        maxDex = inner;
      }
    }

    printf(" %d",max);
    array[maxDex] = -1;
    max = 0;
  }

  printf("\nSmallest 5 values in data:");

  for(outer = 0;outer < NUMOUTPUTS;outer++)
  {

    for(inner = 0;inner < SIZE;inner++)
    {
      if(array[inner] < min && array[inner] >= 0)
      {
        min = array[inner];
        minDex = inner;
      }
    }

    printf(" %d",min);
    array[minDex] = absMax;
    min = absMax;
  }
}
