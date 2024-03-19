/*****+---***---**----***--*---*----**-*-*-**-******************************
*
*  Lab #:4
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program uses user defined functions to get
*  user inputs of three vertices of a triangle, and outputs the distances
*  between the vertices and outputs their angles.
*
******+---***---**----***--*---*----**-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>
#define DEGTORAD 180 / M_PI

double distance_calculator(double, double, double, double);
double angle_calculator(double, double, double);

int main (void)
{

  double x1; // x-coordinate of the first point
  double y1; // y-coordinate of the first point
  double x2; // x-coordinate of the second point
  double y2; // y-coordinate of the second point
  double x3; // x-coordinate of the third point
  double y3; // y-coordinate of the third point
  double distance_1; // first side length of the triangle
  double distance_2; // second side length of the triangle
  double distance_3; // third side length of the triangle
  double angle_1; // first angle of the triangle
  double angle_2; // second angle of the triangle
  double angle_3; // third angle of the triangle

  printf("Enter coordinates for point #1 -> ");
  scanf("%lf %lf",&x1,&y1);
  printf("Enter coordinates for point #2 -> ");
  scanf("%lf %lf",&x2,&y2);
  printf("Enter coordinates for point #3 -> ");
  scanf("%lf %lf",&x3,&y3);
 
  distance_1 = distance_calculator(x1,y1,x2,y2);
  distance_2 = distance_calculator(x2, y2, x3, y3);
  distance_3 = distance_calculator(x1, y1, x3, y3);

  angle_1 = angle_calculator(distance_1, distance_2, distance_3);
  angle_2 = angle_calculator(distance_2, distance_1, distance_3);
  angle_3 = angle_calculator(distance_3, distance_2, distance_1);

  printf("\n");

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  
  printf("Line #1 Distance:%6.1lf Angle:%6.1lf\n",distance_1,angle_1);
  printf("Line #2 Distance:%6.1lf Angle:%6.1lf\n",distance_2,angle_2);
  printf("Line #3 Distance:%6.1lf Angle:%6.1lf\n",distance_3,angle_3);

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
}

/*****+***---*-----*-**-**--*-*-*----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: distance_calculator
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double x_input1 - INPUT OF THE FIRST X COORDINATE
*    2. double y_input1 - INPUT OF THE FIRST Y COORDINATE
*    3. double x_input2 - INPUT OF THE SECOND X COORDINATE
*    4. double y_input2 - INPUT OF THE SECOND Y COORDINATE
*
*  Function Description: Calculates the distance between two points on
*   an xy-coordinate system.
*
******+***---*-----*-**-**--*-*-*----*-*-*-**-*****************************/

double distance_calculator(double x_input1,double y_input1,double x_input2,double y_input2)
{

  double distance; // calculates distance between two points

  distance = sqrt((pow((y_input2 - y_input1) , 2) + pow((x_input2 - x_input1),2)));

  return (distance);
}

/*****+***--***-*-****--**--*-*-*----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: angle_calculator
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double t_length_1 - FIRST SIDE LENGTH OF THE TRIANGLE
*    2. double t_length_2 - SECOND SIDE LENGTH OF THE TRIANGLE
*    3. double t_length_3 - THIRD SIDE LENGTH OF THE TRIANGLE
*
*  Function Description: Uses the Law of Cosines to calculate the angle
*   of a triangle.
*
******+***--***-*-****--**--*-*-*----*-*-*-**-*****************************/

double angle_calculator(double t_length_1, double t_length_2, double t_length_3)
{
  double angle; // the angle calculated for the triangle
  double top; // top part of the fraction when solved the angle from the Law of Cosines
  double bottom; // bottom part of the fraction when solved the angle from the Law of Cosines
  
  top = pow(t_length_1, 2) - pow(t_length_2, 2) - pow(t_length_3, 2);
  bottom = -2.0 * t_length_2 * t_length_3;
  angle = acos((top / bottom)) * DEGTORAD;

  return(angle);
}
