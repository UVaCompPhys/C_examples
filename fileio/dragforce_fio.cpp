// Calculate drag force on a body moving in air
// This version reads it inputs from a file: inputs.dat
 
#include <stdio.h>
 
// constant values used within the program
const double RHO=1.23;             // density of air kg m^-3
const double SQFT_TO_SQM=0.09290;  // conversion of feet^2 to m^2 
const double HP_TO_WATT=746;       // conversion for watts to horsepower 
const double MPH_TO_MPS=0.477;     // conversion miles/hr to meters/s 
 
int main() {
 
  float mph, area, coef;    // read from a file
  float mps, sq_m, drag_force, power;
 
  const char* fileName="inputs.dat";  // file name string
  FILE *fp;  // define a "file pointer" to represent the data file
  fp = fopen(fileName,"r");  // open the file for reading
 
 
  fscanf(fp,"%f",&mph); 
  fscanf(fp,"%f",&area);
  fscanf(fp,"%f",&coef);
 
  printf("Read inputs: mph %f, area %f, coef %f\n",mph,area,coef);
 
  // calculation of drag force F_D = (RHO/2)*v^2*A*C_d (Newtons)
 
  mps = mph * MPH_TO_MPS;       // speed in m/s
  sq_m = area * SQFT_TO_SQM;    // area in m^2
  drag_force = (RHO/2.) * mps*mps * sq_m * coef;
 
  // calculation of power to overcome drag P = F_D * v (Watts)
 
  power = drag_force * mps;
 
  printf("\nTotal drag force = %6.2f (N)\n",drag_force);
  printf("Horsepower needed to overcome drag = %6.2f (HP)\n",
         power/HP_TO_WATT);
 
  return 0;
}
