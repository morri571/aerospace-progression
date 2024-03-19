/*****+----*-----*--*--*--**--***----*-*-*-**-******************************
*
*  Lab #: 05
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program uses user defined functions to 
*  calculate the distances of three lines of a triangle as well as its three
*  angles. The program accepts 4 user inputs, those being the coordinates of two
*  points of the triangle and the measurements of two angles measured at the x-axis
*  for lines passing through the inputted points. The program uses a scan UDF to
*  collect the inputs necessary to perform the calculations.
*
******+----*-----*--*--*--**--***----*-*-*-**-*****************************/

#include <stdio.h>
#include <math.h>
#define DEG_TO_RAD M_PI/180
#define RAD_TO_DEG 180/M_PI

// Function Declarations
void get_input(double*, double*, double*, double*, double*, double*);
double distance_calculator(double, double, double, double);
void intersect_calculator(double, double, double, double, double*, double*, double, double);
double law_cosines(double, double, double);
void output(double, double, double, double, double, double);

int main (void)
{

  // Declarations
  double x1; // The x-coordinate of the first inputted point
  double y1; // The y-coordinate of the first inputted point
  double x2; // The x-coordinate of the second inputted point
  double y2; // The y-coordinate of the second inputted point
  double x3; // The calculated x-coordinate of the third triangle point
  double y3; // The calculated y-coordinate of the third triangle point
  double p1_angle; // The first inputted angle as measured at the x-axis for the line passing through point 1
  double p2_angle; // The second inputted angle as measured at the x-axis for the line passing through point 2
  double t1_angle; // The calculated first interior angle of the triangle as it corresponds to line 1
  double t2_angle; // The calculated second interior angle of the triangle as it corresponds to line 2
  double t3_angle; // The calculated third interior angle of the triangle as it corresponds to line 3 
  double distance_1; // The calculated distance of line 1
  double distance_2; // The calculated distance of line 2
  double distance_3; // The calculated distance of line 3

  // Inputs
  get_input(&x1, &y1, &x2, &y2, &p1_angle, &p2_angle);

  // Function Calls
  distance_1 = distance_calculator(x1, y1, x2, y2);

  intersect_calculator(x1, y1, x2, y2, &x3, &y3, p1_angle, p2_angle);

  distance_1 = distance_calculator(x1, y1, x2, y2);
  distance_2 = distance_calculator(x2, y2, x3, y3);
  distance_3 = distance_calculator(x1, y1, x3, y3);

  t1_angle = law_cosines(distance_2, distance_3, distance_1);
  t2_angle = law_cosines(distance_3, distance_1, distance_2);
  t3_angle = law_cosines(distance_1, distance_2, distance_3);

  // Outputs
  output(distance_1, distance_2, distance_3, t1_angle, t2_angle, t3_angle);

  return 0;

}

/*****+*-***-*----**-*-*--*--**-*----*-*-*-**-******************************
 *
 *  Function Information
 *
 *  Name of Function: get_input
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. double* x1 - the inputted x-coordinate of the first point
 *    2. double* y1 - the inputted y-coordinate of the first point
 *    3. double* x2 - the inputted x-coordinate of the second point
 *    4. double* y2 - the inputted y-coordinate of the second point
 *    5. double* p1_angle - the inputted first angle as measured from the
 *       x-axis for the line passing through point 1
 *    6. double* p2_angle - the inputted second angle as measured from the
 *       x-axis for the line passing through point 2
 *
 *  Function Description: Gathers user inputs of coordinates and angles and
 *  then passes them by address to the main function for their use in
 *  calculations.
 *
 ******+*-***-*----**-*-*--*--**-*----*-*-*-**-*****************************/

void get_input(double* x1, double* y1, double* x2, double* y2, double* p1_angle, double* p2_angle)
{

  printf("Enter coordinates for point #1 -> ");
  scanf("%lf %lf", x1, y1);
  printf("Enter angle at x-axis for line passing through point #1 -> ");
  scanf("%lf", p1_angle);
  printf("Enter coordinates for point #2 -> ");
  scanf("%lf %lf", x2, y2);
  printf("Enter angle at x-axis for line passing through point #2 -> ");
  scanf("%lf", p2_angle);

}

