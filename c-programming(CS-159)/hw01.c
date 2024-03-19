/*****+---**--*--*----***--**--*--*--***-*-**-******************************
*
*  Homework #: 1
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program takes the user's input of mass in pounds, and velocity in fps, and tells the user its   kinetic energy in joules, velocity in m/s, and mass in kg.
*
******+---**--*--*----***--**--*--*--***-*-**-*****************************/
#include <stdio.h>
#include <math.h>

int main(void)
{
  float obj_mass; //mass of the object in pounds
  float obj_velocity; //velocity of the object in feet per second
  float obj_k_energy; //kinetic energy of the object in joules_

  printf("Enter the object mass in pounds -> ");
  scanf("%f", &obj_mass);

  printf("Enter the object velocity ft/s -> ");
  scanf("%f", &obj_velocity);
  
  obj_mass = obj_mass * .453592;
  obj_velocity = obj_velocity * .3048;
  obj_k_energy = (0.5 * obj_mass) * (pow(obj_velocity, 2));

  printf("\n");
  printf("The mass of the object: %.2f (kg)\n", obj_mass);
  printf("The velocity of the object: %.2f (m/s)\n", obj_velocity);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("The kinetic energy of the object: %.2f (J)\n", obj_k_energy);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
}
