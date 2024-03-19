/*****+----**-*-**--*-**--***--*-----*-*****--******************************
 *
 *  Lab #: 10 
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: Given a positive integer to serve as the seed for the random 
 *  number generator, generate 500 two-dimensional points (generate x then y for each point)
 *  and analyze the data set created to calculate (1) the maximum distance between
 *  two points, (2) the number of horizontal lines, and (3) the number of vertical lines.
 *  The range of both dimensions will be integers in the range from -100 to 100 inclusive.
 *
 ******+----**-*-**--*-**--***--*-----*-*****--*****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 1000
#define UPPER 100
#define LOWER -100

void input(int*);
void fillArray(int[],int[]);
double maximumDistance(int[], int []);
double distanceFormula (double, double, double, double);
int vertical(int[],int[]);
int horizontal(int[],int[]);
void outputs(double,int,int);

int main(void)
{
  int seed; //user inputted seed value for srand()
  int xVals[SIZE / 2]; //array of 500 x points
  int yVals[SIZE / 2]; //array of 500 y points
  double maxDist; //maximum distance between all 500 coordinate combinations
  int horzCount; //number of horizontal lines
  int vertCount; //number of vertical lines

  input(&seed);

  srand(seed);
  fillArray(xVals,yVals);

  maxDist = maximumDistance(xVals,yVals); // maximum distance
  horzCount = horizontal(xVals,yVals); // horizontal lines
  vertCount = vertical(xVals,yVals); // vertical lines

  outputs(maxDist,horzCount,vertCount); // required outputs

  return(0);
}

/*****+----**-*-***---**--**--**--*-****-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: input
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int* seed, seed value for the srand function
 *
 *  Function Description: Prompts user to enter in a seed value that's positive.
 *  If it's not positive it'll keep prompting until valid.
 *
 ******+----**-*-***---**--**--**--*-****-***--*****************************/

void input(int* seed)
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

/*****+----**-*-***---**--**--**--*-****-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: fillArray
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int xVals[], array of x points of a coordinate
 *    2. int yVals[], array of y points of a coordinate
 *
 *  Function Description: fills a temporary array with all the x and y values. Then it
 *  assigns every other element starting from 0 to the x array and then assigns every other
 *  element starting from 1 to the y array.
 *
 ******+----**-*-***---**--**--**--*-****-***--*****************************/

void fillArray(int xVals[], int yVals[])
{
  int i; //counter for filling a temporary array of all 1000 x and y values
  int x; //counter for retrieving x values from temporary array
  int y; //counter for retrieving y values from temporary array
  int tempArray[SIZE]; //temporary array with all 1000 x and y values
  int xcount; //counter for filling x array at certain index
  int ycount; //counter for filling y array at certain index

  xcount = 0;
  ycount = 0;
  x = 0; 
  y = 1;

  // creates a temporary array of 1000 with values in the range of -100 to 100 inclusive of both
  for(i = 0; i < SIZE; i++)
  {
    tempArray[i] = rand() % (UPPER - LOWER + 1) + LOWER;
  }

  // assigns each index of the x array to a value retrieved from the temporary array
  while(xcount < SIZE / 2)
  {
    xVals[xcount] = tempArray[x];
    xcount++;
    x += 2;
  }

  // assigns each index of the x array to a value retrieved from the temporary array
  while(ycount < SIZE / 2)
  {
    yVals[ycount] = tempArray[y];
    ycount++;
    y += 2;
  }

}

/*****+-*--**-*-***---**--**--**--*-****-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: maximumDistance
 *
 *  Function Return Type: double
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int xArray[], array of x points of a coordinate
 *    2. int yArray[], array of y points of a coordinate
 *
 *  Function Description: Calculates the distance between two points in the array, it will then
 *  calculate another difference between a different set of points and whichever one is bigger will be
 *  kept.
 *
 ******+-*--**-*-***---**--**--**--*-****-***--*****************************/

