/*****+----**---***----**--**-**--*--*-*****--******************************
 *
 *  Homework #: 6
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description:
 *
 ******+----**---***----**--**-**--*--*-*****--*****************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define LOWER 1
#define UPPER 100
#define SIZE 75

void getInput(int*);
void dataFiller(int[]);
double meanCalc(int[]);
double stdevCalc(double,int[]);
void output(double,double,int[]);

int main (void)
{
  int seedValue; //user inputted value for the srand() function
  int dataSet[SIZE]; //75 element array to store random numbers
  double dataMean; //mean value of the data set 
  double standardDeviation; //standard deviation of the data set

  getInput(&seedValue);
  srand(seedValue);

  dataFiller(dataSet);

  dataMean = meanCalc(dataSet);
  standardDeviation = stdevCalc(dataMean,dataSet);

  output(dataMean,standardDeviation,dataSet);

  return 0;
}

/*****+---***----*--*--**--**-***----*-*****--******************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int*,seedValue, seed value for srand() that the user inputs
*    2.
*    3.
*
*  Function Description: this function uses pass by address to assign the
*  user input to a variable.
*
******+---***----*--*--**--**-***----*-*****--*****************************/

void getInput(int* seedValue)
{

  printf("Enter seed value -> ");
  scanf("%d",seedValue);

}

/*****+---***----*--*--**--**-***----*-*****--******************************
*
*  Function Information
*
*  Name of Function: dataFiller
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int[],numData, array for 75 randomized values from 1-100.
*    2.
*    3.
*
*  Function Description: this function uses pass by address and a for-loop
*  to fill a 75 element array with random values from 1-100.
*
******+---***----*--*--**--**-***----*-*****--*****************************/

void dataFiller(int numData[])
{
  int i; //counter for for loop

  for(i = 0; i < SIZE; i++)
  {
    numData[i] = rand() % (UPPER - LOWER + 1) + LOWER;
  }
}

/*****+---***----*--*--**--**-***----*-*****--******************************
*
*  Function Information
*
*  Name of Function: meanCalc
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int[],numData, array for 75 randomized values from 1-100.
*    2.
*    3.
*
*  Function Description: this function uses the newly filled array and a
*  for loop to add each element to a placeholder, and divides the
*  placeholder by the number of elements to get the mean.
*
******+---***----*--*--**--**-***----*-*****--*****************************/

double meanCalc(int numData[])
{
  int i; //counter for for loop

  double mean; //placeholder for mean of data set

  for(i = 0; i < SIZE; i++)
  {
    mean += numData[i];
  }

  mean = mean / SIZE;

  return mean;

}

/*****+---***----*--*--**--**-***----*-*****--******************************
*
*  Function Information
*
*  Name of Function: stdevCalc
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. double,mean, mean of the data set
*    2. int[],numData, array for 75 randomized values from 1-100.
*    3.
*
*  Function Description: this function uses the previously calculated mean
*  and applies it to the standard deviation formula. The formula includes
*  a sum of the data set so a for loop is needed.
*
******+---***----*--*--**--**-***----*-*****--*****************************/

double stdevCalc(double mean,int numData[])
{
  int i; //counter for for loop
  double stdev; //standard deviation of data set

  stdev = 0;

  for(i = 0;  i < SIZE; i++)
  {
    stdev += pow((numData[i] - mean),2);
  }

  stdev = sqrt(stdev / (SIZE - 1));

  return stdev;
}

/*****+---***----*--*--**--**-***----*-*****--******************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double,mean, mean value of the data set
*    2. double,stdev, standard deviation of the data set
*    3. int[],numData, array for 75 randomized values from 1-100.
*
*  Function Description: this function prints the mean and standard 
*  deviation of the data set. The function also prints values one deviation
*  above and below the mean using a for loop.
*
******+---***----*--*--**--**-***----*-*****--*****************************/

void output(double mean,double stdev, int numData[])
{
  int i; //counter for for loop

  printf("\n");
  printf("Data set mean: %.1lf\n",mean);
  printf("Data set standard deviation: %.1lf\n",stdev);
  printf("Values less than one deviation from mean:");

  for(i = 0; i < SIZE; i++)
  {
    if (numData[i] < (mean - stdev))
    {
      printf(" %d",numData[i]);
    }
  }

  printf("\nValues greater than one deviation from mean:");

  for(i = 0; i < SIZE; i++)
  {
    if (numData[i] > (mean + stdev))
    {
      printf(" %d",numData[i]);
    }
  }

}
