/*****+-*--*--*--*----***-***-***-*--*-*-*-**-******************************
*
*  Homework #: 03
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program uses 6 user-defined-functions using
*  pass by address and pass by value to get user inputs, convert inputs
*  to factorial form, calculate probability of situations given the 
*  inputs, and display the results.
*
******+-*--*--*--*----***-***-***-*--*-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>
#define ZERO 0
 
void get_inputs(double*,int*,int*);
void placeholder(double*,double*,double*,double*,int*,int,int);
void factorial_converter(double*,double*,double*,double*);
double probability_calculator(double,int,int,double,double,double);
double perfect_calculator(double,double,double);
void output(int,int,int,double,double,double);

int main (void)
{
  double percent_defective; //percent of defective units (to be converted to a decimal later)
  int sample_size; //number of units to sample
  int defective_units; //number of defective units
  double ss_factorial; //sample size expressed as a factorial
  double du_factorial; //defective units expressed as a factorial
  double d_factorial; //difference of ss_factorial and du_factorial (used in factorial_converter)
  double du_perfect; //perfect number of defective units expressed in factorial form (0!)
  int no_defects; //number of defective units for perfect batch calculations
  double perfect_probability; //probability of a perfect batch
  double defective_probability; //probability of a defective batch

  get_inputs(&percent_defective,&sample_size,&defective_units);

  placeholder(&ss_factorial,&du_factorial,&d_factorial,&du_perfect,&no_defects,sample_size,defective_units);
    
  factorial_converter(&ss_factorial,&du_factorial,&d_factorial,&du_perfect);
  
  perfect_probability = perfect_calculator(percent_defective,sample_size,du_perfect);

  defective_probability = probability_calculator(percent_defective,sample_size,defective_units,ss_factorial,du_factorial,d_factorial);

  output(sample_size,no_defects,defective_units,percent_defective,perfect_probability,defective_probability);

  return 0;
}

/*****+---**--*--**-*-***--*---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: get_inputs
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double*,percent_defective,percent of defective units (to be 
*    converted to a decimal later)
*    2. int *,sample_size,number of units to sample
*    3. int*,defective_units,number of defective units
*
*  Function Description: this function uses pass by address to get 
*  user inputs and assign them to variables.
*
******+---**--*--**-*-***--*---*-----*-*-*-**-*****************************/

void get_inputs(double* percent_defective,int * sample_size,int* defective_units)
{
  printf("Enter percentage of defective units produced -> ");
  scanf("%lf",percent_defective);
  printf("Enter number of units to sample -> ");
  scanf("%d",sample_size);
  printf("Enter number of defective units in sample -> ");
  scanf("%d",defective_units);
}

/*****+---**--*--**-*-***--*---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: placeholder
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double*,ss_factorial,factorial of sample size
*    2. double*,du_factorial,factorial of defective units
*    3. double*,d_factorial,difference between ss and du factorial
*    4. double*,du_perfect,factorial of no defective units
*    5. int*,no_defects,number of units for a perfect batch
*    6. int,a,sample size
*    7. int,b,defective units
*
*  Function Description: this function  uses pass by address to assign
*  numbers to four variables that will later be converted to factorial 
*  values.
*
******+---**--*--**-*-***--*---*-----*-*-*-**-*****************************/

void placeholder(double* ss_factorial,double* du_factorial,double* d_factorial,double* du_perfect,int* no_defects,int a,int b)
{

  *ss_factorial = a;
  *du_factorial = b;
  *d_factorial = *ss_factorial - *du_factorial;
  *du_perfect = ZERO;
  *no_defects = ZERO;
}

/*****+-*--*--*--**-*-***--*---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: factorial_converter
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double*,ss_factorial,factorial of sample size
*    2. double*,du_factorial,factorial of defective units
*    3. double*,d_factorial,difference between ss and du factorial
*    4. double*,du_perfect,factorial of no defective units
*
*  Function Description: this function uses pass by address to convert the
*  placeholder values previously assigned to their factorials, using two
*  integers representing the number of defective units and sample size,
*  which are passed by value.
*
******+-*--*--*--**-*-***--*---*-----*-*-*-**-*****************************/

void factorial_converter(double* ss_factorial,double* du_factorial,double* d_factorial,double* du_perfect)
{   

  *ss_factorial = (pow(*ss_factorial,*ss_factorial) * exp(-1 * *ss_factorial)) * sqrt((2 * *ss_factorial + (1.0 / 3.0)) * M_PI);
  *du_factorial = (pow(*du_factorial,*du_factorial) * exp(-1 * *du_factorial)) * sqrt((2 * *du_factorial + (1.0 / 3.0)) * M_PI);
  *d_factorial = (pow(*d_factorial,*d_factorial) * exp(-1 * *d_factorial)) * sqrt((2 * *d_factorial + (1.0 / 3.0)) * M_PI);
  *du_perfect = (pow(*du_perfect,*du_perfect) * exp(-1 * *du_perfect)) * sqrt((2 * *du_perfect + (1.0 / 3.0)) * M_PI);
}

/*****+-*--*--*--**-*-***--*---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: probability_calculator
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double,u,percent of defective units
*    2. int,v,sample size
*    3. int,w,number of defective units
*    4. double,x,factorial of sample size
*    5. double,y,factorial of defective units
*    6. double,z,factorial of difference between sample size and defective
*    units
*
*  Function Description: this function combines the factorial values and
*  non factorial values to plug into a binomial distribution formula and
*  return the probability of the event, using pass by value.
*
******+-*--*--*--**-*-***--*---*-----*-*-*-**-*****************************/

double probability_calculator(double u, int v, int w, double x, double y, double z)
{
  double probability; //probability of an event with w defective units 

  probability = (x / (y * z)) * (pow((u / 100),w)) * (pow(1 - (u / 100),v - w));

  return probability;
}

/*****+-*--*--*--**-*-***--*---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: perfect_calculator
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double,x,percent of defective units
*    2. double,y,sample size
*    3. double,z,factorial of number of defective units in a perfect batch
*
*  Function Description: this function is a binomial distribution 
*  calculator like the previous, but it simplifies the formula given
*  that many values will cancel with 0 defective units. The function
*  calculates the probability of an event given there are 0 defective
*  units, using pass by value, and returns the probability.
*
******+-*--*--*--**-*-***--*---*-----*-*-*-**-*****************************/

double perfect_calculator(double x,double y,double z)
{

  double probability; //probability of an event with 0 defective units

  probability = (1 / z) * pow(1 - (x / 100),y);

  return probability;

}

/*****+-*--*--*--**-*-***--*---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int,ss,sample size
*    2. int,nd,number of defective units in a perfect batch
*    3. int,du,number of defective units
*    4. double,pd,percent of defective units
*    5. double,pp,probability of an event happening with a perfect batch
*    6. double,dp,probability of an event happening with a number of 
*    defective units
*
*  Function Description: this function takes the final values to be
*  displayed and prints the  percent rounded to two decimals, number of
*  units as an integer, and probability rounded to three decimals.
*
******+-*--*--*--**-*-***--*---*-----*-*-*-**-*****************************/

void output(int ss, int nd, int du, double pd, double pp, double dp)
{

  printf("\n");
  printf("Average number of defective units: %.2f%%\n",pd);

  printf("Selecting %d units with %d being defective has a probability of: %.3lf\n",ss,nd,pp);

  printf("Selecting %d units with %d being defective has a probability of: %.3lf\n",ss,du,dp);

}
