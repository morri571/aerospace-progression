/*****+---***---***-*-***-***--*--*-********--******************************
 *
 *  Homework #:
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description:
 *
 ******+---***---***-*-***-***--*--*-********--*****************************/
#include <stdio.h>
#include <math.h>
#define HATH_SEPTEMBER 30 //constant for all 30 day months (from a rhyme)
#define HATH_OTHERS 31 //constant for 31 day months 
#define FEB_REG 28 //constant for days in February
#define FEB_LEAP 29 //constant for days in February in a leap year
#define REG_YEAR 365 //constant for days in regular year
#define LEAP_YEAR 366 //constant for days in leap year

void get_input(int*);
void digit_extractor(int,int*,int*,int*);
void error();
int day_month_counter(int,int,int);
int day_year_counter(int,int,int,int);
void output(int,int);

int main (void)
{

  int date; //date expressed as MMDDYYYY
  int day_num; //day expressed in two digits
  int month_num; //month expressed in two digits
  int year_num; //year expressed in four digits
  int month_days_remain; //number of days remaining in the given month
  int year_days_remain; //number of days remaining in the given year
  
  //default functions
  get_input(&date);
 
  digit_extractor(date,&day_num,&month_num,&year_num);

  //functions dependent on whether values from previous functions work
  if ((day_num > 31 || day_num < 1 || month_num > 12 || month_num < 1 || year_num < 1)) //checks for valid inputs
  {
    error();
  }
  else
  {
    month_days_remain = day_month_counter(day_num,month_num,year_num);

    year_days_remain = day_year_counter(day_num,month_num,year_num,month_days_remain);
    
    output(month_days_remain,year_days_remain);
  }

  return 0;

}

/*****+-*-***----**-*--*---**--**-*--*******--******************************
*
*  Function Information
*
*  Name of Function: get_input
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int*,date,inputted date expressed in eight digits (MMDDYY)
*    2.
*    3.
*
*  Function Description: uses pass by address to assign the user input
*  to variable date.
*
******+-*-***----**-*--*---**--**-*--*******--*****************************/

void get_input(int* date)
{

  printf("Enter a date in the form MMDDYYYY -> ");
  scanf("%d",date);

}

/*****+-*-***----**-*--*---**--**-*--*******--******************************
*
*  Function Information
*
*  Name of Function: digit_extractor
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,mmddyyyy,inputted date by user
*    2. int*,day_num,day of the inputted date
*    3. int*,month_num,month of inputted date
*    4. int*,year_num,year of inputted date
*
*  Function Description: this function uses integer division and integer
*  modulus to extract individual components of the date.
*
******+-*-***----**-*--*---**--**-*--*******--*****************************/

void digit_extractor(int mmddyyyy,int* day_num,int* month_num,int* year_num)
{

  *year_num = mmddyyyy % 10000;
  mmddyyyy /= 10000;
  *day_num = mmddyyyy % 100;
  mmddyyyy /= 100;
  *month_num = mmddyyyy;

}

/*****+---***----**-*--*---**--**-*--*******--******************************
*
*  Function Information
*
*  Name of Function: day_month_counter
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,day,day of the inputted date
*    2. int,month,month of the inputted date
*    3. int,year,year of the inputted date
*
*  Function Description: uses switch and if else to first determine whether
*  the inputted year is a leap year, and calculates the remaining days
*  based off of a switch statement.
*
******+---***----**-*--*---**--**-*--*******--*****************************/

