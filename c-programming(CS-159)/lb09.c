/*****+*-----*--*-**---*-*******--*--*-*****--******************************
 *
 *  Lab #:09
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description: Given a positive integer value as a starting point the code will determine the next integer, starting
 *  with the value input that is either a perfect square or a semi-square. It will then print out that integer and its status.
 *
 ******+*-----*--*-**---*-*******--*--*-*****--*****************************/
#include <stdio.h>
#include <math.h>

void input(int*);
int squareCalc(int,int*,int*);
int checkFactor(int);
void output(int,int,int);

int main(void)
{
  int user_input; //user inputted starting number
  int num; //final square or semi-square number
  int square; //logical value for whether calculated number is a square
  int semi; //logical value for whether calculated number is a semi-square

  input(&user_input);
  //calls function to figure out identified value that fits the criteria and assigns it to a variable
  num = squareCalc(user_input,&square,&semi);
  //outputs value and if it's a perfect square or semi-square
  output(num,square,semi);

  return(0);
}

/*****+----*----***---**--***--**----*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: input
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int*, user, user inputted number
 *
 *  Function Description: Prompts the user to input a positive integer value and if the value isn't
 *  valid it will print an error and then keep running until the input is valid.
 *
 ******+----*----***---**--***--**----*-*****--*****************************/

void input(int* user)
{

  printf("Enter starting value -> ");
  scanf("%d", user);

  while (*user <= 0) //while loop if the input is not a positive integer
  {
    printf("\nError! Positive values only!\n");
    printf("\nEnter starting value -> ");
    scanf("%d", user);
  }

}

/*****+-*-***-*--**---**--***--**----*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: squareCalc
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int, user, user inputted number
 *    2. int*, square, logical value for if the number is a square
 *    3. int*, semi, logical value for if the number is a semi-square
 *
 *  Function Description: Given the passed parameters, it will calculate the next integer that is either a square or a
 *  semi-square such that the number entered is equal to the product of the square of a second integer and a third integer
 *  where the third integer is greater than 1 and less than the second integer.
 *
 ******+-*-***-*--**---**--***--**----*-*****--*****************************/

int squareCalc(int user,int* square,int* semi)
{
  int count; //counter for factor being evaluated
  int sqFact1; //logical value for if the factor is a square
  int sqFact2; //logical value for if the second factor is a square
  int factor1; //first factor of the number being evaluated
  int factor2; //second factor of the number being evaluated

  count = 1;
  *square = 0;
  *semi = 0;

  while (*square == 0 && *semi == 0) 
  {
    while(count <= user)  //continues to loop if count is less than or equal to the user's input
    {
      if (user % count == 0) 
      {
        factor1 = user / count; 
        sqFact1 = checkFactor(factor1);
        
        factor2 = user / factor1;
        sqFact2 = checkFactor(factor2);
        
        if (factor2 == factor1)
        {
          *square = 1; // identifies that the integer is a perfect square
          count = user + 1; // value of the perfect square
        }

        else if (sqFact1 != 0 || sqFact2 != 0)
        {

          if(sqFact1 != 0)
          {

            if (factor2 > 1 && factor2 < sqrt(factor1)) 
            {
              /* identifies if the value is a valid semi-square if the second factor 
              is greater than one and less than the square root of the first factor */

              *semi = 1;
              
              if(*square != 1 && count == user)
              {
                count = user + 1;
              }
            }
          }

          else if(sqFact2 != 0)
          {
            if (factor1 > 1 && factor1 < sqrt(factor2)) 
            {
              /* identifies if the value is a valid semi-square if the first factor is
              greater than one and less than the square root of the second factor */

              *semi = 1; 
              
              if(*square != 1 && count == user)
              {
                count = user + 1;
              }
            }

          }

        }
      }

      count++; //updates the count after running all statements in the body
      
    }

    if(*square == 0 || *semi == 0)
    {
      count = 1;
      user++;
    }

  }

  return(factor1 * factor2);
}

/*****+-*-***-*--**---**--***--**----*-*****--******************************
 *
 *  Function Information
 *
 *  Name of Function: checkFactor
 *
 *  Function Return Type: int
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int, num, one factor of the number being checked
 *
 *  Function Description: This segment utilizes truncation and  checks if the inputted number is a perfect square 
 *  by comparing its decimal root to its integer root. 
 *
 ******+-*-***-*--**---**--***--**----*-*****--*****************************/

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

/*****+-*--**-*--**-*--**--*---**----*-*****--******************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, value, value of the semi or perfect square
*    2. int, perfSquare, logical value to check if number is perfect square
*    3. int, semiSquare, logical value to check if number is semi square
*
*  Function Description: Prints the output of the next integer and states if it is a semi-square or perfect square.
*
******+-*--**-*--**-*--**--*---**----*-*****--*****************************/

void output(int value, int perfSquare, int semiSquare)
{
  //prints the identified value and its status

  printf("\n");
  printf("Identified value: %d\n",value);

  if(perfSquare == 1)
  {
    printf("Status: Perfect square\n");
  }
  else if(semiSquare == 1)
  {
    printf("Status: Semi-square");
  }
}