double maximumDistance(int xArray[], int yArray[])
{    
  double diff; // assigns the calculated distance between the points to this variable
  int outer; // variable for the index of the first set of points
  int inner; // variable for the index of the second set of points
  double tempDist; // assigns the calculated distance between two DIFFERENT points to this variable for comparison

  diff = distanceFormula(xArray[0], yArray[0], xArray[1], yArray[1]);

  /* Uses the elements in index 0 from the x and y arrays to determine the first set of points and then goes
     through each possible combination with the second set of points to determine if there is a larger distance
     than the previous ones calculated. If the distance is bigger than the previous then it will keep that
     number. The inside for loop will continue to run this process and once it gets to the last index it
     will update the outside for loop and then do the whole process again until the outside for loop finishes.*/
  for (outer = 0; outer < SIZE / 2; outer++)
  {

    for (inner = 0; inner < SIZE / 2; inner++)
    {
      tempDist = distanceFormula(xArray[outer], yArray[outer], xArray[inner], yArray[inner]);
      if (tempDist >= diff)
      {
        diff = tempDist;
      }
    }

  }         
  return (diff);
}

/*****+-*--**-*-***---**--**--**--*-****-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: distanceFormula
 *
 *  Function Return Type: double
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double x1, first x point for distance formula
 *    2. double y1, first y point for distance formula
 *    3. double x2, second x point for distance formula
 *    4. double y2, second y point for distance formula
 *
 *  Function Description: Calculates the distance between the two points passed from
 *  the calling function
 *
 ******+-*--**-*-***---**--**--**--*-****-***--*****************************/

double distanceFormula(double x1, double y1, double x2, double y2)
{
  double distance; // initializes the distance
  double xDiff; // difference between the two x points
  double yDiff; // difference between the two y points

  xDiff = abs(x2 - x1);
  yDiff = abs(y2 - y1);

  // distance formula calculations
  distance = sqrt(pow(xDiff , 2) + pow(yDiff , 2));

  return(distance);

}

/*****+-*--**-*-***---**--**--**--*-****-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: vertical
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int xArray[], array of x points of a coordinate
 *    2. int yArray[], array of y points of a coordinate
 *
 *  Function Description: If the x value of two points are the same and the y values are
 *  different then the program will recognize this is a horizontal line.
 *
 ******+-*--**-*-***---**--**--**--*-****-***--*****************************/

int vertical(int xArray[],int yArray[])
{ 
  int count; // initializes the count of how many vertical lines there are
  int outer; // outer for loop iteration
  int inner; // inner for loop iteration

  count = 0;

  // goes through each possible combination of points to find the vertical lines
  for (outer = 0; outer < SIZE / 2 - 1; outer++)
  {

    for (inner = outer + 1; inner < SIZE / 2; inner++)
    {

      if ((xArray[outer] == xArray[inner]) && (yArray[outer] != yArray[inner]))
      {
        count++; // adds to the vertical line counter if the y values are the same
      }
    }

  }
  return (count);
}

/*****+-*--**-*-***---**--**--**--*-****-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: horizontal
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int xArray[], array of x points of a coordinate
 *    2. int yArray[], array of y points of a coordinate
 *
 *  Function Description: If the y values of two points are the same and the x values are
 *  different then the program will identify that as a vertical line and add to a counter.
 *
 ******+-*--**-*-***---**--**--**--*-****-***--*****************************/

int horizontal(int xArray[], int yArray[])
{
  int count; // initializes the counter for the number of horizontal lines
  int outer; // outer for loop iterations
  int inner; // inner for loop iterations

  count = 0; 

  // goes through all possible combinations of points to find the horizontal lines
  for (outer = 0; outer < SIZE / 2 - 1; outer++)
  {

    for (inner = outer + 1; inner < SIZE / 2; inner++)
    {

      if ((yArray[outer] == yArray[inner]) && (xArray[outer] != xArray[inner]))
      {
        count++; // adds to the count of horizontal lines if found
      }
    }

  }
  return (count);
}

/*****+-*--**-*-***---**--**--**--*-****-***--******************************
 *
 *  Function Information
 *
 *  Name of Function: outputs
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double dist, max distance between the combinations of points
 *    2. int horizontal, number of horizontal lines
 *    3. int vertical, number of vertical lines
 *
 *  Function Description: prints out the calculated maximum distance between two points
 *  and the counts of the identified  horizontal and vertical lines.
 *
 ******+-*--**-*-***---**--**--**--*-****-***--*****************************/

void outputs(double dist, int horizontal, int vertical)
{
  printf("\n");
  printf("Maximum Distance: %.1lf\n",dist);
  printf("Horizontal Lines: %d\n",horizontal);
  printf("Vertical Lines: %d\n",vertical);
}
