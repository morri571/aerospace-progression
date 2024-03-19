/*****+-*-**--*-***-*--**-***-***---****-***--******************************
 *
 *  Lab #: 11
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description:  Given a positive integer to serve as the seed for the
 *  random number generator and the maximum value to generate, create a data set of
 *  100 integers ranging from 1 to the given maximum value (inclusive of both end 
 *  points) and display the perfect squares (in sorted order) followed by the semi-squares
 *  (in sorted order). A number identified as a perfect square will not be a candidate 
 *  for display as a semi-square.
 *
 ******+-*-**--*-***-*--**-***-***---****-***--*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LOWER 1
#define SIZE 100

void inputSeed(int*);
void inputRange(int*);
void randFill(int[],int);
void perfFill(int[],int[]);
void squareCalc(int[],int[],int[],int*,int*);
int checkFactor(int);
void sortArray(int[]);
void outputs(int[],int[],int*,int*);

int main (void)
{
  int seed; //user inputted seed for srand().
  int range; //user inputted max value for rand.
  int semi; //number of semi squares found and logical value for whether one is found
  int square; //number of perfect squares found and logical value for whether one is found
  int array[SIZE]; //array of 100 randomly generated numbers based on user inputted range
  int perfSquares[SIZE]; //array of perfect squares found from the 100 numbers
  int semiSquares[SIZE]; //array of semi squares found from the 100 numbers

  inputSeed(&seed);
  inputRange(&range);

  srand(seed);

  randFill(array,range);

  sortArray(array);

  squareCalc(array,perfSquares,semiSquares,&square,&semi);

  outputs(perfSquares,semiSquares,&square,&semi);

  return (0);
}

/*****+**-*--*----**--**-*-******-*--***-***--******************************
*
*  Function Information
*
*  Name of Function: inputSeed
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int*,seed, user inputted seed for srand()
*    2.
*    3.
*
*  Function Description: this function uses input validation to get the
*  user inputted seed value.
*
******+**-*--*----**--**-*-******-*--***-***--*****************************/

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

/*****+*--*--*----**--**-*-******-*--***-***--******************************
*
*  Function Information
*
*  Name of Function: inputRange
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int*,range, maximum value the rand function can generate 
*    2.
*    3.
*
*  Function Description: this function uses input validation to get the
*  max value for generating random numbers from 1 to that value.
*
******+*--*--*----**--**-*-******-*--***-***--*****************************/

void inputRange(int* range)
{
  do
  {

    printf("Enter maximum range value -> ");
    scanf("%d",range);

    if(*range <= 0)
    {
      printf("\n");
      printf("Error! Positive range values only!!\n");
      printf("\n");
    }

  }while(*range <= 0);

}

/*****+*--*--*----**--**-*-******-*--***-***--******************************
*
*  Function Information
*
*  Name of Function: randFill
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int[],array, array with 100 randomly generated integers
*    2. int,range, max value, for rand function
*    3.
*
*  Function Description: fills array with 100 random value from 1 to the
*  inputted max.
*
******+*--*--*----**--**-*-******-*--***-***--*****************************/

void randFill(int array[], int range)
{
  int i; //loop control variable for for loop

  for(i = 0;i < SIZE;i++)
  {
    array[i] = rand() % (range - LOWER + 1) + LOWER;
  }

}

/*****+*--*--*----**--**-*-******-*--***-***--******************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int[],array, array with 100 random integers
*    2.
*    3.
*
*  Function Description: this function rearranges the raw generated data
*  in an ascending order using sorting.
*
******+*--*--*----**--**-*-******-*--***-***--*****************************/

void sortArray(int array[])
{
  int numPasses; //LCV that controls the number of passes
  int lcv; //lcv for sorting
  int temp; //holds value during swap

  for(numPasses = 1; numPasses < SIZE; numPasses++)
  {
    for(lcv = 0; lcv < SIZE - numPasses; lcv++)
    {
      if(array[lcv] > array[lcv + 1])
      {
        temp = array[lcv];
        array[lcv] = array[lcv + 1];
        array[lcv + 1] = temp;
      }
    }
  }
}

