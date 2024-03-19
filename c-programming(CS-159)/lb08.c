/*****+-*-***-*-**----***--**--**---**-*****--******************************
 *
 *  Lab #: 8
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: this program takes the user input using input 
 *  validation by a do-while loop. The loop ensure that only 1's and 2's are
 *  entered. After inputs are validated, the program calculates the number of
 *  changes to be made to the configuration, so that there are no side by
 *  side 1's or 2's. Like "11" or "22." The program uses modulus 10 and 
 *  division 10 to achieve this with a while loop. Finally, the program
 *  outputs the least number of changes depending on which loop required
 *  less changes.
 *
 ******+-*-***-*-**----***--**--**---**-*****--*****************************/

#include <stdio.h>
#include <math.h>

// Function Declarations
long int getInput(long int*);
int numChanges(long int);
void output(int);

int main (void)
{
  
  // Declarations
  long int config; //user inputted value to be split into individual digits
  long int configUnchanged; //original input without being split
  int requiredChange; //required number of changes for the configuration

  // Function Calls
  configUnchanged = getInput(&config);

  requiredChange = numChanges(configUnchanged); 

  output(requiredChange);

  return 0;
}

/*****+---***----**----**-***-***-*--*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: getInput
 *
 *  Function Return Type: long int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. long int* config - the original number consisting of 1s and 2s that
 *       the user inputs
 *
 *  Function Description: The purpose of this function is to accept the user
 *  input of an integer that consists solely of 1s and 2s for the program to
 *  rearrange. The function also validates the number to ensure that it only
 *  consists of 1s and 2s. Should the number fail to be only 1s and 2s, the
 *  function will flag it, tell the user of the error, and then request that
 *  a new input be made. The function lastly returns the unchanged initial
 *  input to the main function so that it can be called upon in future functions.
 *
 ******+---***----**----**-***-***-*--*-*****--*****************************/

long int getInput(long int* config)
{

  long int configHolder; //placeholder for unsplit config value
  int invalid; //counts if a digit is not 1 or 2

  do
  {
    printf("Enter the initial configuration -> ");
    scanf("%ld",config);
    printf("\n");

    configHolder = *config;
    invalid = 0;

    while(*config > 0)
    {
      if(!(*config % 10 == 1 || *config % 10 == 2))
      {
        invalid++;
      }

      *config = *config / 10;
    }

    if (invalid != 0)
    {

      printf("Error! Input must contain only digits 1 and 2!\n");
      printf("\n");

    }

  } while(invalid != 0);

  return configHolder;

}

/*****+---***----**----**-***-***-*--*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: numChanges
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. long int num - the unchanged original integer that the user inputted
 *
 *  Function Description: The purpose of this function is to determine the
 *  minimum number of required changes that need to be made to the initial
 *  inputted integer by the user to make it a number that consists of
 *  alternating 1s and 2s.
 *
 ******+---***----**----**-***-***-*--*-*****--*****************************/

int numChanges (long int num)
{

  long int numLeft; //user inputted configuration for left side evaluation
  int changesLeft; //number of required changes evaluating digits to the left
  int left; //digit to the left of the current digit being evaluated
  long int numRight; //user inputted configuration for right side evaluation
  int changesRight; // number of required changes evaluating digits to the right
  int right; //digit to the right of the current digit being evaluated
  int rHolder; //placeholder for right hand digit for right side evaluation
  int changes; //number of required changes to the configuration

  numLeft = num;
  numRight = num;

  changesLeft = 0;
  changesRight = 1;
  rHolder = 0;

  while(numLeft > 0)
  {
    left = (numLeft / 10) % 10;

    if(numLeft % 10 == 1 && left == 1)
    {
      changesLeft++;
    }
    else if(numLeft % 10 == 2 && left == 2)
    {
      changesLeft++;
    }

    if(numLeft % 10 == 1 && left == 1)
    {
      numLeft = ((numLeft / 100) * 10) + 2;
    }
    else if (numLeft % 10 == 2 && left == 2)
    {
      numLeft = ((numLeft / 100) * 10) + 1;
    }
    else
    {
      numLeft = numLeft / 10;
    }

  }

  if(numRight % 10 == 1)
  {
    numRight = ((numRight / 10) * 10) + 2;
  }
  else if (numRight % 10 == 2)
  {
    numRight = ((numRight / 10) * 10) + 1;
  }

  while(numRight > 0)
  {
    right = numRight % 10;

    if((rHolder == 1 && right != 1) || (rHolder == 2 && right != 2))
    {
      numRight = numRight / 10;
    }
    else if( right == 1 && rHolder == 1)
    {
      numRight = ((numRight / 10) * 10) + 2;
    }
    else if  (right == 2 && rHolder == 2)
    {
      numRight = ((numRight / 10) * 10) + 1;
    }
    else
    {
      numRight = numRight / 10;
    }

    if(right == 1 && rHolder == 1)
    {
      changesRight++;
    }
    else if(right == 2 && rHolder == 2)
    {
      changesRight++;
    }

    rHolder = right;

  }

  if(changesLeft < changesRight)
  {
    changes = changesLeft;
  }
  else if(changesRight <= changesLeft)
  {
    changes = changesRight;
  }

  return changes;

}

/*****+---***----**----**-***-***-*--*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: output
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int changes - the number of changes required to make the inputted
 *       number one that consists of alternating 1s and 2s
 *
 *  Function Description: This function returns the fewest number of required
 *  changes to make the inputted number one that consists of alternating 1s
 *  and 2s to the user.
 *
 ******+---***----**----**-***-***-*--*-*****--*****************************/

void output(int changes)
{
  printf("Fewest # of required changes: %d",changes);
}