int day_month_counter(int day,int month, int year)
{
  int month_days; //number of days in given month

  if (month == 2)
  {
    if (((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) //leap year checker
    {
      month = 13;
    }
    else
    {
      month = 2;
    }
  }

  switch (month)
  {
    case  2:  month_days = FEB_REG;
              break;
    case 13: month_days = FEB_LEAP; //13 represents leap year February
             break;
    case  4:
    case  6:
    case  9:
    case 11: month_days = HATH_SEPTEMBER;
             break;
    default: month_days = HATH_OTHERS; //default is for 31 day months because it has the most corresponding numbers
  }

  month_days = month_days - day;

  return month_days;
}

/*****+---***----**-*--*---**--**-*--*******--******************************
*
*  Function Information
*
*  Name of Function: day_year_counter
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,day,day of the inputted date
*    2. int,month,month of the inputted date
*    3. int,year,year of the inputted date
*    4. int,remain_month,the number of days remaining in the inputted month
*
*  Function Description: this function calculates the number of days 
*  remaining in the year by checking if the input is a leap year, and then
*  adds up the number of months depending on the month the user inputted.
*  After adding up the months to the point of the input, the function
*  takes the difference between that and the remaining days in the month,
*  and subtracts that number from 365 or 366 to get the number of days 
*  remaining in the year.
*
******+---***----**-*--*---**--**-*--*******--*****************************/

int day_year_counter(int day,int month,int year,int remain_month)
{

  int day_format; //day formatted out of 365 or 366 days

  if (!((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
  { //this logic chain is for non leap years and adds up the days in each month up until the inputted month
    if (month == 1)
    {
      day_format = REG_YEAR - (HATH_OTHERS - remain_month);
    }
    else if (month == 2)
    {
      day_format = REG_YEAR - ((HATH_OTHERS + FEB_REG) - remain_month);
    }
    else if (month == 3)
    {
      day_format = REG_YEAR - ((2 * HATH_OTHERS + FEB_REG) - remain_month);
    }
    else if (month == 4)
    {
      day_format = REG_YEAR - ((2 * HATH_OTHERS + FEB_REG + HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 5)
    {
      day_format = REG_YEAR - ((3 * HATH_OTHERS + FEB_REG + HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 6)
    {
      day_format = REG_YEAR - ((3 * HATH_OTHERS + FEB_REG + 2 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 7)
    {
      day_format = REG_YEAR - ((4 * HATH_OTHERS + FEB_REG + 2 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 8)
    {
      day_format = REG_YEAR - ((5 * HATH_OTHERS + FEB_REG + 2 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 9)
    {
      day_format = REG_YEAR - ((5 * HATH_OTHERS + FEB_REG + 3 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 10)
    {
      day_format = REG_YEAR - ((6 * HATH_OTHERS + FEB_REG + 3 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 11)
    {
      day_format = REG_YEAR - ((6 * HATH_OTHERS + FEB_REG + 4 *  HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 12)
    {
      day_format = REG_YEAR - ((7 * HATH_OTHERS + FEB_REG + 4 * HATH_SEPTEMBER) - remain_month);
    }

  }  

  else if(((year % 4 == 0 && year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
  { //this logic chain is for leap years and adds up the days in each month up until the inputted month
    if (month == 1)
    {
      day_format = LEAP_YEAR - (HATH_OTHERS - remain_month);
    }
    else if (month == 2)
    {
      day_format = LEAP_YEAR - ((HATH_OTHERS + FEB_LEAP) - remain_month);
    }
    else if (month == 3)
    {
      day_format = LEAP_YEAR - ((2 * HATH_OTHERS + FEB_LEAP) - remain_month);
    }
    else if (month == 4)
    {
      day_format = LEAP_YEAR - ((2 * HATH_OTHERS + FEB_LEAP + HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 5)
    {
      day_format = LEAP_YEAR - ((3 * HATH_OTHERS + FEB_LEAP + HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 6)
    {
      day_format = LEAP_YEAR - ((3 * HATH_OTHERS + FEB_LEAP + 2 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 7)
    {
      day_format = LEAP_YEAR - ((4 * HATH_OTHERS + FEB_LEAP + 2 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 8)
    {
      day_format = LEAP_YEAR - ((5 * HATH_OTHERS + FEB_LEAP + 2 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 9)
    {
      day_format = LEAP_YEAR - ((5 * HATH_OTHERS + FEB_LEAP + 3 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 10)
    {
      day_format = LEAP_YEAR - ((6 * HATH_OTHERS + FEB_LEAP + 3 * HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 11)
    {
      day_format = LEAP_YEAR - ((6 * HATH_OTHERS + FEB_LEAP + 4 *  HATH_SEPTEMBER) - remain_month);
    }
    else if (month == 12)
    {
      day_format = LEAP_YEAR - ((7 * HATH_OTHERS + FEB_LEAP + 4 * HATH_SEPTEMBER) - remain_month);
    }

  }

  return day_format;

}

/*****+-*--**----**-*--*---**--**-*--*******--******************************
*
*  Function Information
*
*  Name of Function: error
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: this function prints an error message when it is
*  called.
*
******+-*--**----**-*--*---**--**-*--*******--*****************************/

void error()
{
  //only called when month/day/year is invalid  
  printf("\n");
  printf("Error: Date entered is not valid!");

}

/*****+-*--**----**-*--*---**--**-*--*******--******************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,remain_month,number of days remaining in the month
*    2. int,remain_year,number of days remaining in the year
*    3.
*
*  Function Description: this function displays the final calculated
*  remaining days in the month and remaining days in the year.
*
******+-*--**----**-*--*---**--**-*--*******--*****************************/

void output(int remain_month,int remain_year)
{
  if(remain_month <= -1 || remain_year <= -1) //another fail-safe for improper values
  {
    error();
  }
  else
  {
    printf("\n");
    printf("Days remaining in current month: %d\n",remain_month);
    printf("Days remaining in current year: %d",remain_year);
  }

}
