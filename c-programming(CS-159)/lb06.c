/*****+*---*--****-*****-**--*--*-*-********--******************************
 *
 *  Lab #:6
 *
 *  Academic Integrity Statement:
 *
 *  I have not used source code obtained from any other unauthorized source, 
 *  either modified or unmodified.  Neither have I provided access to my code 
 *  to another. The effort I am submitting is my own original work.
 *
 *  Program Description:this program accepts four user inputs of four
 *  potential triangle sizes and outputs the max and min areas of them, or 
 *  an error.
 *
 ******+*---*--****-*****-**--*--*-*-********--*****************************/
#include <stdio.h>
#include <math.h>

void get_input(double*,double*,double*,double*);
double min_logic(double,double,double,double);
double max_logic(double,double,double,double);
double min_area_calculator(double,double,double,double,double);
double max_area_calculator(double, double, double, double, double);
void small_outputs(double,double,double,double,double,double,double,int);
int big_outputs(double,double,double,double,double,double,double);

int main (void)
{
  double side_1; //first side of triangle
  double side_2; //second side of triangle
  double side_3; //third side of triangle
  double side_4; //fourth side of triangle
  double biggest_length; //largest side length
  double smallest_length; //smallest side length
  double min_area; //minimum triangle area
  double max_area; //maximum triangle area
  int valid_inputs; //logic checker to see whether to proceed with min_area function

  get_input(&side_1,&side_2,&side_3,&side_4);
  biggest_length = min_logic(side_1,side_2,side_3,side_4);
  smallest_length = max_logic(side_1,side_2,side_3,side_4);

  max_area = max_area_calculator(smallest_length, side_1, side_2, side_3, side_4);
  min_area = min_area_calculator(biggest_length, side_1, side_2, side_3, side_4);

  valid_inputs = big_outputs(smallest_length, side_1, side_2, side_3, side_4,max_area,min_area);

  small_outputs(biggest_length, side_1, side_2, side_3, side_4,min_area,max_area,valid_inputs); 

  return 0;
}

/*****+----*--*-**--*-***-**--**----********--******************************
 *
 *  Function Information
 *
 *  Name of Function:get_input
 *
 *  Function Return Type:void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double*,side1,user input of first side
 *    2. double*,side2,user input of second side
 *    3. double*,side3,user input of third side
 *    4. double*,side4,user input of fourth side
 *
 *  Function Description: this function uses pass by address to get the 
 *  four user inputs.
 *
 ******+----*--*-**--*-***-**--**----********--*****************************/

void get_input(double* side_1, double* side_2, double* side_3, double* side_4)
{

  printf("Enter length of side #1 -> ");
  scanf("%lf",side_1);
  printf("Enter length of side #2 -> ");
  scanf("%lf",side_2);
  printf("Enter length of side #3 -> ");
  scanf("%lf",side_3);
  printf("Enter length of side #4 -> ");
  scanf("%lf",side_4);

}

/*****+---***---**--*-***-**--**----********--******************************
 *
 *  Function Information
 *
 *  Name of Function: min_logic
 *
 *  Function Return Type: double
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double,side1,first side of triangle
 *    2. double,side2,second side of triangle
 *    3. double,side3,third side of triangle
 *    4. double,side4,fourth side of triangle
 *
 *  Function Description: this function calculates the largest side of 
 *  the four inputted.
 *
 ******+---***---**--*-***-**--**----********--*****************************/

double min_logic(double side1,double side2,double side3,double side4)
{

  double biggest; //biggest triangle side
  // logic checker for largest sides
  if (side1 >= side2 && side1 >= side3 && side1 >= side4)
  {
    biggest = side1;

  }
  else if (side2 >= side1 && side2 >= side3 && side2 >= side4)
  {
    biggest = side2;

  }
  else if (side3 >= side1 && side3 >= side2 && side3 >= side4)
  {
    biggest = side3;

  }
  else if (side4 >= side1 && side4 >= side2 && side4 >= side3)
  {
    biggest = side4;

  }

  else
  {
    printf("Inputs are invalid.");
  }

  return biggest;

}

