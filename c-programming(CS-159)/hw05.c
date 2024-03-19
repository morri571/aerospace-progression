/*****+-*-***-*-**--*-***-***--*--*--*******--******************************
 *
 *  Homework #: 5
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: this program makes use of do-while loops to ensure
 *  that the program does not stop until the user inputs valid numbers.
 *  Based on the inputs the user enters, the program displays a sequence of
 *  numbers which are calculated using a combination of a while loop, nested
 I  if statement, and prefix operator.
 *
 ******+-*-***-*-**--*-***-***--*--*--*******--*****************************/

#include <stdio.h>
#include <math.h>

void get_input_evenOdd(int*);
void get_input_start(int*);
void get_input_end(int*,int);
void noVal ();
void loopPrint(int,int,int);

int main (void)
{
  int evenOdd; //logical variable representing even or odd
  int startNum; //starting number of the sequence
  int endNum; //ending number of the sequence

  get_input_evenOdd(&evenOdd);
  get_input_start(&startNum);
  get_input_end(&endNum,startNum);

  loopPrint(startNum,endNum,evenOdd); //prints all value using a while loop

  return 0;
}

/*****+----*--*-***---***--*---**----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: get_input_evenOdd
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int*,evenOdd,logical variable representing even or odd
 *    2.
 *    3.
 *
 *  Function Description: this function uses a do while loop to keep
 *  executing itself until the user puts in a valid number, which is told
 *  to them by a print statement.
 *
 ******+----*--*-***---***--*---**----*******--*****************************/

void get_input_evenOdd(int* evenOdd)
{
  do //infinite loop for valid inputs
  {
    printf("Enter 0 for even or 1 for odd values -> ");
    scanf("%d",evenOdd);

    if (!(*evenOdd == 0 || *evenOdd == 1)) //same condition as while
    {
      printf("\n");
      printf("Error! Select a valid option!!\n");
      printf("\n");
    }

  } while (!(*evenOdd == 0 || *evenOdd == 1)); //same condition as if

}  

/*****+----*--*-***---***--*---**----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: get_input_start
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int*,startNum,starting number of the sequence
 *    2.
 *    3.
 *
 *  Function Description: this function uses a do while loop to keep
 *  executing itself until the user puts in a valid number, which is told
 *  to them by a print statement.
 *
 ******+----*--*-***---***--*---**----*******--*****************************/

void get_input_start(int* startNum)
{
  do //infinite loop for valid inputs
  {
    printf("Enter starting value -> ");
    scanf("%d",startNum);

    if (*startNum <= 0) //condition matches while
    {
      printf("\n");
      printf("Error! Starting value must be positive!\n");
      printf("\n");
    }

  } while (*startNum <= 0); //condition matches if
}

/*****+-*--*--*-***---***--*---**----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: get_input_end
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int*,endNum, ending number of the sequence
 *    2. int,start,starting number of the sequence
 *    3.
 *
 *  Function Description: this function uses a do while loop to keep
 *  executing itself until the user puts in a valid number, which is told
 *  to them by a print statement.
 *
 ******+-*--*--*-***---***--*---**----*******--*****************************/

void get_input_end(int* endNum, int start)
{
  do //infinite loop for valid inputs
  {
    printf("Enter ending value -> ");
    scanf("%d",endNum);

    if (*endNum <= start) //condition matches while
    { 
      printf("\n");
      printf("Error! Ending value must be > %d\n",start);
      printf("\n");
    }

  } while (*endNum <= start); //condition matches if
}

/*****+-*--*--*-***---***--*---**----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: noVal
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1.
 *    2.
 *    3.
 *
 *  Function Description: this function displays an error message. It is not
 *  used in the infinite loop input functions because then the program would
 *  not be terminated.
 *
 ******+-*--*--*-***---***--*---**----*******--*****************************/

void noVal()
{
  printf("Error: No values generated.\n");
}

/*****+-*--*--*-***---***--*---**----*******--******************************
 *
 *  Function Information
 *
 *  Name of Function: loopPrint
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int,start,starting point of the sequence
 *    2. int,end,ending point of the sequence
 *    3. int,even_or_odd,logical value for even or odd
 *
 *  Function Description: this function checks whether the user wants even or
 *  odd values printed from a starting to an ending point. The function uses
 *  a while loop and a counter to print individual values, with a nested if
 *  statement, to make sure the numbers printed are all odd or all even.
 *  The function also checks if the inputted values will return no
 *  calculations. This checker is put inside this function because
 *  it mimics the boiler calculations for the second to last and last
 *  numbers.
 *
 ******+-*--*--*-***---***--*---**----*******--*****************************/

void loopPrint(int start,int end,int even_or_odd)
{
  int count; //counter to determine whether to exit/continue loop
  int boiler; //boiler number to print
  int boilerLast; //last boiler number
  int boilerSecondLast; //second to last boiler number 

  count = 1; //default count value
  boiler = 1; //default boiler number value
  boilerLast = 1; //default last calculated boiler number
  boilerSecondLast = 1; //default second to last calculated boiler number

  printf("\n");

  while(count <= end - 1)
  { 
    boilerLast = boilerLast + ++count;
  }

  count = 1;

  while(count < end - 1)
  {
    boilerSecondLast = boilerSecondLast + ++count;
  }

  if(even_or_odd == 0 && end - start == 1 && (boilerSecondLast % 2 != 0 && boilerLast % 2 != 0))
  {
    noVal();
  }
  else if(even_or_odd == 1 && end - start == 1 && (boilerSecondLast % 2 == 0 && boilerLast % 2 == 0))
  {
    noVal();
  }
  else
  {

    count = 1;

    if(even_or_odd == 0)
    {
      printf("Even Boiler numbers: ");
    }
    else
    {
      printf("Odd Boiler numbers: ");
    }

    while (count <= end)
    { 
      if((count >= start && even_or_odd == 0) && boiler % 2 == 0)
      {
        printf("%d ",boiler);
      }
      else if ((count >= start && even_or_odd == 1) && boiler % 2 != 0)
      {
        printf("%d ",boiler);
      }

      boiler = boiler + ++count;
    }
  }
}
