// Dragforce calculation program
// From Brooks, Problem: 2.7
// A minimal version in the style of the textbook. 
 
#include <stdio.h>
 
const double RHO=1.23;             // density of air 
const double SQFT_TO_SQM=0.09290;  // conversion of feet^2 to m^2 
const double HP_TO_WATT=746;       // conversion for watts to horsepower 
const double MPH_TO_MPS=0.477;     // conversion miles/hr to meters/s 
 
int main() {
 
  float mph, area, coef;    // read from keyboard 
 
  float mps, sq_m, drag_force, power;
 
  printf("Enter Speed of object (mph): ");
  scanf("%f",&mph);
 
  printf("Enter Area of object (feet^2): ");
  scanf("%f",&area);
 
  printf("Enter Drag Coefficient of object (0.2-0.5): ");
  scanf("%f",&coef);
 
  // calculation of drag force F_D = (RHO/2)*v^2*A*C_d (Newtons)
  
  mps = mph * MPH_TO_MPS;       // speed in m/s
  sq_m = area * SQFT_TO_SQM;    // area in m^2
  drag_force = (RHO/2.) * mps*mps * sq_m * coef;
 
  // calculation of power to overcome drag P = F_D * v (Watts)
 
  power = drag_force * mps;
 
  printf("\n\nTotal drag force = %6.2f (N)\n",drag_force);
  printf("Horsepower needed to overcome drag = %6.2f (HP)\n",
         power/HP_TO_WATT);
 
  return 0;
}
