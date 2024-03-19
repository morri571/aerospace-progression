/*****+****--**---**-**-***-*---*-*--***-*-**-******************************
*
*  Lab #: 01
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: When given a value for the height of a right circular cone
*  and radius of a hemisphere, calculate the volume of the cone, the hemisphere, and
*  total volume in cubic meters.
*
******+****--**---**-**-***-*---*-*--***-*-**-*****************************/
#include <stdio.h>
#include <math.h>
#define MPI 3.1416
#define FEET_METERS_CUBED 35.315

int main(void)
{
  float cone_height; //height in meters
  float hemi_radius; //radius in meters
  float vol_hemi; //volume of hemisphere in meters cubed
  float vol_cone; //volume of cone in meters cubed
  float vol_tot_m; //total volume of the cone and hemisphere in meters cubed
  float vol_tot_ft; //total volume of the cone and hemisphere in feet cubed

  printf("Enter the height of the cone in meters -> ");
  scanf("%f", &cone_height);

  printf("Enter the radius of the hemisphere in meters -> ");
  scanf("%f", &hemi_radius);

  vol_hemi = 2 * MPI / 3 * pow(hemi_radius, 3);
  vol_cone = MPI / 3 * cone_height * pow(hemi_radius, 2);
  vol_tot_m = vol_hemi + vol_cone;
  vol_tot_ft = FEET_METERS_CUBED * vol_tot_m;

  printf ("\nThe volume of the hemisphere: %.2f cubic meters\n", vol_hemi);
  printf ("The volume of the cone: %.2f cubic meters\n", vol_cone);
  printf ("The total volume of the shape: %.2f cubic meters\n", vol_tot_m);
  printf ("The total volume of the shape: %.2f cubic feet\n", vol_tot_ft);

  return 0;
}