/*****+---***---**--*-***-**--**----********--******************************
 *
 *  Function Information
 *
 *  Name of Function: max_logic
 *
 *  Function Return Type: double
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double,side1,first side of triangle
 *    2. double,side2,second side of triangle
 *    3. double,side3,third side of triangle
 *    4. double,side4,fourth side of triangle
 *
 *  Function Description: this function calculates the smallest side of 
 *  the four inputted sides.
 *
 ******+---***---**--*-***-**--**----********--*****************************/

double max_logic(double side1,double side2,double side3,double side4)
{

  double smallest; //smallest triangle side
  //logic checker to find smallest sides
  if (side1 <= side2 && side1 <= side3 && side1 <= side4)
  {
    smallest = side1;

  }
  else if (side2 <= side1 && side2 <= side3 && side2 <= side4)
  {
    smallest = side2;

  }
  else if (side3 <= side1 && side3 <= side2 && side3 <= side4)
  {
    smallest = side3;

  }
  else if (side4 <= side1 && side4 <= side2 && side4 <= side3)
  {
    smallest = side4;
  }

  else
  {
    printf("Inputs are invalid.");
  }

  return smallest;

}

/*****+-*--*-----**-*-***-**--**----********--******************************
 *
 *  Function Information
 *
 *  Name of Function:min_area_calculator
 *
 *  Function Return Type:double
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double,biggest,biggest side of triangle
 *    2. double,side1,first side of triangle
 *    3. double,side2,second side of triangle
 *    4. double,side3,third side of triangle
 *    5. double,side4,fourth side of triangle
 *
 *  Function Description: this function calculates the minimum area of a 
 *  triangle using its semi perimeter and largest sides.
 *
 ******+-*--*-----**-*-***-**--**----********--*****************************/

double min_area_calculator(double biggest, double side1, double side2, double side3, double side4)
{

  double semi_perimeter; //semi perimeter of triangle
  double area_triangle; //area of triangle

  if (side1 == biggest)
  { //checks if triangle has valid dimensions
    if (side2 + side3 > side4 && side2 + side4 > side3 && side3 + side4 > side2)
    {
      semi_perimeter = (side2 + side3 + side4) / 2.0;
      area_triangle = sqrt(semi_perimeter * (semi_perimeter - side2) * (semi_perimeter - side3) * (semi_perimeter - side4));   
    }
    else
    {
      area_triangle = 0;
    }
  }

  else if (side2 == biggest)
  { //checks if triangle has valid dimensions
    if (side1 + side3 > side4 && side1 + side4 > side3 && side3 + side4 > side1)
    {
      semi_perimeter = (side1 + side3 + side4) / 2.0;
      area_triangle = sqrt(semi_perimeter * (semi_perimeter - side1) * (semi_perimeter - side3) * (semi_perimeter - side4));
    }
    else
    {
      area_triangle = 0;
    }
  }

  else if (side3 == biggest)
  { //checks if triangle has valid dimensions
    if (side1 + side2 > side4 && side2 + side4 > side1 && side1 + side4 > side2)
    {
      semi_perimeter = (side1 + side2 + side4) / 2.0;
      area_triangle = sqrt(semi_perimeter * (semi_perimeter - side1) * (semi_perimeter - side2) * (semi_perimeter - side4));
    }
    else
    {
      area_triangle = 0;
    }
  }

  else if (side4 == biggest)
  { //checks if triangle has valid dimensions
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
    {
      semi_perimeter = (side1 + side2 + side3) / 2.0;
      area_triangle = sqrt(semi_perimeter * (semi_perimeter - side1) * (semi_perimeter - side2) * (semi_perimeter - side3));
    }
    else
    {
      area_triangle = 0;
    }
  }

  return area_triangle;
}