/*****+----*--*--**----*--**---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: distance_calculator
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double x_first - the x-coordinate of the first point
*    2. double y_first - the y-coordinate of the first point
*    3. double x_second - the x-coordinate of the second point
*    4. double y_second - the y-coordinate of the second point
*
*  Function Description: Determines the distance between two points as they
*  are called on in the function call.
*
******+----*--*--**----*--**---*-----*-*-*-**-*****************************/

double distance_calculator(double x_first, double y_first, double x_second, double y_second)
{

  double distance; // The calculated distance between the two points

  distance = sqrt((pow((y_second - y_first) , 2) + pow((x_second - x_first),2)));

  return distance;

}

/*****+----*--*--**----*--**---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: intersect_calculator
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double x_first - the x-coordinate of the first point
*    2. double y_first - the y-coordinate of the first point
*    3. double x_second - the x-coordinate of the second point
*    4. double y_second - the y-coordinate of the second point
*    5. double* x3 - the x-coordinate of the third point
*    6. double* y3 - the y-coordinate of the third point
*    7. double angle_1 - the first inputted angle
*    8. double angle_2 - the second inputted angle
*
*  Function Description: This function calculates the slopes of two of lines
*  comprising the triangle by using the given angles the user has inputted.
*  The function then uses these slopes to determine the coordinates of the
*  third point of the triangle, which is the point at which the lines intersect.
*  The data is passed to the main function using pass by address.
*
******+----*--*--**----*--**---*-----*-*-*-**-*****************************/

void intersect_calculator(double x_first, double y_first, double x_second, double y_second, double* x3, double* y3, double angle_1, double angle_2)
{

  double slope_1; // The slope of the first line
  double slope_2; // The slope of the second line

  slope_1 = tan(angle_1 * DEG_TO_RAD);
  slope_2 = tan(angle_2 * DEG_TO_RAD);

  *x3 = (((-1.00 * slope_2 * x_second) + y_second) + ((slope_1 * x_first) -y_first)) / (slope_1 - slope_2);
  *y3 = (slope_1 * *x3) - (slope_1 * x_first) + y_first;

}

/*****+----*--*--**----*--**---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: law_cosines
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double d_1 - the calculated distance of the first line
*    2. double d_2 - the calculated distance of the second line
*    3. double d_3 - the calculated distance of the third line
*
*  Function Description: This function uses the law of cosines to calculate
*  the interior angles of the triangle given the distances or lengths of each
*  of its sides.
*
******+----*--*--**----*--**---*-----*-*-*-**-*****************************/

double law_cosines(double d_1, double d_2, double d_3)
{

  double angle; // The calculated angle

  angle = acos((pow(d_3,2) - pow(d_1,2) - pow(d_2,2)) / (-2 * d_1 * d_2)) * RAD_TO_DEG;

  return angle;

}

/*****+----*--*--**----*--**---*-----*-*-*-**-******************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double d_1 - the calculated distance of line 1
*    2. double d_2 - the calculated distance of line 2
*    3. double d_3 - the calculated distance of line 3
*    4. double t1_angle - the calculated first interior angle of the triangle
*       as it corresponds to line 1
*    5. double t2_angle - the calculated second interior angle of the triangle
*       as it corresponds to line 2
*    6. double t3_angle - the calculated third interior angle of the triangle
*       as it corresponds to line 3
*
*  Function Description: The purpose of this function is to output all of
*  the calculated line distances and corresponding interior angles for each line
*  in the triangle into a neat display in the command window.
*
******+----*--*--**----*--**---*-----*-*-*-**-*****************************/

void output(double d_1, double d_2, double d_3, double t1_angle, double t2_angle, double t3_angle)
{

  printf("\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Line #1 Distance: %5.1lf Angle: %5.1lf\n",d_1,t1_angle);
  printf("Line #2 Distance: %5.1lf Angle: %5.1lf\n",d_2,t2_angle);
  printf("Line #3 Distance: %5.1lf Angle: %5.1lf\n",d_3,t3_angle);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

}