/*****+*--*--*----**--**-*-******-*--***-***--******************************
*
*  Function Information
*
*  Name of Function: squareCalc
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int[],user, array of 100 randomly generated numbers
*    2. int[],perfArray, array to store perfect squares
*    3. int[],semiArray, array to store semi squares
*    4. int*,square, logical value and counter for perfect squares
*    5. int*,semi, logical value and counter for semi squares
*
*  Function Description: this function uses a nested for loop to iterate
*  through each factor of each of the 100 numbers and determine if it
*  is a semi square or perfect square, and store it into its corresponding 
*  array/
*
******+*--*--*----**--**-*-******-*--***-***--*****************************/

void squareCalc(int user[],int perfArray[],int semiArray[],int* square,int* semi)
{
  int outer; //loop control variable for going through array of 100 numbers
  int inner; //loop control variable for going through factors
  int sqFact1; //logical value for if the factor is a square
  int sqFact2; //logical value for if the second factor is a square
  int factor1; //first factor of the number being evaluated
  int factor2; //second factor of the number being evaluated
  int currentSquare; //logical value for whether number in this iteration is a square

  *square = 0;
  *semi = 0;
  currentSquare = 0;

  for(outer = 1; outer <= SIZE; outer++)
  {
    for(inner = 1;inner <= user[outer - 1];inner++)  //continues to loop if count is less than or equal to the user's input
    {
      if (user[outer - 1] % inner == 0)
      {
        factor1 = user[outer - 1] / inner;
        sqFact1 = checkFactor(factor1);

        factor2 = user[outer - 1] / factor1;
        sqFact2 = checkFactor(factor2);

        if (factor2 == factor1)
        {
          *square += 1; // identifies that the integer is a perfect square
          currentSquare = 1;
          perfArray[*square - 1] = factor1 * factor2; 
        }

        else if (sqFact1 != 0 || sqFact2 != 0)
        {
          if(sqFact1 != 0)
          {

            if (factor2 > 1 && factor2 < sqrt(factor1))
            {
              /* identifies if the value is a valid semi-square if the second factor 
                 is greater than one and less than the square root of the first factor */

              if(currentSquare == 0 /*&& inner == user[outer - 1]*/)
              {
                *semi += 1;
                semiArray[*semi - 1] = factor1 * factor2;
              }
            }
          }

        }

      }

      currentSquare = 0;

    }
  }
}

/*****+*--*--*----**--**-*-******-*--***-***--******************************
*
*  Function Information
*
*  Name of Function: checkFactor
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,num, one of the two factors of the number being evaluated in 
*       squareCalc
*    2. 
*    3.
*
*  Function Description: this function uses square root comparisons between
*  an integer and a float to find out whether the factor is a square.
*
******+*--*--*----**--**-*-******-*--***-***--*****************************/

int checkFactor(int num)
{
  double num1; //decimal of inputted number
  int square; //logical value for whether inputted value is a perfect square

  num1 = num;
  num1 = sqrt(num1);
  num = sqrt(num);

  if (num1 == num)
  {
    square = 1; //if the decimal root and the integer root is equal then it is a perfect square.
  }
  else
  {
    square = 0;
  }

  return(square);
}

/*****+*--*--*----**--**-*-******-*--***-***--******************************
*
*  Function Information
*
*  Name of Function: outputs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int[],perfArray, array of perfect squares
*    2. int[],semiArray, array of semi squares
*    3. int*,square, counter and logical value for perfect squares
*    4. int*, semi, counter and logical value for semi squares
*
*  Function Description: this function uses a for loop based on the semi and
*  square int*'s to iterate and print the semi squares and perfect squares
*  in both arrays.
*
******+*--*--*----**--**-*-******-*--***-***--*****************************/

void outputs(int perfArray[],int semiArray[],int* square,int* semi)
{

  int i; //counter for for loops
  float semiArray2[SIZE]; //duplicated array of float value of semi squares

  if(*square != 0)
  {
    printf("\nPerfect squares:");

    for(i = 0; i < *square;i++)
    {
      printf(" %d",perfArray[i]);
    }
  }

  if(*semi != 0)
  {
    printf("\nSemi-squares:");

    for(i = 0; i < *semi;i++)
    { 
      semiArray2[i] = semiArray[i];

      if((int)sqrt(semiArray[i]) != sqrt(semiArray2[i]))
      {
        printf(" %d",semiArray[i]);
      }
    }
  }

  if(*square == 0 && *semi == 0)
  {
    printf("\n");
    printf("Result: No perfect or semi-squares found.");
  }

  printf("\n");

}