/*****+-*--*-----**-*-***-**--**----********--******************************
 *
 *  Function Information
 *
 *  Name of Function:max_area_calculator
 *
 *  Function Return Type:double
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double,smallest,smallest side of triangle
 *    2. double,side1,first side of triangle
 *    3. double,side2,second side of triangle
 *    4. double,side3,third side of triangle
 *    5. double,side4,fourth side of triangle
 *
 *  Function Description: this function calculates the max area of a 
 *  triangle using its semi perimeter and largest sides.
 *
 ******+-*--*-----**-*-***-**--**----********--*****************************/

double max_area_calculator(double smallest, double side1, double side2, double side3, double side4)
{

  double semi_perimeter; //semi perimeter of triangle
  double area_triangle; //area of triangle

  if (side1 == smallest)
  { //checks if triangle has valid dimensions
    if (side2 + side3 > side4 && side2 + side4 > side3 && side3 + side4 > side2)
    {
      semi_perimeter = (side2 + side3 + side4) / 2.0;
      area_triangle = sqrt(semi_perimeter * (semi_perimeter - side2) * (semi_perimeter - side3) * (semi_perimeter - side4));
    }
    else
    {  
      area_triangle = 0;
    }
  }

  else if (side2 == smallest)
  { //checks if triangle has valid dimensions
    if (side1 + side3 > side4 && side1 + side4 > side3 && side2 + side4 > side1)
    {
      semi_perimeter = (side1 + side3 + side4) / 2.0;
      area_triangle = sqrt(semi_perimeter * (semi_perimeter - side1) * (semi_perimeter - side3) * (semi_perimeter - side4));
    }
    else
    {  
      area_triangle = 0;
    }
  }

  else if (side3 == smallest)
  { //checks if triangle has valid dimensions
    if (side1 + side2 > side4 && side1 + side4 > side2 && side2 + side4 > side1)
    {
      semi_perimeter = (side1 + side2 + side4) / 2.0;
      area_triangle = sqrt(semi_perimeter * (semi_perimeter - side1) * (semi_perimeter - side2) * (semi_perimeter - side4));
    }
    else
    {
      area_triangle = 0;
    }
  }

  else if (side4 == smallest)
  { //checks if triangle has valid dimensions
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
    {
      semi_perimeter = (side1 + side2 + side3) / 2.0;
      area_triangle = sqrt(semi_perimeter * (semi_perimeter - side1) * (semi_perimeter - side2) * (semi_perimeter - side3));
    }
    else
    {  
      area_triangle = 0;
    }
  }

  return area_triangle;

}

/*****+-*-***-*-**--*-***-**--**----********--******************************
 *
 *  Function Information
 *
 *  Name of Function:small_outputs
 *
 *  Function Return Type:void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double,biggest,biggest side of triangle
 *    2. double,side1,first side of triangle
 *    3. double,side2,second side of triangle
 *    4. double,side3,third side of triangle
 *    5. double,side4,fourth side of triangle
 *    6. double,s_area,small triangle area
 *    7. double,b_area,large triangle area
 *    8. int,valid,checks to display error message
 *
 *  Function Description: this function displays areas of two triangles
 *  based on what their dimensions are and does not display an error
 *  message, because only one is needed from the large area output
 *  function.
 *
 ******+-*-***-*-**--*-***-**--**----********--*****************************/

