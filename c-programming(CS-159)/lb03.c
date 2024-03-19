/*****+----*--*-***---**---*--**--*-**-*-*-**-******************************
*
*  Lab # 3:
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Program Description: This program takes a user two user inputs, being  
*  circumcircle radius or incircle radius, and length of the corresponding 
*  value. The program then uses logic based on truncating and the modulus 
*  function to calculate pentagon components, and then calculates the 
*  rest of the circle and hexagon values based on the pentagon values.
*
******+----*--*-***---**---*--**--*-**-*-*-**-*****************************/
#include <stdio.h>
#include <math.h>
#define ASCII_INRAD 73
#define ASCII_CIRCUM 67
#define DEGTORAD M_PI/180

int main (void) 
{

  char inradius_or_circumradius; // user input for type of radius
  double I_C_length; // length of incircle radius or circumcircle radius
  int logic_checker_inrad; // checks for incircle radius
  int logic_checker_circum; // checks for circumcircle radius
  double pent_ap; // apothem of pentagon
  double pent_base; // base length of pentagon
  double pent_area; // area of pentagon
  double scir_rad; // radius of small circle
  double lcir_rad; // radius of large circle
  double lcir_area; // area of large circle
  double hex_area; // area of hexagon
  double scir_area; // area of small circle
  double hex_side; // side length of hexagon

  printf("Select the (I)ncircle or (C)ircumcircle radius -> ");
  scanf("%c", &inradius_or_circumradius);

  printf("Enter the length -> ");
  scanf("%lf", &I_C_length);

  inradius_or_circumradius = (double)inradius_or_circumradius;

  logic_checker_inrad = (int)(inradius_or_circumradius % (ASCII_INRAD + 1)) / ASCII_INRAD; // 0 or 1 casters
  logic_checker_circum = (int)(inradius_or_circumradius % (ASCII_CIRCUM + 1)) / ASCII_CIRCUM; 

  pent_ap = (logic_checker_inrad * I_C_length) + (logic_checker_circum * I_C_length * sin(54 * DEGTORAD));
  pent_base = (logic_checker_inrad * pent_ap * 2 * tan(36 * DEGTORAD)) + (logic_checker_circum * pent_ap * 2 * tan(36 * DEGTORAD)); // calculations based on 0/1
  pent_area = (logic_checker_inrad * 2.5 * pent_base * pent_ap) + (logic_checker_circum * 2.5 * pent_base * pent_ap);
  
  hex_side = 2 * pent_ap * sin(30 * DEGTORAD); // calculations without the need of the logic checker
  lcir_rad = hex_side;
  lcir_area = (M_PI * pow(lcir_rad,2));
  hex_area = 3 * sqrt(3) / 2 * pow(hex_side, 2);
  scir_rad = hex_side * cos(30 * DEGTORAD);
  scir_area = M_PI * pow(scir_rad, 2);

  printf("\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Apothem of pentagon:%13.2f\n",pent_ap);
  printf("Base of pentagon:%16.2f\n",pent_base);
  printf("Area of pentagon:%16.2f\n",pent_area);
  printf("Area of large circle:%12.2f\n",lcir_area);
  printf("Area of hexagon:%17.2f\n",hex_area);
  printf("Area of small circle:%12.2f\n",scir_area);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("\n");

  return 0; 
}

