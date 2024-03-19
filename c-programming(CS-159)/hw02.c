/*****+----*--*-**----***--*--***----***-*-**-******************************
*
*  Homework #: 02
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program takes the user input of three different
*  points, two of which are on the same line. The program then calculates the 
*  distance between the first point and third point, and second point and
*  third point. Finally, the program calculates the point of intersection
*  between the line of the first two points, and a perpendicular line
*  through the third point.
*
******+----*--*-**----***--*--***----***-*-**-*****************************/
#include <stdio.h>
#include <math.h>

int main (void) 
{

  float road_1_x_coord; //x coordinate of the first input
  float road_1_y_coord; //y coordinate of the first input
  float road_2_x_coord; //x coordinate of the second input
  float road_2_y_coord; //y coordinate of the second input
  float road_3_x_coord; //x coordinate of the third input
  float road_3_y_coord; //y coordinate of the third input
  float road_1_2_slope; //slope of the first road
  float road_3_slope_perpendicular; //slope of the perpendicular line to the first road
  float xdistance_1_3; //distance formula x component for point 1 and 3
  float ydistance_1_3; //distance formula y component for point 1 and 3
  float xdistance_2_3; //distance formula x component for point 2 and 3 
  float ydistance_2_3; //distance formula y component for point 2 and 3
  float point_1_3_distance; //distance between the first and third point
  float point_2_3_distance; //distance between the second and third point
  float pslope_line_1; //point slope form of the line between the first 2 points
  float pslope_line_perp; //point slope form for the perpendicular line 
  float x_intersect_coord; //value of the x coordinate of the point of intersection
  float y_intersect_coord; //value of the y coordinate of the point of intersection

  printf("Enter coordinates for first point of road -> ");
  scanf("%f %f", &road_1_x_coord, &road_1_y_coord); //user input for coordinate 1
 
  printf("Enter coordinates for second point of road -> ");
  scanf("%f %f", &road_2_x_coord, &road_2_y_coord); //user input for coordinate 2

  printf("Enter coordinates for point on perpendicular road -> ");
  scanf("%f %f", &road_3_x_coord, &road_3_y_coord); //user input for coordinate 3

  printf("\n");

  xdistance_1_3 = road_3_x_coord - road_1_x_coord; //components of the distance formula
  ydistance_1_3 = road_3_y_coord - road_1_y_coord;
  xdistance_2_3 = road_3_x_coord - road_2_x_coord;
  ydistance_2_3 = road_3_y_coord - road_2_y_coord; 
  
  point_1_3_distance = sqrt(pow(xdistance_1_3,2) + pow(ydistance_1_3,2)); //distance calculator for points 1 and 3
  point_2_3_distance = sqrt(pow(xdistance_2_3,2) + pow(ydistance_2_3,2)); //distance calculator for points 2 and 3
 
  road_1_2_slope = ((road_2_y_coord - road_1_y_coord) / (road_2_x_coord - road_1_x_coord)); //slopes of roads
  road_3_slope_perpendicular = (-1.00 / road_1_2_slope);
 
  pslope_line_1 = ((road_1_2_slope * road_1_x_coord) - road_1_y_coord); //components of point-slope formula
  pslope_line_perp = ((-1 * road_3_slope_perpendicular * road_3_x_coord) + road_3_y_coord);

  x_intersect_coord = (pslope_line_1 + pslope_line_perp) / (road_1_2_slope - road_3_slope_perpendicular); 
  y_intersect_coord = ((road_1_2_slope * x_intersect_coord) - (road_1_2_slope * road_1_x_coord) + road_1_y_coord);

  printf("Distance from (%.1f, %.1f) to (%.1f, %.1f): %.1f \n", road_1_x_coord, road_1_y_coord, road_3_x_coord, road_3_y_coord, point_1_3_distance);
  printf("Distance from (%.1f, %.1f) to (%.1f, %.1f): %.1f \n", road_2_x_coord, road_2_y_coord, road_3_x_coord, road_3_y_coord, point_2_3_distance);
  printf("Coordinate of intersection: %.1f, %.1f \n", x_intersect_coord, y_intersect_coord);

  return 0;
}