void small_outputs (double biggest, double side1, double side2, double side3, double side4, double s_area, double b_area,int valid)
{
  if (valid != 0) //checks whether to continue the program
  { 
    printf("\n");

    if (side1 == biggest) //begins logic to check what to output
    {
      if (s_area == 0 && b_area != 0)
      {
        printf("Smallest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side2,side3,side4);
      }
      else if (s_area != 0 && b_area == 0)
      {
        printf("Smallest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side2,side3,side4);
      }
      else
      {
        printf("Smallest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side2,side3,side4);
      }
    }

    else if (side2 == biggest)
    {
      if (s_area == 0 && b_area != 0)
      {
        printf("Smallest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side3,side4);
      }
      else if (s_area != 0 && b_area == 0)
      {
        printf("Smallest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side3,side4);
      }
      else
      {
        printf("Smallest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side3,side4);
      }
    }

    else if (side3 == biggest)
    {
      if (s_area == 0 && b_area != 0)
      {
        printf("Smallest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side4);
      }
      else if (s_area != 0 && b_area == 0)
      {
        printf("Smallest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side4);
      } 
      else
      {
        printf("Smallest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side4);
      }
    }

    else if (side4 == biggest)
    {
      if (s_area == 0 && b_area != 0)
      {
        printf("Smallest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side3);
      }
      else if (s_area != 0 && b_area == 0)
      {
        printf("Smallest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side3);
      }
      else
      {
        printf("Smallest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side3);
      }
    }
  } //end of valid checker
} //end of function

/*****+-*-***-*-**--*-***-**--**----********--******************************
 *
 *  Function Information
 *
 *  Name of Function:small_outputs
 *
 *  Function Return Type:void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double,biggest,biggest side of triangle
 *    2. double,side1,first side of triangle
 *    3. double,side2,second side of triangle
 *    4. double,side3,third side of triangle
 *    5. double,side4,fourth side of triangle
 *    6. double,s_area,small triangle area
 *    7. double,b_area,large triangle area
 *
 *  Function Description: this function displays areas of two triangles
 *  based on what their dimensions are and displays an error if the
 *  dimensions are invalid.
 *
 ******+-*-***-*-**--*-***-**--**----********--*****************************/

int big_outputs (double smallest, double side1, double side2, double side3, double side4, double s_area, double b_area)
{
  int valid; //checks if there is an error message
  { 
    printf("\n");

    if (side1 == smallest)
    {

      if (b_area == 0 && s_area == 0)
      { 
        printf("Error: No triangles can be created from lengths given!\n");
        valid = 0;
      }
      else if (s_area == 0 && b_area != 0)
      {
        printf("Largest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side2,side3,side4);
        valid = 1;
      }
      else if (s_area != 0 && b_area == 0)
      {
        printf("Largest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side2,side3,side4);
        valid = 1;
      }
      else
      {
        printf("Largest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side2,side3,side4);
        valid = 1;
      }
    }
    else if (side2 == smallest)
    {
      if (b_area == 0 && s_area == 0)
      { 
        printf("Error: No triangles can be created from lengths given!\n");
        valid = 0;
      }
      else if (s_area == 0 && b_area != 0)
      {
        printf("Largest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side3,side4);
        valid = 1;
      }
      else if (s_area != 0 && b_area == 0)
      {
        printf("Largest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side3,side4);
        valid = 1;
      }
      else
      {
        printf("Largest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side3,side4);
        valid = 1;
      }
    }
    else if (side3 == smallest)
    {
      if (b_area == 0 && s_area == 0)
      { 
        printf("Error: No triangles can be created from lengths given!\n");
        valid = 0;
      }
      else if (s_area == 0 && b_area != 0)
      {
        printf("Largest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side4);
        valid = 1;
      }
      else if (s_area != 0 && b_area == 0)
      {
        printf("Largest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side4);
        valid = 1;
      }
      else
      {
        printf("Largest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side4);
        valid = 1;
      }
    }
    else if (side4 == smallest)
    {
      if (b_area == 0 && s_area == 0)
      { 
        printf("Error: No triangles can be created from lengths given!\n");
        valid = 0;
      }
      else if (s_area == 0 && b_area != 0)
      {
        printf("Largest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side3);
        valid = 1;
      }
      else if (s_area != 0 && b_area == 0)
      {
        printf("Largest possible triangle area: %.2lf\n",s_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side3);
        valid = 1;
      }
      else
      {
        printf("Largest possible triangle area: %.2lf\n",b_area);
        printf("Side values used: %.1lf, %.1lf, %.1lf\n",side1,side2,side3);
        valid = 1;
      }
    }
  }
  return valid;
}
